#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;

class Circulo
{
private:
	CircleShape* CirculoNuevo;
	Texture* Textura;

	float radio = 50.0f;
	float velocidad = 0.0f;
	float gravedad = 0.5;
	float fuerzaderebote = 8.0f;
	Color color = Color::Red;

	bool visible = true;
	float deltaTime;

	int timer;
	int timerMaximo = 3000;

	int limiteAltura;

	Vector2f Posicion;

public:
	Circulo(Vector2f posicion, int limite);
	CircleShape getCirculo();
	void Mover();
	bool clickeado(Window &App);
	bool getVisibilidad();
	void setVisibilidad(bool visibleActualmente);

	void setPosicion(Vector2f posicionnueva);

	bool timerTerminado();
	void reducirTimer();
	void reiniciarTimer();
};

