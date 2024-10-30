#ifndef TP2_HUMIDADE_H
#define TP2_HUMIDADE_H
#include "Propriedade.h"

class Humidade: public Propriedade{
    static const int minValor = 0;
    static const int maxValor = 100;

public:
    Humidade(int valor);
    string actualizaValor(int valor) override;
    void modificaValor(int valor) override;
};


#endif //TP2_HUMIDADE_H
