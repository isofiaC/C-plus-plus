#ifndef TP2_SOM_H
#define TP2_SOM_H
#include "Propriedade.h"

class Som: public Propriedade {
    static const int minValor = 0;

public:
    Som(int valor);
    string actualizaValor(int valor) override;
    void modificaValor(int valor) override;
};


#endif //TP2_SOM_H
