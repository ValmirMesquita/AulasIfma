#include <stdio.h>
#include <string.h> //Biblioteca para string
#include <conio.h> // Biblioteca para getch() limpar final.

int num1, num2, maior;





int	main()
{
   
    printf("Digite o primeiro numero:");
    scanf("%d", &num1);

    printf("Digite o segundo numero:");
    scanf("%d", &num2);
    

    if(num1 > num2){
        maior = num1;
     }
    else{
        maior = num2;
    }
    printf("O maior numero e:  %d", maior);


    getch();
    return 0;
}