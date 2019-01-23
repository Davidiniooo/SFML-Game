#include"player.hpp"
#include <iostream>


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
  float viewAngle;
  float mousePositionX = mousePosition.x;
  float mousePositionY = mousePosition.y;
  float windowMiddleX = round(g_pFramework->getWindow()->getSize().x/2);
  float windowMiddleY = round(g_pFramework->getWindow()->getSize().y/2);

  if(mousePositionX == windowMiddleX)
  {
    if(mousePositionY >= windowMiddleY)
    {
      m_pCharacter->setViewDirection(180);
    }
    else if(mousePositionY < windowMiddleY)
    {
      m_pCharacter->setViewDirection(0);
    }
  }
  else if(mousePositionY == windowMiddleY)
  {
    if(mousePositionX<windowMiddleX)
    {
      m_pCharacter->setViewDirection(270);
    }
    else if(mousePositionX>windowMiddleX)
    {
      m_pCharacter->setViewDirection(90);
    }
  }
  else
  {
    viewAngle = atan((abs(mousePositionY-windowMiddleY)/abs(mousePositionX-windowMiddleX)))*(360/(2*PI));
    if(mousePositionX>=windowMiddleX&&mousePositionY<=windowMiddleY)
    {
      viewAngle = 90 - viewAngle;
    }
    else if(mousePositionX>=windowMiddleX&&mousePositionY>windowMiddleY)
    {
      viewAngle += 90;
    }
    else if(mousePositionX<windowMiddleX&&mousePositionY>windowMiddleY)
    {
      viewAngle =90-viewAngle+180;
    }
    else if(mousePositionX<=windowMiddleX&&mousePositionY<=windowMiddleY)
    {
      viewAngle += 270;
    }
    m_pCharacter->setViewDirection(viewAngle);
  }
  if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    m_pCharacter->shoot();
}

void CPlayer::moveCamera(){
  sf::Vector2f tempPos = m_pCharacter->getPos();
  tempPos.x += m_pCharacter->getCSprite().getSprite().getGlobalBounds().width/2;
  tempPos.y += m_pCharacter->getCSprite().getSprite().getGlobalBounds().height/2;
  g_pFramework->updateView(tempPos);
}
