#include <stdio.h>

int valor;

int	main()
{
  
    printf("Digite um valor de 1 a 7:");
    scanf("%d",&valor);

    switch (valor){
        case 1:
            printf("Domingo \n");
            break;

        case 2:
            printf("Segunda Feira\n");
            break;

        case 3:
            printf("Terca Feira\n");
            break;        
        
        case 4:
            printf("Quarta Feira\n");
            break; 

        case 5:
            printf("Sexta Feira\n");
            break; 

        case 6:
            printf("Sabado  \n");
            break; 

        default:
            printf("----- FORA DO CASO ----- \n");
            break;

    }

    return 0;
}
