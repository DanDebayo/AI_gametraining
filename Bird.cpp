#include "Bird.h"

Bird::Bird(float width, float height) {
    if (!birdTexture.loadFromFile("bird_1.png")) {
        // Handle error if texture loading fails
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
