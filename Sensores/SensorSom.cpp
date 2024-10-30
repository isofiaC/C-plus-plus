#include "SensorSom.h"

SensorSom::SensorSom(Propriedade *propriedade) : Sensor(propriedade) {}

string SensorSom::getLetra() {
    return "o";
}

void SensorSom::imprimir(term::Window* window) {
    (*window) << "Tipo: S, ID: " << this->getId() << ", SensorSom, Valor: " << this->getLeitura() << "\n";
}

void SensorSom::imprimirNomeID(term::Window *window) {
    (*window) << "SensorSom " << this->getId();
}