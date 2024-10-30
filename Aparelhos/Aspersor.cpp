#include "Aspersor.h"

Aspersor::Aspersor(Humidade *humidade, Vibracao *vibracao, Fumo *fumo) : humidade(humidade), vibracao(vibracao),
                                                                         fumo(fumo), efeitoLigado(false), instanteDesligado(-1), Aparelho() {}

void Aspersor::executarComando(std::string comando) {
    this->setUltimoComando(comando);

    if (comando == "liga") {
        if (!isLigado()) {
            if (!efeitoLigado) {
                setInstante(0);
                instanteDesligado = -1;

                vibracao->modificaValor(100);

                if(humidade->getValor() + 50 > maxHumidade)
                    humidade->setValor(maxHumidade);
                else
                    humidade->modificaValor(50);
            }

            setLigado(true);
            efeitoLigado = true;
        }
    } else if (comando == "desliga") {
        if (isLigado()) {
            instanteDesligado = getInstante();
            setLigado(false);
        }
    }
    //Possivel adicionar else com erro
}

string Aspersor::getLetra() {
    if (isLigado()) {
        return "S";
    }

    return "s";
}


void Aspersor::processarInstante() {
    if (efeitoLigado) {
        setInstante(getInstante() + 1);

        if (getInstante() == 2) {
            fumo->setValor(0);
        }

        if (!isLigado()) {
            if (getInstante() - instanteDesligado == 5) {
                //Ao Desligar
                efeitoLigado = false;
                vibracao->modificaValor(-100);
            }
        }
    }
}

void Aspersor::imprimir(term::Window* window) {
    (*window) << "Tipo: A, ID: " << this->getId() << ", Aspersor, U_CMD: " << this->getUltimoComando() << "\n";
}