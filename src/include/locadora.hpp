#ifndef LOCADORA_HPP
#define LOCADORA_HPP

#include "locacao.hpp"

#include <string>
#include <vector>


class Locadora
{
private:
    // Atributos
    int _id_da_locadora;
    std::string _nome_da_locadora;
    std::vector<Cliente*> _clientes_cadastrados;
    Estoque* _estoque_da_locadora;

    // Vetor que contem todas as locaoes
	static std::vector<*Locacao> _lista_de_locacoes; 

    // Arquivo de recibos e de locacoes
	static std::ofstream _recibos_txt("recibos.txt");
	static std::ofstream _locacoes_txt("locacoes.txt");

public:

    // Construtore e destrutor
    Locadora();
    ~Locadora();

}

#endif