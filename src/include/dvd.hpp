#ifndef DVD_HPP
#define DVD_HPP

#include "filme.hpp"

class DVD : public Filme {
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
