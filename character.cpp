#include "character.hpp"
#include "timer.hpp"
#include <iostream>


CCharacter::CCharacter(){

}

void CCharacter::init(const std::string texture,float xPos, float yPos,float acceleration, float maxVelocity){

  m_fAcceeration = acceleration;
  m_fMaxVelocity = maxVelocity;
  m_pcharacterSprite.initAnimation(texture,6);

  m_fxPos = xPos;
  m_fyPos = yPos;
  m_fxVelocity = 0;
  m_fyVelocity = 0;
  m_fviewDirection = 250;
  m_fcurrentAnimPhase = ANIMPHASE_STANDING_LEFT;
  m_pcharacterSprite.setPos(m_fxPos,m_fyPos);
  std::cout<<"tr";
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


  m_fxPos += m_fxVelocity;
  m_fyPos += m_fyVelocity;
}

void CCharacter::render(){
  if(m_fxVelocity != 0 || m_fyVelocity != 0)
  {
    if(m_fviewDirection>=45&&m_fviewDirection <135)
    {
      m_fcurrentAnimPhase += sqrt(abs(pow(m_fxVelocity,2))+abs(pow(m_fyVelocity,2))*g_pTimer->getElapsed());

      if(m_fcurrentAnimPhase>ANIMPHASE_WALKING_RIGHT_2||m_fcurrentAnimPhase<ANIMPHASE_WALKING_RIGHT_1)
      {
        m_fcurrentAnimPhase= ANIMPHASE_WALKING_RIGHT_1;
      }
    }
    if(m_fviewDirection>=135&&m_fviewDirection <225)
    {
      m_fcurrentAnimPhase += sqrt(abs(pow(m_fxVelocity,2))+abs(pow(m_fyVelocity,2))*g_pTimer->getElapsed());

      if(m_fcurrentAnimPhase>ANIMPHASE_WALKING_RIGHT_2||m_fcurrentAnimPhase<ANIMPHASE_WALKING_RIGHT_1)
      {
        m_fcurrentAnimPhase= ANIMPHASE_WALKING_RIGHT_1;
      }
    }
    if(m_fviewDirection>=225&&m_fviewDirection <315)
    {
      m_fcurrentAnimPhase += sqrt(abs(pow(m_fxVelocity,2))+abs(pow(m_fyVelocity,2))*g_pTimer->getElapsed());

      if(m_fcurrentAnimPhase>ANIMPHASE_WALKING_LEFT_2||m_fcurrentAnimPhase<ANIMPHASE_WALKING_LEFT_1)
      {
        m_fcurrentAnimPhase= ANIMPHASE_WALKING_RIGHT_1;
      }
    }
    if(m_fviewDirection>=315&&m_fviewDirection <45)
    {
      m_fcurrentAnimPhase += sqrt(abs(pow(m_fxVelocity,2))+abs(pow(m_fyVelocity,2))*g_pTimer->getElapsed());

      if(m_fcurrentAnimPhase>ANIMPHASE_WALKING_LEFT_2||m_fcurrentAnimPhase<ANIMPHASE_WALKING_LEFT_1)
      {
        m_fcurrentAnimPhase= ANIMPHASE_WALKING_LEFT_1;
      }
    }

  }
  else
  {
    if(m_fviewDirection>=45&&m_fviewDirection <135)
    {
      m_fcurrentAnimPhase =  ANIMPHASE_STANDING_RIGHT;
    }
    if(m_fviewDirection>=135&&m_fviewDirection <255)
    {
      m_fcurrentAnimPhase =  ANIMPHASE_STANDING_RIGHT;
    }
    if(m_fviewDirection>=255&&m_fviewDirection <315)
    {
      m_fcurrentAnimPhase =  ANIMPHASE_STANDING_LEFT;
    }
    if(m_fviewDirection>=315&&m_fviewDirection <45)
    {
      m_fcurrentAnimPhase =  ANIMPHASE_STANDING_LEFT;
    }

  }
  m_pcharacterSprite.setPos(m_fxPos,m_fyPos);
  m_pcharacterSprite.renderAnimation(round(m_fcurrentAnimPhase));
}

void CCharacter::setViewDirection(float degrees){
  m_fviewDirection = degrees;
}

sf::Vector2f CCharacter::getPos(){
  sf::Vector2f tempPos(m_fxPos,m_fyPos);
  return tempPos;
}
