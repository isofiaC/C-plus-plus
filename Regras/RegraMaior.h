#ifndef TP2_REGRAMAIOR_H
#define TP2_REGRAMAIOR_H
#include "Regra.h"

class RegraMaior: public Regra{
public:
    RegraMaior(Sensor *sensor, int parametro1);
    bool verificar() override;
    void imprimir(term::Window* window) override;
};


#endif //TP2_REGRAMAIOR_H
