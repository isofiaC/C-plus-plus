#ifndef TP2_SENSORLUMINOSIDADE_H
#define TP2_SENSORLUMINOSIDADE_H
#include "Sensor.h"

class SensorLuminosidade: public Sensor {
public:
    SensorLuminosidade(Propriedade *propriedade);
    string getLetra() override;
    void imprimir(term::Window* window) override;
    void imprimirNomeID(term::Window* window) override;
};


#endif //TP2_SENSORLUMINOSIDADE_H
