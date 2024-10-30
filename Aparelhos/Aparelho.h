#ifndef TP_APARELHO_H
#define TP_APARELHO_H
#include <iostream>
#include "../Componente.h"
#include "../Terminal.h"

using namespace std;

class Aparelho: public Componente{
private:
    bool ligado;
    int instante;
    string ultimoComando;
public:
    Aparelho();
    virtual void executarComando(string comando) = 0;
    virtual string getLetra() = 0;
    virtual void processarInstante() = 0;
    virtual void imprimir(term::Window* window) = 0;
    bool isLigado() const;
    void setLigado(bool ligado);
    int getInstante() const;
    void setInstante(int instante);
    const string &getUltimoComando() const;
    void setUltimoComando(const string &ultimoComando);
    virtual ~Aparelho();

};

#endif //TP_APARELHO_H
