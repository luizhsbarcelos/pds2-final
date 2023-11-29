#ifndef LOCACAO_HPP
#define LOCACAO_HPP

#include "cliente.hpp" 
#include "cadastro_filmes.hpp"

#include <vector>
#include <string>
#include <fstream>


class Locacao 
{
private:
	// Atributos da classe 
	int _id_locacao;
	Cliente* _cliente;
	std::vector<int> _filmes_alugados;

public:
	// Construtor e destrutor
	Locacao(int id, Cliente* cliente, std::vector<int> filmes);
	Locacao::Locacao();
	Locacao::~Locacao();

	// Geters
	int get_id_locacao();
	CLiente* get_cliente_locacao();
	std::vector<int> get_filmes_alugados();

	// Metodo para printar os status da locacao
	void imprimir_locacao();

};

#endif
