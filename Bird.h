#pragma once

#include <SFML/Graphics.hpp>

class Bird {
public:
    Bird(float width, float height); // Constructor with width and height parameters
    void update(float deltaTime); // Update function with deltaTime parameter
    void jump(); // Function to make the bird jump
    void applyGravity(float deltaTime); // Function to apply gravity to the bird
    void draw(sf::RenderWindow& window);
    
    sf::Vector2f getPosition() const;

private:
    sf::Texture birdTexture;
    sf::Sprite birdSprite;

    float gravity; // Gravity value to simulate downward force
    float velocityY; // Vertical velocity of the bird
};
