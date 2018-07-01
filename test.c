#include <stdio.h>
#include <stdlib.h>

typedef struct redisServer {
	int fd; //  套接字描述符

	char *name; // 服务端的名字

	char* querybuf; // 查询缓冲区

	int argc; // 参数数量

	char **argv; // 参数对象数组

	struct redisCommand *cmd, *lastcmd; // 记录被客户端执行的命令

	int reqtype; // 请求的类型,是内联命令还是多条命令 

	int multibulklen; // 剩余未读取的命令内容数量

	long bulklen; // 命令内容的长度

	//list *reply; // 回复链表

	int sentlen; // 已发送字节,处理short write时使用

	unsigned long reply_bytes; // 回复链表中对象的总大小

	int bufpos; // 回复偏移量

	char buf[100];

} redisServer;

typedef struct {
    int  size;
    redisServer *server;
} server_pools;


//
//int main(){
//	server_pools*  pools;
//	pools = (server_pools*) malloc(sizeof(server_pools));
//	pools->size= 5;
//	pools->server = (redisServer*) malloc(sizeof(redisServer)*pools->size);
//	pools->server[0].fd=10;
//	pools->server[1].fd=20;
//	printf("%d\n", pools->server[0].fd);
//	printf("%d\n", pools->server[1].fd);
//}