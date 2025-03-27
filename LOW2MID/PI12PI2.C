#include <stdio.h>
#include <stdlib.h>
#include <tos.h>
#include <aes.h>
#include "a16defs.h"
#include "low2mid.h"

int main() {
	char ifile[255];
	char ofile[255];
	char fname[20]="";
	char path[255]="C:\*.PI1";
	char title[60]="PI1 file to load.";
	int b=0;
	int ret=0;

	printf("%cEPI12PI2 converter\n",27);

	ret = fsel_exinput(path,fname, &b, title);
	printf("%x\n",ret);
	getchar();
	if (b == 0) goto exit;
	printf("%cEPI12PI2 converter\n",27);
	printf("Filename:%s\nPath:%s",fname,path);
	

	exit:
	getchar();
	return 0;
}