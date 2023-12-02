#include "../include/locacao.hpp"
#include "../include/arquivo.hpp"
#include "../include/cadastro_clientes.hpp"
#include "../include/estoque.hpp"
#include "../include/filme.hpp"
#include <iostream>
#include <string>

// Destrutor padrão
Locacao::~Locacao() {}

// Destrutor

// Contrutor
Locacao::Locacao(Estoque *estoque_ptr) {
  if (estoque_ptr == nullptr) {
    std::cout << "ERRO: ponteiro de estoque inválido\n";
    Locacao::~Locacao();
  } else {

    std::string cpf;
    std::cin >> cpf;

    cliente = ControleClientes::pesquisaCPF(cpf);

    if (cliente == nullptr) {
      std::cout << "ERRO: CPF inexistente \n";
      Locacao::~Locacao();
    } else {
      // Faz leitura da linha de filmes
      std::string linha_filmes;
      std::getline(std::cin, linha_filmes);

      // Manipulação para separar os filmes
      std::vector<std::string> cdg_filmes =
          Arquivo::separa_palavras(linha_filmes);
      // Adiciona filmes à locacao

      for (auto it : cdg_filmes) {
        int cdg = std::stoi(it);

        // Pesquisa existencia do filme no estoque
        Filme *filme = estoque_ptr->Pesquisa_filme(cdg);

        // Não permite locação de filmes caso algum não exista
        if (filme == nullptr) {
          Locacao::~Locacao();
        } else {

          if (filme->get_quantidade() > 0) {
            lista_filmes.push_back(filme);
            filme->set_quantidade('-');
          } else {
            std::cout << "ERRO: filme " << cdg << " indisponivel\n";
          }
        }
      }
      std::cout << "Cliente " << cpf << " " << cliente->get_nome()
                << " alugou os filmes:\n";
      for (auto it : lista_filmes) {
        std::cout << it->get_codigo() << " " << it->get_titulo() << " "
                  << it->tipo_midia() << std::endl;
      }
    }
  }
}

Cliente *Locacao::get_cliente() { return cliente; }

std::vector<Filme *> Locacao::get_lista_filmes() { return lista_filmes; }