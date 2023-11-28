int main() {
    Estoque_filmes estoque;

    std::ifstream arquivo("estoque.txt");
    if (arquivo.is_open()) {
        char tipo;
        int quantidade, codigo;
        std::string titulo, categoria;
        bool rebobinada;

       while (arquivo >> tipo) {
            switch (tipo) {
                case 'F':
                    arquivo >> quantidade >> codigo >> titulo >> rebobinada;
                    estoque.Adiciona_filme(new Fita(codigo, titulo, quantidade, rebobinada));
                    break;
                case 'D':
                    arquivo >> quantidade >> codigo >> titulo >> categoria;
                    if (categoria == "Lancamento") {
                        estoque.Adiciona_filme(new DVD(codigo, titulo, quantidade, DVD::Lancamento));
                    } else if (categoria == "Estoque") {
                        estoque.Adiciona_filme(new DVD(codigo, titulo, quantidade, DVD::Estoque));
                    } else if (categoria == "Promocao") {
                        estoque.Adiciona_filme(new DVD(codigo, titulo, quantidade, DVD::Promocao));
                    } else {
                        std::cout << "ERRO: dados incorretos\n";
                    }
                    break;
                default:
                    std::cout << "ERRO: dados incorretos\n";
            }
        }

        arquivo.close();
    } else {
        std::cout << "ERRO: Nao foi possivel abrir o arquivo de estoque.\n";
        return 1;
    }

    estoque.Imprime_relatorio();

    return 0;
}
