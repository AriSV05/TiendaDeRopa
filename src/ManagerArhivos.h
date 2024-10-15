//
// Created by Raquel on 20/6/2022.
//

#ifndef PROGRA2_PROJECT_2_BRAVO_MANAGERARHIVOS_H
#define PROGRA2_PROJECT_2_BRAVO_MANAGERARHIVOS_H
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "ManagerVentas.h"
using namespace std;

class ManagerArhivos {
public:
    void guardarArchivo(ManagerVentas *ventas,const string& nombreArchivo);
    string leerArchivo(const string& nombreArchivo);

};


#endif //PROGRA2_PROJECT_2_BRAVO_MANAGERARHIVOS_H
