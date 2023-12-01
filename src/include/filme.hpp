#ifndef FILME_HPP
#define FILME_HPP

#include <iostream>
#include <string>

class Filme {
private:
    int cod;
    std::string titulo;
    int qtd;

public:
    Filme(int qtd, int cod, std::string titulo);
    virtual ~Filme();
    double valor_locacao(int dias) const;
    virtual void imprime_relatorio() = 0;
    virtual std::string tipo_midia() const = 0;
    int get_codigo() const;
    std::string get_titulo() const;
    int get_quantidade() const;

};

#endif

