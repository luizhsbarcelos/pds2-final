#ifndef ESTOQUE_HPP
#define ESTOQUE_HPP

#include <vector>
#include <string>
#include "filme.hpp"

class Estoque {
private:
    std::vector<Filme*> lista_filmes;

public:
    void Adiciona_filme(Filme* filme);
void Adiciona_filme();
    void Remove_filme(int codigo);
    Filme* Pesquisa_filme(int codigo);
    void Imprime_relatorio();
};

#endif 
