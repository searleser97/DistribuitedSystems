#include "mongoose.h"
#include <dirent.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

static const char *s_http_port = "8000";
static struct mg_serve_http_opts s_http_server_opts;

int compare(const struct mg_str *str1, const char *str2) {
  size_t n2 = strlen(str2), n1 = str1->len;
  int r = strncmp(str1->p, str2, (n1 < n2) ? n1 : n2);
  if (r == 0) {
    return n1 - n2;
  }
  return r;
}

vector<string> getFilesAndFolders(string path) {
	DIR *dir = opendir(path.c_str());
	if (dir == NULL) return {};
	struct dirent *ent;
	vector<string> files;
	while ((ent = readdir(dir)) != NULL) {
		string file(ent->d_name);
		if (file != "." && file != ".." && file != "index.html" && file != "script.js" && file != "estilos.css" && file != "jquery.lazyload.min.js" && file != "jquery-1.11.1.min.js" && file != "jquery.easytabs.min.js" && file != "jquery.hashchange.min.js") {
			files.push_back(file);
		}
	}
	return files;
}

static void ev_handler(struct mg_connection *nc, int ev, void *ev_data) {
	struct http_message *hm = (struct http_message *) ev_data;
	if (ev == MG_EV_HTTP_REQUEST) {
		if (compare(&hm->uri, "/getHosts") == 0) {
			mg_printf(nc, "%s", "HTTP/1.1 200 OK\r\nTransfer-Encoding: chunked\r\n\r\n");
			vector<string> hosts = getFilesAndFolders("captures");
			mg_printf_http_chunk(nc, "{\"hosts\": [");
			for (size_t i = 0; i < hosts.size(); ++i) {
				if (i > 0) mg_printf_http_chunk(nc, ", ");
				mg_printf_http_chunk(nc, "\"%s\"", hosts[i].c_str());
			}
			mg_printf_http_chunk(nc, "]}");
			mg_send_http_chunk(nc, "", 0);
		} else if(compare(&hm->uri, "/getCaptures") == 0) {
			mg_printf(nc, "%s", "HTTP/1.1 200 OK\r\nTransfer-Encoding: chunked\r\n\r\n");
			char host[100];
			strncpy(host, hm->query_string.p + 5, hm->query_string.len - 5);
			host[hm->query_string.len - 5] = '\0';
			string path = "captures/" + string(host);
			vector<string> captures = getFilesAndFolders(path);
			sort(captures.begin(), captures.end(), greater<string>());
			mg_printf_http_chunk(nc, "{\"captures\": [");
			for (size_t i = 0; i < captures.size(); ++i) {
				if (i > 0) mg_printf_http_chunk(nc, ", ");
				mg_printf_http_chunk(nc, "\"%s\"", captures[i].c_str());
			}
			mg_printf_http_chunk(nc, "]}");
			mg_send_http_chunk(nc, "", 0);
		} else {
			mg_serve_http(nc, hm, s_http_server_opts);
		}
	}
}

int main(void) {
	struct mg_mgr mgr;
	struct mg_connection *nc;

	mg_mgr_init(&mgr, NULL);
	printf("Starting web server on port %s\n", s_http_port);
	nc = mg_bind(&mgr, s_http_port, ev_handler);
	if (nc == NULL) {
		printf("Failed to create listener\n");
		return 1;
	}

	// Set up HTTP server parameters
	mg_set_protocol_http_websocket(nc);
	s_http_server_opts.document_root = "captures"; // Serve current directory
	s_http_server_opts.enable_directory_listing = "yes";
	for (;;) {
		mg_mgr_poll(&mgr, 1000);
	}
	mg_mgr_free(&mgr);

	return 0;
}
