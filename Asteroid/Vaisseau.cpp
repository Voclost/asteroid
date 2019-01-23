#include "stdafx.h"
#include "Vaisseau.h"

using namespace std;

const float ACCELERATION{ 7000.f };
const float COEFF_FROTTEMENTS{ 2.f };

Vaisseau::Vaisseau(sf::Color const& couleur)
{
	//cercle.setFillColor(couleur);
	if (texture.loadFromFile("ressources/vaisseau.png")) {
		cerr << "L'image du vaisseau n'a pas été chargée " << endl;
	}
	sprite.setTexture(texture);
	sprite.setColor(couleur);
}

/*Vaisseau::Vaisseau(sf::Color couleur, float rayon) :
	cercle{rayon}
{
	cercle.setFillColor(couleur);
}*/

Vaisseau::~Vaisseau()
{
}

void Vaisseau::avancer()
{
	//cercle.move(10, 0);
	sprite.move(10, 0);
}

void Vaisseau::actualiserEtat(sf::Event const& evenement)
{
	if (evenement.type == sf::Event::KeyPressed && evenement.key.code == sf::Keyboard::Up) 
	{
		accelerationEnCours = true;
	}
	else if (evenement.type == sf::Event::KeyReleased && evenement.key.code == sf::Keyboard::Up)
	{
		accelerationEnCours = false;
	}


}

void Vaisseau::mettreAJour(float temps)
{
	if (accelerationEnCours)
	{
		vitesse += ACCELERATION*temps;
		vitesse -= vitesse * COEFF_FROTTEMENTS* temps;
		sprite.move(vitesse*temps, 0);
	}
	
}

void Vaisseau::afficher(sf::RenderWindow& fenetre) const
{
	//fenetre.draw(cercle);
	fenetre.draw(sprite);
}


