#ifndef TP2_SENSORRADIACAO_H
#define TP2_SENSORRADIACAO_H
#include "Sensor.h"

class SensorRadiacao: public Sensor {
public:
    SensorRadiacao(Propriedade* propriedade);
    string getLetra() override;
    void imprimir(term::Window* window) override;
    void imprimirNomeID(term::Window* window) override;
};


#endif //TP2_SENSORRADIACAO_H
