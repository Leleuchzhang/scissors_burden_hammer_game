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

//�����붨��  
#define Sock_Ok          0
#define Sock_Err   		3000

#define Sock_ErrParam                	(Sock_Err+1) //��������
#define Sock_ErrTimeOut                	(Sock_Err+2) //��ʱ����
#define Sock_ErrPeerClosed               (Sock_Err+3)//�Է��ر�
#define Sock_ErrMalloc			   		(Sock_Err+4)//malloc�������

//�ͻ��˺�������
//�ͻ��˻�����ʼ��
int SockClient_init(void **handle);
//�ͻ��˽�������
int SockClient_getconn(void *handle, char *ip, int port, int *connfd,int contime);
//�ͻ��˶Ͽ�����
int SockClient_closeconn(int connfd);
//�ͻ��˷��ͱ���
int SockClient_send(void *handle, int  connfd,  unsigned char *data, int datalen,int sendtime);
//�ͻ��˶˽��ܱ���
int SockClient_rev(void *handle, int  connfd, unsigned char *out, int *outlen,int recvtime); 
// �ͻ��˻����ͷ� 
int SockClient_destroy(void *handle);

//�������˺�������
//�������˳�ʼ��
int SockServer_init(const char* ip,short port, int *listenfd);
//����˽�������
int SockServer_accept(int listenfd, int *connfd,  int timeout);
//�������˷��ͱ���
int SockServer_send(int connfd,  unsigned char *data, int datalen, int timeout);
//�������˶˽��ܱ���
int SockServer_rev(int  connfd, unsigned char *out, int *outlen,  int timeout); 
//�������˻����ͷ� 
int SockServer_destroy(void *handle);

#endif
