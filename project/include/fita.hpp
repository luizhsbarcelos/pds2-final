#ifndef FITA_HPP
#define FITA_HPP

#include "filme.hpp"

class Fita : public Filme {
private:
    bool fita_rebobinada = true;

public:
    Fita(int qtd, int cod, std::string titulo);
    virtual ~Fita();
    bool rebobina() const;
    double valor_locacao(int dias) override;
    std::string tipo_midia() const override;
    void imprime_relatorio() override;
};

#endif 
