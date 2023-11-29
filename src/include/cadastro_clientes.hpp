#ifndef CADASTRO_CLIENTES_HPP
#define CADASTRO_CLIENTES_HPP

#include <iostream>
#include <vector>
#include <algorithm>

// Classe para representar um cliente
class Cliente {
private:
    std::string nome;
    std::string cpf;

public:
    // Construtor para inicializar um cliente
    Cliente(std::string nome, std::string cpf);

    // Métodos getters
    std::string obterNome() const;
    std::string obterCPF() const;
};

// Classe para o cadastro de clientes
class CadastroClientes {
private:
    std::vector<Cliente> clientes;

public:
    // Método para cadastrar um novo cliente
    void cadastrarCliente(std::string nome, std::string cpf);

    // Método para verificar se um CPF já está cadastrado
    bool existeClienteComCPF(std::string cpf) const;

    // Método para listar todos os clientes
    void listarClientes() const;
};

#endif  // CADASTRO_CLIENTES_HPP
