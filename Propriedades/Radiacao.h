#ifndef TP2_RADIACAO_H
#define TP2_RADIACAO_H
#include "Propriedade.h"

class Radiacao:public Propriedade {
    static const int minValor = 0;
public:
    Radiacao(int valor);
    string actualizaValor(int valor) override;
    void modificaValor(int valor) override;
};

#endif //TP2_RADIACAO_H
