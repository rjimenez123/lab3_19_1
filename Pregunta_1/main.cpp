#include "my_lib.h"
#include "char_struct.h"

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <inttypes.h>

using namespace std;

int main(int argc, char** argv) {
    
//    struct_cadena cadena, cadena2;
//    inicializa(cadena, 10);
//    cout << "Capacidad de la cadena: " << capacidad(cadena) << endl;
//    leer(cadena, ',');
//    imprimir(cadena);
//    cout << endl << "Recortando..." << endl;
//    recortar(cadena);
//    imprimir(cadena);
//    cout << endl << "Leyendo cadena2..." << endl;
//    cadena = cadena2;
//    inicializa(cadena2, 20);
//    leer(cadena2, '\n');
//    imprimir(cadena2);
//    cout << endl << "Intercambiando..." << endl;
//    intercambiar(cadena, cadena2);
//    cout << "Cadena1:" << endl;
//    imprimir(cadena);
//    cout << "Cadena2:" << endl;
//    imprimir(cadena2);
    
//    struct_cadena cadena, cadena2;
//    leer(cadena, ',');
//    cadena = cadena2;
//    cout << "Cadena1:" << endl;
//    imprimir(cadena);
//    cout << "Cadena2:" << endl;
//    imprimir(cadena2);
    
    cout << "AAAAAAH" << endl;
    struct_cadena cadena;
    struct_cadena cadena2;
    leer(cadena, ',');
    leer(cadena2, ',');
    cout << "Cadena1:" << endl;
    imprimir(cadena);
    cout << endl;
    cadena += cadena2;
    cout << "Cadena1:" << endl;
    imprimir(cadena);
    cout << "Cadena2:" << endl;
    imprimir(cadena2);
    return 0;
}

