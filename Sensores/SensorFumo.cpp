#include "SensorFumo.h"

SensorFumo::SensorFumo(Propriedade *propriedade) : Sensor(propriedade) {}

string SensorFumo::getLetra() {
    return "f";
}

void SensorFumo::imprimir(term::Window* window) {
    (*window) << "Tipo: S, ID: " << this->getId() << ", SensorFumo, Valor: " << this->getLeitura() << "\n";
}

void SensorFumo::imprimirNomeID(term::Window *window) {
    (*window) << "SensorFumo " << this->getId();
}