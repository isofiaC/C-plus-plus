#include "SensorHumidade.h"

SensorHumidade::SensorHumidade(Propriedade *propriedade) : Sensor(propriedade) {}

string SensorHumidade::getLetra() {
    return "h";
}

void SensorHumidade::imprimir(term::Window* window) {
    (*window) << "Tipo: S, ID: " << this->getId() << ", SensorHumidade, Valor: " << this->getLeitura() << "\n";
}

void SensorHumidade::imprimirNomeID(term::Window *window) {
    (*window) << "SensorHumidade " << this->getId();
}