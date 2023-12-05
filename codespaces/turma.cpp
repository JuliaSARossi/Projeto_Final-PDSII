#include "turma.hpp"
#include "aluno.hpp"
#include "professor.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

Turma::Turma(const std::string& codigoMateria, const std::string& codigoTurma, Professor* professor)
    : codigoMateria(codigoMateria), professor(professor) {}

const std::string& Turma::getCodigoMateria() const {
    return codigoMateria;
}

Professor* Turma::getProfessor() const {
    return professor;
}

const std::vector<Aluno*>& Turma::getAlunos() const {
    return alunos;
}

bool Turma::atingiuLimiteAlunos() const {
    return alunos.size() >= limiteMaxAlunos;
}

const std::string& Turma::getCodigoTurma() const {
    return codigoTurma;
}

bool Turma::matricularAluno(Aluno* aluno) {
    // Verifica se o aluno já está matriculado
    auto it = std::find(alunos.begin(), alunos.end(), aluno);
    if (it == alunos.end()) {
        // Verifica se a turma atingiu o limite máximo de alunos
        if (limiteMinAlunos < alunos.size() < limiteMaxAlunos) {
            alunos.push_back(aluno);
            std::cout << "Aluno matriculado com sucesso na turma " << codigoMateria << "\n";
            return true;
        } else {
            std::cout << "Erro: Limite de alunos atingido para a turma " << codigoMateria << "\n";
        }
    } else {
        std::cout << "Erro: Aluno ja matriculado nesta turma.\n";
    }
    return false;
}

void Turma::excluirAluno(Aluno* aluno) {
    // Remove o aluno da lista de matriculados
    auto it = std::find(alunos.begin(), alunos.end(), aluno);
    if (it != alunos.end()) {
        alunos.erase(it);
        std::cout << "Aluno removido com sucesso da turma " << codigoMateria << "\n";
    } else {
        std::cout << "Erro: Aluno nao encontrado nesta turma.\n";
    }
}