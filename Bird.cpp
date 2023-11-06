#include "Bird.h"
#include <iostream>

Bird::Bird(float width, float height) {
	if (!birdTexture.loadFromFile("bird_2.png")) {
		std::cout << "Failed to laod texture"<< std::endl; // Handle error if texture loading fails
	}
	birdSprite.setTexture(birdTexture);
	birdSprite.setPosition(100.0f, 300.0f);
	birdSprite.setScale(width / birdSprite.getGlobalBounds().width, height / birdSprite.getGlobalBounds().height);

	gravity = 900.0f; // Set the gravity value 
	velocityY = 700.0f; // Initial fall vertical velocity
}

void Bird::update(float deltaTime) {
	applyGravity(deltaTime); // Apply gravity to the bird
	birdSprite.move(0.0f, velocityY * deltaTime); // Update bird's position based on velocity
	if (birdSprite.getPosition().y < 0){
		birdSprite.setPosition(birdSprite.getPosition().x, 0);// limits the bird position from the top of the screen
		velocityY = 0;// stops the bird from flying higher than the top border
	} else if (birdSprite.getPosition().y + birdSprite.getGlobalBounds().height >= 925) {
		birdSprite.setPosition(birdSprite.getPosition().x, 925 - birdSprite.getGlobalBounds().height); // Limit bird's position from going below the screen
		velocityY = 0; // Stop falling when hitting the bottom border
	}
	if(velocityY < 0){// if the bird is going opposite of gravity change texture
		if (!birdTexture.loadFromFile("bird_1.png")) {
			std::cout << "Failed to laod texture"<< std::endl; // Handle error if texture loading fails
		}
	}else if (velocityY > 0){

		if (!birdTexture.loadFromFile("bird_2.png")) { // if bird is falling change back to original  texture
			std::cout << "Failed to laod texture"<< std::endl; // Handle error if texture loading fails
		}

	}else{
		if (!birdTexture.loadFromFile("bird_3.png")) {// change texture if the bird hit the ground
			std::cout << "Failed to laod texture"<< std::endl; // Handle error if texture loading fails
		}

	}
}

void Bird::jump() {
	// Implement bird jumping logic here
	//vertical velocity to a negative value to make the bird jump
	velocityY = -290.0f; // velocity jump  force
}

void Bird::applyGravity(float deltaTime) {
	// Apply gravity to the bird by increasing its vertical velocity
	velocityY += gravity * deltaTime;
}

void Bird::draw(sf::RenderWindow& window) {
	window.draw(birdSprite);
}

sf::Vector2f Bird::getPosition() const{
	return birdSprite.getPosition();
}
