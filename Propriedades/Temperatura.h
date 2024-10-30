#ifndef TP2_TEMPERATURA_H
#define TP2_TEMPERATURA_H
#include "Propriedade.h"

class Temperatura: public Propriedade {
    static const int minValor = -273;

public:
    Temperatura(int valor);
    string actualizaValor(int valor) override;
    void modificaValor(int valor) override;
};


#endif //TP2_TEMPERATURA_H
