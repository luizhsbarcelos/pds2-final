#include "../include/dvd.hpp"
#include <iostream>

DVD::DVD(int qtd, int cod, std::string titulo, std::string categoria)
    : Filme(qtd, cod, titulo), categoria(categoria) {}

DVD::~DVD() {
  std::cout << "Filme " << get_codigo() << " removido com sucesso\n";
}

double DVD::valor_locacao(int dias) const {
  if (categoria == "Lancamento") {
    return dias * 20;
  }
  if (categoria == "Estoque") {
    return dias * 10;
  }
  if (categoria == "Promocao") {
    return 10;
  } else {
    return 0;
  }
}

std::string DVD::tipo_midia() const { return "DVD"; }

void DVD::imprime_relatorio() {
  std::cout << get_codigo() << " " << get_titulo()
            << " " << get_quantidade() << " " << tipo_midia() << "\n";
  return;
}
