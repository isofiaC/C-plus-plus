#include "Simulador.h"

Simulador::Simulador() {}

void Simulador::executar() {
    string str_cmd;

    // Atribuir nullptr para fácil identificação
    habitacao = nullptr;

    while (true) {
        Terminal &t = Terminal::instance();

        t.clear();

        //posições e dimensões das várias janelas
        int xCmd = 0, yCmd = 24, hCmd = 6, wCmd = 120, xInfo = 0, yInfo = 0, hInfo = 24, wInfo = 32;
        Window win_cmd = t.create_window(xCmd, yCmd, wCmd, hCmd, true);
        Window win_info = t.create_window(xInfo, yInfo, wInfo, hInfo, true);

        // 88*24 de sobra
        // cada retangulo / zona 22*6

        int wZona = 22, hZona = 6;

        Window windows[4][4] = {
                {
                        t.create_window(wInfo, 0, wZona, hZona, true),
                        t.create_window(wInfo + wZona, 0, wZona, hZona, true),
                        t.create_window(wInfo + wZona * 2, 0, wZona, hZona, true),
                        t.create_window(wInfo + wZona * 3, 0, wZona, hZona, true)
                },
                {
                        t.create_window(wInfo, hZona, wZona, hZona, true),
                        t.create_window(wInfo + wZona, hZona, wZona, hZona, true),
                        t.create_window(wInfo + wZona * 2, hZona, wZona, hZona, true),
                        t.create_window(wInfo + wZona * 3, hZona, wZona, hZona, true)
                },
                {
                        t.create_window(wInfo, hZona * 2, wZona, hZona, true),
                        t.create_window(wInfo + wZona, hZona * 2, wZona, hZona, true),
                        t.create_window(wInfo + wZona * 2, hZona * 2, wZona, hZona, true),
                        t.create_window(wInfo + wZona * 3, hZona * 2, wZona, hZona, true)
                },
                {
                        t.create_window(wInfo, hZona * 3, wZona, hZona, true),
                        t.create_window(wInfo + wZona, hZona * 3, wZona, hZona, true),
                        t.create_window(wInfo + wZona * 2, hZona * 3, wZona, hZona, true),
                        t.create_window(wInfo + wZona * 3, hZona * 3, wZona, hZona, true)
                }
        };

        //Se Habitacao nao existe
        if (habitacao != nullptr) {
            //Percorre todas as janelas
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    //Se a janela estiver fora dos limites da habitacao tranca a janela
                    if (i > (habitacao->getLinhas() - 1) || j > (habitacao->getColunas() - 1)) {
                        windows[i][j] << "                    ----------------------------------------";
                    }
                }
            }

            habitacao->desenhaHabitacao();
        }

        if (str_cmd.empty()) {
            win_cmd.clear();
            win_info.clear();
        }

        win_cmd << "Comando: ";
        win_cmd >> str_cmd;

        interpretarComando(str_cmd, win_info, win_cmd, windows, false);
    }
}

int Simulador::valida_args(const string &linha) {
    int i = 0;
    istringstream buffer(linha);

    while (buffer) {
        string tok;
        buffer >> tok;
        cout << tok << endl;
        i++;
    }
    return i - 2;
}

