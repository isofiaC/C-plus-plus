#include "Sensor.h"

Sensor::Sensor(Propriedade *propriedade): Componente() {
    this->propriedade = propriedade;
}

int Sensor::getLeitura() {
    return propriedade->getValor();
}

Sensor::~Sensor() {

}


