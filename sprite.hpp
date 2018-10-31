#include<string>
#include<SFML/Graphics.hpp>
#include "framework.hpp"
class CSprite
{
public:
  CSprite();
  void init(const std::string inputImage);
  void render();
private:
  sf::Sprite sprite;
  sf::RenderWindow * window;
};
