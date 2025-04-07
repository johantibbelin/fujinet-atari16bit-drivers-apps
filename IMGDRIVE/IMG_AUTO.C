#include <stdio.h>
#include <tos.h>
#include "a16defs.h"
#include "reset.h"

int main() {
	LONG *resvec = (LONG *)0x42A;
	LONG *resvalid =(LONG *)0x426;
	LONG *phystop = (LONG *)0x42E;
	LONG s_sp;

	s_sp = Super(0L);

	if (*resvalid != 0x87654321L) {
		if (*phystop >= 0x200000L) {
			phystop -= 0x25000L;
			*resvalid = 0x87654321L;
			*resvec = *phystop;
		}
		else {
			printf("\nNot enough memory. At least 2 MB needed.\n");
		}
	}
	return 0;
}