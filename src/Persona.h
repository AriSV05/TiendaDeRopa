
#ifndef II_PERSONA_H
#define II_PERSONA_H

#include <ostream>
#include "Cliente.h"


class Persona : public Cliente{

private:
    string nacionalidad;

public:
    Persona();

    const string &getNacionalidad() const;
    void setNacionalidad(const string &nacionalidad);

    friend std::ostream &operator<<(std::ostream &os, const Persona &persona);

    void update(int) override; //TODO
    string toString() override;

};


#endif //II_PERSONA_H
