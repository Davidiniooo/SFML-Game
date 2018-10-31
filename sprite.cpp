#include "sprite.hpp"

CSprite::CSprite(){
  window = g_pFramework->getWindow();
}

void CSprite::init(std::string inputImage){
  sf::Texture texture;
  texture.loadFromFile(inputImage);
  sprite.setTexture(texture);
}

void CSprite::render(){
  window->draw(sprite);
}
