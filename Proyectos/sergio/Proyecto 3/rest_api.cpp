#include "mongoose.h"
#include <filesystem>
#include <iostream>
#include <vector>
using namespace std;

vector<string> getFileList(string path) {
  vector<string> fileNames;
  for (const auto &entry : filesystem::directory_iterator(path))
    fileNames.push_back(entry.path().generic_string().substr(2));
  return fileNames;
}

vector<string> getScreenshots() { return getFileList("./ScreenShots"); }

static const char *s_http_port = "8000";
static struct mg_serve_http_opts s_http_server_opts;

static void ev_handler(struct mg_connection *connection, int event_id,
                       void *event_data) {
  struct http_message *http = (struct http_message *)event_data;

  std::string uri("");

  if (event_id == MG_EV_HTTP_REQUEST) {
    connection->flags |= MG_F_SEND_AND_CLOSE;
    uri.assign(http->uri.p, http->uri.len);
    if (uri == "/getScreenShots") {
      vector<string> screenshots = getScreenshots();
      string response = "{\n    screenshots: [\n";
      for (int i = 0; i < screenshots.size(); i++) {
        if (i)
          response += ",\n";
        for (int i = 0; i < 8; i++)
          response += " ";
        response += screenshots[i];
      }
      response += "\n";
      for (int i = 0; i < 4; i++) response += " ";
      response += "]\n}";
      cout << response << endl;
      mg_printf(connection, "%s", "HTTP/1.1 200 OK\r\nTransfer-Encoding: chunked\r\n\r\n");
      mg_printf_http_chunk(connection, response.c_str());
      mg_send_http_chunk(connection, "", 0);
    } else {
      mg_serve_http(connection, http, s_http_server_opts);
    }
  }
}

int main() {
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
  s_http_server_opts.document_root = "ScreenShots"; // Serve directory
  s_http_server_opts.enable_directory_listing = "yes";
  while (true) {
    mg_mgr_poll(&mgr, 1000);
  }
  mg_mgr_free(&mgr);

  return 0;
}
