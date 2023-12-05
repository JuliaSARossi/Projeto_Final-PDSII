#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.hpp"
#include "aluno.hpp"
#include "professor.hpp"
#include "materia.hpp"
#include "turma.hpp"
#include "sistema.hpp"
#include <sstream>

TEST_CASE("Teste de cadastro de aluno") {
    Aluno aluno("John", "Doe", "john.doe@example.com", 20, 'M');
    aluno.cadastrar("john_doe", "password");

    CHECK(aluno.getLogin() == "john_doe");
    CHECK(aluno.getSenha() == "password");
}

TEST_CASE("Teste de matrícula em disciplinas") {
    Aluno aluno("John", "Doe", "john.doe@example.com", 20, 'M');
    aluno.cadastrar("john_doe", "password");

    Materia materia("Matemática", "MAT101", "Departamento de Matemática");
    Professor professor("Jane", "Smith", "Matemática", 30, 'F');
    materia.cadastrarProfessor(&professor);

    Sistema sistema;
    sistema.criarTurma("MAT101", "T1", &professor);

    SUBCASE("Matricular aluno com sucesso") {
        aluno.matricular("MAT101","T1");
        CHECK_EQ(aluno.getTurmasMatriculadas().size(), 1);
    }

    SUBCASE("Matricular aluno ultrapassando o limite") {
        for (int i = 0; i < 6; ++i) {
            aluno.matricular("MAT101","T1");
        }

        CHECK_EQ(aluno.getTurmasMatriculadas().size(), 5);  // O limite é 5
    }
}

TEST_CASE("Teste de criação de matéria") {
    Sistema sistema;
    sistema.criarMateria("Física", "FIS101", "Departamento de Física");

    CHECK_EQ(sistema.getMateriasCadastradas().size(), 1);
    CHECK_EQ(sistema.getMateriasCadastradas()[0]->getNome(), "Física");
    CHECK_EQ(sistema.getMateriasCadastradas()[0]->getCodigoMateria(), "FIS101");
}

TEST_CASE("Cadastro e Matrícula de Professor em uma Matéria") {
    Sistema sistema;
    Professor professor("João", "Silva", "Computação", 35, 'M');

    professor.cadastrar("login_professor", "senha_professor");
    professor.matricular("DCC02","TM1");

    CHECK(professor.temTurmaAssociada("Codigo da Materia"));
}

TEST_CASE("Registro de Notas e Frequências por um Professor e Acessar notas e frequências do aluno") {
    Sistema sistema;

    Professor professor("João", "Silva", "Computação", 35, 'M');
    Aluno aluno("Mariazinha", "Aparecida", "mraprc78@gmail.com", 20, 'F');
    Materia materia("PDS", "DCC02", "DCC");
    Turma turma("DCC02", "TM1", &professor);
    aluno.cadastrar("login_aluno", "senha_aluno");
    aluno.matricular("DCC02", "TM1");
    professor.cadastrar("login_professor", "senha_professor");
    professor.matricular("DCC02","TM1");

    professor.registrarNotasEFrequencias("TM1", {"Maria Aparecida - "}, {80}, {8});

    std::ostringstream oss;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf(oss.rdbuf());

    aluno.acessarNotasEFrequencias();

    std::cout.rdbuf(oldCoutBuffer);

    std::string resultadoEsperado = "Notas e frequencias do aluno Mariazinha Aparecida:\nMaria Aparecida - Notas e frequencias do aluno na matéria TM1\n80\n8\n";

    CHECK_EQ(oss.str(), resultadoEsperado);
}

TEST_CASE("Acesso ao Sistema por um Professor com Login e Senha") {
    Sistema sistema;
    Professor professor("João", "Silva", "Computação", 35, 'M');

    professor.cadastrar("jsilva", "totalnoTP");

     CHECK(professor.verificarCredenciais("jsilva", "totalnoTP"));
}

TEST_CASE("Acesso ao Sistema por um Aluno com Login e Senha") {
    Sistema sistema;
    Aluno aluno("Mariazinha", "Aparecida", "mraprc78@gmail.com", 20, 'F');

    aluno.cadastrar("mraaprc", "totalnoTP");

     CHECK(aluno.verificarCredenciais("mraaprc", "totalnoTP"));
}

