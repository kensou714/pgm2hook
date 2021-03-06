#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "game_type.h"

#define ClearRAM_1002F722				FUNC16(0x1002F722)//全局初始化内存
#define	GetDipsw_1002F5F4				FUNC16(0x1002F5F4)//Get v200200F8<<24
#define ChkKeySt_100000B2				FUNC16(0x100000B2)//检查按键状态
#define Warnning_100374B0				FUNC16(0x100374B0)//WARNNING界面

//--Game Init -----
#define	sub_1002FA82					FUNC16(0x1002FA82)//这里判断了版本号
#define	sub_10099596					FUNC16(0x10099596)//清空一些内存

#define	sub_100003C0					FUNC16(0x100003C0)//ubBank操作
#define	sub_10034920					FUNC16(0x10034920)
#define	sub_1000F094					FUNC16(0x1000F094)//图形RAM操作
#define	sub_10041F56					FUNC16(0x10041F56)//片头
#define	sub_1003F38A					FUNC16(0x1003F38A)//DEBUG MODE
#define	sub_10042C6C					FUNC16(0x10042C6C)//标题画面
#define	sub_10035112					FUNC16(0x10035112)//TEST MODE
#define	sub_10037340					FUNC16(0x10037340)//QC TEST
//------------------
//--Main Title-----
#define SetAudio_1002F36C					FUNC16(0x1002F36C)
#define SetAudio_1002F26C					FUNC16(0x1002F26C)
#define sub_1002F65C						FUNC16(0x1002F65C)
#define sub_100300AC						FUNC16(0x100300AC)
#define sub_100300B4						FUNC16(0x100300B4)
#define sub_10030698						FUNC16(0x10030698)
#define sub_10031D66						FUNC16(0x10031D66)
#define CreatMainTitle_10042B48				FUNC16(0x10042B48)
#define sub_10030684						FUNC16(0x10030684)
#define sub_1004C738						FUNC16(0x1004C738)
#define sub_1004D9EA						FUNC16(0x1004D9EA)
#define sub_10057A8C						FUNC16(0x10057A8C)
#define sub_1005923C						FUNC16(0x1005923C)
#define sub_1005BF64						FUNC16(0x1005BF64)
#define sub_10064E3A						FUNC16(0x10064E3A)
#define sub_10065846						FUNC16(0x10065846)
#define CreatGameWorld_1008C63C				FUNC16(0x1008C63C)
#define sub_10126438						FUNC16(0x10126438)
//------------------
//--Creat GameWorld-----
#define sub_1000F2B4						FUNC16(0x1000F2B4)
#define sub_1008AEDE						FUNC16(0x1008AEDE)//选择模式界面
#define sub_10086780						FUNC16(0x10086780)//选人界面
#define sub_1007B9B8						FUNC16(0x1007B9B8)
//------------------
//--Creat GameWorld-----
#define sub_10015CA0						FUNC16(0x10015CA0)
#define sub_10011B04						FUNC16(0x10011B04)
#define sub_1002E5F8						FUNC16(0x1002E5F8)
#define sub_10004B62						FUNC16(0x10004B62)
#define sub_10042ABC						FUNC16(0x10042ABC)
#define sub_1000F182						FUNC16(0x1000F182)
#define sub_1002FE9C						FUNC16(0x1002FE9C)
#define sub_1000EEB2						FUNC16(0x1000EEB2)
#define sub_100300BC						FUNC16(0x100300BC)
#define sub_100004EE						FUNC16(0x100004EE)
#define sub_10004116						FUNC16(0x10004116)
#define sub_10081E32						FUNC16(0x10081E32)
#define sub_100827F4						FUNC16(0x100827F4)
#define sub_100035CA						FUNC16(0x100035CA)
#define sub_10003FA4						FUNC16(0x10003FA4)
#define sub_1008219E						FUNC16(0x1008219E)
#define sub_10094EFC						FUNC16(0x10094EFC)
#define sub_1001227E						FUNC16(0x1001227E)
#define sub_100813E0						FUNC16(0x100813E0)
#define sub_10086766						FUNC16(0x10086766)
#define sub_1009AEEC						FUNC16(0x1009AEEC)
#define sub_10081C08						FUNC16(0x10081C08)
#define sub_10081C70						FUNC16(0x10081C70)
#define sub_100814E6						FUNC16(0x100814E6)
#define sub_10011BC2						FUNC16(0x10011BC2)
#define sub_10015D4A						FUNC16(0x10015D4A)

#define sub_10126378						FUNC32(0x10126378)
#define	sub_101263D8						FUNC32(0x101263D8)//JMPOUT(0x3128)
#define	sub_101263C0						FUNC32(0x101263C0)//JMPOUT(0x30B8)

