#include "controle_locacao.hpp"
#include "cadastro_clientes.hpp"
#include "estoque.hpp"

#include <iostream>
#include <vector>

void Controle_locacao::alugar(std::string cpf, std::vector<int> filmes) {
  // Verifica a existência do cliente
  *Cliente aux = nullptr;
  aux = CadastroClientes::pesquisaCPF(cpf);
  if (aux->obterCPF() == cpf) {
    // Verifica a disponibilidade dos filmes
    for (int it : filmes) {
      if (_estoque_ptr->Pesquisa_filme(it) == nullptr) {
        return;
      }
    }
    // Se locação é válida
    _locacoes_em_curso.pushback(new Locacao(_num_locacao, cpf, filmes));
    std::cout << "Cliente " << aux->obterCPF() << " " << aux->obterNome()
              << " alugou os filmes:\n";

    Cadastro_filme *aux = nullptr;
    for (int it : filmes) {
      aux = _estoque_ptr->Pesquisa_filme(it);
      std::cout << aux->get_codigo() << " " << aux->get_titulo() << " "
                << aux->tipo_locacao() << "\n";
    }
  } else {
    return;
  }
}

void Controle_locacao::devolver(std::string cpf, int dias);
void Controle_locacao::gerar_relatorio();
void Controle_locacao::recibo_devolucao();
void Controle_locacao::recibo_locacao();
