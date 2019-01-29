#include<string>
#include <iostream>
#include<SFML/Graphics.hpp>
#include "framework.hpp"

#ifndef SPRITE_HPP
#define SPRITE_HPP

#define PI 3.141592653589793238462643383279

class CSprite
{
public:
  CSprite();
  void init(const std::string inputImage);
  void init(const std::string inputImage,float width,float height);
  void initAnimation(const std::string inputImage,int animationPhases);

  void setPos(float xPos, float yPos);
  void rotate(float degrees);
  void setScale(float scale);
  void setOrigin(float x, float y);
  sf::Sprite getSprite(){return sprite;};
  void render();
  void renderAnimation(int animationPhase);

private:
  sf::Sprite sprite;
  sf::Texture texture;
  sf::RenderWindow * window;
  int animationPhases;
};
#endif
