/*************************************************************************
	> File Name: service.cpp
	> Author: wk
	> Mail: 18402927708@163.com
	> Created Time: Tue 22 Nov 2016 12:01:49 AM CST
 ************************************************************************/

#include"comm.h"


#define ERR_EXIT(m) \
        do \
        { \
                perror(m); \
                exit(EXIT_FAILURE); \
        } while(0)

void handle(int signum)
{
	int pid = 0;
	printf("recv signum:%d ", signum);

	while ((pid = waitpid(-1, NULL, WNOHANG) ) > 0)
	{
		printf("exit child proccess  pid= %d \n", pid);
		fflush(stdout);
	} 
}

int main(void)
{
	int		ret = 0;
	int 	listenfd;
	
	
	signal(SIGCHLD, handle);
	signal(SIGPIPE, SIG_IGN);
	
	ret = SockServer_init("127.0.0.1",8002, &listenfd);
	if (ret != 0)
	{
		printf("SockServer_init() err:%d \n", ret);
		return ret;
	}
	
	while(1)
	{
		int ret = 0;
		int wait_seconds = 10;
		int connfd = 0;

		ret = SockServer_accept(listenfd, &connfd,  wait_seconds);
		if (ret == Sock_ErrTimeOut)
		{
			printf("timeout....\n");
			continue;
		}
	   //printf("listenfd %d\nconfd : %d\n",listenfd,connfd);
		int pid = fork();
		if (pid == 0)
		{	
			close(listenfd);
			logic_processing(connfd);
		}
		else if (pid > 0)//father
		{
			close(connfd);
		}
		else if(pid == -1)
		{
		   close(connfd);
		   close(listenfd);
           ERR_EXIT("fork");
		}
	}
	
	return 0;
}