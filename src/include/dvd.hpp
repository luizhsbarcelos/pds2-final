#ifndef DVD_HPP
#define DVD_HPP

#include "cadastro_filmes.hpp"

class DVD : public Cadastro_filme {
private:
    int categoria;

public:
    DVD(int cod, std::string titulo, int qtd, int categoria);
    double valor_locacao(int dias) const override;
    std::string tipo_locacao() const override;
    void imprime_relatorio() override;
};

#endif // DVD_HPP
