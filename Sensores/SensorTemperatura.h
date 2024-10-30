#ifndef TP2_SENSORTEMPERATURA_H
#define TP2_SENSORTEMPERATURA_H
#include "Sensor.h"

class SensorTemperatura: public Sensor{
public:
    SensorTemperatura(Propriedade* propriedade);
    string getLetra() override;
    void imprimir(term::Window* window) override;
    void imprimirNomeID(term::Window* window) override;
};


#endif //TP2_SENSORTEMPERATURA_H
