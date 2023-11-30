#include "../include/estoque.hpp"
#include "../include/dvd.hpp"
#include "../include/fita.hpp"

#include <algorithm>
#include <iostream>

// Libera o espaço de memória alocado para os filmes
Estoque::~Estoque() {
  for (Filme* it : _lista_filmes) {
    delete it;
  }
} 

void Estoque::Adiciona_filme(std::vector<std::string> &filme) {

  if (filme.size() >= 4 && filme.size() <= 5) {

    // Verifica a existencia de outro filme com mesmo código
    for (auto it : lista_filmes) {
      if (std::stoi(filme[1]) == it->get_codigo()) {
        std::cout << "ERRO: codigo repetido\n";
        return;
      }
    }
    // Verifica se é DVD
    if (filme.size() == 5 && filme[0] == "D") {
      DVD *novoDvd =
          new DVD(std::stoi(filme[1]), std::stoi(filme[2]), filme[3], filme[4]);
      lista_filmes.push_back(novoDvd);
      std::cout << "Filme: " << novoDvd->get_codigo()
                << " cadastrado com sucesso\n";

      // Verifica se é DVD
    } else if (filme.size() == 4 && filme[0] == "F") {

      Fita *novaFita =
          new Fita(std::stoi(filme[1]), std::stoi(filme[2]), filme[3]);
      lista_filmes.push_back(novaFita);
    } else {
      std::cout << "ERRO: Dados incorretos\n";
    }
  }
  return;
}

void Estoque::Remove_filme(int codigo) {
  for (auto it = lista_filmes.begin(); it != lista_filmes.end(); it++) {
    if (codigo == (*it)->get_codigo()) {
      delete *it;
      lista_filmes.erase(it);
      std::cout << "Filme: " << codigo << "removido com sucesso\n"; 
      return;

    } else {
      std::cout << "ERRO: codigo inexistente\n";
    }
  }
  return;
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

void Estoque::relatorio_estoque() {
  std::cout << "Relatorio de Estoque:\n";
  for (Filme *filme_vetor : lista_filmes) {
    std::cout << "Código: " << filme_vetor->get_codigo()
              << ", Título: " << filme_vetor->get_titulo()
              << ", Quantidade: " << filme_vetor->get_quantidade() << "\n";
  }
  return;
}

void Estoque::listar_filmes() {
  char input;
  std::cin >> input;
  
  switch (input) {
    case 'C':
      // Organiza o estoque por código em ordem crescente
      std::sort(lista_filmes.begin(), lista_filmes.end(), [] (const Filme *a, const Filme *b) {
        return a->get_codigo() < b->get_codigo();
      });
      // Imprime estoque organizado
      for (Filme* it : lista_filmes) {
        it->imprime_relatorio();
      }
      break;
  
    case 'T':
      // Organiza o estoque por título em ordem alfabética
      std::sort(lista_filmes.begin(), lista_filmes.end(), [] (const Filme *a, const Filme *b) {
        return a->get_titulo() < b->get_titulo();
      });
      // Imprime estoque organizado
      for (Filme* it : lista_filmes) {
        it->imprime_relatorio();
      }
      break;
  
    default:
      std::cout << "ERRO: Tipo de ordenação inválido\n";
      break;
  }
  return;
}