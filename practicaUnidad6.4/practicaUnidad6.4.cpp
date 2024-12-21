/////Librerías//////
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Circulo.h"

/////Variables//////
using namespace sf;
using namespace std;

//variables de pantalla
float alto = 600.0f;
float ancho = 800.0f;

//texto de puntaje y gameOver
Font fuente;
Text texto;

//pointer para crear circulos
Circulo *circulo1;

//Array donde guardamos nuestros circulos
vector<Circulo> circulos;

int puntaje = 0;

//el numero va a ser 1 menos que la variable
int numeroDePelotas = 4;


void crearPelotas() {
	//creamos las pelotas y las esparcimos aleatoriamente
	for (int i = 1; i < numeroDePelotas; i++) {
		circulo1 = new Circulo(alto);
		circulos.push_back(*circulo1);
	}
}

void textoInicial() {
	//texto que muestra el puntaje
	texto.setScale(0.5, 0.5);
	texto.setPosition(50, 50);
	
}

void textoFinal() {
	//texto de pantalla final
	texto.setString("puntaje final: " + to_string(puntaje) + "\n \nPresione [ESPACIO] \n \npara reiniciar");
	texto.setPosition(ancho/3.5, alto/4);
	texto.setScale(0.6, 0.6);

}

int main()
{
	

	//Creamos nuestro texto
	fuente.loadFromFile("operius-regular.ttf");
	texto.setFont(fuente);
	texto.setFillColor(Color::White);
	texto.setOrigin(texto.getGlobalBounds().width / 2, texto.getGlobalBounds().height / 2);
	
	//llamamos al texto inicial
	textoInicial();

	//Creamos el array de pelotas
	crearPelotas();

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

			case Event::MouseButtonPressed:
				if (Mouse::isButtonPressed(Mouse::Left)) {
					//registra si hicimos click arriba de cada circulo en el array
					bool clickeado;
					for (int i = 0; i < circulos.size(); i++) {
						clickeado =  circulos[i].clickeado(App);

						if (clickeado) {
							//esconde el circulo y aumenta el puntaje
							circulos[i].setVisibilidad(false);
							puntaje++;
						}

					}
				}
			case::Event::KeyPressed:
				if (Keyboard::isKeyPressed(Keyboard::Space)) {
					//si tenemos pelotas, el juego termina al presionar espacio, mostrando el texto final
					if (circulos.size() > 0) {
						circulos.clear();
						textoFinal();	
					}
					else {
						//si no tenemos pelotas, creamos pelotas y reiniciamos el contador, mostrando el texto original
						puntaje = 0;
						crearPelotas();
						textoInicial();
					}
				}
				if (Keyboard::isKeyPressed(Keyboard::Escape)) {
					App.close();
				}
			}

		}
		

		App.clear();

		//Si tenemos pelotas, las dibuja
		if (circulos.size() > 0) {
			texto.setString("puntaje actual: " + to_string(puntaje) + "\n \nPresione [ESPACIO] \n\npara terminar");


			for (int i = 0; i < circulos.size(); i++) {

				//si las pelotas son visibles, reenderizamos su movimiento
				if (circulos[i].getVisibilidad() == true) {
					circulos[i].Mover();
					App.draw(circulos[i].getCirculo());
				}

				else if (circulos[i].getVisibilidad()== false) {

					//si son invisibles, esperamos que termine su timer para mostrarlas, sino termino, simplemente lo reducimos
					if (circulos[i].timerTerminado()) {
						circulos[i].reiniciarTimer();
						circulos[i].setVisibilidad(true);

						circulos[i].ReiniciarPosicion();

					}
					else {
						circulos[i].reducirTimer();
						}
					}

			}
		}
		
		App.draw(texto);
		App.display();


	}
	return 0;
}