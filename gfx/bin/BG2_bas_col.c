#include <PA_BgStruct.h>

extern const char BG2_bas_col_Tiles[];
extern const char BG2_bas_col_Map[];
extern const char BG2_bas_col_Pal[];

const PA_BgStruct BG2_bas_col = {
	PA_BgNormal,
	256, 192,

	BG2_bas_col_Tiles,
	BG2_bas_col_Map,
	{BG2_bas_col_Pal},

	9216,
	{1536}
};
