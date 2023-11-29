#include "cadastro_clientes.hpp"

// Implementação dos métodos da classe Cliente
Cliente::Cliente(std::string nome, std::string cpf)
    : nome(nome), cpf(cpf) {}

std::string Cliente::obterNome() const {
    return nome;
}

std::string Cliente::obterCPF() const {
    return cpf;
}

// Implementação dos métodos da classe CadastroClientes
void CadastroClientes::cadastrarCliente(std::string nome, std::string cpf) {
    // Verificar se o CPF já existe
    if (existeClienteComCPF(cpf)) {
        std::cout << "ERRO: CPF repetido\n";
    } else {
        // Adicionar novo cliente ao vetor
        clientes.push_back(Cliente(nome, cpf));
        std::cout << "Cliente " << cpf << " cadastrado com sucesso\n";
    }
}

bool CadastroClientes::existeClienteComCPF(std::string cpf) const {
    // Utilizar std::find_if para buscar um cliente com o mesmo CPF
    auto it = std::find_if(clientes.begin(), clientes.end(),
                           [cpf](const Cliente& cliente) {
                               return cliente.obterCPF() == cpf;
                           });
    // Se encontrar, significa que o CPF já está cadastrado
    return it != clientes.end();
}

void CadastroClientes::listarClientes() const {
    std::cout << "Lista de Clientes:\n";
    // Iterar sobre o vetor de clientes e imprimir suas informações
    for (const auto& cliente : clientes) {
        std::cout << cliente.obterCPF() << " - " << cliente.obterNome() << "\n";
    }
}
