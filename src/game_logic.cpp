/*************************************************************************
	> File Name: game_logic.cpp
	> Author: wk
	> Mail: 18402927708@163.com
	> Created Time: Tue 22 Nov 2016 05:07:34 AM CST
 ************************************************************************/

#include"game_logic.h"

typedef struct cmd_map
{
	const char*cmd;
	void (*cmd_func)(session_t *sess);
}cmd_map_t; 


static void do_login(session_t *sess);
static void do_pass(session_t *sess);
static void do_user();
static void do_open();
static void do_join();
static void do_cast();
static void do_info();
static void do_find();
static void do_logout();


static cmd_map_t cmd_function[]={

    //命令   执行函数
    {"login",do_login},//用户登录 
	{"open",do_open},//发起一个战局
	{"join",do_join},//加入一个战局(可以随机匹配到同样执行join的用户)
	{"cast",do_cast},//出招
	{"info",do_info},//显示在线用户(名字 得分 在线)
	{"find",do_find},//根据名称找用户
	{"logout",do_logout}
	{"",NULL}
};


void logic_processing();
void ftp_reply(session_t *sess,int status,const char *text)
{
    char buf[1024]={'\0'};
	sprintf(buf,"%d %s\r\n",status,text);
     writen(sess->ctrl_fd,buf,strlen(buf));
}


