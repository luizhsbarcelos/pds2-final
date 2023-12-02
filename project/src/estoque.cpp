#include "../include/estoque.hpp"
#include "../include/controle_locacao.hpp"
#include "../include/dvd.hpp"
#include "../include/fita.hpp"

#include <algorithm>
#include <iostream>

// Libera o espaço de memória alocado para os filmes
Estoque::~Estoque() {
  for (Filme *it : lista_filmes) {
    delete it;
  }
}

bool Estoque::Adiciona_filme(std::vector<std::string> &filme) {

  // Verificação se quantidade é válida
  if (std::stoi(filme[2]) > 0) {

    // Verifica a existencia de outro filme com mesmo código
    for (auto it : lista_filmes) {
      if (std::stoi(filme[2]) == it->get_codigo()) {
        std::cout << "ERRO: codigo repetido\n";
        return false;
      }
    }
    // Verifica se é DVD
    if ((filme[0] == "D") || (filme[0] == "d")) {

      // Verificar se o filme possui nome composto
      int tamanho = filme.size();

      if (!(DVD::valida_categoria(filme[tamanho - 1]))) {
        std::cout << "ERRO: categoria inválida\n";
        return false;
      }

      std::string titulo;
      for (int i = 3; i < (tamanho - 2); i++) {
        titulo += filme[i] + " ";
      }
      titulo += filme[tamanho - 2];

      DVD *novoDvd = new DVD(std::stoi(filme[1]), std::stoi(filme[2]), titulo,
                             filme[tamanho - 1]);
      lista_filmes.push_back(novoDvd);
      std::cout << "Filme: " << novoDvd->get_codigo()
                << " cadastrado com sucesso\n";
      return true;

      // Verifica se é fita
    } else if ((filme[0] == "F") || (filme[0] == "f")) {

      // Verificar se o filme possui nome composto
      int tamanho = filme.size();
      std::string titulo;
      for (int i = 3; i < (tamanho - 1); i++) {
        titulo += filme[i] + " ";
      }
      titulo += filme[tamanho - 1];

      Fita *novaFita =
          new Fita(std::stoi(filme[1]), std::stoi(filme[2]), titulo);
      lista_filmes.push_back(novaFita);
      std::cout << "Filme: " << novaFita->get_codigo()
                << " cadastrado com sucesso\n";
      return true;
    } else {
      std::cout << "ERRO: dados incorretos\n";
    }
  } else {
    std::cout << "ERRO: dados incorretos\n";
  }
  return false;
}

void Estoque::Remove_filme(int codigo) {
  for (auto it = lista_filmes.begin(); it != lista_filmes.end(); it++) {
    if (codigo == (*it)->get_codigo()) {
      // Verificar se o Filme está alugado
      if (ControleLocacao::buscaFilmeLocacao(codigo) == nullptr) {
        delete *it;
        lista_filmes.erase(it);
        std::cout << "Filme: " << codigo << " removido com sucesso\n";
        return;
      } else {
        std::cout << "ERRO: Locacao pendente\n";
      }
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

  if (lista_filmes.empty()) {
    std::cout << "Nenhum filme cadastrado\n";
    return;
  }

  switch (input) {
  case 'C':
    // Organiza o estoque por código em ordem crescente
    std::sort(lista_filmes.begin(), lista_filmes.end(),
              [](const Filme *a, const Filme *b) {
                return a->get_codigo() < b->get_codigo();
              });
    // Imprime estoque organizado
    for (Filme *it : lista_filmes) {
      it->imprime_relatorio();
    }
    break;

  case 'T':
    // Organiza o estoque por título em ordem alfabética
    std::sort(lista_filmes.begin(), lista_filmes.end(),
              [](const Filme *a, const Filme *b) {
                return a->get_titulo() < b->get_titulo();
              });
    // Imprime estoque organizado
    for (Filme *it : lista_filmes) {
      it->imprime_relatorio();
    }
    break;

  default:
    std::cout << "ERRO: Tipo de ordenação inválido\n";
    break;
  }
  return;
}