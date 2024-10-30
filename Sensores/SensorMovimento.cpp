#include "SensorMovimento.h"

SensorMovimento::SensorMovimento(Propriedade *propriedade) : Sensor(propriedade) {}

string SensorMovimento::getLetra() {
    return "v";
}

void SensorMovimento::imprimir(term::Window* window) {
    (*window) << "Tipo: S, ID: " << this->getId() << ", SensorMovimento, Valor: " << this->getLeitura() << "\n";
}

void SensorMovimento::imprimirNomeID(term::Window *window) {
    (*window) << "SensorMovimento " << this->getId();
}