#include<string>
#include <iostream>
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
  void initAnimation(const std::string inputImage,int animationPhases);

  void render();
  void renderAnimation(int animationPhase);
  void setPos(float xPos, float yPos);
  sf::Sprite getSprite(){return sprite;};
private:
  sf::Sprite sprite;
  sf::Texture texture;
  sf::RenderWindow * window;
  int animationPhases;
};
#endif
