#include "Linha.hpp"

vector<Paragem> stringToParagens(std::vector<string> stringParagens){
  vector<Paragem> newParagens;
  //  loop atraves das virgulas
  for(string paragemString: stringParagens){
    Paragem newParagem = Paragem(trimString(paragemString));
    newParagens.push_back(newParagem);
  }
  return newParagens;
}

vector<int> stringsToInt(vector<string> newTemposString){
  std::vector<int> newVector;
  for(string tempoString: newTemposString){
    newVector.push_back(stoi(tempoString));
  }
  return newVector;
}

istream& operator>> (istream &is, Linha &linha){
  string line;

  getline(is, line);

  if (!line.empty()) {

    //  dividir a linha de acordo com ';'
    vector<string> data = split(line, ';');

    //  configurar objecto
    linha.uid = stoi(data[0]);
    linha.freq = stoi(data[1]);

    //  configurar paragens
    vector<string> stringParagens = split(data[2],',');
    linha.paragens = stringToParagens(stringParagens);

    //  configurar tempos
    vector<string> newTemposString = split(data[3], ',');
    linha.tempos = stringsToInt(newTemposString);
  }

  return is;
}

ostream& operator<< (ostream &os, Linha &linha){

  os << linha.uid;
  os << " ; ";
  os << linha.freq;
  os << " ;";

  //  paragens
  for (unsigned int i = 0; i < linha.paragens.size(); i++) {
    if (i < linha.paragens.size()-1){
      os << " " << linha.paragens[i].getNome() << ',';
    } else {
      os << " " << linha.paragens[i].getNome() << ';';
    }
  }

  //  tempos
  for (unsigned int i = 0; i < linha.tempos.size(); i++) {
    if (i < linha.tempos.size()-1){
      os << " " << linha.tempos[i] << ',';
    } else {
      os << " " << linha.tempos[i];
    }
  }

  return os;
}
