#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP

#include <string>
#include <vector>
#include "turma.hpp"

class Professor {
public:
    // Construtor padrão de Professor
    Professor(const std::string& nome, const std::string& sobrenome, const std::string& areaAtuacao, int idade, char sexo);

    // Funções relacionadas ao cadastro
    void cadastrar(const std::string& login, const std::string& senha);

    // Função para matricular como professor em uma matéria
    void matricular(const std::string& codigoMateria, const std::string& codigoTurma);
    bool temTurmaAssociada(const std::string& codigoMateria) const;


    // Função para registrar notas e frequências de alunos
    void registrarNotasEFrequencias(const std::string& codigoTurma, const std::vector<std::string>& alunos, const std::vector<int>& notas, const std::vector<int>& frequencias);

    // Função para acessar notas e frequências de uma turma
    void acessarNotasEFrequencias(const std::string& codigoTurma) const;

    // Função para verificar o login e a senha
    bool verificarCredenciais(const std::string& login, const std::string& senha) const;

    // Getters
    std::string getNome() const;
    std::string getSobrenome() const;
    int getIdade() const;
    char getSexo() const;
    std::string getAreaAtuacao() const;
    std::string getLogin() const;
    std::string getSenha() const;
    const std::vector<std::string>& getTurmasAssociadas() const;

    // Outros métodos necessários
    void criarLoginSenha(const std::string& login, const std::string& senha);
    bool realizarLogin(const std::string& login, const std::string& senha);

private:
    std::string nome;
    std::string sobrenome;
    std::string areaAtuacao;
    int idade;
    char sexo;
    std::string login;
    std::string senha;
    std::string turmas;
    std::vector<std::string> turmasMatriculadas;
};

#endif