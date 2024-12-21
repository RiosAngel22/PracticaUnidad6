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
	float gravedad = 0.25;
	float fuerzaderebote = 2.0f;
	Color color = Color::Red;

	bool visible = true;
	float deltaTime;

	int timer;
	int timerMaximo = 3000;

	int limiteAltura;

	Vector2f Posicion;

public:
	Circulo(int limite);
	CircleShape getCirculo();

	//mover circulo
	void Mover();
	void ReiniciarPosicion();
	void CambiarPosicion();

	//borrar circulo
	bool clickeado(Window &App);
	bool getVisibilidad();
	void setVisibilidad(bool visibleActualmente);

	bool timerTerminado();
	void reducirTimer();
	void reiniciarTimer();
};

