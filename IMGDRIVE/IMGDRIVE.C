/**
 * IMGDRIVE - Mount disk images to A or B drive
 *
 * Written by: Johan Tibbelin (sjfroos)
 * 
 * for the Fujinet project
 *
 * Start date: 2025-03-31
 *
 * Last changed: 2025-04-03
 *
 * Version: 0.01a
 */

#include <stdio.h>
#include <stdlib.h>
#include <tos.h>
#include <aes.h>
#include <string.h>
#include "a16defs.h"
#include "imgrwabs.h"

int main() {
	FILE *f = NULL;
	BYTE *dta = NULL;
	char fname[20]="";
	char path[255]="C:\*.ST";
	char title[60]=".ST file to load.";
	int ret=0;
	int b,l,gf;

	printf("%cEFujinet IMG-drive",27);
	ret = fsel_input(path,fname, &b);
	if (b == 0) {
		printf("\nNo file selected!");
		ret = -1;
		goto exit;
	}
	l = (int)strlen(path);
	path[l-5] = '\0';
	strcat(path, fname);
	b = Fsfirst(path, 0);
	printf("b=,%i\n\n",b);
	goto exit;
	gf = Fopen(path,FO_READ);
	l = Fseek(0, gf, 2);
	printf("File len:%i\n\n",l);
	exit:
	getchar();
	return ret;
}