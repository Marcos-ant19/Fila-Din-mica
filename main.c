#include <stdio.h>
#include "fila.h"
#include <locale.h>
int main(){

    setlocale(LC_ALL, "portuguese");
    Fila* f = criar_fila();
    int opcao;
    char letra;

    do{
        printf("================ Menu =====================\n");
        printf("---------------------------------------------\n");
        printf("1-Inserir elementos na fila\n");
        printf("2-remover elementos na fila\n");
        printf("3-Quantidade de elementos na fila\n");
        printf("4-Limpar a fila\n");
        printf("5-Conteudo da fila\n");
        printf("6-Mostrar o conteudo e limpar automaticamente\n");
        printf("7-Mostrar em ordem inversa e remover os elementos\n");
        printf("8-Mostrar conteúdo em ordem inversa\n");
        printf("9-Inserir uma palavra na fila\n");
        printf("10-Encerrar o programa!\n");
        printf("----------------------------------------------\n");
        printf("================ Fim =====================\n");
        printf("Thamer qual opção o deseja: ");
        scanf("%d", &opcao);
        while(getchar() != '\n');

        switch(opcao){
            case 1:
            printf("Insere 1 caractere por vez\n");
                do{
                printf("Digite: ");
                scanf(" %c", &letra);

                if(letra != '0'){
                    inserir(f, letra);
                }
                }while(letra != '0');

            break;
            case 2:
            if(isEmpty(f)){
                printf("Voce precisa inserir elementos antes de remover!\n\n");
                break;
            }
            printf("Caractere removido com sucesso!\n");
            remover(f);
            imprimir(f);
            break;


            case 3:
            printf("== ELEMENTOS DA FILA ==\n");
            printf("%d ", size(f));
            printf("\n");
            break;

            case 4:
            if(isEmpty(f)){
                printf("Voce precisa inserir elementos antes de limpar!\n\n");
                break;
            }
            clear(f);
            break;

            case 5:
            if(!isEmpty(f)){
                printf("\n== FILA ==\n");
                imprimir(f);
                break;
            }
             printf("Voce precisa inserir elementos na fila!\n\n");
             break;

            case 6:
            if(!isEmpty(f)){
                printf("\n== FILA ==\n");
                imprimir(f);
                clear(f);
                break;
            }
            printf("Voce precisa inserir elementos na fila!\n\n");
            break;

            case 7:
            printf("Conteúdo da fila na ordem inversa!\n");
            inverter(f);
            while(!isEmpty((f))){
                remover(f);
            }
            printf("Conteúdo removido com sucesso!\n");
            break;

            case 8:
            if(isEmpty((f))){
               printf("Você precisa inserir elementos na fila!\n");
               break;
            }
            inverter(f);
            break;

            case 9:
                palavra(f);
                printf("Palavra inserido com sucesso!n");
                break;
            case 10:
                printf("Saindo do programa\n");
                break;
            default:
                printf("Opção inválida, tente novamente!\n");

        }

    }while(opcao != 10);



    return 0;
}
