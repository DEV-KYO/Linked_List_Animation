//
// Created by jnmen on 5/29/2024.
//

#ifndef ARROWSHAPE_H
#define ARROWSHAPE_H
#include <SFML/Graphics.hpp>


class Arrowshape :      public sf::Drawable,
                        public sf::Transformable {
private:
    sf::CircleShape triangle;  // Triangle shape uses circle with 3 points to create a triangle
    sf::RectangleShape line;   // Line shape to create the arrow line
    sf::Vector2f direction;    // Direction of the arrow
    sf::Vector2f position;     // Position of the arrow
    float length;              // Length of the arrow
    float thickness;           // Thickness of the arrow
    float triangleSize;        // Size of the triangle
    float triangleAngle;       // Angle of the triangle
    float triangleOffset;      // Offset of the triangle
    float lineOffset;          // Offset of the line
    float lineLength;          // Length of the line
    float lineThickness;       // Thickness of the line
    float lineRotation;        // Rotation of the line
    float triangleRotation;    // Rotation of the triangle
    void update();             // Updates the arrow shape

public:
    Arrowshape();              // Default constructor
    Arrowshape(sf::Vector2f position, sf::Vector2f direction, float length, float thickness); // Constructor with parameters

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override; // Draws the arrow shape

    // Getters
    sf::Vector2f getPosition() const; // Returns the position of the arrow
    sf::Vector2f getDirection() const; // Returns the direction of the arrow
    float getLength() const; // Returns the length of the arrow
    float getThickness() const; // Returns the thickness of the arrow
    float getTriangleSize() const; // Returns the size of the triangle
    float getTriangleAngle() const; // Returns the angle of the triangle
    float getTriangleOffset() const; // Returns the offset of the triangle
    float getLineOffset() const; // Returns the offset of the line
    float getLineLength() const; // Returns the length of the line
    float getLineThickness() const; // Returns the thickness of the line
    float getLineRotation() const; // Returns the rotation of the line
    float getTriangleRotation() const; // Returns the rotation of the triangle

    // Setters
    void setPosition(sf::Vector2f position); // Sets the position of the arrow
    void setDirection(sf::Vector2f direction); // Sets the direction of the arrow
    void setLength(float length); // Sets the length of the arrow
    void setThickness(float thickness); // Sets the thickness of the arrow
    void setTriangleSize(float triangleSize); // Sets the size of the triangle
    void setTriangleAngle(float triangleAngle); // Sets the angle of the triangle
    void setTriangleOffset(float triangleOffset); // Sets the offset of the triangle
    void setLineOffset(float lineOffset); // Sets the offset of the line
    void setLineLength(float lineLength); // Sets the length of the line
    void setLineThickness(float lineThickness); // Sets the thickness of the line
    void setLineRotation(float lineRotation); // Sets the rotation of the line
    void setTriangleRotation(float triangleRotation); // Sets the rotation of the triangle


};



#endif //ARROWSHAPE_H
