#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    // imprime o cabecalho do nosso jogo
    printf("|========================================|\n");
    printf("| Bem vindo ao nosso jogo de adivinhacao |\n");
    printf("|========================================|\n");

    int segundos = time(0);
    srand(segundos);

    int numero_grande = rand();
    int numero_secreto = numero_grande % 100;

    int chute;
    int tentativas = 1;

    double pontos = 1000;

    while(1)
    {
        printf("Tentativa %d\n", tentativas);
        printf("|==============================================|\n");
        printf("Qual e o seu chute? ");
        scanf("%d", &chute);

        if(chute < 0) {
            printf("Voce nao pode chutar numeros negativos!\n");
            printf("|==============================================|\n");
            continue;
        }

        int acertou = (chute == numero_secreto);
        int maior = (chute > numero_secreto);

        if (acertou) {
            printf("Parabens!! voce acertou!\n");
            printf("|==============================================|\n"); 
            break;
        } 
       
        else if(maior) {
            printf("Seu chute foi %d.. Maior que o numero secreto..\n", chute);
            printf("|==============================================|\n");
        } 

        else {
            printf("Seu chute foi %d.. Menor que o numero secreto..\n", chute);
            printf("|==============================================|\n");
        }
           tentativas++;
                                    // abs() - converte números negativos para positivos
            double pontos_perdidos = abs(chute - numero_secreto) / (double)2; 
            pontos = pontos - pontos_perdidos;
    } 

    printf("****************\n");
    printf("* Fim de jogo! *\n");
    printf("****************\n");
     
    printf("Voce acertou em %d tentativas\n", tentativas);
    printf("|==============================================|\n");
    printf("Total de pontos: %.1f\n", pontos);
} 