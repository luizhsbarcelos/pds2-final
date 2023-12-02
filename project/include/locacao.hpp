#ifndef LOCACAO_HPP
#define LOCACAO_HPP

#include "estoque.hpp"
#include "filme.hpp"
#include "cadastro_clientes.hpp"
#include <vector>

class Locacao {
private:
  Cliente* cliente;
  std::vector<Filme*> lista_filmes;

public:
  // Construtor e destrutor  
  Locacao(Estoque* estoque_ptr);
  ~Locacao();

  // Métodos getters
  Cliente* get_cliente();
  std::vector<Filme*> get_lista_filmes();

};

#endif