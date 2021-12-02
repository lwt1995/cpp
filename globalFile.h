#pragma once

//管理员文件
#define ADMIN_FILE  "admin.txt"
//学生文件
#define STUDENT_FILE  "student.txt"
//教师文件
#define TEACHER_FILE  "teacher.txt"
//机房信息文件
#define COMPUTER_FILE  "computerRoom.txt"
//订单文件
#define ORDER_FILE  "order.txt"

#define LINUX_R "read"
#define LINUX_C "clear"
#define WINDOW_P "pause"
#define WINDOW_C "cls"

//返回当前系统
static int returnSystem() {

	int no_os_flag = 1;
#ifdef linux

	no_os_flag = 0;

#endif

#ifdef _UNIX

	no_os_flag = 0;


#endif

#ifdef __WINDOWS_

	no_os_flag = 1;


#endif

#ifdef _WIN32

	no_os_flag = 1;


#endif

	return no_os_flag;
}

static const char* p_read = returnSystem() == 0 ? LINUX_R : WINDOW_P;

static const char* c_clear = returnSystem() == 0 ? LINUX_C : WINDOW_C;
