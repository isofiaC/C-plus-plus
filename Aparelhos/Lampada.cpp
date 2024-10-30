#include "Lampada.h"

Lampada::Lampada(Luz *luz) : luz(luz), Aparelho() {}

void Lampada::executarComando(std::string comando) {
    this->setUltimoComando(comando);

    if (comando == "liga") {
        if (!isLigado()) {
            setLigado(true);
            luz->modificaValor(900);
        }
    } else if (comando == "desliga") {
        if (isLigado()) {
            setLigado(false);
            luz->modificaValor(-900);
        }
    }
}

string Lampada::getLetra() {
    if (isLigado()) {
        return "L";
    }
    return "l";
}

void Lampada::processarInstante() {}

void Lampada::imprimir(term::Window* window) {
    (*window) << "Tipo: A, ID: " << this->getId() << ", Lampada, U_CMD: " << this->getUltimoComando() << "\n";
}