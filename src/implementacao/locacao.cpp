#include "locacao.hpp"
#include "cliente.hpp" 
#include "cadastro_filmes.hpp"

#include <vector>
#include <iostream>

// Construtor
Locacao::Locacao(int id, Cliente* cliente, std::vector<int> filmes_alugados) 
    : _id_locacao(id), _cliente(cliente), _filmes(filmes_alugados)
{   
}

// Construtor e destrutor padrao
Locacao::Locacao()
{
	std::cout << "ERRO: Objeto instaciado indevidamente, o destrutor sera chamado" << std::endl;
	~Locacao();
}

Locacao::~Locacao()
{
}

int Locacao::get_id_locacao()
{
    return _id_locacao;
}

Cliente* Locacao::get_cliente_locacao()
{
    return _cliente;
}

std::vector<int> Locacao::get_filmes_alugados()
{
    return _filmes_alugados;
}

Locacao::imprimir_locacao()
{
    std::cout << "==============================" << std::endl;
    std::cout << "ID: " << get_id_locacao() << std::endl;
    std::cout << "Cpf do cliente: " << get_id_locacao() << std::endl; 
    std::cout << "Filmes alugados (cód.):";
    for (int it : _filmes_alugados)
    {
        std::cout << " " << it << std::endl;
    }
    std::cout << "==============================" << std::endl << std::endl;
}


