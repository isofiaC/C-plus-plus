#ifndef TP2_SENSORHUMIDADE_H
#define TP2_SENSORHUMIDADE_H
#include "Sensor.h"

class SensorHumidade: public Sensor{
public:
    SensorHumidade(Propriedade *propriedade);
    string getLetra() override;
    void imprimir(term::Window* window) override;
    void imprimirNomeID(term::Window* window) override;
};



#endif //TP2_SENSORHUMIDADE_H
