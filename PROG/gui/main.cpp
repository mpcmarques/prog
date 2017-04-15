//
//  main.cpp
//  PROG
//
//  Created by Mateus Pedroza on 14/04/17.
//  Copyright © 2017 Mateus Pedroza. All rights reserved.
//

#include "../logic/Transportadora.hpp"
#include "../logic/FileService.hpp"
#include <unistd.h>

int main(int argc, const char * argv[]) {
  FileService fileService;

  vector<Linha> linhas = fileService.getLinhas();
  vector<Condutor> condutores = fileService.getCondutores();

  Transportadora transportadora = Transportadora(linhas, condutores);

  cout << "Criado uma transportadora com " << linhas.size() << " linhas e " << condutores.size() << " condutores." << endl;




  //  terminar programa, salvar dados.
  fileService.saveData(transportadora);
  cout << "Dados salvos com sucesso!" << endl;
  return 0;
}
