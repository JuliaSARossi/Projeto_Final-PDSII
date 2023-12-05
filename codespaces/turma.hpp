#ifndef TURMA_HPP
#define TURMA_HPP

#include <string>
#include <vector>
#include "aluno.hpp"
#include "professor.hpp"
#include "materia.hpp"

class Aluno;
class Professor;

class Turma {
public:
    // Construtor padrão de Turma
    Turma(const std::string& codigoMateria, const std::string& codigoTurma, Professor* professor);

    // Funções relacionadas à matrícula de alunos
    bool matricularAluno(Aluno* aluno);
    void excluirAluno(Aluno* aluno);

    // Getters
    const std::string& getCodigoMateria() const;
    const std::string& getCodigoTurma() const;
    Professor* getProfessor() const;
    const std::vector<Aluno*>& getAlunos() const;

    // Verifica se a turma atingiu o limite de alunos
    bool atingiuLimiteAlunos() const;

private:
    std::string codigoMateria;
    std::string codigoTurma;
    Professor* professor;
    std::vector<Aluno*> alunos;
    static const int limiteMinAlunos = 10;
    static const int limiteMaxAlunos = 50;
};

#endif