TEST_CASE("Criação e Exclusão de Matéria e Cadastro de Professores") {
    Sistema sistema;

    SUBCASE("Criação de Matéria") {
        sistema.criarMateria("Matemática", "MAT101", "Departamento de Matemática");

        CHECK_EQ(sistema.getMateriasCadastradas().size(), 1);
        CHECK_EQ(sistema.getMateriasCadastradas()[0]->getNome(), "Matemática");
        CHECK_EQ(sistema.getMateriasCadastradas()[0]->getCodigoMateria(), "MAT101");
    }

    SUBCASE("Exclusão de Matéria") {
        sistema.excluirMateria("MAT101");

        CHECK_EQ(sistema.getMateriasCadastradas().size(), 0);
    }

    SUBCASE("Cadastro de Professores na Matéria") {
        Professor professor1("João", "Silva", "Matemática", 35, 'M');
        Professor professor2("Maria", "Santos", "Matemática", 40, 'F');

        sistema.criarMateria("Matemática", "MAT101", "Departamento de Matemática");

        professor1.cadastrar("jsilva", "senha1");
        professor2.cadastrar("msantos", "senha2");

        professor1.matricular("MAT101","TM1");
        professor2.matricular("MAT101","TM1");

        CHECK(professor1.getTurmasAssociadas().size() == 1);
        CHECK(professor2.getTurmasAssociadas().size() == 1);
        CHECK(professor1.getTurmasAssociadas()[0] == "MAT101");
        CHECK(professor2.getTurmasAssociadas()[0] == "MAT101");
    }
}

TEST_CASE("Associação de Turma a Matéria") {
    Sistema sistema;
    Professor professor("João", "Silva", "Matemática", 35, 'M');
    professor.cadastrar("jsilva", "senha1");

    SUBCASE("Associação Básica") {
        sistema.criarMateria("Matemática", "MAT101", "Departamento de Matemática");
        sistema.criarTurma("MAT101", "T1", &professor);
        sistema.criarTurma("MAT101", "T2", &professor);
        professor.matricular("MAT101","T1");
        professor.matricular("MAT101","T2");

        CHECK_EQ(sistema.getTurmasCadastradas().size(), 2);
        CHECK_EQ(sistema.getTurmasCadastradas()[0]->getCodigoTurma(), "T1");
        CHECK_EQ(sistema.getTurmasCadastradas()[1]->getCodigoTurma(), "T2");
    }
}

TEST_CASE("Limite de Alunos por Turma") {
    Sistema sistema;

    SUBCASE("Limite de Alunos máximo Alcançado - Nova Turma Criada") {
        sistema.criarMateria("Matemática", "MAT101", "Departamento de Matemática");

        Professor professor("João", "Silva", "Matemática", 35, 'M');
        sistema.criarTurma("MAT101", "T1", &professor);

        for (int i = 0; i < 49; ++i) {
            Aluno aluno("Aluno", std::to_string(i), "aluno@example.com", 20, 'M');
            aluno.matricular("MAT101","T1");
        }

        CHECK_EQ(sistema.getTurmasCadastradas().size(), 1);
        CHECK_EQ(sistema.getTurmasCadastradas()[0]->getAlunos().size(), 1); 
    }

    SUBCASE("Limite Mínimo de Alunos Não Atingido - Nova Turma Não Criada") {
        sistema.criarMateria("Matemática", "MAT101", "Departamento de Matemática");

        Professor professor("João", "Silva", "Matemática", 35, 'M');
        sistema.criarTurma("MAT101", "T1", &professor);

        for (int i = 0; i < 5; ++i) {
            Aluno aluno("Aluno", std::to_string(i), "aluno@example.com", 20, 'M');
            aluno.matricular("MAT101", "T1");
        }

        CHECK_EQ(sistema.getTurmasCadastradas().size(), 1);
        CHECK_EQ(sistema.getTurmasCadastradas()[0]->getAlunos().size(), 5);
    }
}

TEST_CASE("Limite de Turmas por Professor") {
    Sistema sistema;

    SUBCASE("Professor Pode Dar Aula para Duas Turmas") {
        sistema.criarMateria("Matemática", "MAT101", "Departamento de Matemática");

        Professor professor("João", "Silva", "Matemática", 35, 'M');
        sistema.criarTurma("MAT101", "T1", &professor);
        sistema.criarTurma("MAT101", "T2", &professor);

        CHECK_EQ(sistema.getTurmasCadastradas().size(), 2);
    }

    SUBCASE("Professor Não Pode Dar Aula para Mais de Duas Turmas") {
        sistema.criarMateria("Matemática", "MAT101", "Departamento de Matemática");

        Professor professor("João", "Silva", "Matemática", 35, 'M');
        sistema.criarTurma("MAT101", "T1", &professor);
        sistema.criarTurma("MAT101", "T2", &professor);
        sistema.criarTurma("MAT101", "T3", &professor);  // Terceira turma não é criada

        CHECK_EQ(sistema.getTurmasCadastradas().size(), 3);
    }
}