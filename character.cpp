#include "character.hpp"
#include "timer.hpp"
#include <iostream>


CCharacter::CCharacter(){

}

void CCharacter::init(const std::string texture,float xPos, float yPos,float acceleration, float maxVelocity){

  m_fAcceeration = acceleration;
  m_fMaxVelocity = maxVelocity;
  m_playerSprite.initAnimation(texture,6);

  m_fxPos = xPos;
  m_fyPos = yPos;
  m_fxVelocity = 0;
  m_fyVelocity = 0;
  m_fcurrentAnimPhase = ANIMPHASE_STANDING_RIGHT;
  m_playerSprite.setPos(m_fxPos,m_fyPos);
}

void CCharacter::move(int leftright,int updown){
  if(leftright == LEFT)
  {
    m_fxVelocity-=m_fAcceeration * g_pTimer->getElapsed();
  }
  else if(leftright == RIGHT)
  {
        m_fxVelocity+=m_fAcceeration * g_pTimer->getElapsed();
  }
  else if(leftright == NO)
  {
    if(m_fxVelocity>0)
      {
        m_fxVelocity-=m_fAcceeration * g_pTimer->getElapsed();
        if(m_fxVelocity<0)
          m_fxVelocity=0;
      }
    else if(m_fxVelocity<0)
      {
        m_fxVelocity+=m_fAcceeration * g_pTimer->getElapsed();
        if(m_fxVelocity>0)
          m_fxVelocity=0;
      }
  }
  if(updown == UP)
  {
    m_fyVelocity-=m_fAcceeration * g_pTimer->getElapsed();
  }
  else if(updown == DOWN)
  {
    m_fyVelocity+=m_fAcceeration * g_pTimer->getElapsed();
  }
  else if(updown == NO)
  {
    if(m_fyVelocity>0)
      {
        m_fyVelocity-=m_fAcceeration * g_pTimer->getElapsed();
        if(m_fyVelocity<0)
          m_fyVelocity=0;
      }
    else if(m_fyVelocity<0)
      {
        m_fyVelocity+=m_fAcceeration * g_pTimer->getElapsed();
        if(m_fyVelocity>0)
          m_fyVelocity=0;
      }
  }
  if(m_fxVelocity>m_fMaxVelocity)
    m_fxVelocity = m_fMaxVelocity;

  if(m_fxVelocity<-m_fMaxVelocity)
    m_fxVelocity = -m_fMaxVelocity;


  if(m_fyVelocity>m_fMaxVelocity)
      m_fyVelocity = m_fMaxVelocity;

  if(m_fyVelocity<-m_fMaxVelocity)
    m_fyVelocity = -m_fMaxVelocity;


  if(m_fyVelocity>0)
    m_lastYDir = DOWN;
  if(m_fyVelocity<0)
    m_lastYDir = UP;
  if(m_fyVelocity>0)
    m_lastXDir = RIGHT;
  if(m_fyVelocity<0)
    m_lastXDir = LEFT;


  m_fxPos += m_fxVelocity;
  m_fyPos += m_fyVelocity;
}

void CCharacter::render(){

  if(m_fxVelocity == 0 &&m_fyVelocity == 0)
  {
    switch (m_lastXDir) {
      case RIGHT:
        m_fcurrentAnimPhase = ANIMPHASE_STANDING_RIGHT;
      case LEFT:
        m_fcurrentAnimPhase = ANIMPHASE_STANDING_LEFT ;
    }

  }


  m_playerSprite.renderAnimation(static_cast<int>(round(m_fcurrentAnimPhase)));
  m_playerSprite.setPos(m_fxPos,m_fyPos);
  m_playerSprite.render();

}

sf::Vector2f CCharacter::getPos(){
  sf::Vector2f tempPos(m_fxPos,m_fyPos);
  return tempPos;
}
