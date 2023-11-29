#include "../include/fita.hpp"
#include <iostream>

Fita::Fita(int qtd, int cod, std::string titulo) : Filme(qtd, cod, titulo) {}

bool Fita::rebobina() const { return fita_rebobinada; }

double Fita::valor_locacao(int dias) const {
  return 5 * dias + (fita_rebobinada ? 0 : 2);
}

std::string Fita::tipo_locacao() const { return "FITA"; }

void Fita::imprime_relatorio() {
  std::cout << "FITA - Codigo: " << get_codigo() << ", Titulo: " << get_titulo()
            << ", Rebobinada: " << (fita_rebobinada ? "Sim" : "Nao") << "\n";
}
