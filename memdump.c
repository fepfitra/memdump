#include <ctype.h>
#include <stdint.h>
#include <stdio.h>

int is32bit() { return sizeof(long) == 4; }

void memdump(char *desc, void *address, int line) {
  printf("%s\n", desc);
  for (int i = 0; i < line; i++) {
    printf("%p: ", address + i * 0x10);
    for (int j = 0; j < 4; j++) {
      if (is32bit()) {
        printf("0x%.08x ", ((int *)address)[j + i * 0x10]);
      } else {
        printf("0x%.16x ", ((int *)address)[j + i * 0x10]);
      }
    }

    printf(" | ");
    for (int j = 0; j < 0x10; j++) {
      unsigned char byte = ((unsigned char *)address)[j + i * 0x10];
      if (isprint(byte)) {
        printf("%c", byte);
      } else {
        printf(".");
      }
    }
    printf(" |\n");
  }
}
