// Escreva um programa que leia dois números e mostre o maior entre eles
#include <stdio.h>

int num1,num2, maior;

int main(){
    printf("digite um numero: ");
    scanf("%d", &num1);

    printf("Digite o segundo numero: ");
    scanf("%d", &num2);

    printf("Primeiro numero %d e segundo numero %d\n ",num1,num2);
    

    if (num1 > num2)
    {
        maior = num1;
        printf("Primeiro numero maior que o segundo: ");
        printf("-------------------------------------------\n");

    }else
    {
        maior = num2;
        printf("Segundo numero maior que o primeiro:");
        printf("-------------------------------------------\n");
    }
    
    return 0;
}