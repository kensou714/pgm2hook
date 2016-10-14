#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern void pgm2log(const char *fmt, ...);
#define update_1002F81A		(*(int (*)())(0x1002F81A+1))
#define GetDipsw_1002F5F4	(*(int (*)())(0x1002F5F4+1))
#define sub_1000F094		(*(void (*)())(0x1000F094+1))
#define printf_1000063C		(*(int (*)())(0x1000063C+1))
#define printf_10000CE0		(*(int (*)())(0x10000CE0+1))
#define check_key_status_100000B2		(*(int (*)())(0x100000B2+1))
//------------- MAIN MENU ------------------------------
#define sub_1000F0B0		(*(void (*)())(0x1000F0B0+1))
#define sub_1000EEB2		(*(int (*)())(0x1000EEB2+1))
#define sub_1002F394		(*(int (*)())(0x1002F394+1))
#define sub_1000F106		(*(int (*)())(0x1000F106+1))
#define sub_100003C0		(*(void (*)())(0x100003C0+1))
#define sub_10038F18		(*(int (*)())(0x10038F18+1))
#define sub_10011B04		(*(void (*)())(0x10011B04+1))
#define sub_1002E5F8		(*(int (*)())(0x1002E5F8+1))
#define sub_100035CA		(*(int (*)())(0x100035CA+1))
#define sub_1004C738		(*(int (*)())(0x1004C738+1))
#define sub_100299C0		(*(int (*)())(0x100299C0+1))
#define sub_10019F3A		(*(int (*)())(0x10019F3A+1))

#define byte_20020170		*( int *)0x20020170
struct Menu{		//0x101309B0	
	int	*String;	//菜单文本地址
	int *Function;	//菜单程序地址
};	
//------------------------------------------------------
//--------------IO TEST---------------------------------
#define sub_1000F11E		(*(void (*)())((0x1000F11E)+1))
#define sub_10030880		(*(int (*)())(0x10030880+1))
#define sub_10039052		(*(int (*)())(0x10039052+1))
#define sub_1002F288		(*(int (*)())(0x1002F288+1))
#define sub_1003908A		(*(int (*)())(0x1003908A+1))

#define dword_1013066C		*( char *)0x1013066C
//------------------------------------------------------


int hook_io_test()
{
	//v1 = 21930;
	int v15[104];
	int i;
	int j;
	int dipsw;
	int lastdipsw;
	int v22;
	int v9;
	pgm2log("%s()",__FUNCTION__);
	sub_1000F094();
	sub_1000F11E();
	update_1002F81A(0,0,0,0);
	sub_10030880();//byte_2002012C=0
	for(i=0;i<53;i=(i+1)&0xFF)
	{
		v15[2*i]=1;
	}
	sub_10039052();//图形RAM
	printf_1000063C((int *)19, 0, 4, 1, "I/O TEST");// x,y,color,bold
	printf_1000063C((int *)4, 2, 4, 1, "1P&2P");
	printf_1000063C((int *)27, 2, 4, 1, "3P&4P");
	printf_1000063C((int *)44, 2, 4, 0, " DIPSW");
	printf_1000063C((int *)44, 3, 4, 0, "12345678");
	printf_1000063C((int *)15, 27, 4, 0, "EXIT:PRESS A+B BUTTON");
	printf_1000063C((int *)12, 7, 4, 1, "1P");
	printf_1000063C((int *)39, 7, 4, 1, "2P");
	printf_1000063C((int *)12, 17, 4, 1, "3P");
	printf_1000063C((int *)39, 17, 4, 1, "4P");
	sub_100003C0();

	lastdipsw=0;
	v9=0;
	while (1)
	{
		dipsw=GetDipsw_1002F5F4();//0x200200F8 DIPSW

		if(dipsw != lastdipsw)
		{
			v22=0;
			for(i=0;i<8;i=(i+1)&0xFF)
				v22 = ((((dipsw >> i) & 1) << (7 - i)) | v22) & 0xFFFF;
			printf_10000CE0(44,4,2,0,(int)"%08b",v22);
			lastdipsw=dipsw;
		}
		for (j=0;j<4 ;j=(j+1)&0xFF )
		{
			v9 = dword_1013066C + 10 * j;
			for (i=0;i<10 ;i=(i+1)&0xFF )
			{
				if (check_key_status_100000B2(v9))
				{
					if (!v15[2*v9])
					{
						sub_1002F288(2,250);
						v15[2*v9]=1;
						sub_1003908A(0,6,j,i,0);
					}
				}
				else
				{
					v15[2*v9]=0;
					sub_1003908A(0,6,j,i,2);
				}
				++v9;
			}
		}

	}



	return 1;
}





