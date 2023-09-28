#include <stdio.h>
#include <stdlib.h>

int main(){
    // imprime o cabecalho do nosso jogo
    printf("******************************************\n");
    printf("* Bem vindo ao nosso jogo de adivinhacao *\n");
    printf("******************************************\n");

    int numero_secreto = 42;

    int chute;
    int tentativas = 1;

    double pontos = 1000;

    while(1)
    {
        printf("Tentativa %d\n", tentativas);
        printf("Qual e o seu chute? ");
     
        scanf("%d", &chute);
        printf("Seu chute foi %d \n", chute);

        if(chute < 0) {
            printf("Voce nao pode chutar numeros negativos!\n");
            continue;
        }

        int acertou = (chute == numero_secreto);
        int maior = (chute > numero_secreto);

        if (acertou) {
            printf("Parabens!! voce acertou!\n"); 
            break;
        } 
       
        else if(maior) {
            printf("Seu chute foi maior que o numero secreto..\n");
        } 

        else {
            printf("Seu chute foi menor que o numero secreto..\n");
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
    printf("Total de pontos: %.1f\n", pontos);
} 