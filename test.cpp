//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdarg.h>
//#include <time.h>
//#include <sys/timeb.h>
//
//
//
//#define NONE        "\e[0m"
//#define BLACK       "\e[0;30m"
//#define L_BLACK     "\e[1;30m"
//#define RED         "\e[0;31m"
//#define L_RED       "\e[1;31m"
//#define GREEN       "\e[0;32m"
//#define L_GREEN     "\e[1;32m"
//#define BROWN       "\e[0;33m"
//#define YELLOW      "\e[1;33m"
//#define BLUE        "\e[0;34m"
//#define L_BLUE      "\e[1;34m"
//#define PURPLE      "\e[0;35m"
//#define L_PURPLE    "\e[1;35m"
//#define CYAN        "\e[0;36m"
//#define L_CYAN      "\e[1;36m"
//#define GRAY        "\e[0;37m"
//#define WHITE       "\e[1;37m"
//#define BOLD        "\e[1m"
//#define UNDERLINE   "\e[4m"
//#define BLINK       "\e[5m"
//#define REVERSE     "\e[7m"
//#define HIDE        "\e[8m"
//#define CLEAR       "\e[2J"
//#define CLRLINE     "\r\e[K" //or "\e[1K\r"
//
//#define log_info(format, ...)                                                                            \
//    do                                                                                                      \
//    {                                                                                                       \
//        log_time(L_CYAN);                                                                                   \
//        printf(L_CYAN "[WARN][%s][%s][%d]" format "\r\n", __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__); \
//        printf(NONE);                                                                                       \
//    } while (0)
//
//#define log_error(format, ...)                                                                            \
//    do                                                                                                      \
//    {                                                                                                       \
//        log_time(L_RED);                                                                                   \
//        printf(L_RED "[WARN][%s][%s][%d]" format "\r\n", __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__); \
//        printf(NONE);                                                                                       \
//    } while (0)
//
//#define log_warning(format, ...)                                                                            \
//    do                                                                                                      \
//    {                                                                                                       \
//        log_time(YELLOW);                                                                                    \
//        printf(YELLOW "[WARN][%s][%s][%d]" format "\r\n", __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__); \
//        printf(NONE);                                                                                       \
//    } while (0)
//
//#define log_bug(format, ...)                                                                                \
//    do                                                                                                      \
//    {                                                                                                       \
//        log_time(L_BLUE);                                                                                   \
//        printf(L_BLUE "[WARN][%s][%s][%d]" format "\r\n", __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__); \
//        printf(NONE);                                                                                       \
//    } while (0)
//
//#define log_time(color)                                                                                                                                      \
//    do                                                                                                                                                      \
//    {                                                                                                                                                       \
//        struct tm *t;                                                                                                                                       \
//        struct timeb stTimeb;                                                                                                                               \
//        ftime(&stTimeb);                                                                                                                                    \
//        t = localtime(&stTimeb.time);                                                                                                                       \
//        printf(color "[%4d%02d%02d-%02d:%02d:%02d:%03d]", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec, stTimeb.millitm); \
//        fflush(stdout);                                                                                                                                     \
//        printf("\033[0m");                                                                                                                                  \
//    } while (0)
//
//int main()
//{
//    log_info("This is INFOMATION!");
//    log_error("This is ERROR!");
//    log_warning("This is WARNNING!");
//    log_bug("This is BUG!");
//    return 0;
//}


//#include <iostream>
//#include "windows.h"
//using namespace std;
//
//int main()
//{
//    cout << "原色testCOLOR（没有设置字体颜色）" << endl;
//    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
//    cout << "白色testCOLOR（红色绿色蓝色相加）" << endl;
//    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);//设置红色
//    cout << "红色testCOLOR（设置的颜色为红色）" << endl;
//    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);//设置绿色
//    cout << "绿色testCOLOR（设置的颜色为绿色）" << endl;
//    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);//设置蓝色
//    cout << "蓝色testCOLOR（设置的颜色为蓝色）" << endl;
//    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);//设置红色和绿色相加
//    cout << "黄色testCOLOR（红色和绿色相加色）" << endl;
//    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);//设置红色和蓝色相加
//    cout << "粉色testCOLOR（红色和蓝色相加色）" << endl;
//    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);//设置绿色和蓝色相加
//    cout << "青色testCOLOR（绿色和蓝色相加色）" << endl;
//    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);//设置颜色，没有添加颜色，故为原色
//    cout << endl;
//
//    system("pause");
//    return 0;
//}


