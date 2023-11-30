#include "locacao.hpp"

#include <iostream>
#include <vector>

// Construtor
Locacao::Locacao(int id, std::string cpf, std::vector<int> filmes)
    : _id_locacao(id), _cpf_cliente(cpf), _filmes_alugados(filmes) {}

// Construtor e destrutor padrão
Locacao::Locacao() {
  std::cout << "ERRO: Objeto instaciado indevidamente, o destrutor será chamado"
            << std::endl;
  ~Locacao();
}

Locacao::~Locacao() {}

// Implementação dos métodos get
int Locacao::get_id() { return _id_locacao; }

std::string Locacao::get_cpf() { return _cpf_cliente; }

std::vector<int> Locacao::get_filmes() { return _filmes_alugados; }
