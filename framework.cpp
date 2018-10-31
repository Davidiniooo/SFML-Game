#include "framework.hpp"

CFramework::CFramework(){
  window = NULL;
}

void CFramework::init(int width,int height){
  window = new sf::RenderWindow(sf::VideoMode(width,height),"window");
}

void CFramework::render(){
  window->clear();
  window->display();
}

void checkEvents(){
  window.pollEvent(event);
}
