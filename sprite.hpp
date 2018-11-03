#include<string>
#include<SFML/Graphics.hpp>
#include "framework.hpp"

#ifndef SPRITE_HPP
#define SPRITE_HPP

class CSprite
{
public:
  CSprite();
  void init(const std::string inputImage);
  void init(const std::string inputImage,float width,float height);
  void render();
  void setPos(float xPos, float yPos);
private:
  sf::Sprite sprite;
  sf::Texture texture;
  sf::RenderWindow * window;
};
#endif
