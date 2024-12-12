#include <stdio.h>
//#include <stdlib.h>
//#include <locale.h>

//#include <stdbool.h>
//#include <iso646.h>

int n1, n2, diferenca;

int	main()
{
    //setlocale(LC_ALL, "Portuguêse");

    printf("Digite dois numeros: ");
    scanf("%d", &n1);

    printf("Digite dois numeros inteiros: ");
    scanf("%d", &n2);

    diferenca = n1 - n2;

    printf("Resultado da soma dos dois numeros: %d ", diferenca);

    
    return 0;
}