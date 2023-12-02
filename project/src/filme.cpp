#include "../include/filme.hpp"

Filme::Filme(int qtd, int cod, std::string titulo)
    : qtd(qtd), cod(cod), titulo(titulo) {}

Filme::~Filme() {}

int Filme::get_codigo() const { return cod; }

std::string Filme::get_titulo() const { return titulo; }

int Filme::get_quantidade() const { return qtd; }

void Filme::set_quantidade(char c) {
  switch (c) {
  case '+':
    qtd++;
    break;
  case '-':
    qtd--;
    break;
  }
  return;
}