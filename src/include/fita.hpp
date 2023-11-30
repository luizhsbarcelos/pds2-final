#ifndef FITA_HPP
#define FITA_HPP

#include "filme.hpp"

class Fita : public Filme {
private:
    bool fita_rebobinada = true;

public:
    Fita(int qtd, int cod, std::string titulo);
    ~Fita();
    bool rebobina() const;
    double valor_locacao(int dias) const;
    std::string tipo_locacao() const;
    void imprime_relatorio() override;
};

#endif 