void Simulador::interpretarComando(const string &comando, Window &win_info, Window &win_cmd, Window windows[4][4],
                                   bool fromFile) {

    istringstream buffer(comando);
    //Ler palavra a palavra a frase dada
    string parte, esperaInput, resultadoOperacao;
    buffer >> parte;
    int num_args;

    win_info << comando << "\n";

    if (!(parte == "exec" || parte == "hnova") && habitacao == nullptr) {
        if (!fromFile) win_cmd << "Comando Invalido: Nao existe uma habitacao";
    } else if (parte == "prox") {//Avança um instante
        num_args = valida_args(comando);
        if (num_args == 0) {
            habitacao->processarInstante();
            if (!fromFile) win_info << "Proxima Iteracao\n";
        } else {
            if (!fromFile) win_cmd << "Comando Invalido\n";
        }
    } else if (parte == "avanca") { //Avança x instantes
        num_args = valida_args(comando);
        int instantes;
        if (num_args == 1) {
            buffer >> instantes;
            for (int i = 0; i < instantes; i++) {
                habitacao->processarInstante();
            }
            if (!fromFile) win_info << "Comando Avanca " << instantes << " instantes\n";
        } else {
            if (!fromFile) win_cmd << "Comando Invalido\n";
        }
    } else if (parte == "hnova") {//Cria nova habitação <num_linhas> < num_colunas>
        num_args = valida_args(comando);
        if (num_args == 2) {
            int num_linhas, num_colunas;
            buffer >> num_linhas;
            buffer >> num_colunas;

            if (habitacao == nullptr) {
                if (num_linhas >= 2 && num_linhas <= 4 && num_colunas >= 2 && num_colunas <= 4) {
                    habitacao = new Habitacao(num_linhas, num_colunas);
                    if (!fromFile)
                        win_info << "Cria nova habitacao com " << num_linhas << " linhas e " << num_colunas
                                 << " colunas\n";
                } else {
                    if (!fromFile) win_cmd << "Comando Invalido: num_linhas e num_colunas devem estar entre 2 e 4\n";
                }
            } else {
                if (!fromFile) win_cmd << "Comando Invalido: Ja existe uma habitacao";
            }
        } else {
            if (!fromFile) win_cmd << "Comando Invalido\n";
        }
    } else if (parte == "hrem") {//Remove habitacao
        num_args = valida_args(comando);
        if (num_args == 0) {
            if (habitacao != nullptr) {
                delete habitacao;
                habitacao = nullptr;

                if (!fromFile) win_info << "Habitacao apagada\n";
            } else {
                if (!fromFile) win_cmd << "Comnado Invalido: nao existe uma habitacao";
            }
        } else {
            if (!fromFile) win_cmd << "Comando Invalido\n";
        }
    } else if (parte == "znova") {//Cria nova zona
        num_args = valida_args(comando);
        if (num_args == 2) {
            int linha, coluna;
            buffer >> linha;
            buffer >> coluna;
            resultadoOperacao = habitacao->criarZona(linha, coluna, &windows[linha][coluna]);

            if (!fromFile) {
                if (resultadoOperacao == "OK") {
                    win_info << "Cria nova zona na posicao " << linha << "," << coluna << "\n";
                } else {
                    win_cmd << "Comando Invalido: " << resultadoOperacao << "\n";
                }
            };
        } else {
            if (!fromFile) win_cmd << "Comando Invalido\n";
        }
    } else if (parte == "zrem") {//Apaga zona com o ID indicado
        num_args = valida_args(comando);
        if (num_args == 1) {
            int id_zona;
            buffer >> id_zona;
            resultadoOperacao = habitacao->removerZona(id_zona);
            if (!fromFile) {
                if (resultadoOperacao == "OK") {
                    win_info << "Apaga zona com o ID " << id_zona << "\n";
                } else {
                    win_cmd << "Comando Invalido: " << resultadoOperacao << "\n";
                }
            }
        } else {
            if (!fromFile) win_cmd << "Comando Invalido\n";
        }

    } else if (parte == "zlista") {//Lista todas as zonas da habitacao
        num_args = valida_args(comando);
        if (num_args == 0) {
            habitacao->imprimirZonas(&win_info);
        } else {
            if (!fromFile) win_cmd << "Comando Invalido\n";
        }
    } else if (parte == "zcomp") {//Listar componentes de uma zona com ID indicado
        num_args = valida_args(comando);
        if (num_args == 1) {
            int id_zona;
            buffer >> id_zona;

            Zona *zona = habitacao->getZona(id_zona);
            if (zona != nullptr) {
                zona->imprimirComponentes(&win_info);
            } else {
                if (!fromFile) win_cmd << "Comando Invalido: Nao existe uma zona com este id";
            }
        } else {
            if (!fromFile) win_cmd << "Comando Invalido\n";
        }
    } else if (parte == "zprops") {//Lista as propriedades reconhecidas pelo simulador na zona com o ID indicado
        num_args = valida_args(comando);
        if (num_args == 1) {
            int id_zona;
            buffer >> id_zona;

            Zona *zona = habitacao->getZona(id_zona);
            if (zona != nullptr) {
                zona->imprimirPropriedades(&win_info);
            } else {
                if (!fromFile) win_cmd << "Comando Invalido: Nao existe uma zona com este id";
            }
        } else {
            if (!fromFile) win_cmd << "Comando Invalido\n";
        }

    } else if (parte ==
               "pmod") {//Modifica o valor da propriedade cujo nome é indicado na zona com o ID indicado para o valor especificado
        num_args = valida_args(comando);
        if (num_args == 3) {
            int id_zona, valor;
            string nome;
            buffer >> id_zona;
            buffer >> nome;
            buffer >> valor;

            Zona *zona = habitacao->getZona(id_zona);
            if (zona != nullptr) {
                Propriedade *propriedade = zona->getPropriedade(nome);

                if (propriedade != nullptr) {
                    resultadoOperacao = propriedade->actualizaValor(valor);

                    if (!fromFile) {
                        if (resultadoOperacao == "OK") {
                            win_info << "Atualizada propriedade da zona " << id_zona << "\n";
                        } else {
                            win_cmd << "Comando Invalido: " << resultadoOperacao << "\n";
                        }
                    }
                } else {
                    if (!fromFile) win_cmd << "Comando Invalido: Nao existe uma propriedade com este nome";
                }
            } else {
                if (!fromFile) win_cmd << "Comando Invalido: Nao existe uma zona com este id";
            }
        } else {
            if (!fromFile) win_cmd << "Comando Invalido\n";
        }
    }//cnovo <ID zona> <s | p | a> <tipo | comando>
    else if (parte ==
             "cnovo") {//Adiciona um sensor (s) / processador (p) / aparelho (a) do tipo indicado à zona que tem o ID indicado.
        num_args = valida_args(comando);
        if (num_args == 3) {
            int id_zona;
            char tipo, cmd_tipo; //s p ou a
            Zona *zona;
            Temperatura *temperatura;
            Som *som;
            Luz *luz;
            Humidade *humidade;
            Vibracao *vibracao;
            Fumo *fumo;
            Propriedade *propriedade;
            Aparelho *aparelho;
            Sensor *sensor;
            ProcessadorRegras *processador;
            string cmd_procesador;
            buffer >> id_zona;
            buffer >> tipo;

            switch (tipo) {
                case 'a' :
                    zona = habitacao->getZona(id_zona);
                    if (zona != nullptr) {
                        buffer >> cmd_tipo;
                        switch (cmd_tipo) {
                            case 'a':
                                temperatura = (Temperatura *) zona->getPropriedade("temperatura");
                                som = (Som *) zona->getPropriedade("som");

                                aparelho = new Aquecedor(temperatura, som);
                                zona->add(aparelho);

                                if (!fromFile) win_info << "Aquecedor adicionado a zona com id " << id_zona;
                                break;
                            case 's':
                                humidade = (Humidade *) zona->getPropriedade("humidade");
                                vibracao = (Vibracao *) zona->getPropriedade("vibracao");
                                fumo = (Fumo *) zona->getPropriedade("fumo");

                                aparelho = new Aspersor(humidade, vibracao, fumo);
                                zona->add(aparelho);

                                if (!fromFile) win_info << "Aspersor adicionado a zona com id " << id_zona;
                                break;
                            case 'r':
                                temperatura = (Temperatura *) zona->getPropriedade("temperatura");
                                som = (Som *) zona->getPropriedade("som");

                                aparelho = new Refrigerador(temperatura, som);
                                zona->add(aparelho);

                                if (!fromFile) win_info << "Refrigerador adicionado a zona com id " << id_zona;
                                break;
                            case 'l':
                                luz = (Luz *) zona->getPropriedade("luz");

                                aparelho = new Lampada(luz);
                                zona->add(aparelho);

                                if (!fromFile) win_info << "Lampada adicionada a zona com id " << id_zona;
                                break;
                            default:
                                if (!fromFile) win_cmd << "Comando Invalido: Tipo de aparelho invalido";
                                break;
                        }
                    } else {
                        if (!fromFile) win_cmd << "Comando Invalido: Nao existe uma zona com este id";
                    }
                    break;
                case 'p' :
                    buffer >> cmd_procesador;
                    zona = habitacao->getZona(id_zona);
                    if (zona != nullptr) {
                        processador = new ProcessadorRegras(cmd_procesador);
                        zona->add(processador);
                        if (!fromFile) win_info << "Processador adicionado a zona com id " << id_zona;
                    } else {
                        if (!fromFile) win_cmd << "Comando Invalido: Nao existe uma zona com este id";
                    }
                    break;
                case 's':
                    zona = habitacao->getZona(id_zona);
                    if (zona != nullptr) {
                        buffer >> cmd_tipo;
                        switch (cmd_tipo) {
                            case 't':
                                propriedade = zona->getPropriedade("temperatura");
                                sensor = new SensorTemperatura(propriedade);
                                zona->add(sensor);
                                if (!fromFile) win_info << "SensorTemperatura adicionado a zona com id " << id_zona;
                                break;
                            case 'v':
                                propriedade = zona->getPropriedade("vibracao");
                                sensor = new SensorMovimento(propriedade);
                                zona->add(sensor);
                                if (!fromFile) win_info << "SensorMovimento adicionado a zona com id " << id_zona;
                                break;
                            case 'm':
                                propriedade = zona->getPropriedade("luz");
                                sensor = new SensorLuminosidade(propriedade);
                                zona->add(sensor);
                                if (!fromFile) win_info << "SensorLuminosidade adicionado a zona com id " << id_zona;
                                break;
                            case 'd':
                                propriedade = zona->getPropriedade("radiacao");
                                sensor = new SensorRadiacao(propriedade);
                                zona->add(sensor);
                                if (!fromFile) win_info << "SensorRadiacao adicionado a zona com id " << id_zona;
                                break;
                            case 'h':
                                propriedade = zona->getPropriedade("humidade");
                                sensor = new SensorHumidade(propriedade);
                                zona->add(sensor);
                                if (!fromFile) win_info << "SensorHumidade adicionado a zona com id " << id_zona;
                                break;
                            case 'o':
                                propriedade = zona->getPropriedade("som");
                                sensor = new SensorSom(propriedade);
                                zona->add(sensor);
                                if (!fromFile) win_info << "SensorSom adicionado a zona com id " << id_zona;
                                break;
                            case 'f':
                                propriedade = zona->getPropriedade("fumo");
                                sensor = new SensorFumo(propriedade);
                                zona->add(sensor);
                                if (!fromFile) win_info << "SensorFumo adicionado a zona com id " << id_zona;
                                break;
                            default:
                                if (!fromFile) win_cmd << "Comando Invalido: Tipo de sensor invalido";
                                break;
                        }
                    } else {
                        if (!fromFile) win_cmd << "Comando Invalido: Nao existe uma zona com este id";
                    }
                    break;
                default:
                    if (!fromFile) win_cmd << "Comando Invalido\n";
                    break;
            }
            //win_cmd << "Adiciona " << tipo << " na zona com ID=" << id_zona << " com o comando " << comando << "\n";

        } else {
            if (!fromFile) win_cmd << "Comando Invalido\n";

        }

    }//crem <ID zona> <s | p | a> <ID>
    else if (parte == "crem") {//Remove o componente com ID indicado da zona especificada
        num_args = valida_args(comando);
        if (num_args == 3) {
            int id_componente, id_zona;
            char tipo;//s/p ou a
            buffer >> id_zona;
            buffer >> tipo;
            buffer >> id_componente;

            Zona *zona = habitacao->getZona(id_zona);
            if (zona != nullptr) {
                switch (tipo) {
                    case 'a' :
                        zona->removeAparelho(id_componente);
                        if (!fromFile)
                            win_info << "Remove o Aparelho " << id_componente << " na zona " << id_zona
                                     << "\n";
                        break;

                    case 'p' :
                        zona->removeProcessadorRegras(id_componente);
                        if (!fromFile)
                            win_info << "Remove o Processador " << id_componente << " na zona " << id_zona
                                     << "\n";
                        break;

                    case 's':
                        zona->removeSensor(id_componente);
                        if (!fromFile)
                            win_info << "Remove o Sensor " << id_componente << " na zona " << id_zona
                                     << "\n";
                        break;
                    default:
                        if (!fromFile) win_cmd << "Comando invalido: Tipo de componente invalido\n";
                        break;
                }
            } else {
                if (!fromFile) win_cmd << "Comando Invalido: Nao existe uma zona com este id";
            }
        } else {
            if (!fromFile) win_cmd << "Comando Invalido\n";
        }
    }//rnova <ID zona> <ID proc. regras> <regra> <ID sensor> [param1] [param2] [...]
    else if (parte == "rnova") {//cria nova regra
        num_args = valida_args(comando);
        if (num_args >= 4) {
            int id_zona, id_processador, id_sensor, parametro1, parametro2;
            string tipo;
            buffer >> id_zona;
            buffer >> id_processador;
            buffer >> tipo;
            buffer >> id_sensor;
            buffer >> parametro1;
            Zona *zona;
            ProcessadorRegras *processador;
            Sensor *sensor;
            Regra *regra;

            zona = habitacao->getZona(id_zona);

            if (zona != nullptr) {
                processador = zona->getProcessadorRegras(id_processador);

                if (processador != nullptr) {
                    sensor = zona->getSensor(id_sensor);

                    if (sensor != nullptr) {
                        if (tipo == "igual_a") {
                            regra = new RegraIgual(sensor, parametro1);
                            processador->adicionarRegra(regra);
                            if (!fromFile) win_info << "Regra igual_a adicionada";
                        } else if (tipo == "menor_que") {
                            regra = new RegraMenor(sensor, parametro1);
                            processador->adicionarRegra(regra);
                            if (!fromFile) win_info << "Regra menor_que adicionada";
                        } else if (tipo == "maior_que") {
                            regra = new RegraMaior(sensor, parametro1);
                            processador->adicionarRegra(regra);
                            if (!fromFile) win_info << "Regra maior_que adicionada";
                        } else if (tipo == "entre") {
                            buffer >> parametro2;
                            regra = new RegraEntre(sensor, parametro1, parametro2);
                            processador->adicionarRegra(regra);
                            if (!fromFile) win_info << "Regra entre adicionada";
                        } else if (tipo == "fora") {
                            buffer >> parametro2;
                            regra = new RegraFora(sensor, parametro1, parametro2);
                            if (!fromFile) win_info << "Regra fora adicionada";
                            processador->adicionarRegra(regra);
                        } else {
                            if (!fromFile) win_cmd << "Comando invalido: Tipo de regra invalido";
                        }
                    } else {
                        if (!fromFile) win_cmd << "Comando invalido: Nao existe um sensor com este id";
                    }
                } else {
                    if (!fromFile) win_cmd << "Comando invalido: Nao existe um processador com este id";
                }
            } else {
                if (!fromFile) win_cmd << "Comando invalido: Nao existe uma zona com este id";
            }
        } else {
            if (!fromFile) win_cmd << "Comando Invalido\n";
        }
    }//pmuda <ID zona> <ID proc. regras> <novo comando>
    else if (parte == "pmuda") {//Muda o comando do processador indicado, na zona especificada.
        num_args = valida_args(comando);
        if (num_args == 3) {
            int id_zona, id_processador;
            string novo_comando;
            buffer >> id_zona;
            buffer >> id_processador;
            buffer >> novo_comando;
            Zona *zona;
            ProcessadorRegras *processador;

            zona = habitacao->getZona(id_zona);
            if (zona != nullptr) {
                processador = zona->getProcessadorRegras(id_processador);

                if (processador != nullptr) {
                    processador->setComando(novo_comando);
                    if (!fromFile)
                        win_info << "Processador " << id_processador << " atualizado com o comando " << novo_comando;
                } else {
                    if (!fromFile) win_cmd << "Comando invalido: Nao existe um processador com este id";
                }
            } else {
                if (!fromFile) win_cmd << "Comando invalido: Nao existe uma zona com este id";
            }
        } else {
            if (!fromFile) win_cmd << "Comando Invalido\n";
        }
    }//rlista <ID zona> <ID proc. regras>
    else if (parte == "rlista") {// Lista as regras do processador de regras
        num_args = valida_args(comando);
        if (num_args == 2) {
            int id_zona, id_processador;
            buffer >> id_zona;
            buffer >> id_processador;
            ProcessadorRegras *processador;

            Zona *zona = habitacao->getZona(id_zona);
            if (zona != nullptr) {
                processador = zona->getProcessadorRegras(id_processador);

                if (processador != nullptr) {
                    processador->imprimirRegras(&win_info);
                } else {
                    if (!fromFile) win_cmd << "Comando invalido: Nao existe um processador com este id";
                }
            } else {
                if (!fromFile) win_cmd << "Comando Invalido: Nao existe uma zona com este id";
            }
        } else {
            if (!fromFile) win_cmd << "Comando Invalido\n";
        }
    }//rrem <ID zona> <ID proc. regras> <ID regra>
    else if (parte == "rrem") {//Remove regra indicada do processador de regras especificado
        num_args = valida_args(comando);
        if (num_args == 3) {
            int id_zona, id_processador, id_regra;
            buffer >> id_zona;
            buffer >> id_processador;
            buffer >> id_regra;
            ProcessadorRegras *processador;

            Zona *zona = habitacao->getZona(id_zona);
            if (zona != nullptr) {
                processador = zona->getProcessadorRegras(id_processador);

                if (processador != nullptr) {
                    processador->removeRegra(id_regra);
                    if (!fromFile)
                        win_info << "Removida regra " << id_regra << " do processador " << id_processador << " da zona "
                                 << id_zona;
                } else {
                    if (!fromFile) win_cmd << "Comando invalido: Nao existe um processador com este id";
                }
            } else {
                if (!fromFile) win_cmd << "Comando Invalido: Nao existe uma zona com este id";
            }
        } else {
            if (!fromFile) win_cmd << "Comando Invalido\n";
        }
    }//asoc <ID zona> <ID proc. regras> <ID aparelho>
    else if (parte ==
             "asoc") {//Estabelece a associação entre a saída do processador indicado e o aparelho especificado.
        num_args = valida_args(comando);
        if (num_args == 3) {
            int id_zona, id_processador, id_aparelho;
            buffer >> id_zona;
            buffer >> id_processador;
            buffer >> id_aparelho;
            ProcessadorRegras *processador;
            Aparelho *aparelho;

            Zona *zona = habitacao->getZona(id_zona);
            if (zona != nullptr) {
                processador = zona->getProcessadorRegras(id_processador);

                if (processador != nullptr) {
                    aparelho = zona->getAparelho(id_aparelho);

                    if (aparelho != nullptr) {
                        processador->adicionaAparelho(aparelho);
                        if(!fromFile) win_info << "Processador " << id_processador << " ligada ao aparelho " << id_aparelho;

                    } else {
                        if (!fromFile) win_cmd << "Comando invalido: Nao existe um aparelho com este id";
                    }
                } else {
                    if (!fromFile) win_cmd << "Comando invalido: Nao existe um processador com este id";
                }
            } else {
                if (!fromFile) win_cmd << "Comando Invalido: Nao existe uma zona com este id";
            }
        } else {
            if (!fromFile) win_cmd << "Comando Invalido\n";
        }
    }//ades <ID zona> <ID proc. regras> <ID aparelho>
    else if (parte == "ades") {//Remove a associação entre a saída do processador indicado e o aparelho especificado.
        num_args = valida_args(comando);
        if (num_args == 3) {
            int id_zona, id_processador, id_aparelho;
            buffer >> id_zona;
            buffer >> id_processador;
            buffer >> id_aparelho;
            ProcessadorRegras *processador;
            Aparelho *aparelho;

            Zona *zona = habitacao->getZona(id_zona);
            if (zona != nullptr) {
                processador = zona->getProcessadorRegras(id_processador);

                if (processador != nullptr) {
                    processador->removeAparelho(id_aparelho);
                    if(!fromFile) win_info << "Aparelho removido do processador";
                } else {
                    if (!fromFile) win_cmd << "Comando invalido: Nao existe um processador com este id";
                }
            } else {
                if (!fromFile) win_cmd << "Comando Invalido: Nao existe uma zona com este id";
            }
        } else {
            if (!fromFile) win_cmd << "Comando Invalido\n";
        }
    }//acom <ID zona> <ID aparelho> <comando>
    else if (parte == "acom") { //Envia “manualmente” o comando indicado ao aparelho cujo ID foi especificado
        num_args = valida_args(comando);
        if (num_args == 3) {
            int id_zona, id_aparelho;
            string novo_comando;
            Zona *zona;
            Aparelho *aparelho;
            buffer >> id_zona;
            buffer >> id_aparelho;
            buffer >> novo_comando;

            zona = habitacao->getZona(id_zona);
            if (zona != nullptr) {
                aparelho = zona->getAparelho(id_aparelho);

                if (aparelho != nullptr) {
                    aparelho->executarComando(novo_comando);
                    if (!fromFile) win_info << "Comando enviado ao aparelho na zona " << id_zona << "\n";
                } else {
                    if (!fromFile) win_cmd << "Comando invalido: Nao existe um aparelho com este id";
                }
            } else {
                if (!fromFile) win_cmd << "Comando invalido: Nao existe uma zona com este id";
            }
        } else {
            if (!fromFile) win_cmd << "Comando Invalido\n";
        }
    }//psalva <ID zona> <ID proc. regras> <nome>
    else if (parte ==
             "psalva") {//Salva o estado de um processador de regras e de tudo o que lhe estiver associado para memória.
        num_args = valida_args(comando);
        if (num_args == 3) {
            int id_zona, id_processador;
            string nome;
            buffer >> id_zona;
            buffer >> id_processador;
            buffer >> nome;
            if (!fromFile)
                win_info << " Salva estado: " << nome << ". Para o processador " << id_processador << " na zona "
                         << id_zona
                         << "\n";
        } else {
            if (!fromFile) win_cmd << "Comando Invalido\n";
        }
    }//prepoe <nome>
    else if (parte == "prepoe") {//Repõe o processador previamente gravado em memória com o nome indicado.
        num_args = valida_args(comando);
        if (num_args == 1) {
            string nome;
            buffer >> nome;
            if (!fromFile) win_info << "Repoe o processador previamente gravado em memória com o nome " << nome << "\n";
        } else {
            if (!fromFile) win_cmd << "Comando Invalido\n";
        }
    }//prem <nome>
    else if (parte == "prem") {//Apaga uma cópia do processador de regras armazenado em memória.
        num_args = valida_args(comando);
        if (num_args == 1) {
            string nome;
            buffer >> nome;
            if (!fromFile)
                win_info << "Apaga uma cópia do processador de regras armazenado em memória com o nome " << nome
                         << "\n";
        } else {
            if (!fromFile) win_cmd << "Comando Invalido\n";
        }
    }//plista
    else if (parte == "plista") {
        num_args = valida_args(comando);
        if (num_args == 0) {
            if (!fromFile)
                win_info << "Apresenta uma lista de cópias de processadores de regras salvaguardados em memória."
                         << "\n";
        } else {
            if (!fromFile) win_cmd << "Comando Invalido\n";
        }
    }//exec <nome de ficheiro>
    else if (parte == "exec") {
        num_args = valida_args(comando);
        if (num_args == 1) {
            string nome;
            buffer >> nome;
            //string nome_fich = "C:/Tp2/" + nome;
            ifstream f(nome); //abre o ficheiro
            if (f.is_open()) {
                string c;
                //int i = 1;
                while (getline(f, c)) {
                    interpretarComando(c, win_info, win_cmd, windows,
                                       true); //envia o comando para a função de validação/execução
                }
            } else {
                if (!fromFile) win_cmd << "Erro a abrir o ficheiro " << nome << "!\n";
            }
            f.close();
        } else {
            if (!fromFile) win_cmd << "Comando Invalido\n";
        }
    } else if (parte == "sair") {
        //limpar os recursos alocados
        num_args = valida_args(comando);
        if (num_args == 0) {
            delete habitacao;
            habitacao = nullptr;
            endwin();
            exit(0);

        } else {
            if (!fromFile) win_cmd << "Comando Invalido\n";
        }
    } else {
        if (!fromFile) win_cmd << "Comando Invalido!\n";
    }

    if (!fromFile) {
        win_cmd >> esperaInput;
    }
}

Simulador::~Simulador() {
    delete habitacao;
}
