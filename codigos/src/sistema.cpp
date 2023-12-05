#include "sistema.hpp"
#include "aluno.hpp"
#include "professor.hpp"
#include "materia.hpp"
#include "turma.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

void Sistema::loginAluno(const std::string& login, const std::string& senha) {
    for (const auto& aluno : alunosCadastrados) {
        if (aluno->verificarCredenciais(login, senha)) {
            std::cout << "Login de aluno realizado com sucesso.\n";
            acessarNotasEFrequenciasAluno(aluno);
            return;
        }
    }

    std::cout << "Erro: Credenciais invalidas para aluno.\n";
}


void Sistema::loginProfessor(const std::string& login, const std::string& senha) {
    for (const auto& professor : professoresCadastrados) {
        if (professor->verificarCredenciais(login, senha)) {
            std::cout << "Login de professor realizado com sucesso.\n";
            acessarTurmasProfessor(professor);
            return;
        }
    }

    std::cout << "Erro: Credenciais invalidas para professor.\n";
}

const std::vector<Materia*>& Sistema::getMateriasCadastradas() const {
    return materiasCadastradas;
}

const std::vector<Turma*>& Sistema::getTurmasCadastradas() const {
    return turmasCadastradas;
}

void Sistema::criarMateria(const std::string& nome, const std::string& codigoMateria, const std::string& departamento) {
    materiasCadastradas.push_back(new Materia(nome, codigoMateria, departamento));
    std::cout << "Materia criada com sucesso.\n";
}

void Sistema::excluirMateria(const std::string& codigo) {
    auto it = std::find_if(materiasCadastradas.begin(), materiasCadastradas.end(),
                           [codigo](const Materia* materia) { return materia->getCodigoMateria() == codigo; });

    if (it != materiasCadastradas.end()) {
        delete *it;
        materiasCadastradas.erase(it);
        std::cout << "Materia excluida com sucesso.\n";
    } else {
        std::cout << "Erro: Materia nao encontrada.\n";
    }
}

void Sistema::listarMaterias() const {
    std::cout << "Materias cadastradas:\n";
    for (const auto& materia : materiasCadastradas) {
        std::cout << " - " << materia->getNome() << " (" << materia->getCodigoMateria() << ")\n";
    }
}

void Sistema::criarTurma(const std::string& codigoMateria, const std::string& codigoTurma, Professor* professor) {
    auto it = std::find_if(materiasCadastradas.begin(), materiasCadastradas.end(),
                           [codigoMateria](const Materia* materia) { return materia->getCodigoMateria() == codigoMateria; });

    if (it != materiasCadastradas.end()) {
        if (!professor->temTurmaAssociada(codigoMateria)) {
            turmasCadastradas.push_back(new Turma(codigoMateria, codigoTurma, professor));
            std::cout << "Turma criada com sucesso.\n";
        } else {
            std::cout << "Erro: Professor ja tem turma cadastrada para esta materia.\n";
        }
    } else {
        std::cout << "Erro: Materia nao encontrada.\n";
    }
}


void Sistema::excluirTurma(const std::string& codigoTurma) {
    auto it = std::find_if(turmasCadastradas.begin(), turmasCadastradas.end(),
                           [codigoTurma](const Turma* turma) { return turma->getCodigoMateria() == codigoTurma; });

    if (it != turmasCadastradas.end()) {
        delete *it;
        turmasCadastradas.erase(it);
        std::cout << "Turma excluida com sucesso.\n";
    } else {
        std::cout << "Erro: Turma nao encontrada.\n";
    }
}

void Sistema::listarTurmas() const {
    std::cout << "Turmas cadastradas:\n";
    for (const auto& turma : turmasCadastradas) {
        std::cout << " - " << turma->getCodigoMateria() << " (" << turma->getCodigoTurma() << ")\n";
    }
}

void Sistema::acessarNotasEFrequenciasAluno(Aluno* aluno) const {
    std::cout << "Notas e frequencias do aluno " << aluno->getNome() << " " << aluno->getSobrenome() << ":\n";
    aluno->acessarNotasEFrequencias();
}

void Sistema::acessarTurmasProfessor(Professor* professor) const {
    if (professorTemTurmas(professor)) {
        std::cout << "Turmas do professor " << professor->getNome() << " " << professor->getSobrenome() << ":\n";
    } else {
        std::cout << "Nao ha turmas cadastradas para voce dar aula neste semestre.\n";
    }
}

void Sistema::acessarNotasETurmasProfessor(Professor* professor) const {
    // Verifica se o professor é nulo (pode adicionar mais verificações conforme necessário)
    if (professor == nullptr) {
        std::cout << "Erro: Professor inválido.\n";
        return;
    }

    // Obtém as turmas associadas ao professor
    const std::vector<std::string>& turmasAssociadas = professor->getTurmasAssociadas();

    // Verifica se o professor tem turmas associadas
    if (turmasAssociadas.empty()) {
        std::cout << "O professor não tem turmas associadas.\n";
        return;
    }

    // Itera sobre as turmas associadas e exibe informações
    for (const std::string& codigoTurma : turmasAssociadas) {
        std::cout << "Turma: " << codigoTurma << "\n";
    }
}

bool Sistema::professorTemTurmas(Professor* professor) const {
    for (const auto& turma : turmasCadastradas) {
        if (turma->getProfessor() == professor) {
            return true;
        }
    }

    return false;
}