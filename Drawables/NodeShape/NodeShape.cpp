//
// Created by jnmen on 5/31/2024.
//

#include "NodeShape.h"

NodeShape::NodeShape() {

}

NodeShape::NodeShape(const sf::Vector2f &size)
{
    nodeSize = size;
    //intit body
    body = sf::RectangleShape(sf::Vector2f ({size.x/3,size.y}));
    body.setOrigin(sf::Vector2f ({nodeSize.x/6,nodeSize.y/2}));
    // /////////////////////////////////////////////////////////////
    //                  FOR TESTING                               //
    body.setFillColor(sf::Color(0,0,0,0));
    body.setOutlineColor(sf::Color({155,100,0}));
    body.setOutlineThickness(1.0f);
    // /////////////////////////////////////////////////////////////

    //get values of box
    sf::FloatRect b = body.getLocalBounds();

    //init arrows
//

    nextBlock = sf::RectangleShape(sf::Vector2f ({size.x/3, size.y}));
    nextBlock.setFillColor({250,250,250,50});
    nextBlock.setOrigin({nodeSize.x, nodeSize.y});
    nextBlock.setPosition({nodeSize.x/3 *2, nodeSize.y});

    prevBlock = sf::RectangleShape(sf::Vector2f ({size.x/3, size.y}));
    prevBlock.setFillColor({250,250,250,50});

    prevBlock.setOrigin({nodeSize.x, nodeSize.y});
    prevBlock.setPosition({nodeSize.x/3*4, nodeSize.y});

    next = Arrowshape(sf::Vector2f ({size.x, size.y}), Direction::RIGHT);

    prev = Arrowshape(sf::Vector2f ({size.x, size.y}), Direction::LEFT);

}

void NodeShape::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    states.transform = body.getTransform();

    window.draw(body);

    window.draw(prev,states);
    window.draw(next,states);
    window.draw(nextBlock,states);
    window.draw(prevBlock,states);

}

void NodeShape::setPosition(const sf::Vector2f &position)
{
    // Set the position of body
    body.setPosition(position);

    // Set the position of prev and next to be at the center of the body
    prev.setPosition({position.x, position.y});
    next.setPosition({position.x, position.y});

    // // Set the position of nextBlock to be at the right edge of the body
    // nextBlock.setPosition({position.x+nodeSize.x/3, position.y});
    //
    // // Set the position of prevBlock to be at the left edge of the body
    // prevBlock.setPosition({position.x-nodeSize.x/3, position.y});
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
    // nextBlock.move(offset);
    // prevBlock.move(offset);
}


