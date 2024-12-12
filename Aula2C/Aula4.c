//Escreva um programa que leia um número e exiba sua tabuada de 1 a 10. 
#include <stdio.h>
#include <stdbool.h>

int	main()
{
    int numero;
    int i;

    // Solicita ao usuário que insira um número
    printf("Digite um numero: ");
    scanf("%d", &numero);

    // Exibe a tabuada de 1 a 10
    printf("Tabuada do %d:\n", numero);

    for (i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", numero, i, numero * i);
    }
 
    return 0;
}

