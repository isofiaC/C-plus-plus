#ifndef TP2_ASPERSOR_H
#define TP2_ASPERSOR_H
#include "Aparelho.h"
#include "../Propriedades/Humidade.h"
#include "../Propriedades/Vibracao.h"
#include "../Propriedades/Fumo.h"

class Aspersor: public Aparelho {
private:
    Humidade* humidade;
    Vibracao* vibracao;
    Fumo* fumo;
    static const int maxHumidade = 75;
    bool efeitoLigado;
    int instanteDesligado;

public:
    Aspersor(Humidade *humidade, Vibracao *vibracao, Fumo *fumo);
    void executarComando(string comando) override;
    string getLetra() override;
    void processarInstante() override;
    void imprimir(term::Window* window) override;
};


#endif //TP2_ASPERSOR_H
