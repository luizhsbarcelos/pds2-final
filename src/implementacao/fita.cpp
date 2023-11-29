#include "fita.hpp"
#include <iostream>

Fita::Fita(int cod, std::string titulo, int qtd, bool fita_rebobinada)
    : Filme(cod, titulo, qtd), fita_rebobinada(fita_rebobinada) {}

bool Fita::rebobina() const {
    return fita_rebobinada;
}

double Fita::valor_locacao(int dias) {
    return 5 * dias + (fita_rebobinada ? 0 : 2);
}

std::string Fita::tipo_locacao() const {
    return "FITA";
}

void Fita::imprime_relatorio() {
    std::cout << "FITA - Codigo: " << get_codigo() << ", Titulo: " << get_titulo() << ", Rebobinada: " << (fita_rebobinada ? "Sim" : "Nao") << "\n";
}
