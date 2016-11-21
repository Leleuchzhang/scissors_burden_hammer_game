/*************************************************************************
	> File Name: client_op.cpp
	> Author: wk
	> Mail: 18402927708@163.com
	> Created Time: Tue 22 Nov 2016 04:28:51 AM CST
 ************************************************************************/

#include"comm.h"

void user_register()
{
	 unsigned char send_data[1024];
	 int send_datalen = 0;
	printf("you need register a new user\n");
    printf("username: ");
	if(fgets(send_data,1024,stdin) == NULL)
	 {
         printf("fgets error\n");
         return 0;
	 }
	SockClient_send(NULL,  connfd, send_data, send_datalen,5);
	printf("password: ");
	unsigned char passwd[10];
	int passwd_len = 0;
	SockClient_send(NULL,  connfd, passwd, passwd_len,5);
}

bool  exist_username(int connfd,char *send_data,int send_datalen)
{
     SockClient_send(NULL,  connfd, send_data, send_datalen,5);
	 //数据库或者map中查找出来相同的用户名
	 char recvdata='0';
	SockClient_rev(NULL, connfd, recv_data, &recv_datalen,5);
	if(recvdata != '0') //返回的字符不为'0' 则表示存在相同用户，否则不存在
	 return true;
	else
		return false;
}

void client_login(int connfd)
{
	 unsigned char send_data[1024];
	 int send_datalen = 0;
    printf("-------welcome!!!!--------\n ");
	printf("username: ");
	if(fgets(send_data,1024,stdin) == NULL)
	 {
         printf("fgets error\n");
         return 0;
	 }
	 if(exist_username(send_data,send_datalen)) //如果存在
	 {
	    user_register();
	 }
	 printf("password: ");
    if(fgets(send_data,1024,stdin) == NULL)
	 {
         printf("fgets error\n");
         return 0;
	 }

}

