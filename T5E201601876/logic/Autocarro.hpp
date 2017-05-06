#ifndef AUTOCARRO_HPP
#define AUTOCARRO_HPP

#include <iostream>
#include <vector>
#include "Turno.hpp"

/**
 * Representa um autocarro
 */
class Autocarro {
private:
  int ordemNaLinha;
  int condutorId;
  int linhaId;

std::vector<Turno> programacao;

public:
  Autocarro(int linhaId, int condutorId, int ordemNaLinha);

  void addTurno(Turno turno);
};







#endif
