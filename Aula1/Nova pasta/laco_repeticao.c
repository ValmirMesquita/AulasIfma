/* Arquivo laco_repeticao.c
Autor: Valmir S Mesquita 
Data:03/12/2024
2 Segundo programa em C */

#include <stdio.h>
int	main()
{


    for (int i = 0; i < 20; i++)
    {
       if (i*i>100)
       {
        break;

       }

       else{
        printf("%d\n", (i*i));
       }
       
    }
    
    system("pause");
    return 0;
}