#include "../include/fita.hpp"
#include <iostream>

Fita::Fita(int qtd, int cod, std::string titulo) : Filme(qtd, cod, titulo) {}

Fita::~Fita() {}

bool Fita::rebobina() const { return fita_rebobinada; }

double Fita::valor_locacao(int dias) {
  return 5 * dias + (fita_rebobinada ? 0 : 2);
}

std::string Fita::tipo_midia() const { return "FITA"; }

void Fita::imprime_relatorio() {
  std::cout << get_codigo() << " " << get_titulo() << " " << get_quantidade()
            << " " << tipo_midia() << "\n";
  return;
}
