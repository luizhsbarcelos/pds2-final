#ifndef FILME_HPP
#define FILME_HPP

#include <iostream>
#include <string>

class Filme
{
private:
    int qtd;
    int cod;
    std::string titulo;

public:
    // Construtor e destrutor
    Filme(int qtd, int cod, std::string titulo);
    virtual ~Filme();
    virtual double valor_locacao(int dias) = 0;
    virtual void imprime_relatorio() = 0;

    // Métodos getters
    int get_codigo() const;
    std::string get_titulo() const;
    int get_quantidade() const;
    virtual std::string tipo_midia() const = 0;

    // Métodos setters
    void set_quantidade(char c);
};

#endif
