#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>

int puerto = 7200;

uint32_t ipBlock(uint32_t x, int pos)
{
   return (x >> (pos * 8)) & 0xFF;
}

void printIp(uint32_t ip) {
   printf("%u.%u.%u.%u", ipBlock(ip, 0), ipBlock(ip, 1), ipBlock(ip, 2), ipBlock(ip, 3));
}

int main(int argc, char * argv[])
{
   struct sockaddr_in msg_to_server_addr, client_addr;
   int s, res;
   
   s = socket(AF_INET, SOCK_DGRAM, 0);
   /* rellena la dirección del servidor */
   bzero((char *)&msg_to_server_addr, sizeof(msg_to_server_addr));
   msg_to_server_addr.sin_family = AF_INET;
   uint32_t ip = msg_to_server_addr.sin_addr.s_addr = inet_addr(argv[1]);
   msg_to_server_addr.sin_port = htons(puerto);
   /* rellena la direcciòn del cliente*/
   bzero((char *)&client_addr, sizeof(client_addr));
   client_addr.sin_family = AF_INET;
   client_addr.sin_addr.s_addr = INADDR_ANY;
   printf("ip del servidor a la que nos conectaremos: ");
   printIp(ip);
   printf("\n");
   /*cuando se utiliza por numero de puerto el 0, el sistema se encarga de asignarle uno */
   client_addr.sin_port = htons(6666);
   bind(s, (struct sockaddr *)&client_addr,sizeof(client_addr));
   char num[65507];
   memset(num, 'a', sizeof(num));
   sendto(s, (void *)num, sizeof(num), 0, (struct sockaddr *) &msg_to_server_addr, sizeof(msg_to_server_addr));
   
   /* se bloquea esperando respuesta */
   struct sockaddr_in sender;
   int senderSize = sizeof(sender);
   recvfrom(s, (char *)&res, sizeof(int), 0, (struct sockaddr*) &sender, &senderSize);
   printf("puerto de servidor: %u\n", ntohs(sender.sin_port));
   printf("ip del servidor que nos manda la suma: ");
   printIp(sender.sin_addr.s_addr);
   printf("\n");
   printf("2 + 5 = %d\n", res);
   close(s);
}

