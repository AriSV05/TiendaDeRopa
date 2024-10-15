
#include "Persona.h"

Persona::Persona() {
    this->nacionalidad = "";
    setPagoSuscrip(200);
}

const string &Persona::getNacionalidad() const {
    return nacionalidad;
}

void Persona::setNacionalidad(const string &nacionalidad) {
    Persona::nacionalidad = nacionalidad;
}

void Persona::update(int stock) {
    std::cout<<"Hay disponible "<<stock<<" trajes en tienda\n\n";
}

string Persona::toString() {
    std::stringstream ss;
    ss<<(*this);
    return ss.str();
}

std::ostream &operator<<(std::ostream &os, const Persona &persona) {
    os <<"[Persona] "<<"nombre: " <<persona.getNombre()<<" cedula fisica: "<<persona.getCedula()
    <<" correo electronico: "<<persona.getCorreoElec()<<" pago por suscripcion: "<<persona.getPagoSuscrip()
    <<"$ anuales"<<" nacionalidad: " << persona.nacionalidad<<""<<" ciudad: "<<persona.getCiudad()
    <<" pais: "<<persona.getPais();
    return os;
}
