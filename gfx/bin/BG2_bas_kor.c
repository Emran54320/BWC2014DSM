#include <PA_BgStruct.h>

extern const char BG2_bas_kor_Tiles[];
extern const char BG2_bas_kor_Map[];
extern const char BG2_bas_kor_Pal[];

const PA_BgStruct BG2_bas_kor = {
	PA_BgNormal,
	256, 192,

	BG2_bas_kor_Tiles,
	BG2_bas_kor_Map,
	{BG2_bas_kor_Pal},

	8832,
	{1536}
};
