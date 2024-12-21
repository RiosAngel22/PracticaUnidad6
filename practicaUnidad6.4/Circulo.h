#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;

class Circulo
{
private:
	//circulo
	CircleShape* CirculoNuevo;
	Texture* Textura;
	float radio = 50.0f;


	//variables de movimiento
	float velocidad = 0.0f;
	float gravedad = 0.25;
	float fuerzaderebote = 1.8f;

	//visibilidad
	bool visible = true;

	//deltatime
	float deltaTime;

	//temporizador
	int timer;
	int timerMaximo = 3000;

	//posicion
	int limiteAltura;
	Vector2f Posicion;

public:
	//circulo
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

	//manejar timer
	bool timerTerminado();
	void reducirTimer();
	void reiniciarTimer();
};

