#include <stdio.h>
#include <math.h> 
#include <locale.h>
#include "poliCaio.h"

// funcao de adição de polinômios
int adic_poli(int poli_x[], int tamanho_x, int poli_y[], int tamanho_y, int poli_soma[], int tamanho_soma){
  setlocale(LC_ALL, "Portuguese");
  int grau_poli = 0;
  grau_poli = (tamanho_soma/2)-1;

  int expoente = 0;
  expoente = grau_poli;

  // preenche elementos de index impar da array com expoentes, do maior para o menor
  for(int i = 1; i < tamanho_soma; i+=2){
    poli_soma[i] = expoente;
    expoente -= 1;
  }

  // preenche elementos pares com coeficientes zeros. Eles serao modificados depois.
  for(int i = 0; i < tamanho_soma; i+=2){
    poli_soma[i] = 0;
  }

  // Faz a soma dos elemntos contidos no polinômio X dentro do polinômio soma.
  for(int i=1; i<tamanho_x; i+=2){
    // Procura pelo expoente correspondente na soma. Uma vez encontrado, os coeficientes são somados.
    for(int j =1; j<tamanho_soma;j+=2){
      if(poli_x[i] == poli_soma[j]){
        poli_soma[j-1] += poli_x[i-1];
      }
    }
  }

  // Faz o mesmo processo feito logo acima, porem com o polinômio Y.
  for(int i=1; i<tamanho_y; i+=2){
    for(int j =1; j<tamanho_soma;j+=2){
      if(poli_y[i] == poli_soma[j]){
        poli_soma[j-1] += poli_y[i-1];
      }
    }
  }
  return poli_soma;
}



// Função que resolve o polinômio para um dado x.
int resol_poli(int poli[], int tamanho, int valor){
  setlocale(LC_ALL, "Portuguese");
  int resultado = 0;
  int para_somar = 0;
  // Itera polinomio de 2 em 2 pelos expoentes.
  for(int i = 1; i<tamanho; i+=2){
    // Eleva x ao dado expoente e multiplica com o coeficiente. O resultado dessas operações é então somado.
    para_somar = pow(valor,poli[i])*poli[i-1];
    resultado += para_somar;
  }
  return resultado; // Resultado final é retornado
}



// Função de produto/multiplicacao de polinômios
int mult_poli(int poli_x[], int tamanho_x, int poli_y[], int tamanho_y, int poli_mult[], int tamanho_mult){
  setlocale(LC_ALL, "Portuguese");
  int grau_poli = 0;
  grau_poli = (tamanho_mult/2)-1;

  int expoente = 0;
  expoente = grau_poli;

  // Preenche elementos de index impar da array com expoentes, do maior para o menor.
  for(int i = 1; i < tamanho_mult; i+=2){
    poli_mult[i] = expoente;
    expoente -= 1;
  }

  // Preenche elementos pares com coeficientes zeros. Eles serão modificados depois.
  for(int i = 0; i < tamanho_mult; i+=2){
    poli_mult[i] = 0;
  }

  int coeficiente = 0;
  int expoente_atual = 0;

  // Pega um expoente do polinomio X, encontra seu correspondente no polinômio Y.
  for(int i=1; i<tamanho_x; i+=2){
    for(int j=1; j<tamanho_y; j+=2){
      // Uma vez encontrado, os expoentes sao somados enquanto seus coeficientes sao multiplicados.
      coeficiente = poli_x[i-1] * poli_y[j-1];
      expoente_atual = poli_x[i] + poli_y[j];
      for(int k=1; k<tamanho_mult; k+=2){
        // Procura pelo coeficiente correspondente no polinômio resultado da multiplicação, e os coeficientes sao somados. Lembrar que sao inicializados em zero.
        if(expoente_atual == poli_mult[k]){
          poli_mult[k-1] += coeficiente;
        }
      }
    }
  }
  return poli_mult;
}



// Função especializada em imprimir polinomios da forma mais amigável possível.
int mostrar_poli(int poli[], int tamanho){
  setlocale(LC_ALL, "Portuguese");
  for(int i=0; i<tamanho; i+=2){

    // Imprime o primeiro elemento do polinômio.
    if(i==0 && poli[i]>0){
      printf("%d", poli[i]);
    }

    // No caso do coeficiente ser negativo, imprimir com o símbolo '-'. Multiplicar o coeficiente por -1 para que na hora da impressao nao fiquem 2 símbolos de negativo.
    if(poli[i]<0){
      printf(" - %d", poli[i]*-1);
    }

    // No caso do coeficiente ser positivo, imprimir com o símbolo '+'
    if(poli[i]>0 && i!=0){
      printf(" + %d", poli[i]);
    }

    // Imprime o x elevado ao expoente
    // Se o expoente for zero, nao há necessidade de imprimir
    if(poli[i+1]!=0 && poli[i] != 0){
      printf("*x^%d", poli[i+1]);
    }
  }
  printf("\n\n");
}