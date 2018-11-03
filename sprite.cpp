#include "sprite.hpp"

CSprite::CSprite(){
  window = g_pFramework->getWindow();
}

void CSprite::init(std::string inputImage){

  texture.loadFromFile(inputImage);
  sprite.setTexture(texture);
}

void CSprite::init(const std::string inputImage,float width,float height){
  texture.loadFromFile(inputImage);
  sprite.setTexture(texture);
  sprite.setTextureRect(sf::IntRect(0, 0, width, height));

}

void CSprite::render(){
  window->draw(sprite);
}

void CSprite::setPos(float xPos,float yPos){
  sprite.setPosition(sf::Vector2f(xPos,yPos));
}
