#include <stdio.h>
#include <sys/socket.h>    // socket相关函数
#include <netinet/in.h>    // 网络地址结构

/*
int server_socket = socket(...)

socket() 是一个函数，调用它就创建了一个"通信端点"
返回一个整数编号（像你的店铺营业执照号）
AF_INET 表示用IPv4网络
SOCK_STREAM 表示用TCP协议（可靠传输）
0 是默认协议

if (server_socket == -1)
如果返回-1，说明创建失败了
打印错误信息并退出
*/

int main() {
    // 创建一个socket（返回一个编号）
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // 检查是否创建成功
    if (server_socket == -1) {
        printf("创建socket失败！\n");
        return 1;
    }

    printf("Socket创建成功！编号是：%d\n", server_socket);
    return 0;
}