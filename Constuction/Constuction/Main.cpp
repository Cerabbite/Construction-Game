#include <iostream>
#include <sstream>

#include "libraries/include/SFML/Graphics.hpp"
#include "libraries/include/SFML/System.hpp"
#include "libraries/include/SFML/Window.hpp"
#include "libraries/include/SFML/Audio.hpp"
#include "libraries/include/SFML/Graphics.hpp"

int main()
{
	// Window variables
	int width = 850;
	int height = 850;
	// Setup window and event
	sf::RenderWindow window(sf::VideoMode(width, height), "Construction");
	window.setFramerateLimit(120);
	sf::Event ev;

	// Define variables
	int clicks = 0;
	int click_floor = 0;
	int click_level = 0;
	int click_height = 0;
	float block_width = 10;
	float block_height = 15;

	// Load font
	//sf::Font font;
	//font.loadFromFile("E:/GitHub/Construction-Game/Constuction/x64/Debug/AlexBrush-7XGA.ttf");

	// Define text
	//sf::Text text;
	//std::stringstream ss;

	// Define building blocks
	const int max_blocks = 100;
	sf::RectangleShape building_block[max_blocks];
	sf::RectangleShape floor[150];

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
				if (clicks == max_blocks)
				{
					std::cout << "Build the maximum ammount of blocks" << std::endl;
					break;
				}
				else
				{
					click_floor++;
					click_level++;
					building_block[click_floor].setSize(sf::Vector2f(block_width, block_height));
					building_block[click_floor].setFillColor(sf::Color::Red);
					if (click_level == 100 / block_width)
					{
						click_level = 1;
						click_height += block_height;
					}

					building_block[click_floor].setPosition(width - 50 - block_width * click_level, height - block_height - click_height);
				}
			}
		}
		
		// Render
		window.clear(); // Clear previous frame

		// Update text
		//ss << clicks;
		//text.setString(ss.str().c_str());
		//text.setCharacterSize(150);
		//text.setPosition(500, 500);
		//text.setFillColor(sf::Color::Red);
		
		std::cout << clicks << std::endl;

		// Draw all components
		//window.draw(text);

		for (int i = 0; i <= click_floor; i++)
		{
			window.draw(building_block[i]);
		}

		window.display(); // Tell app we have drawn everything

	}

	return 0;
}