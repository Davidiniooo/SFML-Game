#include"player.hpp"
#include <iostream>
#define PI 3.141592653589793238462643383279

CPlayer::CPlayer(CCharacter* player){
  m_pCharacter = player;
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

  m_pCharacter->move(directionx,directiony);
  moveCamera();
}

void CPlayer::checkMouse(){
  sf::Vector2i mousePosition = sf::Mouse::getPosition(*(g_pFramework->getWindow()));
  sf::Vector2i windowMiddle;
  float viewAngle;
  windowMiddle.x = round(g_pFramework->getWindow()->getPosition().x+(g_pFramework->getWindow()->getSize().x/2));
  windowMiddle.y = round(g_pFramework->getWindow()->getPosition().y+(g_pFramework->getWindow()->getSize().y/2));

  if(mousePosition.x == windowMiddle.x)
  {
    if(mousePosition.y >= windowMiddle.y)
    {
      m_pCharacter->setViewDirection(0);
    }
    else if(mousePosition.y < windowMiddle.y)
    {
      m_pCharacter->setViewDirection(180);
    }
  }
  else if(mousePosition.y == windowMiddle.y)
  {
    if(mousePosition.x<windowMiddle.x)
    {
      m_pCharacter->setViewDirection(270);
    }
    else if(mousePosition.x>windowMiddle.x)
    {
      m_pCharacter->setViewDirection(90);
    }
  }
  else
  {
    viewAngle = atan(abs(mousePosition.y-windowMiddle.y)/abs(mousePosition.x-windowMiddle.x))*(360/(2*PI));
  
    if(mousePosition.x>=windowMiddle.x&&mousePosition.y>=windowMiddle.y)
    {
      viewAngle += 90;
    }
    else if(mousePosition.x<windowMiddle.x&&mousePosition.y>windowMiddle.y)
    {
      viewAngle += 180;
    }
    else if(mousePosition.x<=windowMiddle.x&&mousePosition.y<=windowMiddle.y)
    {
      viewAngle += 270;
    }

    m_pCharacter->setViewDirection(viewAngle);
  }

}

void CPlayer::moveCamera(){
  g_pFramework->updateView(m_pCharacter->getPos());
}
