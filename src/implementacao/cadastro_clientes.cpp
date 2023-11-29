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
    if (pesquisaCPF(cpf) != nullptr) {
        std::cout << "ERRO: CPF repetido\n";
    } else {
        // Adicionar novo cliente ao vetor
        clientes.push_back(Cliente(nome, cpf));
        std::cout << "Cliente " << cpf << " cadastrado com sucesso\n";
    }
}

Cliente* CadastroClientes::pesquisaCPF(std::string cpf) const {
    // Utilize std::find_if to buscar um cliente com o mesmo CPF
    auto it = std::find_if(clientes.begin(), clientes.end(),
        [cpf](const Cliente& cliente) {
            return cliente.getCPF() == cpf;
        });

    // Se encontrar, retorna o ponteiro para o cliente
    if (it != clientes.end()) {
        return const_cast<Cliente*>(&(*it));
    } else {
        // Se não encontrar, exibe uma mensagem de erro
        std::cout << "ERRO: CPF inexistente" << std::endl;
        return nullptr;
    }
}

void CadastroClientes::listarClientes() const {
    std::cout << "Lista de Clientes:\n";
    // Iterar sobre o vetor de clientes e imprimir suas informações
    for (const auto& cliente : clientes) {
        std::cout << cliente.obterCPF() << " " << cliente.obterNome() << "\n";
    }
}
