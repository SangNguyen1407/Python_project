/******************************
 *                            *
 *                            *
 ******************************/
#include <iostream>

#define LOG_SIZE_MAX             500
#define CODE_LOG_NORMAL          1
#define CODE_LOG_ERROR           2
#define CODE_LOG_ERROR_1         3
#define CODE_LOG_WARNING         4

//static int num = 0;

void print_log(int LOG_CODE, ...);