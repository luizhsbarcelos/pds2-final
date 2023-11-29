#include "../include/estoque.hpp"
#include <algorithm>
#include <iostream>

void Estoque::Adiciona_filme(Filme *filme) { lista_filmes.push_back(filme); }

void Estoque::Remove_filme(int codigo) {
  auto it = std::remove_if(
      lista_filmes.begin(), lista_filmes.end(),
      [codigo](Filme *filme) { return filme->get_codigo() == codigo; });

  lista_filmes.erase(it, lista_filmes.end());
}

Filme *Estoque::Pesquisa_filme(int codigo) {
  for (Filme *filme_vetor : lista_filmes) {
    if (filme_vetor->get_codigo() == codigo) {
      return filme_vetor;
    }
  }
  std::cout << "ERRO: Filme " << codigo << " inexistente" << std::endl;
  return nullptr;
}

void Estoque::Imprime_relatorio() {
  std::cout << "Relatorio de Estoque:\n";
  for (Filme *filme_vetor : lista_filmes) {
    std::cout << "Código: " << filme_vetor->get_codigo()
              << ", Título: " << filme_vetor->get_titulo()
              << ", Quantidade: " << filme_vetor->get_quantidade() << "\n";
  }
}
