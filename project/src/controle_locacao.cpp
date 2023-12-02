#include "../include/controle_locacao.hpp"
#include "../include/cadastro_clientes.hpp"
#include "../include/estoque.hpp"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<Locacao *> ControleLocacao::lista_locacoes;

void ControleLocacao::reciboLocacao(Locacao *lc_ptr) {}

void ControleLocacao::reciboDevolucao(Locacao *lc_ptr) {}

Locacao *ControleLocacao::buscaClienteLocacao(std::string cpf) {
  for (Locacao *loc_ptr : lista_locacoes) {
    if (loc_ptr->get_cliente()->get_CPF() == cpf) {
      return loc_ptr;
    }
  }
  return nullptr;
}

Locacao *ControleLocacao::buscaFilmeLocacao(int cod) {
  for (Locacao *loc_ptr : lista_locacoes) {
    for (auto *fptr : loc_ptr->get_lista_filmes()) {
      if (fptr->get_codigo() == cod) {
        return loc_ptr;
      }
    }
  }
  return nullptr;
}

void ControleLocacao::adicionarLocacao(Estoque *estoque_ptr) {

  Locacao *aux_loc = new Locacao(estoque_ptr);
  ControleLocacao::lista_locacoes.push_back(aux_loc);

  return;
}

void ControleLocacao::removerLocacao(std::string cpf, int dias) {
  if (lista_locacoes.empty()) {
    std::cout << "ERRO: não existem locações em curso\n";
    return;
  }

  if (ControleClientes::pesquisaCPF(cpf) == nullptr) {
    std::cout << "ERRO: CPF inexistente \n";
    return;
  }

  double total_locacao = 0;
  Locacao *loc_ptr = ControleLocacao::buscaClienteLocacao(cpf);
  if (loc_ptr != nullptr) {
    std::cout << "Cliente: " << cpf << " " << loc_ptr->get_cliente()->get_nome()
              << " devolveu os filmes:\n";

    for (auto *fptr : loc_ptr->get_lista_filmes()) {
      std::cout << fptr->get_codigo() << " R$" << fptr->valor_locacao(dias)
                << std::endl;
      fptr->set_quantidade('+');

      total_locacao += fptr->valor_locacao(dias);
    }

    std::cout << "Total a pagar: R$" << total_locacao << std::endl;

    auto it = std::find(ControleLocacao::lista_locacoes.begin(),
                        ControleLocacao::lista_locacoes.end(), loc_ptr);
    lista_locacoes.erase(it);

    Locacao *aux = loc_ptr;
    delete aux;

  } else {
    std::cout << "ERRO: este cliente não possui locação em curso\n";
  }
  return;
}