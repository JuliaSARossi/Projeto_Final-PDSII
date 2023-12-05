#ifndef MATERIA_HPP
#define MATERIA_HPP

#include "professor.hpp"
#include <string>
#include <vector>

class Professor;

class Materia {
public:
    // Construtor padrãp de Materia
    Materia(const std::string& nome, const std::string& codigoMateria, const std::string& departamento);

    // Funções relacionadas ao cadastro de professores
    void cadastrarProfessor(Professor* professor);
    void excluirProfessor(Professor* professor);

    // Getters
    const std::string& getNome() const;
    const std::string& getCodigoMateria() const;
    const std::string& getDepartamento() const;
    const std::vector<Professor*>& getProfessoresCadastrados() const;

private:
    std::string nome;
    std::string codigoMateria;
    std::string departamento;
    std::vector<Professor*> professoresCadastrados;
};

#endif