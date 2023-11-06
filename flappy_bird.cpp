#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bird.h"

int main()
{

	sf::RenderWindow window(sf::VideoMode(540, 900), "Flappy Bird");

	sf::Color backgroundCustomColor(12,175,255);
	sf::Color backgroundColor = backgroundCustomColor;
	sf::Clock clock;

	bool isInputEnabled = true;


	float birdWidth = 90.0f;
	float birdHeight = 90.0f;

	Bird bird(birdWidth, birdHeight);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed){
								window.close();
			}

		    if (isInputEnabled && event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                bird.jump(); // Make the bird jump when the spacebar is pressed
            }
            // Toggle input
        }

		sf::Time deltaTime = clock.restart();
                float dt = deltaTime.asSeconds();

		  if (isInputEnabled) {
            bird.update(dt);

            // Check if the bird has hit the ground (bottom border of the window)
            if (bird.getPosition().y + birdHeight >= 925) {
		  isInputEnabled= false;
		  //  std::cout << "Limit reached" << std::endl;               
            }
        }



		window.clear();
		window.clear(backgroundColor);
		bird.draw(window);
		window.display();
	}

	return 0;
}
