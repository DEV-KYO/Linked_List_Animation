//
// Created by jnmen on 5/31/2024.
//

#ifndef NODESHAPE_H
#define NODESHAPE_H
#include <any>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Text.hpp>


#include "../Arrowshape/Arrowshape.h"
#include "../../Font/FontManager.h"
#include "../../Font/EnumFonts.h"


class NodeShape : public sf::RectangleShape {
private:
    Arrowshape prev, next;
    sf::RectangleShape prevBlock, nextBlock;
    sf::RectangleShape body;

    sf::Vector2f nodeSize;

    std::any data;
    sf::Font font;
    sf::Text text;

public:

    NodeShape(const std::string& data);
    NodeShape(const sf::Vector2f &size, const std::string& data);
    void update();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
    void setPosition(const sf::Vector2f &position);

    void rotate(float angle);
    void move(sf::Vector2<float> offset);
    void zoom(float factor);

    void getLocalBounds(sf::FloatRect& rect) const;

    void setData(const std::any& data);
    void setFont(EnumFonts font);
    void setFontSize(unsigned int size);

    std::any getData() const;
};


#endif //NODESHAPE_H
