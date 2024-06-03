//
// Created by jnmen on 5/30/2024.
//

#include "System.h"

System::System() : moveFactor(1.0f), testArrow({100,100}, Direction::RIGHT) {
    // Default constructor
    textBox = TextBox();


    //FOR TESTING//
    testNode = NodeShape({50,50 });
    testNode.setPosition({300,400});

    rect = sf::RectangleShape({200,200});
    rect.setOrigin({100,100});
    rect.setFillColor({0,0,0,0});
    rect.setOutlineThickness(1.0f);
    rect.setOutlineColor(sf::Color::White);
    rect.setPosition({200  ,200});


}

void System::Event(sf::RenderWindow& window, sf::Event& event, Drawables command) {

    //switch statement that determines what type of event is happening
    //Events can be anything from closing the window to pressing a key
    switch (event.type)
    {
        //Close window
        case sf::Event::Closed:
            window.close();
        break;

        //Mouse Button Pressed
        case sf::Event::MouseButtonPressed:
            std::cout << "Mouse Button Pressed" << std::endl;

            //This calls the addEventHandler function in the TextBox class
            textBox.addEventHandler(window, event);
        break;

        //Key Pressed
        case sf::Event::KeyPressed:

            //Every time a key is pressed, a new event is added to the history
            //History will eventually be expanded to include more than just key presses
            History::EventHistory(window, event);

            //This switch statement will determine what key was pressed
            switch(event.key.code) {
                //Escape key
                case sf::Keyboard::Escape:
                    window.close();
                break;

                //Backspace key
                case sf::Keyboard::BackSpace:
                    textBox.removeLetter();
                break;

                case sf::Keyboard::Up:
                    testNode.move({0,-1});
                break;

                case sf::Keyboard::Down:
                    testNode.move({0,1});
                break;
                case sf::Keyboard::Left:
                    testNode.move({-1,0});
                break;
                case sf::Keyboard::Right:
                    testNode.move({1,0});
                break;
                case sf::Keyboard::R:
                    testNode.rotate(90);
                break;
            }
        break;

        // This event is triggered when text is entered
        case sf::Event::TextEntered:
            textBox.addEventHandler(window, event);
        break;
    }
}

void System::Update() {
    // Update the system
    textBox.update();

}

void System::Draw(sf::RenderWindow& window) {
    // Draw the system
    window.draw(textBox);

    window.draw(testNode);
    window.draw(rect);
}