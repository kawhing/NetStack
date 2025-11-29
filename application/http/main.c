#include <stdio.h>
#include <sys/socket.h>    // socket相关函数
#include <netinet/in.h>    // 网络地址结构
#include <unistd.h>       // read函数

int main() {
    // 创建TCP IPv4 socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("创建socket失败！\n");
        return 1;
    }
    unsigned short port = 8080;
    // 绑定地址到socket
    struct sockaddr_in server_address; // 服务器地址结构
    server_address.sin_family = AF_INET;        // IPv4
    server_address.sin_addr.s_addr = INADDR_ANY; // 任何IP都能访问
    server_address.sin_port = htons(port);      // 端口号

    // 绑定地址到socket
    int bind_result = bind(server_socket,
                          (struct sockaddr*)&server_address,
                          sizeof(server_address));

    if (bind_result == -1) {
        printf("绑定地址失败！可能端口被占用了\n");
        return 1;
    }
    printf("服务器绑定到端口 %d 成功！\n", port);

    listen(server_socket, 5);// 监听连接，最大连接数5
    printf("服务器正在监听连接...\n");

    int count = 0;
    while (count < 5) {
        // 接受连接
        int client_socket = accept(server_socket, NULL, NULL);

        if (client_socket == -1) {
            printf("接受连接失败！\n");
            return 1;
        }

        count++;

        printf("有客户连接进来了！客户socket编号：%d\n", client_socket);
        char buffer[1024] = {0};

        // 读取客户发来的数据
        int bytes_read = read(client_socket, buffer, 1024);

        printf("收到 %d 字节数据：\n", bytes_read);
        printf("%s\n", buffer);
        // 关闭客户连接
        close(client_socket);
    }
    if (count >= 5) {
        printf("已达到最大连接数，服务器关闭！\n");
        close(server_socket);
    }
    return 0;
}