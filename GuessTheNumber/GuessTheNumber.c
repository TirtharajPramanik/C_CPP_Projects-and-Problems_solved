#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

void compareNumbers(int num, int guess, int tries) {
  char word[16];
  int too = (num / 4) + 1;
  if(guess - too > num) strcpy(word, "Too High");
  else if(guess > num) strcpy(word, "High");
  else if(guess + too < num) strcpy(word, "Too Low");
  else if(guess < num) strcpy(word, "Low");
  else {
    printf("Congrats!🎉 Your Guess is: Correct!\n");
    exit(0);
  }
  tries--;
  if(tries < 1) {
    printf("Oops!👾 You Missed It!!\n");
    exit(0);
  }
  printf("Your Guess is: %s!\tTries left: %d\n", word, tries);
}

void guessNumber(int num, int count) {
  if(count == 0) count = 5;
  else if (count < 0) count = -count;
  int guess;
  for(; count > 0; count--) {
    printf("\nGuess: ");
    if(scanf("%d", &guess) != 1) {
      printf("Oops!☄️  Only Integer (0 - 9) Allowed!!!\n");
      break;
    }
    compareNumbers(num, guess, count);
  }
}

int main(int argc, char *argv[]) {
  srand(time(NULL));
  int max = 10;
  if(argc > 1) {
    char *a = argv[1];
    max = atoi(a);
    if(max > 10000) {
      printf("Oops!☄️  Only Integer (0 - 9) `<= 10000` Allowed!!!\n");
      exit(0);
    }
  }
  int num = (rand() % max) + 1;
  int tries = max / 2;
  if(argc > 2) {
    char *b = argv[2];
    tries = atoi(b);
  }
  printf("Range is `0 - %d`\tTries: %d\t`Too` means: `< or >` %d\n", max, tries, (num / 4) + 1);
  guessNumber(num, tries);
  return 0;  
}
