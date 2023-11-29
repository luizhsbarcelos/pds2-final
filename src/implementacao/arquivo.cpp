#include "../include/arquivo.hpp"

#include <fstream>
#include <iostream>
#include <string>

void Arquivo::ler_arquivo() {

  std::cin >> _nome_arquivo;
  std::ifstream arquivo(_path_arquivo + _nome_arquivo);

  // Checagem se arquivo está aberto
  if (!arquivo.is_open()) {
    std::cout << "ERRO: arquivo inexistente\n";
    return;
  }

  while (std::getline(arquivo, _linha)) {
    _vector_linhas.push_back(_linha);
  }
  arquivo.close();
}
