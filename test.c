#include<stdio.h>
#include<stdlib.h>
#include"memdump.h"
#include<string.h>

int main() {
  printf("Hello, World!\n");
  int *p;
  p = (int *)malloc(sizeof(int));
  p[0] = 0x12345678;
  int a = 8;
  printf("Pointer1: %p\n", p);
  printf("Pointer1 content: %p\n", *p);
  memdump("Pointer1", p, 4);
  memdump("Pointer2", &a, 4);

  char *s;
  s = (char *)malloc(0x10);
  strcpy(s, "Hello, World!");
  memdump("String", s, 4);
  return 0;
}
