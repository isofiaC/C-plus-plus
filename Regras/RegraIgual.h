#ifndef TP2_REGRAIGUAL_H
#define TP2_REGRAIGUAL_H
#include "Regra.h"

class RegraIgual: public Regra{
public:
    RegraIgual(Sensor *sensor, int parametro1);
    bool verificar() override;
    void imprimir(term::Window* window) override;
};


#endif //TP2_REGRAIGUAL_H
