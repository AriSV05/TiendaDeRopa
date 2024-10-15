
#include "ManagerArchivos.h"

void ManagerArchivos::save(string fileName, ManagerVentas ventas_) {

    std::ofstream myFile(fileName, std::ios::out);
    for(auto vent : ventas_.getVentas()){
        myFile<<vent->getGanacia()<<',';
        myFile<<vent->getCodTrajeVendido()<<',';
        myFile<<vent->getPrecioTraje()<<',';
        myFile<<vent->getComprador()->getCedula()<<',';
        myFile<<vent->getComprador()->getNombre()<<',';
        myFile<<vent->getComprador()->getCorreoElec()<<',';
        myFile<<vent->getComprador()->getPais()<<',';
        myFile<<vent->getComprador()->getCiudad();
        myFile<<'\n';
    }
}

string ManagerArchivos::read(string fileName) {

    Cliente client;

    std::vector<string> temp;
    std::ifstream myFile(fileName);
    string linea, text;

    if(!myFile.is_open()){
        throw std::invalid_argument("El archivo esta cerrado");
    }
    while (std::getline(myFile, linea,'\n')) {
        text += linea + "\n";
    }
    return text;
}

const ManagerVentas &ManagerArchivos::getVentas() const {
    return ventas;
}

void ManagerArchivos::setVentas(const ManagerVentas &ventas) {
    ManagerArchivos::ventas = ventas;
}
