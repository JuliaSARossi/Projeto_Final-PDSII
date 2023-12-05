#ifndef ALUNO_HPP
#define ALUNO_HPP

#include <string>
#include <iostream>
#include <vector>

class Aluno {
public:
    // Construtor padrão de Aluno
    Aluno(const std::string& nome, const std::string& sobrenome, const std::string& email, int idade, char sexo);

    // Funções relacionadas ao cadastro
    void cadastrar(const std::string& login, const std::string& senha);

    // Funções relacionadas à matrícula em disciplinas
    void matricular(const std::string& codigoMateria, const std::string& codigoTurma);

    // Função para acessar notas e frequências
    void acessarNotasEFrequencias() const;

    // Getters
    std::string getNome() const;
    std::string getSobrenome() const;
    std::string getEmail() const;
    int getIdade() const;
    char getSexo() const;
    std::string getLogin() const;
    std::string getSenha() const;

        // Outros métodos necessários
    void criarLoginSenha(const std::string& login, const std::string& senha);
    bool realizarLogin(const std::string& login, const std::string& senha);
    const std::vector<std::string>& getTurmasMatriculadas() const;
        
        // Função para verificar o login e a senha
    bool verificarCredenciais(const std::string& login, const std::string& senha) const;

private:
    std::string nome;
    std::string sobrenome;
    std::string email;
    int idade;
    char sexo;
    std::string login;
    std::string senha;
    std::vector<std::string> turmasMatriculadas;
};

#endif