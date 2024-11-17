#include "Init.h"

void Init(void)
{
	Init_Sysclk();
}

void Init_Sysclk(void)
{
	  Enable_Sysclk_Input(HSE);
	  Wait_Sysclk_Ready(HSE);
	  Set_Sysclk_Input(HSE);
}
