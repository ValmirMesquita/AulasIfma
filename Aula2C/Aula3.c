
//Escreva um programa que leia um número e exiba sua tabuada de 1 a 10. 
#include <stdio.h>
#include <stdbool.h>
#include <iso646.h>


int n1, n2, soma;

int	main()
{
    printf("Digite um numero da inteiro: ");
    scanf("%d", &n1);

    printf("Digite um numero da inteiro: ");
    scanf("%d", &n2);

    soma = n1 + n2 ;

     printf("O valor da soma dos dois numeros e: %d", soma, "\n");
     printf("\n");
  
    return 0;
}

