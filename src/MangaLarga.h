
#ifndef PROYECTO_2_MANGALARGA_H
#define PROYECTO_2_MANGALARGA_H

#include <ostream>
#include "CamisAbstr.h"

class MangaLarga: public CamisAbstr {
private:
    bool lisa;

public:
    MangaLarga(double precio, const string &color, const string &talla, bool lisa);

    ~MangaLarga() override;

    bool isLisa() const;
    void setLisa(bool lisa);

    string toString() override;

    friend std::ostream &operator<<(std::ostream &os, const MangaLarga &larga);
};


#endif //PROYECTO_2_MANGALARGA_H
