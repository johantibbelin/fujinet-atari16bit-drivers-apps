#include <stdio.h>
#include <stdlib.h>
#include <tos.h>
#include <aes.h>
#include <string.h>
#include "a16defs.h"
#include "low2mid.h"

int main() {
	BYTE limage[32034];
	BYTE mimage[32034];
	BYTE *lip;
	FILE *f = NULL;
	char ifile[255];
	char ofile[255];
	char fname[20]="";
	char path[255]="C:\*.PI1";
	char title[60]="PI1 file to load.";
	int b=0;
	int ret=0;
	int l=0;
	int b_read = 0;
	int i,d;
	BYTE *scrp = NULL;

	lip = limage;

	printf("%cEPI12PI2 converter\n",27);

	ret = fsel_exinput(path,fname, &b, title);
	printf("%x\n",ret);

	if (b == 0) goto exit;
	printf("%cEPI12PI2 converter\n",27);
	printf("Filename:%s\nPath:%s\n\n",fname,path);
	l = (int)strlen(path);
	path[l-5] = '\0';
	strcat(path, fname);
	printf("Path:%s\n",path);

	f = fopen(path,"r");
	if (f == NULL) {printf("Opening file failed!\n"); goto exit;}
	for (i=0;i<32034;i++) {
		 d = fgetc(f);
		if (d == EOF) break;
		/*limage[i] = d;*/
		b_read++;
	} 
	fclose(f);
	printf("\nFile:%s %i bytes read.\n",fname, b_read);
	scrp = Physbase();
	lip = limage + 34;
	for (i=0;i<32000;i++) {
		*(scrp++) = *(lip++);
	}
	exit:
	getchar();
	return 0;
}
