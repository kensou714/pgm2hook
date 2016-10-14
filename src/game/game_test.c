#include <stdlib.h>
#include <stdio.h>

extern void pgm2log(const char *fmt, ...);

const char *const build_info = "Build By XingXing @[" __DATE__ "][" __TIME__ "]";
#define sub_1000F0B0		(*(void (*)())(0x1000F0B0+1))
#define sub_1000EEB2		(*(int (*)())(0x1000EEB2+1))
#define sub_1002F394		(*(int (*)())(0x1002F394+1))
#define sub_1000F106		(*(int (*)())(0x1000F106+1))
#define sub_100003C0		(*(void (*)())(0x100003C0+1))
#define sub_1002F81A		(*(int (*)())(0x1002F81A+1))
#define printf_1000063C		(*(int (*)())(0x100006C3+1))
void test_function(void)
{
	pgm2log("%s() %d : %s\n", __FUNCTION__, __LINE__, build_info);
}

int patch_sub_10073A02(int role_addr, char role_id)	//根据人物不同赠送初始道具 by 海叔 v.20161009
{
	test_function();
	return 1;

}
