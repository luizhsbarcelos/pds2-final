#include "../include/cadastro_clientes.hpp"

#include <algorithm>
#include <cctype>
#include <string>
#include <vector>

// Implementação dos métodos da classe Cliente
Cliente::Cliente(std::string cpf, std::string nome) : nome(nome), cpf(cpf) {}

std::string Cliente::get_nome() const { return nome; }

std::string Cliente::get_CPF() const { return cpf; }

//----------------------------------------------------------------//
//----------------------------------------------------------------//

// Implementação dos métodos da classe ControleClientes
void ControleClientes::cadastrarCliente() {
  std::string cpf;
  std::cin >> cpf;
  std::string nome;
  std::cin >> nome;

  // Verificar se o CPF já existe
  if (pesquisaCPF(cpf) != nullptr) {
    std::cout << "ERRO: CPF repetido\n";
    return;
  } else {
    // Adicionar novo cliente ao vetor
    lista_de_clientes.push_back(new Cliente(cpf, nome));
    std::cout << "Cliente " << cpf << " cadastrado com sucesso\n";
    return;
  }
}

void ControleClientes::removerCliente() {
  std::string cpf;
  std::cin >> cpf;
  // Verificar se o CPF existe
  Cliente *aux;
  aux = pesquisaCPF(cpf);
  if (aux != nullptr) {
    // Usa find para achar o iterador contendo o CPF
    auto it =
        std::find(lista_de_clientes.begin(), lista_de_clientes.end(), aux);
    if (it != lista_de_clientes.end()) {
      lista_de_clientes.erase(it);

      std::cout << "Cliente: " << cpf << " removido com sucesso\n";
      // Delete memória alocada
      delete aux;
    }
    return;
  }
}

Cliente *ControleClientes::pesquisaCPF(std::string cpf) {

  // Verifica se cpf está vazio
  if (cpf.empty()) {

    std::cout << "ERRO: dados incorretos\n";
    return nullptr;
  }
  // Verifica se cpf é composto apenas de números
  for (char c : cpf) {
    if (!std::isdigit(c)) {
      std::cout << "ERRO: dados incorretos\n";
      return nullptr;
    }
  }
  // Verifica existência do cliente;
  for (Cliente *it : lista_de_clientes) {
    if (it->get_CPF() == cpf) {
      return (it);
    }
  }
  std::cout << "ERRO: CPF inexistente\n";
  return nullptr;
}

void ControleClientes::listarClientes() {
  char comando;
  std::cin >> comando;
  switch (comando) {
  case 'C':
    // Organiza os clientes por CPF em ordem crescente
    std::sort(lista_de_clientes.begin(), lista_de_clientes.end(),
              [](const Cliente *a, const Cliente *b) {
                return a->get_CPF() < b->get_CPF();
              });
    // Imprime clientes organizados
    for (Cliente *it : lista_de_clientes) {
      std::cout << it->get_CPF() << " " << it->get_nome() << std::endl;
    }
    break;

  case 'N':
    // Organiza os clientes por nome em ordem alfabética
    std::sort(lista_de_clientes.begin(), lista_de_clientes.end(),
              [](const Cliente *a, const Cliente *b) {
                return a->get_nome() < b->get_nome();
              });
    // Imprime clientes organizados
    for (Cliente *it : lista_de_clientes) {
      std::cout << it->get_CPF() << " " << it->get_nome() << std::
    }
    break;

    default;
    std::cout << "ERRO: Tipo de ordenação inválido\n";
    break;
  }
}
