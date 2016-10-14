#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "game_type.h"
extern void pgm2log(const char *fmt, ...);

//--------------game_mode----------------------------
#define sub_100293E0		FUNC16(0x100293E0)
#define sub_10020170		FUNC16(0x10020170)
#define sub_10015760		FUNC16(0x10015760)
#define sub_1001852A		FUNC16(0x1001852A)
#define sub_10011956		FUNC16(0x10011956)
#define sub_100337F4		FUNC16(0x100337F4)
#define sub_1002B3FE		FUNC16(0x1002B3FE)
#define sub_1001FF46		FUNC16(0x1001FF46)
#define sub_1001561C		FUNC16(0x1001561C)
#define sub_10018EC0		FUNC16(0x10018EC0)
#define sub_10003EC8		FUNC16(0x10003EC8)
#define sub_1002F138		FUNC16(0x1002F138)
#define sub_10031F20		FUNC16(0x10031F20)
#define sub_10032A24		FUNC16(0x10032A24)
#define sub_1002E714		FUNC16(0x1002E714)
#define sub_10078BEA		FUNC16(0x10078BEA)
#define sub_1006482E		FUNC16(0x1006482E)
#define sub_1002F674		FUNC16(0x1002F674)
#define sub_1002F6A0		FUNC16(0x1002F6A0)
#define Main_Fsm			V8(0x20020104)
#define V_20020105			V8(0x20020105)
#define V_20020106			V8(0x20020106)
#define V_200203C4			V8(0x200203C4)
#define P32_20020110		P32(0x20020110)
#define P64_20020110		P64(0x20020110)
#define P32_2002010C		P32(0x2002010C)
#define printf_10000CE0		(*(int (*)())(0x10000CE0+1))
#define P32_200200FC		*( int *)0x200200FC
#define exp					*( int *)0x2005F768

int lastexp;
int MemInfo[1];
int MemInfo[]={0x0};
int hook_screen_update(int a1,int a2,int a3,int a4)
{
	int i;
	int v4;
	int v5;
	int v9;
	v4=Main_Fsm;
	if(Main_Fsm!=1)
	{
		sub_100293E0();
		v4=sub_10020170();
	}
	v5 = sub_10015760(v4,a2,a3,a4);
	sub_1001852A(v5,0,0,0);
	sub_10011956();
	sub_100337F4();
	sub_1002B3FE();
	sub_1001FF46();
	sub_1001561C();
	sub_10018EC0();
//	if(P32_20020100)
//		P64_20020110();
	sub_10003EC8();
	sub_1002F138();
	sub_10031F20();
  if ( Main_Fsm == 2 )
    sub_10032A24();
  v9 = sub_1002E714();
  sub_10078BEA(v9);
  sub_1006482E();
  if ( Main_Fsm != 3 )
  {
    while ( sub_1002F674() )
      ;
  }
//  if ( P32_2002010C )
  {
    while ( !sub_1002F6A0() )
      ;
  }
//  if(exp!=lastexp || exp==0)
//	{
	  printf_10000CE0(5,5,0,0,(int)"EXP:%d",exp);
//	  lastexp = exp;
	 // pgm2log("EXP:%d",exp);
//	}
  //-------------debugÄÚ´æ------------
//		printf_10000CE0(5,6,1,0,(int)"MainFsm:%d",Main_Fsm);
	//	printf_10000CE0(5,7,0,0,(int)"v200203C4:%d",V_200203C4);
//		printf_10000CE0(5,8,0,0,(int)"v20020106:%d",V_20020106);

  //----------------------------------
	for (i=0;i<sizeof(MemInfo)/sizeof(int) ;i++ )
	{
		printf_10000CE0(5,7+i,0,0,(int)"%02X:%d",MemInfo[i],V8( MemInfo[i]));
	}


  ++P32_200200FC;
  return 1;



}