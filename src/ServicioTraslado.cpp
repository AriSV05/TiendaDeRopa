
#include "ServicioTraslado.h"

ServicioTraslado::ServicioTraslado() = default;
ServicioTraslado::~ServicioTraslado() = default;

double ServicioTraslado::obtenerPrecioTraslado(string pais, string ciudad) {
double PrecioTraslado = 0;

string paisCodigo = obtenerCodigoPais(pais);
string ciudadCodigo = obtenerCodigoCiudad(ciudad);
string codigo = paisCodigo+"-"+ciudadCodigo;

    if (codigo == "0001-0001") {
        PrecioTraslado = 100;
    }
    else if (codigo == "0002-0002") {
        PrecioTraslado = 200;
    }
    else if (codigo == "0003-0003") {
        PrecioTraslado = 250;
    }
    else if (codigo == "0004-0004") {
        PrecioTraslado = 150;
    }
    else if (codigo == "0005-0005") {
        PrecioTraslado = 175;
    }
    else if (codigo == "0006-0006") {
        PrecioTraslado = 160;
    }
    else if (codigo == "0007-0007") {
        PrecioTraslado = 200;
    }
    else if (codigo == "0008-0009") {
        PrecioTraslado = 150;
    }
    else if(codigo == "0001-0008"){
        PrecioTraslado = 210;
    }

    return PrecioTraslado;
}



string ServicioTraslado::obtenerCodigoPais(string pais) {
    string paisCodigo = "0000";

    if (pais == "EE-UU") {
        paisCodigo = "0001";
    }
    else if (pais == "Francia") {
        paisCodigo = "0002";
    }
    else if (pais == "Italia") {
        paisCodigo =  "0003";
    }
    else if (pais == "Brasil") {
        paisCodigo = "0004";
    }
    else if (pais == "Argentina") {
        paisCodigo = "0005";
    }
    else if (pais == "Canadá") {
        paisCodigo = "0006";
    }
    else if (pais == "Inglaterra") {
        paisCodigo = "0007";
    }
    else if (pais == "Mexico") {
        paisCodigo = "0008";
    }

    return paisCodigo;
}

string ServicioTraslado::obtenerCodigoCiudad(string ciudad) {
    string ciudadCodigo = "0000";

    if (ciudad == "New York") {
        ciudadCodigo = "0001";
    }
    else if (ciudad == "Paris") {
        ciudadCodigo = "0002";
    }
    else if (ciudad == "Milán") {
        ciudadCodigo = "0003";
    }
    else if (ciudad == "Brasilia") {
        ciudadCodigo = "0004";
    }
    else if (ciudad == "Buenos Aires") {
        ciudadCodigo = "0005";
    }
    else if (ciudad == "Ontario") {
        ciudadCodigo = "0006";
    }
    else if (ciudad == "Londres") {
        ciudadCodigo = "0007";
    }
    else if (ciudad == "California") {
        ciudadCodigo = "0008";
    }
    else if(ciudad == "Monterrey"){
        ciudadCodigo = "0009";
    }

    return ciudadCodigo;
}


