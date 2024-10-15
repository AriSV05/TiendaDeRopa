
#ifndef PROGRA2_PROJECT_2_BRAVO_DEVESTIR_H
#define PROGRA2_PROJECT_2_BRAVO_DEVESTIR_H

#include "PantalonAbstr.h"

class DeVestir : public  PantalonAbstr{

private:
    bool casimir;

public:
    DeVestir(double precio, const string &color, const string &talla, bool casimir);

    virtual ~DeVestir();

    bool isCasimir() const;
    void setCasimir(bool casimir);

    string toString() override;

    friend std::ostream &operator<<(std::ostream &os, const DeVestir &vestir);
};


#endif //PROGRA2_PROJECT_2_BRAVO_DEVESTIR_H
