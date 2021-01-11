#include <iostream>
#include <string.h>
#include <stdarg.h>
#include <time.h>
#include "../inc/printLog.h"
#include "../inc/fileHandler.h"
 
using namespace std;

void print_log(int LOG_CODE, ...)
{
	char log_1[LOG_SIZE_MAX];
	char log_2[LOG_SIZE_MAX];
	
	time_t timer;
	time(&timer);
	
	/*現在時刻を表示*/
	char *timer_log = ctime(&timer);
	strcpy (log_1, timer_log);
	strcpy (log_1+strlen(timer_log) - 1, " ");
	
	/*エラーを出る*/
	va_list numbers;
	va_start(numbers, LOG_CODE);
	
	if (LOG_CODE == CODE_LOG_NORMAL)
	{
		strcpy(log_1 + strlen(timer_log), va_arg(numbers, char *));
	}
	else if (LOG_CODE == CODE_LOG_ERROR)
	{
		strcpy(log_1 + strlen(timer_log), va_arg(numbers, char *));
		strcpy(log_2, va_arg(numbers, char *));
	}
	
	writeTextFile(".//log//log.txt", "a+", log_1);
	
}