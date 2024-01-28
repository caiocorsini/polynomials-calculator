#ifndef _poliCaio

#define _poliCaio

#include <stdio.h>
#include <math.h> 
#include <locale.h>

int adic_poli(int poli_x[], int tamanho_x, int poli_y[], int tamanho_y, int poli_soma[], int tamanho_soma);

int resol_poli(int poli[], int tamanho, int valor);

int mult_poli(int poli_x[], int tamanho_x, int poli_y[], int tamanho_y, int poli_mult[], int tamanho_mult);

int mostrar_poli(int poli[], int tamanho);

#endif