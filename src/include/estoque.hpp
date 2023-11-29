#ifndef ESTOQUE_HPP
#define ESTOQUE_HPP

#include <vector>
#include "filme.hpp"

class Estoque {
private:
    std::vector<Filme*> lista_filmes;

public:
    void Adiciona_filme(Filme* filme);
    void Remove_filme(int codigo);
    Filme* Pesquisa_filme(int codigo);
    void Imprime_relatorio();
};

#endif 
