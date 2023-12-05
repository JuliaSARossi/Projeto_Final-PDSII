#include "materia.hpp"
#include "professor.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

Materia::Materia(const std::string& nome, const std::string& codigoMateria, const std::string& departamento)
    : nome(nome), codigoMateria(codigoMateria), departamento(departamento) {}

const std::string& Materia::getNome() const {
    return nome;
}

const std::string& Materia::getCodigoMateria() const {
    return codigoMateria;
}

const std::string& Materia::getDepartamento() const {
    return departamento;
}

const std::vector<Professor*>& Materia::getProfessoresCadastrados() const {
    return professoresCadastrados;
}

void Materia::cadastrarProfessor(Professor* professor) {
    // Verifica se o professor já está cadastrado
    auto it = std::find(professoresCadastrados.begin(), professoresCadastrados.end(), professor);
    if (it == professoresCadastrados.end()) { 
        professoresCadastrados.push_back(professor);
        std::cout << "Professor cadastrado com sucesso na materia " << codigoMateria << "\n";
    } else {
        std::cout << "Erro: Professor ja cadastrado nesta materia.\n";
    }
}

void Materia::excluirProfessor(Professor* professor) {
    // Remove o professor da lista de cadastrados
    auto it = std::find(professoresCadastrados.begin(), professoresCadastrados.end(), professor);
    if (it != professoresCadastrados.end()) {
        professoresCadastrados.erase(it);
        std::cout << "Professor removido com sucesso da materia " << codigoMateria << "\n";
    } else {
        std::cout << "Erro: Professor nao encontrado nesta materia.\n";
    }
}

