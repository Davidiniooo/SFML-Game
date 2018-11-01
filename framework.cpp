#include "framework.hpp"

CFramework::CFramework(){
  window = NULL;
}

void CFramework::init(int width,int height){
  window = new sf::RenderWindow(sf::VideoMode(width,height),"window");
  window->setVerticalSyncEnabled(true);
}

void CFramework::render(){

  window->display();
}

void CFramework::checkEvents(){
  window->pollEvent(event);
}

void CFramework::close(){
  window->close();
}

void CFramework::update(){
  checkEvents();
  window->clear();
}
