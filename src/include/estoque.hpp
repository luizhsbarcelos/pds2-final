#ifndef ESTOQUE_HPP
#define ESTOQUE_HPP

#include <vector>
#include "cadastro_filmes.hpp"

class Estoque_filmes {
private:
    std::vector<Cadastro_filme*> lista_filmes;

public:
    void Adiciona_filme(Cadastro_filme* filme);
    void Remove_filme(int codigo);
    Cadastro_filme* Pesquisa_filme(int codigo);
    void Imprime_relatorio();
};

#endif 
