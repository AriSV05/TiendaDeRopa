
#ifndef PROGRA2_PROJECT_2_BRAVO_JEANS_H
#define PROGRA2_PROJECT_2_BRAVO_JEANS_H

#include "PantalonAbstr.h"

class Jeans : public PantalonAbstr{

private:
    bool ajustado;

public:
    Jeans(double precio, const string &color, const string &talla, bool ajustado);

    virtual ~Jeans();

    bool isAjustado() const;
    void setAjustado(bool ajustado);

    string toString() override;
    friend std::ostream &operator<<(std::ostream &os, const Jeans &jeans);
};


#endif //PROGRA2_PROJECT_2_BRAVO_JEANS_H
