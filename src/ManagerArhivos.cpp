//
// Created by Raquel on 20/6/2022.
//

#include "ManagerArhivos.h"

void ManagerArhivos::guardarArchivo(ManagerVentas *ventas, const string &nombreArchivo) {
string texto;
for(auto venta:ventas->getVentas() ){
    texto+= ventas->toString()+"\n";
}
ofstream archivo(nombreArchivo,ios_base::app);
archivo<<texto;
archivo.close();
}



string ManagerArhivos::leerArchivo(const string &nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if(!archivo.is_open()){
        throw invalid_argument("No se puede abrir este archivo");
    }
    string linea, texto;
    while (getline(archivo, linea)) {
        texto += linea+"\n";
    }
    archivo.close();

    return texto;
}
