#ifndef ESTOQUE_HPP
#define ESTOQUE_HPP

#include <vector>
#include <string>
#include "filme.hpp"

class Estoque {
private:
    std::vector<Filme*> lista_filmes;

public:
    void Adiciona_filme(std::vector<std::string>& filmes);
    void Remove_filme(int codigo);
    Filme* Pesquisa_filme(int codigo);
    void Imprime_relatorio();
    void listar_filmes();
};

#endif 
