//
// Created by jnmen on 5/31/2024.
//

#include "NodeShape.h"

NodeShape::NodeShape(const std::string& data) : data(data), text(sf::Text(data, FontManager::getFont(EnumFonts::PIXELGEORGIA), 24)) {
    sf::Vector2f size = {100,100};
    nodeSize = size;
    //intit body
    body = sf::RectangleShape(sf::Vector2f ({size.x/3,size.y}));
    body.setOrigin(sf::Vector2f ({nodeSize.x/6,nodeSize.y/2}));
    // /////////////////////////////////////////////////////////////
    //                  FOR TESTING                               //
    body.setFillColor(sf::Color(0,0,0));
    body.setOutlineColor(sf::Color({250,250,250}));
    body.setOutlineThickness(1.0f);
    // /////////////////////////////////////////////////////////////

    //get values of box
    sf::FloatRect b = body.getLocalBounds();

    //init prev and next

    nextBlock = sf::RectangleShape(sf::Vector2f ({size.x/3, size.y}));
    nextBlock.setFillColor({0,0,0});
    nextBlock.setOutlineColor({250,250,250});
    nextBlock.setOutlineThickness({1.0f});
    nextBlock.setOrigin({nodeSize.x, nodeSize.y});
    nextBlock.setPosition({nodeSize.x/3 *2, nodeSize.y});

    prevBlock = sf::RectangleShape(sf::Vector2f ({size.x/3, size.y}));
    prevBlock.setFillColor({0,0,0});
    prevBlock.setOutlineColor({250,250,250});
    prevBlock.setOutlineThickness({1.0f});
    prevBlock.setOrigin({nodeSize.x, nodeSize.y});
    prevBlock.setPosition({nodeSize.x/3*4, nodeSize.y});

    next = Arrowshape(sf::Vector2f ({size.x, size.y}), Direction::RIGHT);

    prev = Arrowshape(sf::Vector2f ({size.x, size.y}), Direction::LEFT);

    //Set the font

    text.setFillColor(sf::Color::White);
    text.setString(data);
    sf::FloatRect textBounds = text.getLocalBounds();
    text.setOrigin(textBounds.left + textBounds.width/2.0f, textBounds.top + textBounds.height/2.0f);

    sf::FloatRect bodyBounds = body.getLocalBounds();
    text.setPosition(bodyBounds.left + bodyBounds.width/2.0f, bodyBounds.top + bodyBounds.height/2.0f);
}

NodeShape::NodeShape(const sf::Vector2f &size, const std::string& data) {
    nodeSize = size;
    //intit body
    body = sf::RectangleShape(sf::Vector2f ({size.x/3,size.y}));
    body.setOrigin(sf::Vector2f ({nodeSize.x/6,nodeSize.y/2}));
    // /////////////////////////////////////////////////////////////
    //                  FOR TESTING                               //
    body.setFillColor(sf::Color(0,0,0,0));
    body.setOutlineColor(sf::Color({250,250,250}));
    body.setOutlineThickness(1.0f);
    // /////////////////////////////////////////////////////////////

    //get values of box
    sf::FloatRect b = body.getLocalBounds();

    //init prev and next

    nextBlock = sf::RectangleShape(sf::Vector2f ({size.x/3, size.y}));
    nextBlock.setFillColor({250,250,250});
    nextBlock.setOutlineColor({250,250,250});
    nextBlock.setOutlineThickness({1.0f});
    nextBlock.setOrigin({nodeSize.x, nodeSize.y});
    nextBlock.setPosition({nodeSize.x/3 *2, nodeSize.y});

    prevBlock = sf::RectangleShape(sf::Vector2f ({size.x/3, size.y}));
    prevBlock.setFillColor({250,250,250});
    prevBlock.setOutlineColor({250,250,250});
    prevBlock.setOutlineThickness({1.0f});
    prevBlock.setOrigin({nodeSize.x, nodeSize.y});
    prevBlock.setPosition({nodeSize.x/3*4, nodeSize.y});

    next = Arrowshape(sf::Vector2f ({size.x, size.y}), Direction::RIGHT);

    prev = Arrowshape(sf::Vector2f ({size.x, size.y}), Direction::LEFT);
}

void update() {

}

void NodeShape::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    states.transform = body.getTransform();

    window.draw(prev,states);
    window.draw(next,states);

    window.draw(nextBlock,states);
    window.draw(prevBlock,states);

    window.draw(body);
    window.draw(text,states);
}

void NodeShape::setPosition(const sf::Vector2f &position) {
    // Set the position of body
    body.setPosition(position);

    // Set the position of prev and next to be at the center of the body
    prev.setPosition({position.x, position.y});
    next.setPosition({position.x, position.y});


}

void NodeShape::rotate(float angle) {
    body.rotate(angle);
    prev.rotate(angle);
    next.rotate(angle);
}

void NodeShape::move(sf::Vector2<float> offset) {
    body.move(offset);
    prev.move(offset);
    next.move(offset);
}

void NodeShape::zoom(float factor) {
    body.scale(factor, factor);
    prev.zoom(factor);
    next.zoom(factor);
}

void NodeShape::getLocalBounds(sf::FloatRect &rect) const {
    rect = sf::FloatRect({prev.getTipPosition().x, body.getLocalBounds().top, next.getTipPosition().x, body.getLocalBounds().height + body.getLocalBounds().top});
}

void NodeShape::setData(const std::any& data) {
    this->data = data;
    text.setString(std::to_string(std::any_cast<int>(data)));
}

std::any NodeShape::getData() const {
    return data;
}

void NodeShape::setFont(EnumFonts font) {
    this->font = FontManager::getFont(font);
    text.setFont(this->font);
}

void NodeShape::setFontSize(unsigned int size) {
    text.setCharacterSize(size);
}