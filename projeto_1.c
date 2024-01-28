// PROJETO 1 - ALGORITMOS E PROGRAMACAO 2 - CAIO CORSINI
#include <stdio.h>
#include <math.h> 
#include <locale.h>
#include "poliCaio.h"

// Biblioteca math chamada apenas para usar a funcao pow() na multiplicação.

// Para este projeto, os polinômios sao representados por arrays nas quais os elementos de index par são os coeficientes enquanto os de index impar sao os expoentes.

int main(void) {
  setlocale(LC_ALL, "Portuguese");
  
  int menu = 0;
  printf("--- INSERIR POLINÔMIOS ---\n\n");
  // Ao iniciar o programa, o usuário deve inserir o polinômio X
  printf("--- POLINOMIO X ---\n\n");

  int grau_x = 0;
  int tamanho_x = 0;

  printf("Qual é o grau do seu polinômio X: ");
  scanf("%d", &grau_x);

  // Calculo do tamanho do polinômio baseado no seu grau.
  tamanho_x = (grau_x+1)*2;
  int poli_x[tamanho_x];
  int expoente = 0;
  expoente = grau_x;

  // preenche elementos de index impar da array com expoentes, do maior para o menor
  for(int i = 1; i < tamanho_x; i+=2){
    poli_x[i] = expoente;
    expoente -= 1;
  }
  printf("\n");

  // Input dos coeficientes
  for(int i = 0; i < tamanho_x; i+=2){
    int inserir = 0;
    printf("Inserir coeficiente: ");
    scanf("%d", &inserir);
    poli_x[i] = inserir;
  }

  // Quando terminado, o polinômio X eh apresentado ao usuário
  printf("\nPolinomio X: ");
  mostrar_poli(poli_x, tamanho_x);

  // Apos fazer o polinomio X, o usuário vai customizar o polinômio Y.
  printf("\n\n--- POLINOMIO Y ---\n\n");

  int grau_y = 0;
  int tamanho_y = 0;

  printf("Qual é o grau do seu polinômio Y: ");
  scanf("%d", &grau_y);

  tamanho_y = (grau_y+1)*2;
  int poli_y[tamanho_y];
  expoente = grau_y;

  // Preenche elementos de index impar da array com expoentes, do maior para o menor
  for(int i = 1; i < tamanho_y; i+=2){
    poli_y[i] = expoente;
    expoente -= 1;
  }
  printf("\n");

  // Input dos coeficientes
  for(int i = 0; i < tamanho_y; i+=2){
    int inserir = 0;
    printf("Inserir coeficiente: ");
    scanf("%d", &inserir);
    poli_y[i] = inserir;
  }

  // Quando terminado, o polinômio Y eh apresentado ao usuário
  printf("\nPolinômio Y: ");
  mostrar_poli(poli_y, tamanho_y);

  
  while (menu == 0){
    int opcao = 0;
    
    // Menu principal
    // Vai aparecer repetidamente ate o usuário decidir sair do programa clicando 5
    // Usuário esolhe o que deseja fazer ao pressionar um numero de 1 a 5
    printf("--- CALCULADORA DE POLINÔMIOS ---\n\n");
    printf("Selecione o que deseja fazer agora\n");
    printf("[1] Mostrar polinômios\n");
    printf("[2] Resolver polinômios\n");
    printf("[3] Somar polinômios\n");
    printf("[4] Multiplicar polinômios\n");
    printf("[5] Sair\n\n");

    // Usuario escolhe que funcionalidade deseja usar
    printf("Digite aqui: ");
    scanf("%d", &opcao);

    // Polinomios originais sao mostrados novamente ao usuario
    if(opcao == 1){
      printf("\n--- MOSTRAR POLINÔMIOS ---\n\n");
      printf("\nPolinômio X: ");
      mostrar_poli(poli_x, tamanho_x);
      printf("Polinômio Y: ");
      mostrar_poli(poli_y, tamanho_y);
    }

    if(opcao == 2){
      int valor = 0;
      int resultado = 0;
      printf("\n--- RESOLVER POLINÔMIOS ---\n\n");
      
      // Usuario escolhe o valor de x
      printf("Qual é o valor de x: ");
      scanf("%d", &valor);

      // Resultado calculado para o polinômio X
      resultado = resol_poli(poli_x, tamanho_x, valor);
      printf("\n\nPolinômio X quando x = %d resulta em: %d\n", valor, resultado);

      // Resultado calculado para o polinômio Y
      resultado = resol_poli(poli_y, tamanho_y, valor);
      printf("\nPolinômio Y quando x = %d resulta em: %d\n\n", valor, resultado);
    }

    if(opcao == 3){
      printf("\n--- SOMAR POLINÔMIOS ---\n\n");
      // Tamanho do polinomio soma eh definido de acordo com que polinomio tem o tamanho/grau maior
      int poli_soma[tamanho_x > tamanho_y ? tamanho_x : tamanho_y];
      int tamanho_soma = tamanho_x > tamanho_y ? tamanho_x : tamanho_y; 

      // Tamanho tambem passado como parametro na funcao, pois nao foi encontrado metodo de descobrir tamanho da array em c. sizeof dá o tamanho do tipo da variável, mas nao o comprimento
      adic_poli(poli_x, tamanho_x, poli_y, tamanho_y, poli_soma, tamanho_soma);
      mostrar_poli(poli_soma, tamanho_soma);
    }

    if(opcao == 4){
      printf("\n--- MULTIPLICAR POLINÔMIOS ---\n\n");
      int grau_mult = 0;
      int tamanho_mult = 0;

      // Definindo tamanho do polinômio final baseado na soma dos maiores expoentes das funcoes a serem multiplicadas
      grau_mult = poli_x[1] + poli_y[1];
      tamanho_mult = (grau_mult+1)*2;
      int poli_mult[tamanho_mult];

      // Tamanho tambem passado como parâmetro na função, pois nao foi encontrado método de descobrir tamanho da array em c. sizeof dá o tamanho do tipo da variável, mas não o comprimento
      mult_poli(poli_x, tamanho_x, poli_y, tamanho_y, poli_mult, tamanho_mult);
      mostrar_poli(poli_mult, tamanho_mult);
    }

    // Usuário sai do programa. Loop de while é quebrado.
    if(opcao == 5){
      menu = 1;
      printf("\n até mais!\n");
    }
  }
  return 0;
}