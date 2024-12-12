// Escreva um programa define se o numero digitado e impa ou par
#include <stdio.h>
#include <string.h> //Biblioteca para string
#include <conio.h> // Biblioteca para getch() limpar final.
//
//#include <stdbool.h>
//#include <iso646.h>

int num1;
int i;

int	main()
{
    

     for (i = 0; i < 5; i++)
    {
        // Solicitar os dois números ao usuário na mesma linha
        printf("Digite um numero inteiro:");
        scanf("%d", &num1);
        

            // Determina a condição 
        if(num1 % 2 == 0){
            printf("Numero digitado %d e (Par) \n",num1);
            printf("------------------------------------\n");
            
        }else{
            printf("Numero digitado %d e (Impar) \n",num1);
            printf("------------------------------------\n");        
        }   

    }
    printf("**** Fim do Programa **** \n");

    getch();
    return 0;
}