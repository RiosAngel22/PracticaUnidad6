#include "SFML/Graphics.hpp"
#include "Circulo.h"
#include <random>
#include <time.h>

using namespace sf;

Circulo::Circulo(int limite) {
	srand(time(NULL));

	//cargamos la textura
	Textura = new Texture;

	//textura creada por mi para simular un blanco
	Textura->loadFromFile("Blanco.png");

	//seteamos el timer como su valor maximo
	reiniciarTimer();

	//creamos el circulo y cargamos sus texturas
	CirculoNuevo = new CircleShape;
	CirculoNuevo->setTexture(Textura);
	CirculoNuevo->setRadius(radio);
	CirculoNuevo->setOrigin(CirculoNuevo->getRadius() / 2, CirculoNuevo->getRadius() / 2);

	//le implementamos la colision del suelo
	limiteAltura = limite;

	//seteamos la posicion
	ReiniciarPosicion();

	//calculamos el deltaTime
	deltaTime = 1.0f / 60.0f;

}

CircleShape Circulo::getCirculo() {
	return *CirculoNuevo;
}

void Circulo::Mover() {
	//si esta por debajo del suelo, cambiar posicion y reaparecer
	if ((CirculoNuevo->getPosition().y - CirculoNuevo->getRadius()/2) >= limiteAltura) {
		velocidad += -fuerzaderebote * deltaTime;
		CambiarPosicion();
	}
	else {
		//sino, aplicar gravedad
		velocidad += gravedad * deltaTime;
	}

	//mover al circulo
	Posicion.y += velocidad * deltaTime;
	CirculoNuevo->setPosition(Posicion);
}

bool Circulo::clickeado(Window &App) {
	//obtener si el circulo fue clickeado
	FloatRect colision = CirculoNuevo->getGlobalBounds();
	if (colision.contains(Mouse::getPosition(App).x, Mouse::getPosition(App).y)) {
		return true;
	}
	else {
		return false;
	}
}

bool Circulo::getVisibilidad() {
	return visible;
}

void Circulo::setVisibilidad(bool visibleActualmente) {
	visible = visibleActualmente;
}

bool Circulo::timerTerminado() {
	if (timer <= 0) {
		return true;
	}
	else {
		return false;
	}
}

void Circulo::reducirTimer() {
	if (timer > 0){
		timer--;
	}
}

void Circulo::reiniciarTimer() {
	timer = timerMaximo;
}

//borrado por el jugador
void Circulo::ReiniciarPosicion() {
	float PosX = rand() % 500 + 100;
	float PosY = rand() % 50 + 10;
	Posicion = Vector2f(PosX, (limiteAltura  + CirculoNuevo->getRadius() + PosY));
	velocidad = 0;
}

//borrado al caer
void Circulo::CambiarPosicion() {
	float PosX = rand() % 500 + 100;
	Posicion.x = PosX;
}