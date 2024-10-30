#ifndef TP2_FUMO_H
#define TP2_FUMO_H
#include "Propriedade.h"

class Fumo: public Propriedade{
    static const int minValor = 0;
    static const int maxValor = 100;

public:
    Fumo(int valor);
    string actualizaValor(int valor) override;
    void modificaValor(int valor) override;
};


#endif //TP2_FUMO_H
