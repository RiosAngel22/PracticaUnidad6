/////Librerías//////
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

/////Variables//////
using namespace sf;
using namespace std;

Vector2f velocidad (0.0f,0.0f);
float velocidadMaxima = 3.0f;
Vector2f acceleracion(0.0f,0.0f);

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
	circulo.setOrigin(circulo.getGlobalBounds().width / 2, circulo.getGlobalBounds().height / 2);



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

			case Event::KeyPressed:

				//inputs
				if (Keyboard::isKeyPressed(Keyboard::S)) {
					acceleracion.y = velocidadMaxima;
				}
				else if (Keyboard::isKeyPressed(Keyboard::W)) {
					acceleracion.y = -velocidadMaxima;
				}
				else if (Keyboard::isKeyPressed(Keyboard::A)) {
					acceleracion.x = -velocidadMaxima;
				}
				else if (Keyboard::isKeyPressed(Keyboard::D)) {
					acceleracion.x = velocidadMaxima;
				}
				

			}
		}


		//si el circulo esta al borde, lo regresamos al otro extremo
		if (circulo.getPosition().x > ancho) {
			Posicion.x = 0;
			circulo.setPosition(Posicion);
		}
		else if (circulo.getPosition().x < 0) {
			Posicion.x = ancho;
			circulo.setPosition(Posicion);
		}
		if (circulo.getPosition().y > alto) {
			Posicion.y = 0;
			circulo.setPosition(Posicion);
		}
		else if (circulo.getPosition().y < 0) {
			Posicion.x = alto;
			circulo.setPosition(Posicion);
		}

		//aumentamos la velocidad gradualmente
		velocidad += acceleracion * deltaTime;

		Posicion += velocidad * deltaTime;
		circulo.setPosition(Posicion);


		App.clear();
		App.draw(circulo);
		App.display();
			}	return 0;}