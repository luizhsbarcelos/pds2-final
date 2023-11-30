#include "../include/cadastro_clientes.hpp"

#include <cctype>
#include <string>
#include <vector>

// Implementação dos métodos da classe Cliente
Cliente::Cliente(std::string cpf, std::string nome) : nome(nome), cpf(cpf) {}

std::string Cliente::get_nome() const { return nome; }

std::string Cliente::get_CPF() const { return cpf; }

//--------------------------------------------------------------//
// Implementação dos métodos da classe ControleClientes

void ControleClientes::cadastrarCliente(std::string cpf, std::string nome) {
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

Cliente *ControleClientes::pesquisaCPF(std::string cpf) const {
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

void ControleClientes::listarClientes() const {
  std::cout << "Lista de Clientes:\n";
  // Iterar sobre o vetor de clientes e imprimir suas informações
  for (const auto &cliente : li) {
    std::cout << cliente.obterCPF() << " " << cliente.obterNome() << "\n";
  }
}
