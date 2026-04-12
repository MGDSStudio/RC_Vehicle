#include <SFML/Graphics.hpp>

#include "DebugLauncherBuzzerTest.h"
#include "MovementController.h"
#include "gamepad/GamepadController.h"
#include "preferences/PreferencesLoader.h"
#include "BuzzerController.h"
#include "gpio/GpioManager.h"

void testJsonParser();

int count = 0;
constexpr int FRAME_TO_CHANGE_COLOR = 30;
bool colorGreen = true;

void updateColor(sf::CircleShape* circle_shape);

int main()
{
	//testJsonParser();
	MovementController movement_controller;
	BuzzerController buzzerController;
	GpioManager gpioManager;
	sf::RenderWindow window( sf::VideoMode( { 200, 200 } ), "RC Vehicle controller V0.1" );
	sf::CircleShape shape( 100.f );
	window.setFramerateLimit(30);
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
		movement_controller.update(1);
		buzzerController.update(1);
		debug_launcher_buzzer_test.update(1);
		window.clear();
		window.draw( shape );
		window.display();
		updateColor(&shape);

	}
	Logger::debug("Start to dispose");
	buzzerController.complete();
	gpioManager.complete();
	GlobalCommandsListenersObserverSingleton::getInstance().complete();
	Logger::debug("Dispose completed");
}

void updateColor(sf::CircleShape* shape) {
	count++;
	if (count == FRAME_TO_CHANGE_COLOR) {
		if (colorGreen == true) {
			shape->setFillColor( sf::Color::Blue );
			colorGreen = false;
		}
		else {
			shape->setFillColor(sf::Color::Green);
			colorGreen = true;
		}
		count = 0;
	}
}

/*void testJsonParser() {
	PreferencesLoader preferences_loader;
	preferences_loader.load();
}*/
