#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "game_type.h"
#include "rom_func.h"


extern void pgm2log(const char *fmt, ...);


#define CreatOBJ_10081FF0				FUNC16(0x10081FF0)
#define CreatOBJ_10081440				FUNC16(0x10081440)
#define CreatOBJ_100813E0				FUNC16(0x100813E0)

#define GetRegion_10094EFC				FUNC16(0x10094EFC)
#define PalFade_10004E76				FUNC16(0x10004E76)
#define ScreenUpdate_1002F81A			FUNC16(0x1002F81A)
#define GameMode_20020105				V8(0x20020105)

#define dword_10175E8C					V8(0x10175E8C)
#define dword_10175EF4					V8(0x10175EF4)
#define dword_200203EC					V8(0x200203EC)
#define word_2002010A					V8(0x2002010A)
#define byte_200203F4					V8(0x200203F4)
#define byte_200203F5					V8(0x200203F5)
#define dword_200203F0					V8(0x200203F0)
#define dword_200203F8					V8(0x200203F8)
#define off_10175D7C					P32(0x10175D7C)
#define off_10176178					P32(0x10176178)
#define asc_10175D68					P16(0x10175D68)
#define off_10175DA4					P32(0x10175DA4)
#define dword_20061AB4					P32(0x20061AB4)
#define dword_10175D54					P32(0x10175D54)

int hook_DrawSelectPlayer_1008219E()//画选人界面sub_1008219E()
{
  signed int i; // r4@1
  int v1; // r0@2
  signed int j; // r4@11
  int v3; // r0@12
  int v4; // r0@12
  signed int k; // r4@22
  int result; // r0@25
  signed int jj; // r4@54
pgm2log("%s():%d:START\n",__FUNCTION__,__LINE__);
  CreatOBJ_10081FF0(19, 19);                    // 这里设置背景图层的pal=19 画底层和云
  CreatOBJ_10081440(0, 0, 0, 19, 20, 1, 0);     // pal=19,pic=20,layer=1 画SELECT YOUR CHARACTOR英文
 
  for ( i = 0; i < 4; ++i )
  {
    v1 = CreatOBJ_10081440(0, 0, 0, 19, 5 * i + 34, 2, 0); //这个应该是光标的图片
    sub_100190E8(v1, V8(0x10175EF4));
  }

  switch ( (unsigned __int8)GetRegion_10094EFC() )
  {
    case 0u:
    case 1u:
    case 3u:
      if ( GameMode_20020105 == 1 )
        PalFade_10004E76(3, 0, 8);						//这里控制了一个渐变效果
      else 
        PalFade_10004E76(1, 0, 8);
      break;
    default:
        PalFade_10004E76(1, 0, 8);
      break;
  }

      for ( j = 0; j < 10; ++j )
      {
        v3 = sub_10004116(2,P16(0x10175D54)[j] & 0xFF, P32(0x10175D7C)[j]);//色盘
        sub_100043E6(v3);
        v4 = sub_10004116(2,P16(0x10175D68)[j] & 0xFF, P32(0x10175DA4)[j]);//色盘
		sub_100043E6(v4);//上面屏蔽掉了灰色部分

        if ( j % 2 )
        {
//			dword_20061AB4[3*j] = CreatOBJ_100813E0(0, 251+120, -5, asc_10175D68[j], 4, 300,0);
//			sub_1001227E(dword_20061AB4[3*j],off_10176178 [j]);
//			dword_20061AB4[2*j] = CreatOBJ_100813E0(0, 251+60, -5, asc_10175D68[j], 4, 300,0);
//			sub_1001227E(dword_20061AB4[2*j],off_10176178 [j]);
			dword_20061AB4[j] = CreatOBJ_100813E0(0, 251, -5, asc_10175D68[j], 4, 300,0);
			sub_1001227E(dword_20061AB4[j],off_10176178 [j]);
        }
        else
        {
//			dword_20061AB4[3*j] = CreatOBJ_100813E0(0, 193-120, 255, asc_10175D68[j], 4, 300,0);
//          sub_1001227E(dword_20061AB4[3*j],off_10176178[j]);
//          dword_20061AB4[2*j] = CreatOBJ_100813E0(0, 193-60, 255, asc_10175D68[j], 4, 300,0);
//          sub_1001227E(dword_20061AB4[2*j],off_10176178[j]);
		  dword_20061AB4[j] = CreatOBJ_100813E0(0, 193, 255, asc_10175D68[j], 4, 300,0);
          sub_1001227E(dword_20061AB4[j],off_10176178[j]);
        }
      }
      for ( k = 0; k < 30; ++k )
		ScreenUpdate_1002F81A();
      dword_200203F8 = CreatOBJ_10081440(0, 0, 0, 20, 21, 299, 0);
      sub_1009AEEC();

  //pgm2log("%s():%d:START\n",__FUNCTION__,__LINE__);
  for ( jj = 0; jj < 20; ++jj )
    result = ScreenUpdate_1002F81A();
  V8(0x200203E2)=1;
  V8(0x200203E3)=1;
  V8(0x200203E4)=1;
  V8(0x200203E5)=1;
  return result;
}