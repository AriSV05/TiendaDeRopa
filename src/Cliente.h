
#ifndef PROGRA2_PROJECT_2_BRAVO_CLIENTE_H
#define PROGRA2_PROJECT_2_BRAVO_CLIENTE_H
#include "IObserver.h"

class Cliente : public IObserver{

private:
    string nombre;
    string cedula;
    string correoElec;
    double pagoSuscrip;
    string ciudad;
    string pais;

public:

    Cliente();

    virtual ~Cliente();

    const string &getCorreoElec() const;
    void setCorreoElec(const string &correoElec);
    double getPagoSuscrip() const;
    void setPagoSuscrip(double pagoSuscrip);
    const string &getCiudad() const;
    void setCiudad(const string &ciudad);
    const string &getPais() const;
    void setPais(const string &pais);
    const string &getNombre() const;
    void setNombre(const string &nombre);
    const string &getCedula() const;
    void setCedula(const string &cedula);

    void update(int) override;

    virtual string toString();

};


#endif //PROGRA2_PROJECT_2_BRAVO_CLIENTE_H
