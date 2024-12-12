#include <stdio.h>
#include <string.h> //necessário para strcpy
#include <conio.h>

int main (void)
{
  char nome[100];

  printf("Digite seu nome  :" );
  scanf("%s", nome);

  printf("Seu nome e:  %s", nome);
  
  getch();
  return 0;
}