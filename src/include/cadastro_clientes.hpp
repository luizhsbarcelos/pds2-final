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
    std::string get_nome() const;
    std::string get_CPF() const;
};

//----------------------------------------------------------------//
//----------------------------------------------------------------//

// Classe para o cadastro de clientes
class ControleClientes {
private:
    static std::vector<Cliente*> lista_de_clientes;

public:
    // Método para cadastrar/remover um novo cliente
    static void cadastrarCliente();
    static void removerCliente();

    // Método para verificar se um CPF já está cadastrado
    static Cliente* pesquisaCPF(std::string cpf);

    // Método para listar todos os clientes
    static void listarClientes();

};

#endif  // CADASTRO_CLIENTES_HPP
