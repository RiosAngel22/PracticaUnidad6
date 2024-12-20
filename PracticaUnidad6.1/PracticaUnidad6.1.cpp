/////Librerías//////
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

/////Variables//////
using namespace sf;
using namespace std;

int velocidad = 25;
int velocidadMaxima = 50;

float alto = 600;
float ancho = 800;

//creamos la posicion y el delta
Vector2f Posicion(ancho/2, alto / 2.0f);
float deltaTime;

CircleShape circulo;

int main()
{
	deltaTime = 0.1f / 60.0f;

	//creamos el circulo
	circulo.setFillColor(Color::Red);
	circulo.setRadius(50);
	circulo.setOrigin(circulo.getGlobalBounds().width/2, circulo.getGlobalBounds().height / 2);



	/////Creamos la ventana//////
	RenderWindow App(VideoMode(ancho, alto, 32), "ventana");


	while (App.isOpen())
	{

		Event evt;
		while (App.pollEvent(evt)) {
			/////Procesar eventos//////
			switch (evt.type)
			{
				/////Si se cerro la ventana//////
			case Event::Closed:
				App.close();
				break;
				}

			}
	
	//si el circulo esta al borde, lo regresamos al otro extremo
	if (circulo.getPosition().x >= 800) {
		Posicion.x = 0;
		circulo.setPosition(Posicion);

		if (velocidad < velocidadMaxima) {
			velocidad += 5;
		}
		
	}
	
	Posicion.x += velocidad * deltaTime;
	circulo.setPosition(Posicion);
	
	
	App.clear();
	App.draw(circulo);
	App.display();
	}	return 0;}