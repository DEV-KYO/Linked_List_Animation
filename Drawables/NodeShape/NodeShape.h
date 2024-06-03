//
// Created by jnmen on 5/31/2024.
//

#ifndef NODESHAPE_H
#define NODESHAPE_H
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include "../Arrowshape/Arrowshape.h"


class NodeShape : public sf::RectangleShape {
private:
    Arrowshape prev, next;
    sf::RectangleShape prevBlock, nextBlock;
    sf::RectangleShape body;

    sf::Vector2f nodeSize;

public:

    NodeShape();
    NodeShape(const sf::Vector2f &size);
    void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
    void setPosition(const sf::Vector2f &position);

    void rotate(float angle);
    void move(sf::Vector2<float> offset);
};


#endif //NODESHAPE_H
