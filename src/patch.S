
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

	//HOOKѡ�˻���Ļ�ͼ����������

.file ".\\src\\patch\\test_patch.S"
.line 4
	XXPATCH16JMP16(0x1002F90C,hook_Init)

	//����HOOK������CreatOBJ����������������Ϸ����ͼ���

.file ".\\src\\patch\\test_patch.S"
.line 11
	XXPATCH16JMP16(0x1003F38A,hook_mainmenu)

	//�����HOOK����Ļˢ�º�������������������Ļ������ʾ����

.file ".\\src\\patch\\test_patch.S"
.line 1
	XXPATCH16JMP16(0x10073A02,patch_sub_10073A02)

	//�������Ϸ�ʼ��HOOK�ˣ���������

.file ".\\src\\patch\\test_patch.S"
.line 7
	XXPATCH16JMP16(0x100813E0,hook_CreatOBJ_100813E0)

.file ".\\src\\patch\\test_patch.S"
.line 8
	XXPATCH16JMP16(0x10081440,hook_CreatOBJ_10081440)

	//�����MAINMENU�ʼ��HOOK�ˣ���������

.file ".\\src\\patch\\test_patch.S"
.line 17
	XXPATCH16JMP16(0x1008219E,hook_DrawSelectPlayer_1008219E)


.file __FILE__
.line __LINE__
XXEXPORT_END(dumpy)
.org ROM_FREE
XXEXPORT_START(ccode)