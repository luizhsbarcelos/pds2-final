# ProjetoFinal

Este projeto visa implementar um sistema de controle para uma vídeo-locadora, aplicando conceitos estudados e praticados durante o semestre na matéria de Programação e Desenvolvimento de Software II. A ideia central é modelar, implementar, testar e documentar um sistema que seja compreensível, reutilizável e de fácil manutenção, utilizando os princípios de Programação Orientada a Objetos (POO), estruturas de dados, modularidade e corretude.

O projeto é dividido em três partes:
  - Cadastro de Filmes  
  - Cadastro de Clientes  
  - Controle de Locação
    
# Cadastro de filmes
  Cada filme possui um Código Numérico, um Título e a quantidade de unidades disponíveis. A vídeo-locadora trabalha com DVDs e Fitas de Vídeo. Os DVDs podem ser de três categorias: lançamentos, estoque ou promoção. As fitas têm uma única categoria e um campo para indicar se estão rebobinadas. O valor da locação varia conforme a mídia e categoria.

# Cadastro de Clientes
  O cadastro de clientes contém os campos de nome e CPF. E as operações incluem: inserir novos clientes, remover clientes, pesquisar e imprimir relatórios.

# Controle de Locação
  Este módulo cuida das locações, onde o cliente fornece seu CPF e os códigos dos itens a serem alugados. O sistema armazena essas informações, decrementa a quantidade disponível dos itens e calcula automaticamente o valor a ser pago na devolução. O sistema também emite recibos de aluguel e devolução.

# Arquivos do programa
  Os arquivos do programa podem ser encontrados na pasta src
  - project/include: A pasta 'include' possui os arquivos cabeçalhos, ou seja, os arquivos headers (.hpp) para implementação.
  - project/src: A pasta 'implementacao' possui os arquivos com os códigos, ou seja, os arquivos que contém as implementações desses códigos. 
  - project/data: A pasta 'data' possui os arquivos que são usados para testar o programa.
  - project/build: A pasta build contém os arquivos objeto criados na compilação.

# Instrucoes para Entrada e Saída
O programa possui um caso teste no arquivo, mas o usuário também pode inserir os comandos manualmente e o sistema imprime os relatórios, mensagens de confirmação, erros, etc.
OBS: Para funcionar, basta apenas rodar o controle locadora. Se necessário, use makefile.
  - Comandos de entrada do programa:
    ```
    LA     //Lê o arquivo
    CF     //Cadastra um filme novo
    RF     //Remove um filme da lista
    LF     //Lista os filmes cadastrados por código ou título
    CC     //Cadastra um novo cliente
    RC     //Remove o cliente
    LC     //Lista os clientes cadastrados por código ou nome
    AL     //Alugar filme
    DV     //Devolve filme
    FS     //Finaliza o Sistema
    ```
  - Exemplos de saida do programa:
    ```
    ERRO: arquivo inexistente        //Caso o programa não encontre o arquivo
    Filme <código> cadastrado com sucesso       //Filme cadastrado
    ERRO: dados incorretos           //Erro caso o usuário tenha inserido algum dado do filme incorreto
    ERRO: codigo repetido            //Erro caso já exista um filme cadastrado com o código inserido
    Cliente <CPF> cadastrado com sucesso        //Cliente cadastrado
    ERRO: dados incorretos           //Erro caso o usuário tenha inserido algum dado do cliente incorreto
    ERRO: CPF repetido              //Erro caso já exista um cliente cadastrado com o cpf inserido
    Cliente <CPF> <Nome> alugou os filmes: <código> <título> <FITA|DVD>          //Relatório de aluguel de filmes pelo cliente
    Cliente <CPF> <Nome> devolveu os filmes: <código> [Valor a Pagar]            //Relatório de devolução de filmes pelo cliente 
    ```

  O programa foi desenvolvido para que seja um programa reutilizável, acessível, fácil de manipular, de manter visando principalmente as técnicas de programação defensiva.

# Documentação
  A documentação criada pelo Doxygen encontra-se na pasta data.
  
# Principais dificuldades para desenvolvimento do trabalho
  O grupo tentou trabalhar em conjunto para que fosse desenvolvido um programa coerente e que conversasse bem entre seua códigos, porém, todos concordaram que a maior dificuldade enfrentada pelo grupo foi haver concordância e encaixe dos códigos. Era como se fosse um grande quebra cabeça onde cada um tentava montar uma parte e deveria juntar tudo no final. Isso dificultou um pouco a modelagem e o desenvolvimento causando atraso para finalização do programa. Porém, acredita-se que o código final atende os requisitos propostos no enunciado e possuim um bom funcionamento.

# Integrantes do grupo
```
Ana Luísa Messias Ferreira Mendes    - 2020104746
Bernardo Martins de Castro Rossetti  - 2018050243
Geovani Aguilar Paixão               - 2022035636
João Aparecido de Brito              - 2021027680
Luiz Henrique Silveira Barcelos      - 2017105893
```
