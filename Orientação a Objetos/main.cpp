#include <iostream>
#include "Jogo.hpp"
#include "Banco.hpp"
#include "Time.hpp"
#include "Jogador.hpp"
#include "libTime.hpp"
#include "Menus.hpp"
#include "libJogador.hpp"

int main() {
	Jogo* game = new Jogo();
	short int op = 0;
	while (op != 3) {
		system("clear");
		menu();
		std::cin >> op;
		switch(op) {
			case 1:{
				//criar time
				Time* team = new Time();
				op = criarTime(game->getBanco(), team);
				game->adicionarTime(team);
				delete team;
				break;
			}
			case 2: {
				//continuar
				system("clear");
				short int t;
				std::cout << "digite 0 para voltar\n";
  			    std::cout << "Selecione o time:\n";
				imprimirTimes(game);
				std::cin >> t;
				if (t != 0) {
					t = t-1;
					std::list<Time*>::iterator it = std::next(game->getTimes().begin(), t);
					editarTime(*it, &op);
					if (op == 100) {
						game->adicionarTime(*it);
						game->removerTime(t);
					}
				}
				break;
			}
			case 3:
				break;
			default:
				std::cout << "Opção inválida.\n";
				break;
		}
	}
	delete game;
	return 0;
}
