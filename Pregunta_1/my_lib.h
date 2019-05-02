#ifndef MY_LIB_H
#define MY_LIB_H

#include "char_struct.h"
#include <iostream>

using namespace std;

void inicializa(struct_cadena&);
void inicializa(struct_cadena&, int);
void leer(struct_cadena&, char); 
void imprimir(struct_cadena);
int longitud(struct_cadena);
int capacidad(struct_cadena);
void recortar(struct_cadena&);
void intercambiar(struct_cadena&, struct_cadena&);

//struct_cadena& operator=(struct_cadena);
void operator+=(struct_cadena&, struct_cadena);

#endif /* MY_LIB_H */
