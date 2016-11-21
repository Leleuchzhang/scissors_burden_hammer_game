/*************************************************************************
	> File Name: client.cpp
	> Author: wk
	> Mail: 18402927708@163.com
	> Created Time: Tue 22 Nov 2016 12:01:33 AM CST
 ************************************************************************/

#include"comm.h"
 

int main()
{	

	int 		ret = 0;
	void 		*handle = NULL;
	int 		connfd;
	 unsigned char send_data[1024];
	 int send_datalen = 0;
	 
	 unsigned char recv_data[1024];
	 int recv_datalen = 0;
	//客户端环境初始化
	//int SockClient_init(void **handle, char *ip, int port, int contime, int sendtime, int revtime);
	ret = SockClient_init(&handle);
	ret = SockClient_getconn(handle, "127.0.0.1", 8002, &connfd,15);
     
	 client_login(connfd);
  
		send_datalen = strlen((const char*)send_data);
		int flag=0;
	//客户端发送报文
	while(SockClient_send(handle,  connfd, send_data, send_datalen,5) == Sock_ErrTimeOut)
	{
	  if (flag >5)
	  {
          printf("sckClinet_send timeout err:%d\n",Sock_ErrTimeOut);
		  return -1;
	  }
	  ++flag;
	  continue;
	}
	//客户端端接受报文
	ret = SockClient_rev(handle, connfd, recv_data, &recv_datalen,5);
     if(ret != 0)
     {
       recv_data[recv_datalen] = '\0';
	   printf("data: %s \n", recv_data);
     }
	else if(ret == Sock_ErrPeerClosed)
	{
		printf("perr close\n ");
    	// 客户端环境释放 
	   ret = SockClient_destroy(handle);
	   return 0;
	}
	return 0;
}

