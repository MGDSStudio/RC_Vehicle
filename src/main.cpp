#include <SFML/Graphics.hpp>

#include "DebugLauncherBuzzerTest.h"
#include "MovementController.h"
#include "gamepad/GamepadController.h"
#include "preferences/PreferencesLoader.h"
#include "BuzzerController.h"
#include "gpio/GpioManager.h"
#include <cstdlib> // для функции system()

#include "DirectoriesValidator.h"

void testJsonParser();
void mainLoop(sf::RenderWindow* window);

int count = 0;
int framesCompleted = 0;
constexpr int FRAME_TO_CHANGE_COLOR = 30;
bool colorGreen = true;
BuzzerController buzzerController;
GpioManager gpioManager;
GamepadController gamepad_controller;
MovementController movement_controller;
void updateColor(sf::CircleShape* circle_shape);

void dispose();

int main()
{
	sf::RenderWindow window( sf::VideoMode( { 200, 200 } ), "RC Vehicle controller V0.1" );

	window.setFramerateLimit(30);

	DirectoriesValidator directories_validator;
	bool validated = directories_validator.validate();
	if (validated)
	{

		mainLoop(&window);
	}
}

void mainLoop(sf::RenderWindow* window)
{
	bool toClose = false;
	gamepad_controller.attachCompletionFlag(&toClose);
	sf::CircleShape shape( 100.f );
	shape.setFillColor( sf::Color::Green );
	bool mutGamepadPickedUpCommand = false;
	while (window->isOpen() || toClose )
	{
		while ( const std::optional event = window->pollEvent()  )
		{
			if ( event->is<sf::Event::Closed>() || toClose) {
				dispose();
				window->close();
				if (toClose)
				{
					try
					{
						system("sudo shutdown -h now");
					}
					catch (sf::Exception exception)
					{
						Logger::debug("Can not switch off this PC. Maybe the app runs not on a Raspberry PI");
						Logger::debug(exception.what());
					}
				}
			}
			else
			{
				mutGamepadPickedUpCommand = gamepad_controller.attachCommand(event);
				if (!mutGamepadPickedUpCommand ) {

				}
				else
				{

				}
			}
		}
		movement_controller.update(1);
		buzzerController.update(1);
		window->draw( shape );
		window->display();
		updateColor(&shape);
		framesCompleted++;
	}
}

void dispose()
{
	Logger::debug("Start to dispose after " + std::to_string(framesCompleted) + " frames");
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
