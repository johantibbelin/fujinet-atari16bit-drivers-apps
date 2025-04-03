/**
 * IMGDRIVE - Mount disk images to A or B drive
 *
 * Written by: Johan Tibbelin (sjfroos)
 * 
 * for the Fujinet project
 *
 * Start date: 2025-03-31
 *
 * Last changed: 2025-03-31
 *
 * Version: 0.01a
 */

#include <stdio.h>
#include <stdlib.h>
#include <tos.h>
#include <aes.h>
#include "a16defs.h"
#include "imgrwabs.h"

int main() {
	FILE *f = NULL;
	char fname[20]="";
	char path[255]="C:\*.ST";
	char title[60]="PI1 file to load.";
	int ret=0;
	int b;

	printf("%cEFujinet IMG-drive",27);
	ret = fsel_input(path,fname, &b);
	
	return 0;
}