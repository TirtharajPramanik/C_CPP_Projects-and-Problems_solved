#include <stdio.h>

int main() {
  printf("[1]:\tShow All Records\n");
  printf("[2]:\tAdd New Record\n");
  printf("[3]:\tExit\n");
  int cmd;
  printf("Enter:\t");
  scanf("%d", &cmd);
  if(cmd < 0) cmd = -cmd;
  if(cmd == 1 || cmd == 2 || cmd == 3) printf("Done!\n");
  else printf("Options:\t[ `0`, `1`, `2` ]\n");
  return 0;
}
