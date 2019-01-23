#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Vaisseau
{
public:
	//Vaisseau() = default;
	Vaisseau(sf::Color const& Couleur);
	//Vaisseau(sf::Color Couleur, float rayon);
	~Vaisseau();
	void avancer();
	void actualiserEtat(sf::Event const& evenement);
	void mettreAJour(float temps);
	void afficher(sf::RenderWindow& fenetre) const;

private:
	sf::CircleShape cercle{ 30 };
	sf::Texture texture{};
	sf::Sprite sprite{};
	float vitesse{ 0.f };
	bool accelerationEnCours = false;

	static const float ACCELERATION;
	static const float COEFF_FROTTEMENTS;

};

