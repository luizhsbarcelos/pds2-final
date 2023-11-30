#include "../include/arquivo.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> Arquivo::separa_palavras(std::string str) {

  std::istringstream iss(str);

  std::vector<std::string> _vector_str;
  std::string palavra;

  // Extrai cada palavra da string
  while (iss >> palavra) {
    _vector_str.push_back(palavra);
  }
  return _vector_str;
}

void Arquivo::ler_arquivo() {

  std::cin >> _nome_arquivo;
  std::ifstream arquivo("../data/" + _nome_arquivo);

  // Checagem se arquivo está aberto
  if (!arquivo.is_open()) {
    std::cout << "ERRO: arquivo inexistente\n";
    return;
  }

  while (std::getline(arquivo, _linha)) {
    _vector_linhas.push_back(_linha);
  }
  arquivo.close();

  return;
}

void Arquivo::conta_filmes() {
  qtd_filmes_arquivo++;
  return;
}

int Arquivo::get_qtd_filmes() { return qtd_filmes_arquivo; }

Arquivo::Arquivo() {}
Arquivo::~Arquivo() {}
