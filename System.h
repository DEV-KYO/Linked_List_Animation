//
// Created by jnmen on 5/30/2024.
//

#ifndef SYSTEM_H
#define SYSTEM_H

#include "Drawables/Arrowshape/Arrowshape.h"
#include "Drawables/EnumDrawables/EnumDrawables.h"
#include "Drawables/NodeShape/NodeShape.h"
#include "Drawables/TextBox/TextBox.h"
#include "LinkedList/AnimatedLinkedList.h"
#include "LinkedList/EnumListFunctions.h"
#include "System/EnumSystem/EnumInputMode.h"


class System {
private:
    float moveFactor; //factor to move the arrow
    TextBox textBox; //text box to display text
    std::vector<std::string> dataVector; //data to display
    std::string data; //string to display
    EnumInputMode inputMode; //mode of input
    EnumListFunctions listFunction; //function of the linked list


    //FOR TESTING//
    // NodeShape testNode; //node to test
    AnimatedLinkedList list; //linked list to test

public:
    System();
    void Event(sf::RenderWindow& window, sf::Event& event); //function to update the system
    void Update(); //function to update the system
    void Draw(sf::RenderWindow& window); //function to draw the system

    void handleReturn(); //function to handle the return key

    std::string enumToString(EnumListFunctions function); //function to convert enum to string

};



#endif //SYSTEM_H
