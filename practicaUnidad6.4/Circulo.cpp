#include "SFML/Graphics.hpp"
#include "Circulo.h"

using namespace sf;

Circulo::Circulo(Vector2f posicion, int limite) {

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

	//colocamos al circulo y le implementamos la colision del suelo
	limiteAltura = limite;
	Posicion = posicion;

	//calculamos el deltaTime
	deltaTime = 1.0f / 60.0f;

}

CircleShape Circulo::getCirculo() {
	return *CirculoNuevo;
}

void Circulo::Mover() {

	//si esta por debajo del suelo, rebotar
	if ((CirculoNuevo->getPosition().y + CirculoNuevo->getRadius()) >= limiteAltura) {
		velocidad += -fuerzaderebote * deltaTime;
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

void Circulo::setPosicion(Vector2f posicionnueva) {
	Posicion = posicionnueva;
}