#ifndef DVD_HPP
#define DVD_HPP

#include "cadastro_filmes.hpp"

class DVD : public Cadastro_filme {
private:
    int categoria;

public:
    DVD(int cod, std::string titulo, int qtd, int categoria);
    enum Categoria { Lancamento = 1, Estoque = 2, Promocao = 3 };
    double valor_locacao(int dias) const;
    std::string tipo_locacao() const;
    void imprime_relatorio() override;
};

#endif 
