#include <stdio.h>

#define NUMERO_TENTATIVAS 5
// 2.09 aula
int main(){
    // imprime o cabecalho do nosso jogo
    printf("******************************************\n");
    printf("* Bem vindo ao nosso jogo de adivinhacao *\n");
    printf("******************************************\n");

    int numero_secreto = 42;
    int chute;

    for (int i = 1; i <= NUMERO_TENTATIVAS; ++i)
    {
        printf("Tentativa %d de %d\n", i, NUMERO_TENTATIVAS);
        printf("Qual e o seu chute? ");
     
        scanf("%d", &chute);
        printf("Seu chute foi %d \n", chute);

        if(chute < 0) {
            printf("Voce nao pode chutar numeros negativos!\n");
            i--;

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
           
    } 

    printf("Fim de jogo!\n");      
} 