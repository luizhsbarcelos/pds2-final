#include "estoque.hpp"
#include <iostream>
#include <algorithm>

void Estoque_filmes::Adiciona_filme(Cadastro_filme* filme) {
    lista_filmes.push_back(filme);
}

void Estoque_filmes::Remove_filme(int codigo) {
    auto it = std::remove_if(lista_filmes.begin(), lista_filmes.end(),
        [codigo](Cadastro_filme* filme) { return filme->get_codigo() == codigo; });

    lista_filmes.erase(it, lista_filmes.end());
}

Cadastro_filme* Estoque_filmes::Pesquisa_filme(int codigo) {
    for (Cadastro_filme* filme_vetor : lista_filmes) {
        if (filme_vetor->get_codigo() == codigo) {
            return filme_vetor;
        }
    }
    std::cout << "Não encontrado." << std::endl;
    return nullptr;
}

void Estoque_filmes::Imprime_relatorio() {
    std::cout << "Relatorio de Estoque:\n";
    for (Cadastro_filme* filme_vetor : lista_filmes) {
        std::cout << "Código: " << filme_vetor->get_codigo() << ", Título: " << filme_vetor->get_titulo() << ", Quantidade: " << filme_vetor->get_quantidade() << "\n";
    }
}
