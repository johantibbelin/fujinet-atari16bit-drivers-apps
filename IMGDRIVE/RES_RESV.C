/**
 *
 * res_resv.c - Small programs that clears resetvalid
 *              and resetvector
 *
 */

#include <stdio.h>
#include <tos.h>
#include "a16defs.h"

int main(void) {

	LONG volatile *resvec = (LONG *)0x42A;
	LONG volatile *resvalid =(LONG *)0x426;
	LONG s_sp;
	int i;

	s_sp = Super(0L);
	
	*resvec   = 0;
	*resvalid = 0;

	s_sp = Super((void *)s_sp);

	printf("%cEReset-vector and Reset-valid cleared.",27);
	for (i=0;i<100;i++) {
		Vsync();
	}
	return 0;
}