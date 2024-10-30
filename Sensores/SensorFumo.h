#ifndef TP2_SENSORFUMO_H
#define TP2_SENSORFUMO_H
#include "Sensor.h"

class SensorFumo: public Sensor{
public:
    SensorFumo(Propriedade *propriedade);
    string getLetra() override;
    void imprimir(term::Window* window) override;
    void imprimirNomeID(term::Window* window) override;
};


#endif //TP2_SENSORFUMO_H
