
#include "xxpacth_include.h"
.text
XXEXPORT_START(dumpy)

.file ".\\src\\patch\\retarget.S"
.line 1
	XXPATCH32(0x10000000)
	.extern _system_init
	//STMFD           SP!, {R4,LR}
	//BLX             sub_1002F90C
	//LDMFD           SP!, {R4,PC}
	ldr pc, =_system_init+1
	.ltorg



.file ".\\src\\patch\\test_patch.S"
.line 14
	XXPATCH16JMP16(0x1002F81A,hook_screen_update)

	//HOOK选人画面的绘图，用来测试

.file ".\\src\\patch\\test_patch.S"
.line 4
	XXPATCH16JMP16(0x1002F90C,hook_Init)

	//这里HOOK了两个CreatOBJ函数，都是用于游戏创建图像的

.file ".\\src\\patch\\test_patch.S"
.line 11
	XXPATCH16JMP16(0x1003F38A,hook_mainmenu)

	//这个是HOOK了屏幕刷新函数，在里面增加了屏幕文字显示测试

.file ".\\src\\patch\\test_patch.S"
.line 1
	XXPATCH16JMP16(0x10073A02,patch_sub_10073A02)

	//这里把游戏最开始给HOOK了，用来测试

.file ".\\src\\patch\\test_patch.S"
.line 7
	XXPATCH16JMP16(0x100813E0,hook_CreatOBJ_100813E0)

.file ".\\src\\patch\\test_patch.S"
.line 8
	XXPATCH16JMP16(0x10081440,hook_CreatOBJ_10081440)

	//这里把MAINMENU最开始给HOOK了，用来测试

.file ".\\src\\patch\\test_patch.S"
.line 17
	XXPATCH16JMP16(0x1008219E,hook_DrawSelectPlayer_1008219E)


.file __FILE__
.line __LINE__
XXEXPORT_END(dumpy)
.org ROM_FREE
XXEXPORT_START(ccode)
