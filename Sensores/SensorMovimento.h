#ifndef TP2_SENSORMOVIMENTO_H
#define TP2_SENSORMOVIMENTO_H
#include "Sensor.h"

using namespace std;

class SensorMovimento: public Sensor{
public:
    SensorMovimento(Propriedade* propriedade);
    string getLetra() override;
    void imprimir(term::Window* window) override;
    void imprimirNomeID(term::Window* window) override;
};

#endif //TP2_SENSORMOVIMENTO_H
