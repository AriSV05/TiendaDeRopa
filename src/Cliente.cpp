
#include "Cliente.h"


Cliente::Cliente() {
    this->nombre = "";
    this->cedula = "";
    this->correoElec = "";
    this->pagoSuscrip = 0;
    this->ciudad = "";
    this->pais = "";
}

const string &Cliente::getCorreoElec() const {
    return correoElec;
}

void Cliente::setCorreoElec(const string &correoElec) {
    Cliente::correoElec = correoElec;
}

double Cliente::getPagoSuscrip() const {
    return pagoSuscrip;
}

void Cliente::setPagoSuscrip(double pagoSuscrip) {
    Cliente::pagoSuscrip = pagoSuscrip;
}

const string &Cliente::getCiudad() const {
    return ciudad;
}

void Cliente::setCiudad(const string &ciudad) {
    Cliente::ciudad = ciudad;
}

const string &Cliente::getPais() const {
    return pais;
}

void Cliente::setPais(const string &pais) {
    Cliente::pais = pais;
}

const string &Cliente::getNombre() const {
    return nombre;
}

void Cliente::setNombre(const string &nombre) {
    Cliente::nombre = nombre;
}

const string &Cliente::getCedula() const {
    return cedula;
}

void Cliente::setCedula(const string &cedula) {
    Cliente::cedula = cedula;
}

Cliente::~Cliente() {

}

void Cliente::update(int stock) {
    std::cout<<"Hay disponible "<<stock<<" trajes en tienda\n\n";

}

string Cliente::toString() {
    return std::string();
}

