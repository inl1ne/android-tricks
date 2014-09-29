#include "nab_usb_function.h"
#include <stdio.h>

int main() {
  printf ("launching\n");
  nab_usb_function_init();
  printf ("finished\n");
  return 0;
}

