#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <strings.h>
#include <sys/socket.h>
#include <sys/types.h>

uint32_t ipBlock(uint32_t x, int pos)
{
   return (x >> (pos * 8)) & 0xFF;
}

void printIp(uint32_t ip) {
   printf("%u.%u.%u.%u", ipBlock(ip, 0), ipBlock(ip, 1), ipBlock(ip, 2), ipBlock(ip, 3));
}

int puerto = 7200;

int main(void) {
  int num[2];
  int s, res, clilen;
  struct sockaddr_in server_addr, msg_to_client_addr;

  s = socket(AF_INET, SOCK_DGRAM, 0);

  /* se asigna una direccion al socket del servidor*/
  bzero((char *)&server_addr, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(puerto);
  bind(s, (struct sockaddr *)&server_addr, sizeof(server_addr));
  clilen = sizeof(msg_to_client_addr);
  while (1) {
    recvfrom(s, (char *)num, 2 * sizeof(int), 0,
             (struct sockaddr *)&msg_to_client_addr, &clilen);
    
    printf("puerto de cliente: %u\n", ntohs(msg_to_client_addr.sin_port));
    printf("ip del cliente que nos solicita la suma: ");
    printIp(msg_to_client_addr.sin_addr.s_addr);
    printf("\n");
    res = num[0] + num[1];

    /* envía la petición al cliente. La estructura msg_to_client_addr contiene
     * la dirección socket del cliente */
    sendto(s, (char *)&res, sizeof(int), 0,
           (struct sockaddr *)&msg_to_client_addr, clilen);
  }
}
