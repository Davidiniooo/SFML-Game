#include "framework.hpp"
#include<iostream>
CFramework::CFramework(){
  window = NULL;
}

void CFramework::init(int width,int height){
  window = new sf::RenderWindow(sf::VideoMode(width,height),"window");
  view = window->getDefaultView();
  window->setView(view);
}

void CFramework::render(){
  window->setView(view);
  window->display();
}

void CFramework::checkEvents(){
  window->pollEvent(event);
}

void CFramework::close(){
  window->close();
}

void CFramework::update(){
  g_pTimer->reset();
  checkEvents();
  window->clear();
}

void CFramework::updateView(sf::Vector2f pos){
  view.setCenter(pos);
}
