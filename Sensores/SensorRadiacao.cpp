#include "SensorRadiacao.h"

SensorRadiacao::SensorRadiacao(Propriedade *propriedade) : Sensor(propriedade) {}

string SensorRadiacao::getLetra() {
    return "d";
}

void SensorRadiacao::imprimir(term::Window* window) {
    (*window) << "Tipo: S, ID: " << this->getId() << ", SensorRadiacao, Valor: " << this->getLeitura() << "\n";
}

void SensorRadiacao::imprimirNomeID(term::Window *window) {
    (*window) << "SensorRadiacao " << this->getId();
}
