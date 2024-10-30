#include "Zona.h"

int idZona = 0; // gerar numero automatico automatico para o id

Zona::Zona(term::Window *window) : window(window) {
    id = ++idZona;
    //Inicializar todas as propriedades
    propriedades["temperatura"] = new Temperatura(20);
    propriedades["luz"] = new Luz(1000);
    propriedades["radiacao"] = new Radiacao(10);
    propriedades["vibracao"] = new Vibracao(50);
    propriedades["humidade"] = new Humidade(20);
    propriedades["fumo"] = new Fumo(10);
    propriedades["som"] = new Som(30);
}

void Zona::add(Sensor *sensor) {
    sensores.push_back(sensor);
}

void Zona::add(ProcessadorRegras *processador) {
    processadores.push_back(processador);
}

void Zona::add(Aparelho *aparelho) {
    aparelhos.push_back(aparelho);
}

Propriedade *Zona::getPropriedade(std::string chave) {
    for(auto it = propriedades.begin(); it != propriedades.end(); ++it) {
        if (it->first == chave) {
            return it->second;
        }
    }

    return nullptr;
}

Sensor *Zona::getSensor(int id) {
    for (Sensor *sensor: sensores) {
        if (sensor->getId() == id) {
            return sensor;
        }
    }

    return nullptr;
}

ProcessadorRegras *Zona::getProcessadorRegras(int id) {
    for (ProcessadorRegras *processador: processadores) {
        if (processador->getId() == id) {
            return processador;
        }
    }

    return nullptr;
}

Aparelho *Zona::getAparelho(int id) {
    for (Aparelho *aparelho: aparelhos) {
        if (aparelho->getId() == id) {
            return aparelho;
        }
    }

    return nullptr;
}

void Zona::removeSensor(int id) {
    for (int i = 0; i < sensores.size(); i++) {
        if (sensores[i]->getId() == id) {
            delete sensores[i];
            sensores.erase(sensores.begin() + i);
            break;
        }
    }
}

void Zona::removeProcessadorRegras(int id) {
    for (int i = 0; i < processadores.size(); i++) {
        if (processadores[i]->getId() == id) {
            delete processadores[i];
            processadores.erase(processadores.begin() + i);
            break;
        }
    }
}

void Zona::removeAparelho(int id) {
    for (int i = 0; i < aparelhos.size(); i++) {
        if (aparelhos[i]->getId() == id) {
            delete aparelhos[i];
            aparelhos.erase(aparelhos.begin() + i);
            break;
        }
    }
}

void Zona::processarInstante() {
    for (ProcessadorRegras* processador: processadores) {
        processador->processarRegras();
    }
    for (Aparelho* aparelho: aparelhos) {
        aparelho->processarInstante();
    }
}

void Zona::desenhaZona() {
    (*window) << "ID" << id;
    for (auto it = propriedades.begin(); it != propriedades.end(); ++it) {
        //Imprime a primeira letra da chave da propriedade seguida do seu valor, i.e. t23 l100
        (*window) << " " << it->first[0] << it->second->getValor();
    }
    (*window) << "\nS: ";
    for (Sensor* sensor:  sensores) {
        (*window) << sensor->getLetra();
    }
    (*window) << "\nA: ";
    for (Aparelho* aparelho:  aparelhos) {
        (*window) << aparelho->getLetra();
    }
}

Zona::~Zona() {
    for (auto it = propriedades.begin(); it != propriedades.end(); ++it) {
        delete it->second;
    }
    propriedades.clear();
    for (int i = 0; i < aparelhos.size(); i++) {
        delete aparelhos[i];
    };
    aparelhos.clear();
    for (int i = 0; i < sensores.size(); i++) {
        delete sensores[i];
    };
    sensores.clear();
    for (int i = 0; i < processadores.size(); i++) {
        delete processadores[i];
    };
    processadores.clear();
}

int Zona::getId() const {
    return id;
}

void Zona::imprimir(term::Window *window) {
    (*window) << "ID: " << id << "; Sensores: " << to_string(sensores.size()) << "; Processadores: "
              << to_string(processadores.size()) << "; Aparelhos: " << to_string(aparelhos.size()) << "\n";
}

void Zona::imprimirComponentes(term::Window *window) {
    for (Aparelho *aparelho: aparelhos) {
        aparelho->imprimir(window);
    }
    for (ProcessadorRegras *processador: processadores) {
        processador->imprimir(window);
    }
    for (Sensor *sensor: sensores) {
        sensor->imprimir(window);
    }
}

void Zona::imprimirPropriedades(term::Window *window) {
    for (auto it = propriedades.begin(); it != propriedades.end(); ++it) {
        (*window) << it->first << ": " << it->second->getValor() << "\n";
    }
}