// Escreva um programa que leia dois números inteiros do usuário e exiba a soma deles. 
#include <stdio.h>
#include <string.h> //Biblioteca para string
#include <conio.h> // Biblioteca para getch() limpar final.
//#include <stdbool.h>
//#include <iso646.h>

int nota1, nota2, nota3, soma;

int	main()
{
    // Solicitar os dois números ao usuário na mesma linha
    printf("Digite dois numeros inteiros (separados por espaco):");
    scanf("%d %d %d", &nota1, &nota2, &nota3);

    // Calcula asoma
    soma = nota1 + nota2 + nota3;

    // Exibir o resultado
    printf("Resultado da soma dos dois numeros: %d ", soma);

    getch();
    return 0;
}