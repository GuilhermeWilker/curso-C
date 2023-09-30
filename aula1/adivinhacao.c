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

    int acertou = 0;
    int chute;
    int tentativas = 1;

    double pontos = 1000;

    int nivel;
    printf("Qual nível de dificuldade gostaria de jogar?\n");
    printf("(1) Facil\n(2) Medio\n(3) Dificil\n\n");
    printf("Digite sua opcao: ");
    scanf("%d", &nivel);

    int numero_tentativas;
    switch (nivel)
    {
        case 1:
            numero_tentativas = 20;
            break;
        case 2:
            numero_tentativas = 12;
            break;
        default:
            numero_tentativas = 6;
            break;
    }
    
    for(int i = 1; i <= numero_tentativas; i++)
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

        acertou = (chute == numero_secreto);
        int maior = (chute > numero_secreto);

        if (acertou) {
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

    printf("* Fim de jogo! *\n");

    if(acertou){
          printf("****************\n");
          printf("* Voce ganhou! *\n");
          printf("****************\n");

        printf("Voce acertou em %d tentativas\n", tentativas);
        printf("|==============================================|\n");
        printf("Total de pontos: %.1f\n", pontos);
    } else {
        printf("|==============================================|\n");
        printf("Voce perdeu, tente de novo! \n");
    }

    
     
    
} 