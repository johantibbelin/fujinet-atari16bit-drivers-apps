#include <stdio.h>
#include <stdlib.h>
#include <tos.h>
#include <aes.h>
#include "a16defs.h"

int main() {
  int ap_id, menu_id, msg[8];

  ap_id = appl_init();
  menu_id = menu_register(ap_id,"  Test");

wait:
  evnt_mesag(msg);
  if(msg[0] == AC_OPEN && msg[4] == menu_id) {
    form_alert(1,"[0][Test Accessory ][OK]");
   }
  goto wait;	
}