#include <stdio.h>
#include <string.h>

int main() {
  char palavra_secreta[20];
  sprintf(palavra_secreta, "MELANCIA");

  int acertou = 0;
  int enforcou = 1;

  do {
    char chute;
    scanf("%c", &chute);

    for (int i = 0; i < strlen(palavra_secreta); i++) {
      if (palavra_secreta[i] == chute) {
        printf("A posição %d tem essa letra!\n", i);
      }
    }

  } while (!acertou && !enforcou);
}