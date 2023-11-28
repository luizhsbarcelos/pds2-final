#include<vector>
#include "locacao.hpp"

// Construtor
Locacao::Locacao(int id, Cliente* cliente, std::vector<int> filmes_alugados) 
    : _id_locacao(id), _cliente(cliente), _filmes(filmes_alugados)
{
    _lista_de_locacoes.pushback(this);
}

// Destrutor
Locacao::~Locacao(Cliente* cliente, int dias_alugado)
{

}

Locacao::Locacao();
Locacao::~Locacao();


