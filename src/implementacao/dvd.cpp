#include "dvd.hpp"
#include <iostream>

DVD::DVD(int cod, std::string titulo, int qtd, int categoria)
    : Cadastro_filme(cod, titulo, qtd), categoria(categoria) {}

double DVD::valor_locacao(int dias) const {
    if (categoria == Lancamento) {
        return dias * 20;
    }
    if (categoria == Estoque) {
        return dias * 10;
    }
    if (categoria == Promocao) {
        return 10;
    } else {
        return 0;
    }
}

std::string DVD::tipo_locacao() const {
    return "DVD";
}

void DVD::imprime_relatorio() {
    std::cout << "DVD - Codigo: " << get_codigo() << ", Titulo: " << get_titulo() << ", Categoria: " << categoria << "\n";
}