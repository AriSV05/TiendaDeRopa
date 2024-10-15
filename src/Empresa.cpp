
#include "Empresa.h"


Empresa::Empresa() {
    this->clienteFrecuente = true;
    setPagoSuscrip(400);
}

bool Empresa::isClienteFrecuente() const {
    return clienteFrecuente;
}

void Empresa::setClienteFrecuente(bool clienteFrecuente) {
    Empresa::clienteFrecuente = clienteFrecuente;
}

void Empresa::update(int stock) {
    std::cout<<"Hay disponible "<<stock<<" trajes en tienda\n\n";
}

string Empresa::toString() {
    std::stringstream ss;
    ss<<(*this);
    return ss.str();
}

std::ostream &operator<<(std::ostream &os, const Empresa &empresa) {
    os <<"[Empresa] "<<"nombre: " <<empresa.getNombre()<<" cedula juridica: "<<empresa.getCedula()
       <<" correo electronico: "<<empresa.getCorreoElec()<<" pago por suscripcion: "<<empresa.getPagoSuscrip()
       <<"$ anuales"<<" ciudad: "<<empresa.getCiudad()<<" pais: "<<empresa.getPais()<<" cliente frecuente: ";
        if(empresa.clienteFrecuente){
            os<<"si";
        }
        else{
            os<<"no";
        }

    return os;
}

