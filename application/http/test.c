//
// Created by kawhing on 2025/11/30.
//

#include <stdio.h>
#include "Server.h"
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

void launch(struct Server *server) {
    while (1) {
        char buffer[30000];
        printf("===== WATTING FOR CONNECT =====\n");
        int address_length = sizeof(server->address);
        int new_socket = accept(server->socket, (struct sockaddr *)&server->address, (socklen_t *)&address_length);
        read(new_socket, buffer, sizeof(buffer));
        printf("%s\n", buffer);
        char *hello = "HTTP/1.1 200 OK\n"
                      "Date : Mon, 27 Jul 2009 12:28:53 GMT\n"
                      "Server : Apache/2.2.14 (Win32)\n"
                      "Last-Modified : Wed, 22 Jul 2009 19:15:56 GMT\n"
                      "Content-Length : 88\n"
                      "Content-Type : text/html\n"
                      "Connection : Closed\n"
                      "\n"
                      "<html>\n"
                      "<body>\n"
                      "<h1>Hello, World!</h1>\n"
                      "</body>\n"
                      "</html>";
        write(new_socket, hello, strlen(hello));
        close(new_socket);
    }
}
int main() {
    struct Server server = server_constructor(AF_INET, SOCK_STREAM, 0, INADDR_ANY, 8080, 10, launch);
    server.launch(&server);
    return 0;
}