/////Librerías//////
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

/////Variables//////
using namespace sf;
using namespace std;

//variables de pantalla
float alto = 600;
float ancho = 800;

//creamos la posicion y el delta
Vector2f Posicion(ancho / 2, alto / 2.0f);

//variables de movimiento
float deltaTime;
float velocidad = 0.0f;
float gravedad = 0.98f;
float impulsoDeRebote = 35.0;



CircleShape circulo;

int main()
{
	deltaTime = 0.1f / 60.0f;

	//creamos el circulo
	circulo.setFillColor(Color::Red);
	circulo.setRadius(50);
	circulo.setOrigin(circulo.getGlobalBounds().width / 2, circulo.getGlobalBounds().height / 2);

	RenderWindow App(VideoMode(ancho, alto, 32), "ventana");


	while (App.isOpen())
	{

		Event evt;
		while (App.pollEvent(evt)) {
			switch (evt.type)
			{
			case Event::Closed:
				App.close();
				break;

			
			//en cualquier momento, podemos reiniciar la caida de la pelota presionando espacio
			case Event::KeyPressed:
				if (Keyboard::isKeyPressed(Keyboard::Space)) {
					//reiniciamos la posicion, velocidad, 
					// fuerza de rebote y gravedad
					Posicion.y = alto / 2;
					velocidad = 0.0f;
					gravedad = 0.98f;
					impulsoDeRebote = 30.0;
					break;
				}
			}

		}

		velocidad += gravedad * deltaTime;
		Posicion.y += velocidad * deltaTime;

		circulo.setPosition(Posicion);

		if (Posicion.y >= alto) {
			//cada rebote vamos reduciendo la velocidad y aumentando la gravedad, 
			// para que rebote menos, mas rapido
			if (impulsoDeRebote > 0) {
				impulsoDeRebote -= 1.0f;
				gravedad += 1.5;
			}
			
			velocidad = -impulsoDeRebote;
		}

		App.clear();
		App.draw(circulo);
		App.display();


	}
	return 0;
}