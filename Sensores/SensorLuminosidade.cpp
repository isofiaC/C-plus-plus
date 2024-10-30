#include "SensorLuminosidade.h"

SensorLuminosidade::SensorLuminosidade(Propriedade *propriedade) : Sensor(propriedade) {}

string SensorLuminosidade::getLetra() {
    return "m";
}

void SensorLuminosidade::imprimir(term::Window* window) {
    (*window) << "Tipo: S, ID: " << this->getId() << ", SensorLuminosidade, Valor: " << this->getLeitura() << "\n";
}

void SensorLuminosidade::imprimirNomeID(term::Window *window) {
    (*window) << "SensorLuminosidade " << this->getId();
}