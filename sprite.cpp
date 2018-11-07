#include "sprite.hpp"

CSprite::CSprite(){
  window = g_pFramework->getWindow();
  sprite.setPosition(sf::Vector2f(0,0));
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

void CSprite::initAnimation(const std::string inputImage,int numOfAnimPhases){
    animationPhases = numOfAnimPhases;
    texture.loadFromFile(inputImage);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, texture.getSize().x/animationPhases, texture.getSize().y));
    sprite.setScale(5,5);
  }

void CSprite::render(){
  window->draw(sprite);
}

void CSprite::renderAnimation(int animationPhase){
  sprite.setTextureRect(sf::IntRect((texture.getSize().x/animationPhases)*animationPhase,0, texture.getSize().x/animationPhases, texture.getSize().y));
  window->draw(sprite);
}

void CSprite::setPos(float xPos,float yPos){
  sprite.setPosition(sf::Vector2f(xPos,yPos));
}
