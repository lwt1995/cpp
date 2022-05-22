#pragma once

//����Ա�ļ�
#define ADMIN_FILE  "admin.txt"
//ѧ���ļ�
#define STUDENT_FILE  "student.txt"
//��ʦ�ļ�
#define TEACHER_FILE  "teacher.txt"
//������Ϣ�ļ�
#define COMPUTER_FILE  "computerRoom.txt"
//�����ļ�
#define ORDER_FILE  "order.txt"

 #ifdef _WIN32
 #define READ "pause"
 #define PAUSE "cls" 
 #endif

 #ifdef linux
 #define READ "read"
 #define PAUSE "clear"
 #endif

 #ifdef _UNIX
 #define READ "read"
 #define PAUSE "clear"
 #endif

const char* p_read = READ;

const char* c_clear = PAUSE;
