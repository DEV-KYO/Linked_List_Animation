//
// Created by Jonas Mendoza on 4/26/24.
//

#include "Application.h"

#include "KeyboardShortcuts/KeyboardShortcuts.h"

Application::Application() {

    //Create the window with a resolution of "pixelWidth" x "pixelHeight"
    unsigned int pixelWidth = 600; ///sf::VideoMode::getDesktopMode().width;
    unsigned int pixelHeight = 800; ///sf::VideoMode::getDesktopMode().height;

    //Create the window using given resolution and title
    window.create(sf::VideoMode(
            pixelWidth,
            pixelHeight
            ), "Text Input Project");

    //Set the framerate limit to 60
    window.setFramerateLimit(60);

    system = System();
}


void Application::run() {

    std::cout   << "APPLICATION STARTING"
                << std::endl;

    //Main loop of the application
    while (window.isOpen())
    {
        processEvents();
        update();
        render();
    }

    std::cout   << std::endl
                << "APPLICATION CLOSING"
                << std::endl;
}

void Application::processEvents() {

    //The event loop that will process all events that are happening in the window
    //This loop will run as long as there are events to process
    sf::Event event;
    while(window.pollEvent(event))
    {
        system.Event(window, event, command);
    }
}

void Application::update()
{
    system.Update();
}

void Application::render() {
    window.clear({sf::Color::Black});
    draw();
    window.display();
}

void Application::draw() {
    system.Draw(window);
}