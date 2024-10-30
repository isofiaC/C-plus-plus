#ifndef TP2_REGRAMENOR_H
#define TP2_REGRAMENOR_H
#include "Regra.h"

class RegraMenor : public Regra {
public:
    RegraMenor(Sensor *sensor, int parametro1);
    bool verificar() override;
    void imprimir(term::Window* window) override;
};


#endif //TP2_REGRAMENOR_H
