#include <stdio.h>
#include <stdlib.h>

#include "vector_search.h"
#include "binary_tree.h"
#include "helper.h"
#include "menu.h"

void printMenu(){
  printf("Buscas:\n\n");
  printf("1 - Busca por AST\n");
  printf("2 - Busca Sequencial\n");
  printf("3 - Busca Binária\n");
  printf("4 - Busca por Interpolação\n");
  printf("0 - Sair\n\n");
}

void executeMenu() {
  int size, range, opt, value = -1;
  int *vector;

  printf("\n\nListar 1 - Buscas\n\n");
  printf("Digite o tamanho do vetor desejado: ");

  do {
      scanf("%d", &size);
      if(size <= 0){
          printf("Por favor, digite um valor maior que 0: ");
      }
  } while(size <= 0);
 
  printf("Digite o intervalo dos números do vetor (de 0 até esse valor): ");
  do {
      scanf("%d", &range);
      if(range <= 0){
          printf("Por favor, digite um valor maior que 0. \n");
      }
  } while(range <= 0);
 
  vector = createVector(size, range);
  printVector(vector, size);

  do {
    printMenu();
    scanf("%d", &opt);


    
    switch (opt) {
        case 1:
            printVector(vector, size);
            do {
                value = -1;
                printf("Digite o valor a ser pesquisado: ");
                scanf("%d", &value);
                if (value <= 0){
                    printf("Por favor, digite um valor maior que 0.");
                }
            } while (value <= 0);
            
            if (searchInAST(vector, size, value) > 0) {
                printf("Valor encontrado!\n\n\n");
            } else {
                printf("Valor não encontrado.\n\n\n");
            } 
            break;

        case 2:
            printVector(vector, size);
            do {
                value = -1;
                printf("Digite o valor a ser pesquisado: ");
                scanf("%d", &value);
                if (value <= 0){
                    printf("Por favor, digite um valor maior que 0.");
                }
            } while (value <= 0);
            
            if (sequentialSearch(vector, size, value) > 0) {
                printf("Valor encontrado!\n\n\n");
            } else {
                printf("Valor não encontrado.\n\n\n");
            }
            break;
        
        case 3:
            printVector(vector, size);
            do {
                value = -1;
                printf("Digite o valor a ser pesquisado: ");
                scanf("%d", &value);
                if(value <= 0){
                    printf("Por favor, digite um valor maior que 0.");
                }
            } while (value <= 0);
           
            int result = binarySearch(vector, size, value);
            if (result != -1) {
                printf("Valor encontrado!\n\n\n");
            } else {
                printf("Valor não encontrado.\n\n\n");
            }
     
            break;

        case 4:
            printVector(vector, size);
            do {
                value = -1; 
                printf("Digite o valor a ser pesquisado: ");
                scanf("%d", &value);
                if(value <= 0){
                    printf("Por favor, digite um valor maior que 0.");
                }
            } while (value <= 0);
           
            if (interpolationSearch(vector, size, value) != -1 ) {
                printf("Valor encontrado!\n\n\n");
            } else {
                printf("Valor não encontrado.\n\n\n");
            }
            break;
       
        case 0:
            destroyVector(vector);
            break;
       
        default:
            printf("Digite uma opção válida.\n");
    }
  } while(opt);

  destroyVector(vector);
}
