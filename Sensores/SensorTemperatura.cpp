#include "SensorTemperatura.h"

SensorTemperatura::SensorTemperatura(Propriedade *propriedade) : Sensor(propriedade) {}

string SensorTemperatura::getLetra() {
    return "t";
}

void SensorTemperatura::imprimir(term::Window* window) {
    (*window) << "Tipo: S, ID: " << this->getId() << ", SensorTemperatura, Valor: " << this->getLeitura() << "\n";
}

void SensorTemperatura::imprimirNomeID(term::Window *window) {
    (*window) << "SensorTemperatura " << this->getId();
}