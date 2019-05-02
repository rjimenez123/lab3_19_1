#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

#include "my_lib.h"
#include "char_struct.h"

void inicializa(struct_cadena &cadena) {
    cadena.cad = NULL;
    cadena.capacidad = cadena.longitud = 0;
}

void inicializa(struct_cadena& cadena, int cap) {
    cadena.cad = new char[cap+1]; // adicional para colocar el caracter null '\0' al final de la cadena
    cadena.capacidad = cap;
    cadena.longitud = 0;
}

void leer(struct_cadena& cadena, char delim = '\n') {
    cin.clear();
    char buff[100], numChars = 0, c;
    while(1) {
        c = cin.peek();
        if (c == delim)
            break;
        if (c == EOF)
            return;
        buff[numChars] = getchar();
        numChars++;
    }
    c = getchar();
    
    if (numChars <= cadena.capacidad) {
        cadena.longitud = numChars;
        for (int i = 0; i < numChars; i++)
            cadena.cad[i] = buff[i];
        cadena.cad[numChars] = '\0'; 
    } else {
        cadena.cad = new char[numChars+1];
        cadena.capacidad = cadena.longitud = numChars;
        for (int i = 0; i < numChars; i++)
            cadena.cad[i] = buff[i];
        cadena.cad[numChars] = '\0';
    }
}

void imprimir(struct_cadena cadena) {
    cout << "IMPRESION DE LA CADENA:\n" << "LONGITUD: " << setw(6) << cadena.longitud << "  CAPACIDAD:" << setw(6) << cadena.capacidad << endl;
    cout << "CARACTERES: " << cadena.cad << endl;
    
}

int longitud(struct_cadena cadena) {
    return cadena.longitud;
}
int capacidad(struct_cadena cadena) {
    return cadena.capacidad;
}

void recortar(struct_cadena& cadena) {
    bool is_first_blank = true;
    char buff[cadena.longitud+1];
    
    int buff_i = 0;
    for (int i = 0; i < cadena.longitud; i++) {
        if (cadena.cad[i] == ' ' || cadena.cad[i] == '\t' || cadena.cad[i] == '\n') {
            if (is_first_blank) {
                buff[buff_i] = cadena.cad[i];
                buff_i++;
                is_first_blank = false;
            } 
        } else {
            if (i > 0 && isblank(cadena.cad[i-1]))
                is_first_blank = true;
            buff[buff_i] = cadena.cad[i];
            buff_i++;
        } 
    }
    
    if (buff_i == cadena.longitud)
        return;
    
    cadena.longitud = buff_i;
    for (int i = 0; i < cadena.longitud; i++)
        cadena.cad[i] = buff[i];
    cadena.cad[cadena.longitud] = '\0';
    
    int index = cadena.longitud-1;
    while(cadena.cad[index] == '\n' || cadena.cad[index] == ' ' || cadena.cad[index] == '\t' ) 
        index--;
    cadena.longitud = index+1;
    cadena.cad[index+1] = '\0';
}

void intercambiar(struct_cadena& cadena1, struct_cadena& cadena2) {
    char* temp = cadena1.cad;
    int aux_longitud = cadena1.longitud, aux_capacidad = cadena1.capacidad;
    
    cadena1.cad = cadena2.cad;
    cadena1.longitud = cadena2.longitud;
    cadena1.capacidad = cadena2.capacidad;
    
    cadena2.cad = temp;
    cadena2.longitud = aux_longitud;
    cadena2.capacidad = aux_capacidad;
}

//struct_cadena& operator=(struct_cadena source) {
//    struct_cadena dest;
//    dest.cad = new char[source.capacidad+1];
//    dest.capacidad = source.capacidad;
//    dest.longitud = source.longitud;
//    for (int i = 0; i < dest.longitud; i++)
//        dest.cad[i] = source.cad[i];
//    dest.cad[dest.longitud] = '\0';
//    return &dest;
//}

void operator+=(struct_cadena& dest, struct_cadena src) {
    int total_chars = dest.longitud + src.longitud;
    if (total_chars <= dest.capacidad) {
        for (int i = 0; i < src.longitud; i++) {
            dest.cad[dest.longitud] = src.cad[i];
            dest.longitud++;
        }
    } else {
        char aux[total_chars+1];
        strcpy(aux, dest.cad);
        delete[] dest.cad;
        dest.cad = new char[total_chars+1];
        strcpy(dest.cad, aux);
        
        dest.capacidad = total_chars;
        
        for (int i = 0; i < src.longitud; i++) {
            dest.cad[dest.longitud] = src.cad[i];
            dest.longitud++;
        }
    }
}