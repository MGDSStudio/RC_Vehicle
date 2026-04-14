#include <SFML/Graphics.hpp>

#include "DebugLauncherBuzzerTest.h"
#include "MovementController.h"
#include "gamepad/GamepadController.h"
#include "preferences/PreferencesLoader.h"
#include "BuzzerController.h"
#include "gpio/GpioManager.h"
#include <cstdlib> // для функции system()

void testJsonParser();

int count = 0;
constexpr int FRAME_TO_CHANGE_COLOR = 30;
bool colorGreen = true;
BuzzerController buzzerController;
GpioManager gpioManager;
GamepadController gamepad_controller;

void updateColor(sf::CircleShape* circle_shape);

void dispose();

int main()
{
	MovementController movement_controller;


	sf::RenderWindow window( sf::VideoMode( { 200, 200 } ), "RC Vehicle controller V0.1" );
	sf::CircleShape shape( 100.f );
	window.setFramerateLimit(30);
	shape.setFillColor( sf::Color::Green );

	bool toClose = false;
	gamepad_controller.attachCompletionFlag(&toClose);
	while (window.isOpen() || toClose )
	{
		while ( const std::optional event = window.pollEvent()  )
		{
			if ( event->is<sf::Event::Closed>() || toClose) {
				dispose();
				window.close();
				if (toClose)
				{
					system("sudo shutdown -h now");
				}
			}
			else if (!gamepad_controller.attachCommand(event) ) {
				
			}
			/*if (event->is<sf::Event::KeyPressed>()) {
				//const auto* button_pressed = event->getIf<sf::Event::JoystickButtonPressed>()
				const auto* button_pressed = event->getIf<sf::Event::KeyPressed>();
				if (button_pressed->code == sf::Keyboard::Key::Backspace)
				{
					Logger::debug("Try to close");
					toClose = true;
				}
			}*/
		}
		movement_controller.update(1);
		buzzerController.update(1);
		window.draw( shape );
		window.display();
		updateColor(&shape);
	}

	if (toClose){

	}
}

void dispose()
{
	Logger::debug("Start to dispose");
	buzzerController.complete();
	gpioManager.complete();
	gamepad_controller.complete();
	LocalCommandsListenersObserverSingleton::getInstance().complete();
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
		//window_must_be_redrawn = true;
		count = 0;
	}
}
