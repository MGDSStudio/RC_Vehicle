#include <SFML/Graphics.hpp>

#include "DebugLauncherBuzzerTest.h"
#include "MovementController.h"
#include "gamepad/GamepadController.h"
#include "preferences/PreferencesLoader.h"
#include "BuzzerController.h"
#include "gpio/GpioManager.h"

void testJsonParser();



int main()
{
	//testJsonParser();
	MovementController movement_controller;
	BuzzerController buzzerController;
	GpioManager gpioManager;
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
		buzzerController.update(1);
		debug_launcher_buzzer_test.update(1);
		window.clear();
		window.draw( shape );
		window.display();
	}
	Logger::debug("Start to dispose");
	buzzerController.complete();
	gpioManager.complete();
	GlobalCommandsListenersObserverSingleton::getInstance().complete();
	Logger::debug("Dispose completed");
}

/*void testJsonParser() {
	PreferencesLoader preferences_loader;
	preferences_loader.load();
}*/
