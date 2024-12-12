// Crie um programa que leia três notas de um aluno e calcule a média aritmética
#include <stdio.h>

int nota1, nota2, nota3, mediaAritimetica;

int	main()
{
    printf("Digite a primeira nota: ");
    scanf("%d", &nota1);

    printf("Digite a segunda nota: ");
    scanf("%d", &nota2);

    printf("Digite a terceira nota: ");
    scanf("%d", &nota3);

    mediaAritimetica = (nota1 + nota2 + nota3)/3 ;

    if (mediaAritimetica >= 7)
    {
        printf("Aluno aprovado ");
    }
     else if (mediaAritimetica >= 6)
     {
        printf("Aluno em recuperacao ");
     }

     else if (mediaAritimetica >=5)
     {
        printf("Aluno em reprovado ");
     }

     else
     {
        printf("Nenhuma das alternativas ");
     }
     
    return 0;
}