void hook_mainmenu() //完全还原MAINMENU的主函数 by 海叔 2016-10-12
{
	struct Menu MainMenu[21];
	int i;

	MainMenu[0].String = (int *)"IO";
	MainMenu[0].Function =(int *)(hook_io_test+1);
	MainMenu[1].String = (int *)"COUNTER";
	MainMenu[1].Function =(int *) 0x10039491;
	MainMenu[2].String = (int *)"AUDIO";
	MainMenu[2].Function =(int *) 0x10039541;
	MainMenu[3].String = (int *)"SOBJECT";
	MainMenu[3].Function =(int *) 0x10039CF7;
	MainMenu[4].String = (int *)"SIGNATURE";
	MainMenu[4].Function =(int *) 0x10039DD1;
	MainMenu[5].String = (int *)"RANKING";
	MainMenu[5].Function =(int *) 0x10039E2F;
	MainMenu[6].String = (int *)"DIALOG";
	MainMenu[6].Function =(int *) 0x1003C381;
	MainMenu[7].String = (int *)"DIALOGSPEC";
	MainMenu[7].Function =(int *) 0x1003C5F9;
	MainMenu[8].String = (int *)"SYSOBJ";
	MainMenu[8].Function =(int *) 0x10039E7D;
	MainMenu[9].String = (int *)"FOOD";
	MainMenu[9].Function =(int *) 0x1003A107;
	MainMenu[10].String = (int *)"WEAPON";
	MainMenu[10].Function =(int *) 0x1003A2B1;
	MainMenu[11].String = (int *)"ROLE";
	MainMenu[11].Function =(int *) 0x1003A7E7;
	MainMenu[12].String = (int *)"RORO";
	MainMenu[12].Function =(int *) 0x1003B133;
	MainMenu[13].String = (int *)"CHANGEMEN";
	MainMenu[13].Function =(int *) 0x1003BB89;
	MainMenu[14].String = (int *)"PASSSTORY";
	MainMenu[14].Function =(int *) 0x1003C865;
	MainMenu[15].String = (int *)"OVERSTORY";
	MainMenu[15].Function =(int *) 0x1003CA65;
	MainMenu[16].String = (int *)"COMMANDPORT";
	MainMenu[16].Function =(int *) 0x1003CBD1;
	MainMenu[17].String = (int *)"SHARERAM";
	MainMenu[17].Function =(int *) 0x1003CD93;
	MainMenu[18].String = (int *)"CARD DATA";
	MainMenu[18].Function =(int *) 0x1003E0F5;
	MainMenu[19].String = (int *)"TEST BACKFONT";
	MainMenu[19].Function =(int *) 0x10038FBF;
	MainMenu[20].String = (int *)"EXIT";
	MainMenu[20].Function = (int *)0x1003A38B;	

	pgm2log("%s()\n",__FUNCTION__);
//	pgm2log("S:0x%02X F:0x%02X",MainMenu[0].String,MainMenu[0].Function);
	sub_1000F0B0();	//这里将图形RAM清空
	sub_1000EEB2(1,0,0);//一个开关，
	while (1) //进入主循环
	{
		sub_1002F394();//这个函数跟声音有关
		sub_1000F106();//这个跟图形RAM有关
		sub_1000EEB2(0,0,0);//一个开关，
		sub_100003C0();//这里跟色盘有关，应该是导入色盘
		printf_1000063C(10, 0, 4, 3, "---MAIN MENU---");//显示文本
		for (i =0; i<21 ; i=(i+1)&0xFF) //这个循环用来载入菜单列表，共21个选项
			printf_1000063C(14, i + 3, 0, 0,(int *) MainMenu[i].String);//0x101309B0是菜单列表的字符串数组
		byte_20020170 = sub_10038F18(14, 3, (int)MainMenu, 21,byte_20020170);//这个函数是用来计算光标位置的
		if (byte_20020170 == 20)
			break;
		sub_1000F094();//这里也是跟图形RAM有关
		sub_1002E5F8();//NVRAM
		sub_10011B04();//这个跟选择光标有关
		sub_100035CA();//返回一个指针地址
		sub_1004C738();//这里操作了一下内存
		sub_100299C0();//这里也操作了内存
		sub_10019F3A();//功能与100299C0差不多
		sub_100003C0();//调整色盘
		printf_10000CE0( 14,0,0,3,(int)"-%s-",(int *)MainMenu[byte_20020170].String);//把当前光标的文本变成黄色
		((void (*)(void))MainMenu[byte_20020170].Function)();
		sub_1002E5F8();//nvram
		sub_10011B04();//这个跟选择光标有关
		sub_100035CA();//返回了一个指针地址
		sub_1004C738();//这里操作了一下内存
		sub_100299C0();//这里也操作了内存
		sub_10019F3A();//跟上面一样
		update_1002F81A(0,0,0,0);//更新屏幕
	}
}