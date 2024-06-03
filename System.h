//
// Created by jnmen on 5/30/2024.
//

#ifndef SYSTEM_H
#define SYSTEM_H

#include "Drawables/Arrowshape/Arrowshape.h"
#include "Drawables/EnumDrawables/EnumDrawables.h"
#include "Drawables/NodeShape/NodeShape.h"
#include "Drawables/TextBox/TextBox.h"


class System {
private:
    float moveFactor; //factor to move the arrow
    TextBox textBox; //text box to display text

    //FOR TESTING//
    Arrowshape testArrow; //arrow to test
    NodeShape testNode; //node to test
    sf::RectangleShape rect; //rectangle to test

public:
    System();
    void Event(sf::RenderWindow& window, sf::Event& event, Drawables command); //function to update the system
    void Update(); //function to update the system
    void Draw(sf::RenderWindow& window); //function to draw the system

};



#endif //SYSTEM_H
