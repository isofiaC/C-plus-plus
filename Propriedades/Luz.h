#ifndef TP2_LUZ_H
#define TP2_LUZ_H
#include "Propriedade.h"

class Luz: public Propriedade{
    static const int minValor = 0;

public:
    Luz(int valor);
    string actualizaValor(int valor) override;
    void modificaValor(int valor) override;
};


#endif //TP2_LUZ_H
