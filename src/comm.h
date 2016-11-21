/*************************************************************************
	> File Name: comm.h
	> Author: wk
	> Mail: 18402927708@163.com
	> Created Time: Tue 22 Nov 2016 12:52:08 AM CST
 ************************************************************************/

#ifndef _COMM_H
#define _COMM_H

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

//错误码定义  
#define Sock_Ok          0
#define Sock_Err   		3000

#define Sock_ErrParam                	(Sock_Err+1) //参数错误
#define Sock_ErrTimeOut                	(Sock_Err+2) //超时错误
#define Sock_ErrPeerClosed               (Sock_Err+3)//对方关闭
#define Sock_ErrMalloc			   		(Sock_Err+4)//malloc申请错误

//客户端函数声明
//客户端环境初始化
int SockClient_init(void **handle);
//客户端建立连接
int SockClient_getconn(void *handle, char *ip, int port, int *connfd,int contime);
//客户端断开连接
int SockClient_closeconn(int connfd);
//客户端发送报文
int SockClient_send(void *handle, int  connfd,  unsigned char *data, int datalen,int sendtime);
//客户端端接受报文
int SockClient_rev(void *handle, int  connfd, unsigned char *out, int *outlen,int recvtime); 
// 客户端环境释放 
int SockClient_destroy(void *handle);

//服务器端函数声明
//服务器端初始化
int SockServer_init(const char* ip,short port, int *listenfd);
//服务端建立连接
int SockServer_accept(int listenfd, int *connfd,  int timeout);
//服务器端发送报文
int SockServer_send(int connfd,  unsigned char *data, int datalen, int timeout);
//服务器端端接受报文
int SockServer_rev(int  connfd, unsigned char *out, int *outlen,  int timeout); 
//服务器端环境释放 
int SockServer_destroy(void *handle);

#endif