//------------------
#define	v2001058						V8(0x2001058)//
#define	v20020484						V8(0x20020484)//Region
#define	vMainFsm						V8(0x20020104)//主状态机
#define	v20020105						V8(0x20020105)//
#define	v20020106						V8(0x20020105)//
#define	v20020107						V8(0x20020107)//
#define	v2002010A						V8(0x2002010A)//
#define	v2002045A						V8(0x2002045A)//
#define	v200203FC						V8(0x200203FC)//

#define	p20020398						P32(0x20020398)//
#define	p200203E2						P32(0x200203E2)//这个有关是否能选唐僧
#define	p200203C6						P32(0x200203C6)//
#define	p2002039C						P32(0x2002039C)//
#define	p20061C6C						P32(0x20061C6C)//
#define	p20061DFC						P32(0x20061DFC)//
#define	p20061ADC						P32(0x20061ADC)//
#define	p20061AB4						P32(0x20061AB4)//

#define	p1012D980						P32(0x1012D980)//
#define	p10433B68						P32(0x10433B68)//
#define	p10433768						P32(0x10433768)//
#define	p10433868						P32(0x10433868)//
#define	p10433968						P32(0x10433968)//
#define	p10433F68						P32(0x10433F68)//
#define	p10433C68						P32(0x10433C68)//
#define	p10433E68						P32(0x10433E68)//
#define	p10434068						P32(0x10434068)//
#define	p10434168						P32(0x10434168)//
#define	p10431A68						P32(0x10431A68)//
#define	p1042F668						P32(0x1042F668)//
#define	p1042F768						P32(0x1042F768)//
#define	p10430768						P32(0x10430768)//
#define	p10430968						P32(0x10430968)//
#define	p10430A68						P32(0x10430A68)//
#define	p10430B68						P32(0x10430B68)//
#define	p10430C68						P32(0x10430C68)//
#define	p10395AB4						P32(0x10395AB4)//
#define	p10395BB4						P32(0x10395BB4)//
#define	p10395CB4						P32(0x10395CB4)//
#define	p10395DB4						P32(0x10395DB4)//
#define	p10395EB4						P32(0x10395EB4)//
#define	p10175F54						P32(0x10175F54)//
extern void pgm2log(const char *fmt, ...);






int hook_CreatOBJ_100813E0(int a1, int x, int y, __int16 pal, __int16 picnum, __int16 layer, __int16 a7)//sub_100813E0()
{
  int v8; // r0@1 MAPDST
//  a1 = 0;
//  a2 = 160;//x
//  a3 = 165;//y
//  a4 = 23;//色盘
//  a5 = 58;//第几张图
//  a6 = 15;//第几层显示
//  a7 = 0;
	if (a1 || a7)
		pgm2log("%s() %d : a1:%d,x:%d,y:%d,pal:%d,picnum:%d,layer:%d,a7:%d\n", __FUNCTION__, __LINE__,a1,x,y,pal,picnum,layer,a7);
	
   v8 = sub_10011BC2(0x10175F54 + 84 * a1, x, y, 0, a7);
	
  *(_WORD *)(v8 + 80) = pal;//色盘编号
  *(_WORD *)(v8 + 142) = pal;//
  *(_WORD *)(v8 + 58) = picnum;//图片编号
  *(_WORD *)(v8 + 210) = 1;//是否显示
  *(_WORD *)(v8 + 208) = layer;//第几层
  sub_10126378(*(_DWORD *)(v8 + 76), *(signed __int16 *)(v8 + 208));
  *(_WORD *)(v8 + 104) = 0;
  return v8;
}

int hook_CreatOBJ_10081440(int a1, int x, int y, __int16 pal, __int16 picnum, __int16 layer, __int16 a7)//sub_10081440()
{
  int v8; // r0@1 MAPDST
//  a1 = 0;
//  a2 = 160;//x
//  a3 = 165;//y
//  a4 = 23;//色盘
//  a5 = 58;//第几张图
//  a6 = 15;//第几层显示
//  a7 = 0;
	if (a1 || a7)
		pgm2log("%s() %d : a1:%d,x:%d,y:%d,pal:%d,picnum:%d,layer:%d,a7:%d\n", __FUNCTION__, __LINE__,a1,x,y,pal,picnum,layer,a7);
	
   v8 = sub_10015D4A(0x10175F54 + 84 * a1, x, y, 0, a7);
	
  *(_WORD *)(v8 + 80) = pal;//色盘编号
  *(_WORD *)(v8 + 142) = pal;//
  *(_WORD *)(v8 + 58) = picnum;//图片编号
  *(_WORD *)(v8 + 210) = 1;//是否显示
  *(_WORD *)(v8 + 208) = layer;//第几层
  sub_10126378(*(_DWORD *)(v8 + 76), *(signed __int16 *)(v8 + 208));
  *(_WORD *)(v8 + 104) = 0;
  return v8;
}
























