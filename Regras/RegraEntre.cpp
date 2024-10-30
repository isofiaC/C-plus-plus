#include "RegraEntre.h"

RegraEntre::RegraEntre(Sensor *sensor, int parametro1, int parametro2) : Regra(sensor, parametro1),
                                                                         parametro2(parametro2) {}

bool RegraEntre::verificar() {
    int valor = getSensor()->getLeitura();

    return valor > getParametro1() && valor < parametro2;
}

void RegraEntre::imprimir(term::Window *window) {
    (*window) << "RegraEntre " << this->getId() << ", ";
    this->getSensor()->imprimirNomeID(window);
    (*window) << "\n";
}