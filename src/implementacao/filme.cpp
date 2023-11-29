#include "../include/filme.hpp"

Filme::Filme(int qtd, int cod, std::string titulo)
  : qtd(qtd), cod(cod), titulo(titulo) {}

Filme::~Filme() {}

double Filme::valor_locacao(int dias) const { return 0; }

int Filme::get_codigo() const { return cod; }

std::string Filme::get_titulo() const { return titulo; }

int Filme::get_quantidade() const { return qtd; }
