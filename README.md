# Sistema Acadêmico

## Descrição do Projeto
O [presente trabalho](https://github.com/JuliaSARossi/Projeto_Final-PDSII) tem como objetivo o desenvolvimento de um Sistema Acadêmico em C++. Esse sistema oferece funcionalidades básicas, como cadastro de alunos, acesso ao sistema, cadastro de matérias, cadastro de professores, organização de turmas e outros recursos relacionados à gestão acadêmica. Nesse sistema, os alunos têm a possibilidade de se cadastrarem no sistema, acessar suas notas e frequências do semestre, e ainda fazer matrículas em matérias do curso. No caso dos professores, eles podem se cadastrar no sistema como professores, lançar notas e frequências dos alunos.

<ol>
  <li>Status:</li> Atualmente, o projeto se encontra em desenvolvimento;
  <li>Acesso:</li> https://github.com/JuliaSARossi/Projeto_Final-PDSII
</ol>

## Estrutura
Classes:

a)Aluno: A classe `Aluno` representa um aluno e armazena informações como nome, sobrenome, e-mail, idade, sexo, login e senha. Ela possui métodos de acesso para recuperar essas informações.

b)Materia: A classe `Materia` representa uma matéria acadêmica e armazena informações como código, nome e departamento. Ela também possui métodos de acesso para recuperar essas informações.

c)Professor: A classe `Professor` representa um professor e armazena informações como nome, e-mail, idade, sexo e área de atuação. Métodos de acesso são fornecidos para recuperar essas informações.

d)Sistema: A classe `Sistema` é o componente central do sistema de gestão acadêmica. Ela mantém um array de alunos e fornece métodos para cadastrar alunos no sistema e acessar o sistema com login e senha.

e)Turma: A classe `Turma` representa uma turma e armazena informações como código, número de vagas e nome do professor. Métodos de acesso são fornecidos para recuperar essas informações.


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

## Desenvolvimento

Para o desenvolvimento da estrutura do código, utilizamos o Github como plataforma para armazenamento de repositórios online e atualização do código de forma online.

## Colaboradores

[Anna Clara Guimarães Tomaz de Souza](https://github.com/aannacgt)<br>
[Júlia Silva Antunes Rossi](https://github.com/JuliaSARossi)<br>
[Lucas Vinícius Lopes de Araújo](https://github.com/LucasAraujoUFMG)  

## Conclusão

O desenvolvimento deste projeto desempenhou um papel crucial na ampliação das habilidades em linguagem de programação C++. Proporcionou uma significativa expansão do conhecimento dos colaboradores, assim como a aplicação prática de conceitos de lógica de programação. Além disso, a iniciativa permitiu aos membros da equipe vivenciar a experiência de colaborar em um projeto em grupo, compartilhando responsabilidades e oferecendo suporte quando necessário.
