	//这里是HOOK了赠送游戏初始道具的地方
	XXPATCH16JMP16(0x10073A02,patch_sub_10073A02)

	//这里把游戏最开始给HOOK了，用来测试
	XXPATCH16JMP16(0x1002F90C,hook_Init)

	//这里HOOK了两个CreatOBJ函数，都是用于游戏创建图像的
	XXPATCH16JMP16(0x100813E0,hook_CreatOBJ_100813E0)
	XXPATCH16JMP16(0x10081440,hook_CreatOBJ_10081440)

	//这里把MAINMENU最开始给HOOK了，用来测试
	XXPATCH16JMP16(0x1003F38A,hook_mainmenu)

	//这个是HOOK了屏幕刷新函数，在里面增加了屏幕文字显示测试
	XXPATCH16JMP16(0x1002F81A,hook_screen_update)

	//HOOK选人画面的绘图，用来测试
	XXPATCH16JMP16(0x1008219E,hook_DrawSelectPlayer_1008219E)

