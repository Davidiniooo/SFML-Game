#include "sprite.hpp"

CSprite::CSprite(){
  window = CFramework::Get()->getWindow();
}

void CSprite::init(std::string inputImage){

  texture.loadFromFile(inputImage);
  sprite.setTexture(texture);
}

void CSprite::render(){
  window->draw(sprite);
}

void CSprite::setPos(float xPos,float yPos){
  sprite.setPosition(sf::Vector2f(xPos,yPos));
}
