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
	int max_width = 300;
	int max_height = 90;
	int clicks = 0;
	int click_floor = 0;
	int click_level = 0;
	int click_level_blocks = 0;
	int click_height = 0;
	int click_floor_height = 0;
	float block_width = 30;
	float block_height = 30;

	// Load font
	//sf::Font font;
	//font.loadFromFile("E:/GitHub/Construction-Game/Constuction/x64/Debug/AlexBrush-7XGA.ttf");

	// Define text
	//sf::Text text;
	//std::stringstream ss;

	// Define building blocks
	const int max_blocks = 100;
	const int max_floors = 150;
	sf::RectangleShape building_block[max_blocks];
	sf::RectangleShape floor[max_floors];

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
				if (clicks >= max_blocks*5)
				{
					std::cout << "Build the maximum ammount of blocks" << std::endl;
					break;
				}
				else
				{
					click_floor++;
					click_level++;
					click_level_blocks++;
					building_block[click_level_blocks].setSize(sf::Vector2f(block_width, block_height));
					building_block[click_level_blocks].setFillColor(sf::Color::Red);
					if (click_level == int(max_width / block_width))
					{
						click_level = 1;
						if (click_floor_height == int(max_height / block_height))
						{
							click_floor_height = 0;
							click_level = 0;
							click_level_blocks = 0;

							floor[click_floor].setSize(sf::Vector2f(block_width, block_height));
							floor[click_floor].setFillColor(sf::Color::Red);
							floor[click_floor].setPosition(width - (width / 2 - 100) - block_width * click_level, height - block_height - click_height);
						}
						click_height += block_height;
						click_floor_height += block_height;
					}

					building_block[click_level_blocks].setPosition(width - (width/2-100) - block_width * click_level, height - block_height - click_height);
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