int hook_CreatGameWorld(int bPlayerNo)//创建选模式和选人界面sub_1008C63C()
{
	int i;
	pgm2log("%s()\n",__FUNCTION__);
	sub_1000F2B4();//初始化一些内存
	v20020105 = 0;
	for (i=0;i<4 ;++i )
	{
		p20020398[i]=0;
	}
	sub_1008AEDE(bPlayerNo);//这里创建了选择模式界面并返回模式
	sub_10086780(bPlayerNo);//这里创建选人界面并返回所选角色
//	hook_SelectPlayer(bPlayerNo);
	sub_1007B9B8();
	return SetAudio_1002F36C();
}






int hook_Main_Title()		//sub_10042C6C标题画面
{
	int bPlayerNo; // r4@1
	pgm2log("%s()\n",__FUNCTION__);
	SetAudio_1002F36C();//音频初始化
	SetAudio_1002F26C();//音频初始化
	sub_100300AC();//v20020134=0;
	bPlayerNo = CreatMainTitle_10042B48();//这里创建标题画面并返回PLAYERNO
	sub_10030684();//v2002012E=1;
	sub_1004C738();//这里初始化一些内存，并载入PtrRole到内存
	sub_1005923C();//v20020284=v20020280=v20020288=0
	v20020105 = 0;
//	CreatGameWorld_1008C63C(bPlayerNo);//这里创建选模式和选人的界面
	hook_CreatGameWorld(bPlayerNo);
	if ( sub_1002F65C() )
		sub_10030698();
	v20020106 = 0;
	sub_10031D66();
	v2002045A = 0;
	sub_100300B4();
	
	while ( v20020106 != 3 )
	{
		if ( v20020106 )
		{
			if ( v20020106 == 1 )
			{
				sub_10064E3A();
				v20020106 = 2;
			}
			else if ( v20020106 == 2 )
			{
				sub_10065846();
				sub_10057A8C();
				if ( sub_1005BF64() )
				{
					vMainFsm = 0;
				}
				else
				{
					vMainFsm = 2;
				}
				sub_10126438(vMainFsm);
			}
		}
		else
		{
			sub_1004D9EA();
		}
	}
	return SetAudio_1002F36C();
}





void hook_Init(int a1,int a2,int a3,int a4)//sub_1002F9C0
{

	int v5;
	int v6;
	pgm2log("%s\n",__FUNCTION__);
	 
	v5 = 0;
	v6 = 1;
	
	ClearRAM_1002F722(a1,a2,a3,a4);
	sub_1002FA82();
	
	sub_10099596();

	sub_101263D8();//   这里JMPOUT 跟BIOS有关

	if(v5)
	{
		sub_100003C0();
		sub_10034920();
		sub_1000F094();
	}

	if(GetDipsw_1002F5F4() & 1)	
		vMainFsm = 3;

	if (vMainFsm != 3)
	{

		sub_101263C0(vMainFsm); //这里JMPOUT 跟BIOS有关
		
		if (v6)
		{
			if(GetDipsw_1002F5F4() & 0x80)
			{
				if (ChkKeySt_100000B2(41) || ChkKeySt_100000B2(5) || !ChkKeySt_100000B2(6) || !ChkKeySt_100000B2(7) || ChkKeySt_100000B2(8))
				{
					if ( ChkKeySt_100000B2(41) || !ChkKeySt_100000B2(5) || !ChkKeySt_100000B2(6) || ChkKeySt_100000B2(7) || ChkKeySt_100000B2(8) )
					{
						Warnning_100374B0();
					}
					else
					{
						vMainFsm = 4;
					}
				}
				else
				{
					v20020107 = 1;
				}
			}
			else
			{
				Warnning_100374B0();
			}
		}
	}
	
	while (1)
	{
		switch (vMainFsm)
		{
			case 1:
				continue;
			case 2:
				sub_10041F56();
				break;
			case 0:
//				sub_1003F38A();//这里取消屏蔽可以进DEBUG
				sub_10042C6C();//原版标题画面
//				hook_Main_Title();
				break;
			case 3:
				sub_10035112();
				break;
			case 4:
				sub_10037340();
				return;
			default:
				vMainFsm = 2;
				break;
		
		}
	}
}