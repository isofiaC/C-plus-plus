#ifndef TP2_REGRAENTRE_H
#define TP2_REGRAENTRE_H
#include "Regra.h"

class RegraEntre: public Regra {
    int parametro2;

public:
    RegraEntre(Sensor *sensor, int parametro1, int parametro2);
    bool verificar() override;
    void imprimir(term::Window* window) override;
};


#endif //TP2_REGRAENTRE_H
