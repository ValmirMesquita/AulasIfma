// Escreva um programa que leia um número e exiba sua tabuada de 1 a 10.
#include <stdio.h>
#include <string.h> //Biblioteca para string
#include <conio.h> // Biblioteca para getch() limpar final.
//
//#include <stdbool.h>
//#include <iso646.h>

int num1, soma;
int i;

int	main()
{
    // Solicitar os dois números ao usuário na mesma linha
    printf("Digite um numero: ");
    scanf("%d", &num1);

    printf("Tabuada de: %d", num1);
    printf("\n-------------------------------\n");

     for (i = 0; i < 10; i++)
    {
        soma = num1 * i;
        printf("%d * %d = %d\n", num1, i, soma );
        
    }
    printf("-------------------------------\n");

    getch();
    return 0;
}