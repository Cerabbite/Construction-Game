#include <iostream>
#include <sstream>

#include "libraries/include/SFML/Graphics.hpp"
#include "libraries/include/SFML/System.hpp"
#include "libraries/include/SFML/Window.hpp"
#include "libraries/include/SFML/Audio.hpp"
#include "libraries/include/SFML/Graphics.hpp"

int main()
{
	// Setup window and event
	sf::RenderWindow window(sf::VideoMode(850, 850), "Construction");
	window.setFramerateLimit(120);
	sf::Event ev;

	// Define variables
	int clicks = 0;

	// Load font
	sf::Font font;
	if (!font.loadFromFile("AlexBrush-7XGA.tff"))
	{
		std::cout << "Fatal error: Could not load font" << std::endl;
		return -1;
	}

	// Define text
	sf::Text text;
	std::stringstream ss;

	// Game loop
	while (window.isOpen())
	{
		// Event polling
		while (window.pollEvent(ev))
		{
			switch (ev.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::MouseButtonPressed:
				clicks++;
			}
		}

		// Render
		window.clear(); // Clear previous frame

		// Update text
		ss << clicks;
		text.setString(ss.str().c_str());
		text.setCharacterSize(150);
		text.setPosition(500, 500);
		text.setFillColor(sf::Color::Red);
		
		// Draw all components
		window.draw(text);

		window.display(); // Tell app we have drawn everything

	}

	return 0;
}