#ifndef BANCO_HPP
#define BANCO_HPP

#include <list>
#include <cctype>
#include "Jogador.hpp"
#include "Tecnico.hpp"

class Banco{
	public:	
		Banco();
		virtual ~Banco() = default;

		void adicionarJogador(Jogador* novoJogador);
		
		std::list<Jogador*> getGoleiros();

		std::list<Jogador*> getDefensores() const;

		std::list<Jogador*> getMeiocampistas() const;

		std::list<Jogador*> getAtacantes() const;

		std::list<Tecnico*> getTecnicos() const;

		void adicionarTecnico(Tecnico* novoTecnico);

	private:
		std::list<Jogador*> goleiros;
		std::list <Jogador*> defensores;
		std::list <Jogador*> meiocampistas;
		std::list <Jogador*> atacantes;
		std::list <Tecnico*> tecnicos;
		void criarGoleiros();
		void criarDefensores();
		void criarMeiocampistas();
		void criarAtacantes();
		void criarTecnicos();
};

#endif
