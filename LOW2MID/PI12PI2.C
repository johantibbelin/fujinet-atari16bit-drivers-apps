#include <stdio.h>
#include <stdlib.h>
#include <tos.h>
#include <aes.h>
#include <string.h>
#include "a16defs.h"
#include "low2mid.h"

int main() {
	BYTE *limage;
	BYTE *mimage;
	BYTE *lip;
	FILE *f = NULL;
	char fname[20]="";
	char path[255]="C:\*.PI1";
	char title[60]="PI1 file to load.";
	int b=0;
	int ret=0;
	int l=0;
	int b_read = 0;
	int i;
	BYTE *scrp = NULL;

	limage = malloc(32034);
	mimage = malloc(32034);
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

	f = fopen(path,"rb");
	if (f == NULL) {printf("Opening file failed!\n"); goto exit;}
	b_read = fread(limage, 1, 32034, f);
	fclose(f);
	printf("\nFile:%s %i bytes read.\n",fname, b_read);
	scrp = Physbase();
	lip = limage + 34;
	for (i=0;i<32000;i++) {
		*(scrp++) = *(lip++);
	}
	scrp = Physbase();
	low2mid(limage+34, scrp);
	memcpy(mimage+34, Physbase(), 32000);
	mimage[0]=0;
	mimage[1]=1;
	memcpy(mimage+2,limage+2,32);
	f = fopen("mimage.pi2","wb");
	if (f == NULL) { printf("Opening file failed!\n"); goto exit;}
	b_read = fwrite(mimage, 1, 32034, f);
	fclose(f);
	printf("\n%i bytes written.\n", b_read);
	exit:
	getchar();
	free(limage);
	free(mimage);
	return 0;
}
