#include <stdio.h>
#include <tos.h>
#include "a16defs.h"
#include "reset.h"

int main() {
	LONG volatile *resvec = (LONG *)0x42A;
	LONG volatile *resvalid =(LONG *)0x426;
	LONG volatile *phystop = (LONG *)0x42E;
	LONG s_sp;
	int i;

	s_sp = Super(0L);
	
	printf("%cE%cpIMG DRIVE - img files in ram%cq\n",27,27,27);
	if (*resvalid != 0x87654321L) {
		printf("\nIMG DRIVE is not installed.\n");
		if (*phystop >= 0x200000L) {
			*phystop -= 0x100000L;
			*resvalid = 0x87654321L;
			*resvec = *phystop;
			s_sp = Super((void *)s_sp);
			printf("\nInstalled restarting ST.\n");
			for (i=0;i<100;i++) {
				Vsync();
			}
			reset();
		}
		else {
			printf("\nNot enough memory. At least 2 MB needed.\n");
		}
	}
	else {
		printf("\nIMG DRIVE is installed.\n");
		for (i=0;i<100;i++) {
			Vsync();
		}
	} /* else *resvalid != 0x87654321 */
	return 0;
}