//
// Created by jnmen on 5/30/2024.
//

#include "System.h"

System::System() : moveFactor(1.0f) {
    // Default constructor
    textBox = TextBox();
    list = AnimatedLinkedList();
    inputMode = EnumInputMode::LINKEDLIST;
    listFunction = EnumListFunctions::PUSH_BACK;


    //FOR TESTING//
    // testNode.setPosition({300,400});

}

void System::Event(sf::RenderWindow& window, sf::Event& event) {

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

        case sf::Event::MouseWheelScrolled:
            if(event.mouseWheelScroll.delta > 0) {
                list.zoom(1.1f);
            } else if(event.mouseWheelScroll.delta < 0) {
                list.zoom(0.9f);
            }
        break;

        //Key Pressed
        case sf::Event::KeyPressed:

            //Every time a key is pressed, a new event is added to the history
            //History will eventually be expanded to include more than just key presses
            History::EventHistory(window, event);

            //This switch statement will determine what key was pressed
            switch(event.key.code) {
                //Enter key
                case sf::Keyboard::Tab:
                    //Change the input mode
                    break;
                //Change listfunction mode
                case sf::Keyboard::Up:
                    //Change the list function up
                    if(listFunction != EnumListFunctions::PUSH_BACK) {
                        listFunction = static_cast<EnumListFunctions>(static_cast<int>(listFunction) - 1);
                    }
                    std::cout << "~MODE: " << enumToString(listFunction) << std::endl;
                break;

                case sf::Keyboard::Down:
                    //Change the list function down
                    if(listFunction != EnumListFunctions::CLEAR) {
                        listFunction = static_cast<EnumListFunctions>(static_cast<int>(listFunction) + 1);
                    }
                    std::cout << "~MODE: " << enumToString(listFunction) << std::endl;
                break;

                case sf::Keyboard::Return:
                    handleReturn();
                break;

                //Backspace key
                case sf::Keyboard::BackSpace:
                    textBox.removeLetter();
                data = textBox.getStringOfLetters();
                break;

                //Escape key
                case sf::Keyboard::Escape:
                    window.close();
                break;



            }
        break;

        // This event is triggered when text is entered
        case sf::Event::TextEntered:
            if (std::isdigit(static_cast<char>(event.text.unicode)) || event.text.unicode == 32) {
                textBox.addEventHandler(window, event);
            }
        break;
    }
}

void System::Update() {
    // Update the system
    textBox.update();
    list.update();

}

void System::Draw(sf::RenderWindow& window) {
    // Draw the system
    window.draw(textBox);
    list.draw(window, sf::RenderStates::Default);
}

void System::handleReturn() {
    // Handle the return key
    data = textBox.getStringOfLetters();
    switch(inputMode) {
        case EnumInputMode::LINKEDLIST:
            switch(listFunction) {
                case EnumListFunctions::PUSH_BACK:
                    if(!data.empty() && data != " ") {
                        list.push_back(data);
                    }
                break;

                case EnumListFunctions::PUSH_FRONT:
                    list.push_front(data);
                break;

                case EnumListFunctions::POP_BACK:
                    list.pop_back();
                break;

                case EnumListFunctions::POP_FRONT:
                    list.pop_front();
                break;

                case EnumListFunctions::CLEAR:
                    list.clear();
                break;
            }
            std::cout << "LIST: " << enumToString(listFunction) << std::endl;
        break;
    }
    textBox.clear();
    data = "";
}

std::string System::enumToString(EnumListFunctions listFunction) {
    switch(listFunction) {
        case EnumListFunctions::PUSH_BACK:
            return "PUSH_BACK";
        case EnumListFunctions::PUSH_FRONT:
            return "PUSH_FRONT";
        case EnumListFunctions::POP_BACK:
            return "POP_BACK";
        case EnumListFunctions::POP_FRONT:
            return "POP_FRONT";
        case EnumListFunctions::CLEAR:
            return "CLEAR";
        default:
            return "UNKNOWN";
    }
}