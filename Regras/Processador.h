#ifndef TP_PROCESSADOR_H
#define TP_PROCESSADOR_H
#include <vector>
#include "Regra.h"
#include "../Aparelhos/Aparelho.h"
#include "../Componente.h"

using namespace std;

class ProcessadorRegras: public Componente{
private:
    vector<Regra *> regras; //composicao
    vector <Aparelho*> aparelhos; //agregacao
    string comando;

public:
    ProcessadorRegras(const string &comando);
    void adicionarRegra(Regra* regra);
    void processarRegras();
    void removeRegra(int id);
    void adicionaAparelho(Aparelho* aparelho);
    void removeAparelho(int id);
    void imprimir(term::Window* window);
    void imprimirRegras(term::Window* window);
    void setComando(const string &comando);
    ~ProcessadorRegras();
};

#endif //TP_PROCESSADOR_H
