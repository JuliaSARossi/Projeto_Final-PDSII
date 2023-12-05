#include "professor.hpp"
#include "materia.hpp"
#include "sistema.hpp"
#include "turma.hpp"
#include "aluno.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

Professor::Professor(const std::string& nome, const std::string& sobrenome, const std::string& areaAtuacao, int idade, char sexo)
    : nome(nome), sobrenome(sobrenome), areaAtuacao(areaAtuacao), idade(idade), sexo(sexo) {}

std::string Professor::getNome() const {
    return nome;
}

std::string Professor::getSobrenome() const {
    return sobrenome;
}

int Professor::getIdade() const {
    return idade;
}

char Professor::getSexo() const {
    return sexo;
}

std::string Professor::getAreaAtuacao() const {
    return areaAtuacao;
}

std::string Professor::getLogin() const {
    return login;
}

std::string Professor::getSenha() const {
    return senha;
}

void Professor::criarLoginSenha(const std::string& novoLogin, const std::string& novaSenha) {
    login = novoLogin;
    senha = novaSenha;
}

void Professor::cadastrar(const std::string& login, const std::string& senha) {
    // Apenas permite o cadastro uma vez
    if (this->login.empty() && this->senha.empty()) {
        this->login = login;
        this->senha = senha;
        std::cout << "Cadastro realizado com sucesso!\n";
    } else {
        std::cout << "Erro: O professor ja esta cadastrado.\n";
    }
}

bool Professor::realizarLogin(const std::string& tentativaLogin, const std::string& tentativaSenha) {
    return (tentativaLogin == login && tentativaSenha == senha);
}

bool Professor::verificarCredenciais(const std::string& login, const std::string& senha) const {
    return (this->login == login && this->senha == senha);
}

void Professor::matricular(const std::string& codigoMateria,const std::string& codigoTurma) {
    if (turmasMatriculadas.size() < 2) { // Limite de 2 matrículas
        turmasMatriculadas.push_back(codigoMateria);
        for (std::string i : turmasMatriculadas) {
        std::cout << i << " ";    }
        std::cout << "Matricula realizada com sucesso na materia " << codigoMateria << "\n";
    } else {
        std::cout << "Erro: Limite de materias atingido.\n";
    }
}

const std::vector<std::string>& Professor::getTurmasAssociadas() const {
    return turmasMatriculadas;
}

void Professor::registrarNotasEFrequencias(const std::string& codigoTurma, const std::vector<std::string>& alunos, const std::vector<int>& notas, const std::vector<int>& frequencias) {
    std::string nomeArquivo = "notas_" + codigoTurma + ".txt";
    std::ofstream arquivo(nomeArquivo, std::ios::app);

    if (arquivo.is_open()) {
        for (size_t i = 0; i < alunos.size(); ++i) {
            arquivo << alunos[i] << "Notas e frequencias do aluno na matéria " << codigoTurma << "\n" << notas[i] << "\n" << frequencias[i] << "\n";
        }
        arquivo.close();
        std::cout << "Notas e frequencias registradas com sucesso para a turma " << codigoTurma << "\n";
    } else {
        std::cout << "Erro: Impossivel abrir o arquivo de notas para a turma " << codigoTurma << "\n";
    }
}

void Professor::acessarNotasEFrequencias(const std::string& codigoTurma) const {
    std::cout << "Notas e frequencias da turma " << codigoTurma << " ministrada pelo professor " << nome << " " << sobrenome << ":\n";
    std::string nomeArquivo = "notas_" + codigoTurma + ".txt";
    std::ifstream arquivo(nomeArquivo);

    if (arquivo.is_open()) {
        std::string linha;
        while (std::getline(arquivo, linha)) {
            std::cout << linha << "\n";
        }
        arquivo.close();
    } else {
        std::cout << "Erro: Arquivo de notas nao encontrado para a turma " << codigoTurma << "\n";
    }
}

bool Professor::temTurmaAssociada(const std::string& codigoMateria) const {
    // Itera sobre as turmas associadas ao professor
    for (auto it = turmasMatriculadas.begin(); it != turmasMatriculadas.end(); ++it) {
        // Verifica se a turma tem o mesmo código de matéria
        if (0 < turmasMatriculadas.size() <= 2) {
            return true; // Turma associada encontrada
        }
    }
    return false; // Nenhuma turma associada encontrada
}