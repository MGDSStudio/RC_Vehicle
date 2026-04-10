#include <SFML/Graphics.hpp>

#include "DebugLauncherBuzzerTest.h"
#include "gamepad/GamepadController.h"

int main()
{
	sf::RenderWindow window( sf::VideoMode( { 200, 200 } ), "SFML works!" );
	sf::CircleShape shape( 100.f );
	shape.setFillColor( sf::Color::Green );
	GamepadController gamepad_controller;
	DebugLauncherBuzzerTest debug_launcher_buzzer_test;
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
		debug_launcher_buzzer_test.update(1);
		window.clear();
		window.draw( shape );
		window.display();
	}
}
