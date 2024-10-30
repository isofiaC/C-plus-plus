#ifndef TP2_SENSORSOM_H
#define TP2_SENSORSOM_H
#include "Sensor.h"

class SensorSom: public Sensor {
public:
    SensorSom(Propriedade *propriedade);
    string getLetra() override;
    void imprimir(term::Window* window) override;
    void imprimirNomeID(term::Window* window) override;
};

#endif //TP2_SENSORSOM_H
