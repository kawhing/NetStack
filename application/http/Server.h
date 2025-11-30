//
// Created by kawhing on 2025/11/29.
//
#ifndef Server_c
#define Server_c
#include <sys/socket.h>
#include <netinet/in.h>


struct Server {
    int domain;// 域
    int service;// 服务类型
    int protocol;// 协议
    u_long interface;// 监听的网络接口
    int port;// 端口号
    int backlog;// 最大连接数

    struct sockaddr_in address;// 服务器地址结构

    int socket;
    void (*launch)(struct Server *server);
};

struct Server server_constructor(int domain, int service,
    int protocol, u_long interface, int port, int backlog,
    void (*launch)(struct Server *server)
);

#endif //Server_c