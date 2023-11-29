#ifndef CADASTRO_FILME_HPP
#define CADASTRO_FILME_HPP

#include <iostream>
#include <string>

class Filme {
private:
    int cod;
    std::string titulo;
    int qtd;

public:
    Filme(int cod, std::string titulo, int qtd);
    virtual ~Filme();
    double valor_locacao(int dias) const;
    virtual void imprime_relatorio() = 0;
    virtual std::string tipo_locacao() const = 0;
    int get_codigo() const;
    std::string get_titulo() const;
    int get_quantidade() const;
};

#endif
