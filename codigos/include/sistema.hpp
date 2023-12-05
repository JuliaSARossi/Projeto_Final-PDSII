#ifndef SISTEMA_HPP
#define SISTEMA_HPP

#include "sistema.hpp"
#include "aluno.hpp"
#include "professor.hpp"
#include "materia.hpp"
#include "turma.hpp"
#include <string>
#include <vector>

class Aluno;
class Professor;
class Materia;
class Turma;

class Sistema {
public:
    // Funções relacionadas ao login
    void loginAluno(const std::string& login, const std::string& senha);
    void loginProfessor(const std::string& login, const std::string& senha);

    // Funções relacionadas à gestão de matérias
    void criarMateria(const std::string& nome, const std::string& codigoMateria, const std::string& departamento);
    void excluirMateria(const std::string& codigo);
    void listarMaterias() const;
    const std::vector<Materia*>& getMateriasCadastradas() const;

    // Funções relacionadas à gestão de turmas
    void criarTurma(const std::string& codigo, const std::string& codigoTurma, Professor* professor);
    void excluirTurma(const std::string& codigoTurma);
    void listarTurmas() const;
    const std::vector<Turma*>& getTurmasCadastradas() const;

    // Funções relacionadas ao acesso de alunos
    void acessarNotasEFrequenciasAluno(Aluno* aluno) const;


    // Funções relacionadas ao acesso de professores
    void acessarTurmasProfessor(Professor* professor) const;
    void acessarNotasETurmasProfessor(Professor* professor) const;

    // Função para verificar se um professor tem turmas cadastradas
    bool professorTemTurmas(Professor* professor) const;

private:
    std::vector<Aluno*> alunosCadastrados;
    std::vector<Professor*> professoresCadastrados;
    std::vector<Materia*> materiasCadastradas;
    std::vector<Turma*> turmasCadastradas;
};

#endif