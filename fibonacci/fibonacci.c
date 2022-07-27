#include <stdio.h>
#include <stdlib.h>

int isNumber(char number[]);

int main(int argc, char *argv[]) {
  int c;
  int ret = 0;
  int fat = 0;
  if(argc > 1 && isNumber(argv[1])) {
    c = atoi(argv[1]);
    if(c < 0) c = 0 - c;
    if(c > 47) {
      printf("max numaber can take `47`\n");
      return 0;
    }
    if(c < 4) fat = 1;
    else{
      if(c % 2 == 0) {
        ret = 1;
        c = c / 2;
      } else c = (c / 2) + 1;
    }
  } else {
    printf("canculating upto number `10`\n");
    c = 10/2;
    ret = 1;
  }
  int a = 0;
  int b = 1;
  if(!fat) {
    for(int i = 1; i < c; i++) {
      a += b;
      b += a;
   }
  } else {
    if(c == 0) printf("none");
    else{
      if(c > 1) {
        printf("ans: %d\n", b);
      } else printf("ans: %d\n", a);
    }
    return 0;
  }
  if(ret) printf("ans: %d\n", b);
  else printf("ans: %d\n", a);
  return 0;
}

int isNumber(char number[]) {
  int i = 0;
  //checking for negative numbers
  if (number[0] == '-') i = 1;
  for (; number[i] != 0; i++) {
    if (number[i] > '9' || number[i] < '0')
      return 0;
  }
  return 1;
}
