#include <PA_BgStruct.h>

extern const char BG2_bas_arg_Tiles[];
extern const char BG2_bas_arg_Map[];
extern const char BG2_bas_arg_Pal[];

const PA_BgStruct BG2_bas_arg = {
	PA_BgNormal,
	256, 192,

	BG2_bas_arg_Tiles,
	BG2_bas_arg_Map,
	{BG2_bas_arg_Pal},

	9728,
	{1536}
};
