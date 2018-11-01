#include"player.hpp"
#include <iostream>
CPlayer::CPlayer(CCharackter *character){
  m_playerCharacter = character;
}

void CPlayer::checkKeyboard(){
  int directionx;
  int directiony;

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)&&sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    directionx = NO;
  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    directionx = LEFT;
  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    directionx = RIGHT;
  else
    directionx = NO;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)&&sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    directiony = NO;
  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    directiony = UP;
  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    directiony = DOWN;
  else
    directiony = NO;

  m_playerCharacter->move(directionx,directiony);
}