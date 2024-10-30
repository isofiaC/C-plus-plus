#ifndef TP2_VIBRACAO_H
#define TP2_VIBRACAO_H
#include "Propriedade.h"

class Vibracao: public Propriedade {
    static const int minValor = 0;

public:
    Vibracao(int valor);
    string actualizaValor(int valor) override;
    void modificaValor(int valor) override;
};

#endif //TP2_VIBRACAO_H
