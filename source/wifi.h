bool downloadfile(const char *url,char *Name)
{
	int err;
	sBuffer buffer;

	ky_InitBuffer(&buffer);
	err = ky_GetUrl(url, &buffer);
	
	if (err >= 0 && buffer.length > 0) {
		FILE* file = fopen (FILEGAME, "wb");
		if (file) {
			fwrite(buffer.buffer, sizeof(bchar), buffer.length, file);
			fclose(file);
			ky_FreeBuffer(&buffer);
			fadein();
			if (langue == 1) PA_LoadGif(0, (void*)BG3_bas_reussi_eng);
			else if (langue == 2) PA_LoadGif(0, (void*)BG3_bas_reussi_fra);
			else if (langue == 3) PA_LoadGif(0, (void*)BG3_bas_reussi_ger);
			else if (langue == 4) PA_LoadGif(0, (void*)BG3_bas_reussi_ita);
			else if (langue == 5) PA_LoadGif(0, (void*)BG3_bas_reussi_esp);
			else PA_LoadGif(0, (void*)BG3_bas_reussi_eng);
			fadeout();
			return true;
		}
	}
	else
	{
		fadein();
		if (langue == 1) PA_LoadGif(0, (void*)BG3_bas_echec_eng);
		else if (langue == 2) PA_LoadGif(0, (void*)BG3_bas_echec_fra);
		else if (langue == 3) PA_LoadGif(0, (void*)BG3_bas_echec_ger);
		else if (langue == 4) PA_LoadGif(0, (void*)BG3_bas_echec_ita);
		else if (langue == 5) PA_LoadGif(0, (void*)BG3_bas_echec_esp);
		else PA_LoadGif(0, (void*)BG3_bas_echec_eng);
		fadeout();
		maj = false;
	}
	return false;
}


