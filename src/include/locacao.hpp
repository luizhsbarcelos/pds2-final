#ifndef LOCACAO_HPP
#define LOCACAO_HPP

#include <vector>
#include <ctime> // lib para manipulacao de datas
#include <string>

class Locacao 
{
private:
	// Atributos da classe 
	int _id_locacao;
	Cliente* _cliente;
	std::vector<int> _filmes_alugados;
	// atributo datas	
	// Vetor que contem todas as locaoes
	static std::vector<*Locacao> _lista_de_locacoes; 

public:
	// Construtor e destrutor
	Locacao(int id, Cliente* cliente, std::vector<int> filmes);
	~Locacao(Cliente* cliente, int dias_alugado);
	Locacao::Locacao();
	Locacao::~Locacao();



};

#endif
