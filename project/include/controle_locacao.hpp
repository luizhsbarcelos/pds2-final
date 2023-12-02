#ifndef CONTROLE_LOCACAO_HPP
#define CONTROLE_LOCACAO_HPP

#include "estoque.hpp"
#include "locacao.hpp"
#include <vector>

class ControleLocacao{
private:
    static std::vector<Locacao*> lista_locacoes;  

public:
    static void adicionarLocacao(Estoque* estoque_ptr);
    static void removerLocacao(std::string cpf, int dias);
    static Locacao* buscaClienteLocacao(std::string cpf);
    static Locacao* buscaFilmeLocacao(int cod);
    // Recibos
    static void reciboLocacao(Locacao* lc_ptr);
    static void reciboDevolucao(Locacao* lc_ptr);

    static bool loc_em_curso();
    // Destrutor
    ~ControleLocacao();
};

#endif