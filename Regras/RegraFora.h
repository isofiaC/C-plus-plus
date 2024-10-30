#ifndef TP2_REGRAFORA_H
#define TP2_REGRAFORA_H
#include "Regra.h"

class RegraFora: public Regra {
    int parametro2;
public:
    RegraFora(Sensor *sensor, int parametro1, int parametro2);
    bool verificar() override;
    void imprimir(term::Window* window) override;
};


#endif //TP2_REGRAFORA_H
