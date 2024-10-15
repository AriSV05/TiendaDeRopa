
#ifndef PROGRA2_PROJECT_2_BRAVO_SERVICIOTRASLADO_H
#define PROGRA2_PROJECT_2_BRAVO_SERVICIOTRASLADO_H

#include <iostream>
using std::string;

class ServicioTraslado {

public:
    ServicioTraslado();
    virtual ~ServicioTraslado();

    static double obtenerPrecioTraslado(string pais, string ciudad);
    static string obtenerCodigoPais(string pais);
    static string obtenerCodigoCiudad(string ciudad);

};


#endif //PROGRA2_PROJECT_2_BRAVO_SERVICIOTRASLADO_H
