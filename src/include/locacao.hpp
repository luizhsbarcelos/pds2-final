#ifndef LOCACAO_HPP
#define LOCACAO_HPP

#include <vector>
#include <string>


class Locacao 
{
private:
	// Atributos da classe 
	int _id_locacao;
	std::string _cpf_cliente;
	std::vector<int> _filmes_alugados;

public:

	// Métodos get
	int get_id();
	std::string get_cpf();
	std::vector<Cint> get_filmes();

	// Construtores e destrutor
	Locacao(int id, std::string cpf, std::vector<int> filmes);
	Locacao();
	~Locacao();

};

#endif
