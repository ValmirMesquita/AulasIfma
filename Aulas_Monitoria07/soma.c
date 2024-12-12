// Escreva um programa que leia dois números inteiros do usuário e exiba a soma deles. 
#include <stdio.h>
//#include <stdbool.h>
//#include <iso646.h>

int nota1, nota2, soma;

int	main()
{
    printf("Digite dois numeros inteiros: ");
    scanf("%d", &nota1);

    printf("Digite dois numeros inteiros: ");
    scanf("%d", &nota2);

    soma = nota1 + nota2;

    printf("Resultado da soma dos dois numeros: %d ", soma);

    
    return 0;
}