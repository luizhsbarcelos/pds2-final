#include "Cadastro_filme.hpp"

Cadastro_filme::Cadastro_filme(int cod, std::string titulo, int qtd)
    : cod(cod), titulo(titulo), qtd(qtd) {}

Cadastro_filme::~Cadastro_filme() {}

double Cadastro_filme::valor_locacao(int dias) const {
    return 0; 
}

int Cadastro_filme::get_codigo() const {
    return cod;
}

std::string Cadastro_filme::get_titulo() const {
    return titulo;
}

int Cadastro_filme::get_quantidade() const {
    return qtd;
}
