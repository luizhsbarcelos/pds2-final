#ifndef CONTROLEDELOCACAO_HPP
#define CONTROLEDELOCACAO_HPP

#include "locacao.hpp"
#include "estoque.hpp"

#include <vector>

class Controle_locacao
{
private:
    std::vector<Locacao*> _locacoes_em_curso;
    int _num_locacao = 0;
    Estoque_filmes* _estoque_ptr;

public:
    // Métodos de aluguel e devolucao
    void alugar(std::string cpf, std::vector<int> filmes);
    void devolver(std::string cpf, int dias);

    // Método gerador de relatŕorio dos alugueis em curso
    void gerar_relatorio();

    // Métodos para imprimir recibos
    void recibo_locacao();
    void recibo_devolucao();

    // Construtor

};

#endif   