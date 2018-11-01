#include "character.hpp"
#include "timer.hpp"
#include <iostream>
CCharackter::CCharackter(float acceleration){
  m_fAcceeration=acceleration;
}

void CCharackter::init(const std::string texture,float xPos, float yPos){
  m_playerSprite.init(texture);

  m_fxPos = xPos;
  m_fyPos = yPos;
  m_playerSprite.setPos(m_fxPos,m_fyPos);
}

void CCharackter::move(int leftright,int updown){
  if(leftright == LEFT)
  {
    m_fxVelocity-=m_fAcceeration* g_pTimer->getElapsed();
  }
  else if(leftright == RIGHT)
  {
        m_fxVelocity+=m_fAcceeration* g_pTimer->getElapsed();
  }
  else if(leftright == NO)
  {
    if(m_fxVelocity>0)
      {
        m_fxVelocity-=m_fAcceeration* g_pTimer->getElapsed();
        if(m_fxVelocity<0)
          m_fxVelocity=0;
      }
    else if(m_fxVelocity<0)
      {
        m_fxVelocity+=m_fAcceeration* g_pTimer->getElapsed();
        if(m_fxVelocity>0)
          m_fxVelocity=0;
      }
  }
  if(updown == UP)
  {
    m_fyVelocity-=m_fAcceeration* g_pTimer->getElapsed();
  }
  else if(updown == DOWN)
  {
    m_fyVelocity+=m_fAcceeration* g_pTimer->getElapsed();
  }
  else if(updown == NO)
  {
    if(m_fyVelocity>0)
      {
        m_fyVelocity-=m_fAcceeration* g_pTimer->getElapsed();
        if(m_fyVelocity<0)
          m_fyVelocity=0;
      }
    else if(m_fyVelocity<0)
      {
        m_fyVelocity+=m_fAcceeration* g_pTimer->getElapsed();
        if(m_fyVelocity>0)
          m_fyVelocity=0;
      }
  }
  m_fxPos += m_fxVelocity;
  m_fyPos += m_fyVelocity;

}

void CCharackter::render(){

  m_playerSprite.setPos(m_fxPos,m_fyPos);
  m_playerSprite.render();
}

sf::Vector2f CCharackter::getPos(){
  sf::Vector2f tempPos(m_fxPos,m_fyPos);
  return tempPos;
}
