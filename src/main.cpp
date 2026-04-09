#include <SFML/Graphics.hpp>

#include "GamepadController.h"

int main()
{
	sf::RenderWindow window( sf::VideoMode( { 200, 200 } ), "SFML works!" );
	sf::CircleShape shape( 100.f );
	shape.setFillColor( sf::Color::Green );
	GamepadController gamepad_controller;

	while ( window.isOpen() )
	{
		while ( const std::optional event = window.pollEvent() )
		{
			if ( event->is<sf::Event::Closed>() ) {
				window.close();
			}
			else if (!gamepad_controller.attachCommand(event)) {

			}

		}

		window.clear();
		window.draw( shape );
		window.display();
	}
}
