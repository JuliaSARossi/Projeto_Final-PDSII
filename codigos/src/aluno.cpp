#include "aluno.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

Aluno::Aluno(const std::string& nome, const std::string& sobrenome, const std::string& email, int idade, char sexo)
    : nome(nome), sobrenome(sobrenome), email(email), idade(idade), sexo(sexo) {}

std::string Aluno::getNome() const {
    return nome;
}

std::string Aluno::getSobrenome() const {
    return sobrenome;
}

std::string Aluno::getEmail() const {
    return email;
}

int Aluno::getIdade() const {
    return idade;
}

char Aluno::getSexo() const{
    return sexo;
}

std::string Aluno::getLogin() const {
    return login;
}

std::string Aluno::getSenha() const {
    return senha;
}

void Aluno::criarLoginSenha(const std::string& novoLogin, const std::string& novaSenha) {
    login = novoLogin;
    senha = novaSenha;
}

bool Aluno::realizarLogin(const std::string& tentativaLogin, const std::string& tentativaSenha) {
    return (tentativaLogin == login && tentativaSenha == senha);
}

bool Aluno::verificarCredenciais(const std::string& login, const std::string& senha) const {
    return this->login == login && this->senha == senha;
}

void Aluno::cadastrar(const std::string& login, const std::string& senha) {
    // Apenas permite o cadastro uma vez
    if (this->login.empty() && this->senha.empty()) {
        this->login = login;
        this->senha = senha;
        std::cout << "Cadastro realizado com sucesso!\n";
    } else {
        std::cout << "Erro: O aluno ja esta cadastrado.\n";
    }
}

const std::vector<std::string>& Aluno::getTurmasMatriculadas() const {
    return turmasMatriculadas;
}

void Aluno::matricular(const std::string& codigoMateria, const std::string& codigoTurma) {
    if (turmasMatriculadas.size() < 5) { // Limite de 5 matrículas
        turmasMatriculadas.push_back(codigoTurma);
        std::cout << "Matricula realizada com sucesso na turma " << codigoTurma << "\n";
    } else {
        std::cout << "Erro: Limite de matriculas atingido.\n";
    }
}

void Aluno::acessarNotasEFrequencias() const {
    std::cout << "Notas e frequencias do aluno " << nome << " " << sobrenome << ":\n";
    for (const auto& turma : turmasMatriculadas) {
        std::string nomeArquivo = "notas_" + turma + ".txt";
        std::ifstream arquivo(nomeArquivo);

        if (arquivo.is_open()) {
            std::string linha;
            while (std::getline(arquivo, linha)) {
                std::cout << linha << "\n";
            }
            arquivo.close();
        } else {
            std::cout << "Erro: Arquivo de notas nao encontrado para a turma " << turma << "\n";
        }
    }
}