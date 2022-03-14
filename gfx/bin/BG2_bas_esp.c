#include <PA_BgStruct.h>

extern const char BG2_bas_esp_Tiles[];
extern const char BG2_bas_esp_Map[];
extern const char BG2_bas_esp_Pal[];

const PA_BgStruct BG2_bas_esp = {
	PA_BgNormal,
	256, 192,

	BG2_bas_esp_Tiles,
	BG2_bas_esp_Map,
	{BG2_bas_esp_Pal},

	9216,
	{1536}
};
