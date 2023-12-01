#ifndef DVD_HPP
#define DVD_HPP
#include "filme.hpp"
#include <string>

class DVD : public Filme {
private:
    std::string categoria;

public:
    DVD(int qtd, int cod, std::string titulo, std::string categoria);
    virtual ~DVD();
    double valor_locacao(int dias) const;
    std::string tipo_midia() const;
    void imprime_relatorio() override;
};

#endif
