# Sistema Acadêmico

## Descrição do Projeto
O presente trabalho tem como objetivo o desenvolvimento de um Sistema Acadêmico em C++. Esse sistema oferece funcionalidades básicas, como cadastro de alunos, acesso ao sistema, cadastro de matérias, cadastro de professores, organização de turmas e outros recursos relacionados à gestão acadêmica. Nesse sistema, os alunos têm a possibilidade de se cadastrarem no sistema, acessar suas notas e frequências do semestre, e ainda fazer matrículas em matérias do curso. No caso dos professores, eles podem se cadastrar no sistema como professores, lançar notas e frequências dos alunos.

<ol>
  <li>Status:</li> Atualmente, o projeto se encontra em desenvolvimento;
  <li>Acesso:</li> https://github.com/JuliaSARossi/Projeto_Final-PDSII
</ol>

## Dependências

Para compilar e executar este projeto, você precisará de um compilador C++ compatível com o padrão C++11 ou superior. Além disso, o código faz uso da biblioteca [doctest](https://github.com/onqtam/doctest) para os testes unitários.

## Instruções de Compilação e Execução

1. **Compilação:**

   Abra um terminal na pasta do projeto e execute o seguinte comando para compilar o programa:

   g++ -std=c++11 main.cpp Aluno.cpp Sistema.cpp Materia.cpp Professor.cpp Turma.cpp -o sistema_academico
2. **Execução:**

   Após a compilação, execute o programa resultante:

   ./sistema_academico
3. **Observações:**

    * É necessário ajustar as comandos de compilação conforme necessário, dependendo do compilador e do sistema operacional que você está usando.
    * O código foi projetado para funcionar em ambientes Linux/WSL, mas pode ser necessário ajustar detalhes dependendo das configurações específicas de seu ambiente.
