#include "controle_locacao.hpp"
#include "cadastro_clientes.hpp"
#include "estoque.hpp"

#include <iostream>
#include <vector>

void Controle_locacao::alugar(std::string cpf, std::vector<int> filmes)
{
    // Verifica a existência do cliente
    if CadastroClientes::existeClienteComCPF(cpf){

        // Verifica a disponibilidade dos filmes 
        for (int it : filmes)
        {   
            if (_estoque_ptr->Pesquisa_filme(it) == nullptr)
                
        } 
        _locacoes_em_curso.pushback(new Locacao(_num_locacao, cpf, filmes));
    }

    

}

void Controle_locacao::devolver(std::string cpf, int dias);
void Controle_locacao::gerar_relatorio();
void Controle_locacao::recibo_devolucao();
void Controle_locacao::recibo_locacao();


