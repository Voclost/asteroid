// Asteroid.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Vaisseau.h"

using namespace std;

int main()
{
	sf::RenderWindow fenetre{sf::VideoMode(800,600), "Asteroid"};
	//auto cercle = sf::CircleShape{ 100 };
	//cercle.setFillColor(sf::Color{ 128,255,128 });
	//auto vaisseau = Vaisseau{sf::Color::Green, 120};
	auto vaisseau = Vaisseau{sf::Color::Green};
	auto chrono = sf::Clock{};

	while (fenetre.isOpen())
	{
		auto evenement = sf::Event();

		while (fenetre.pollEvent(evenement))
		{
			if (evenement.type == sf::Event::Closed)
			{
				fenetre.close();
			}

			vaisseau.actualiserEtat(evenement);
		}

		vaisseau.mettreAJour(chrono.restart().asSeconds());
		
		fenetre.clear();
		//fenetre.draw(cercle);
		vaisseau.afficher(fenetre);
		fenetre.display();
	}
	return 0;
}

