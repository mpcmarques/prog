//
//  Transportadora.hpp
//  PROG
//
//  Created by Mateus Pedroza on 14/04/17.
//  Copyright © 2017 Mateus Pedroza. All rights reserved.

#ifndef Transportadora_h
#define Transportadora_h

#include "Linha.hpp"
#include "Condutor.hpp"

using namespace std;

class Transportadora {
private:

vector<Linha> linhas;
vector<Condutor> condutores;
vector<Turno> turnos;
vector<Autocarro> autocarros;
int TEMPO_INICIO = 8*60;
int TEMPO_FIM = 22*60 - 1;

void atribuirServicoAosCondutores();
void criarAutocarros();

public:
Transportadora();
Transportadora(std::vector<Linha> linhas, std::vector<Condutor>);
void removerCondutor(int opt);
void removerLinha(int opt);
void addLinha(const Linha linha);
void addCondutor(const Condutor condutor);
const vector<Turno> getTurnosNaoAtribuidos();
vector<Linha> getLinhasComParagem(string nome);

//  getters
// const Autocarro getAutocarro(int linhaId, int ordemNaLinha);
std::vector<Condutor> getCondutores();
std::vector<Linha> getLinhas();

};


#endif /* Transportadora_h */