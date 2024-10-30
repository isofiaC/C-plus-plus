#include "Aparelho.h"

Aparelho::Aparelho() : ligado(false), instante(0), ultimoComando(""), Componente() {}

bool Aparelho::isLigado() const {
    return ligado;
}

void Aparelho::setLigado(bool ligado) {
    Aparelho::ligado = ligado;
}

int Aparelho::getInstante() const {
    return instante;
}

void Aparelho::setInstante(int instante) {
    Aparelho::instante = instante;
}

const string &Aparelho::getUltimoComando() const {
    return ultimoComando;
}

void Aparelho::setUltimoComando(const string &ultimoComando) {
    Aparelho::ultimoComando = ultimoComando;
}

Aparelho::~Aparelho() {

}


