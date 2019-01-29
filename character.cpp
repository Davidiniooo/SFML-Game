#include "character.hpp"
#include "timer.hpp"
#include"math.h"
#include <iostream>

CCharacter::CCharacter(){

}

void CCharacter::init(const std::string texture,float xPos, float yPos,float acceleration, float maxVelocity){

  m_fAcceleration = acceleration;
  m_fMaxVelocity = maxVelocity;
  m_pcharacterSprite.initAnimation(texture,12);

  m_fxPos = xPos;
  m_fyPos = yPos;
  m_fxVelocity = 0;
  m_fyVelocity = 0;
  m_fviewDirection = 0;
  m_fcurrentAnimPhase = ANIMPHASE_STANDING_UP;
  m_pcharacterSprite.setPos(m_fxPos,m_fyPos);
  m_CharacterWeapon.init("Images/smg1.png",m_fxPos,m_fyPos);
}

void CCharacter::move(int leftright,int updown){
  if(leftright == LEFT)
  {
    m_fxVelocity-=m_fAcceleration * g_pTimer->getElapsed();
  }
  else if(leftright == RIGHT)
  {
    m_fxVelocity+=m_fAcceleration * g_pTimer->getElapsed();
  }
  else if(leftright == NO)
  {
    if(m_fxVelocity>0)
      {
        m_fxVelocity-=m_fAcceleration * g_pTimer->getElapsed()*5;
        if(m_fxVelocity<0)
          m_fxVelocity = 0;
      }
    else if(m_fxVelocity<0)
      {
        m_fxVelocity+=m_fAcceleration * g_pTimer->getElapsed()*5;
        if(m_fxVelocity>0)
          m_fxVelocity = 0;
      }
  }
  if(updown == UP)
  {
    m_fyVelocity-=m_fAcceleration * g_pTimer->getElapsed();
  }
  else if(updown == DOWN)
  {
    m_fyVelocity+=m_fAcceleration * g_pTimer->getElapsed();
  }
  else if(updown == NO)
  {
    if(m_fyVelocity>0)
      {
        m_fyVelocity-=m_fAcceleration * g_pTimer->getElapsed()*5;
        if(m_fyVelocity<0)
          m_fyVelocity = 0;
      }
    else if(m_fyVelocity<0)
      {
        m_fyVelocity+=m_fAcceleration * g_pTimer->getElapsed()*5;
        if(m_fyVelocity>0)
          m_fyVelocity = 0;
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


  m_fxPos += m_fxVelocity*g_pTimer->getElapsed();
  m_fyPos += m_fyVelocity*g_pTimer->getElapsed();
}

void CCharacter::render(){
  if(m_fxVelocity != 0 || m_fyVelocity != 0)
  {
    m_fcurrentAnimPhase += sqrt(pow(m_fxVelocity,2)+pow(m_fyVelocity,2))*g_pTimer->getElapsed()*0.002;

    if(m_fviewDirection>=45&&m_fviewDirection <135)
    {
      if(m_fcurrentAnimPhase>ANIMPHASE_WALKING_RIGHT_2||m_fcurrentAnimPhase<ANIMPHASE_WALKING_RIGHT_1)
      {
        m_fcurrentAnimPhase= ANIMPHASE_WALKING_RIGHT_1;
      }
    }
    else if(m_fviewDirection>=135&&m_fviewDirection <225)
    {
      if(m_fcurrentAnimPhase>ANIMPHASE_WALKING_DOWN_2||m_fcurrentAnimPhase<ANIMPHASE_WALKING_DOWN_1)
      {
        m_fcurrentAnimPhase= ANIMPHASE_WALKING_DOWN_1;
      }
    }
    else if(m_fviewDirection>=225&&m_fviewDirection <315)
    {
      if(m_fcurrentAnimPhase>ANIMPHASE_WALKING_LEFT_2||m_fcurrentAnimPhase<ANIMPHASE_WALKING_LEFT_1)
      {
        m_fcurrentAnimPhase= ANIMPHASE_WALKING_LEFT_1;
      }
    }
    else
    {
      if(m_fcurrentAnimPhase>ANIMPHASE_WALKING_UP_2||m_fcurrentAnimPhase<ANIMPHASE_WALKING_UP_1)
      {
        m_fcurrentAnimPhase= ANIMPHASE_WALKING_UP_1;
      }
    }

  }
  else
  {
    if(m_fviewDirection>=45&&m_fviewDirection <135)
    {
      m_fcurrentAnimPhase =  ANIMPHASE_STANDING_RIGHT;
    }
    else if(m_fviewDirection>=135&&m_fviewDirection <225)
    {
      m_fcurrentAnimPhase =  ANIMPHASE_STANDING_DOWN;
    }
    else if(m_fviewDirection>=225&&m_fviewDirection <315)
    {
      m_fcurrentAnimPhase =  ANIMPHASE_STANDING_LEFT;
    }
    else
    {
      m_fcurrentAnimPhase =  ANIMPHASE_STANDING_UP;
    }
  }

  m_pcharacterSprite.setPos(m_fxPos,m_fyPos);
  renderWeapon();
  m_pcharacterSprite.renderAnimation(round(m_fcurrentAnimPhase));
}

void CCharacter::processCollision(CSprite collidingSprite){
  sf::Vector2f middleCharacter;
  middleCharacter.x = this->getCSprite().getSprite().getGlobalBounds().left + (this->getCSprite().getSprite().getGlobalBounds().width / 2);
  middleCharacter.y = this->getCSprite().getSprite().getGlobalBounds().top  + (this->getCSprite().getSprite().getGlobalBounds().height / 2);

  sf::Vector2f middleColliding;
  middleColliding.x = collidingSprite.getSprite().getGlobalBounds().left + (collidingSprite.getSprite().getGlobalBounds().width / 2);
  middleColliding.y = collidingSprite.getSprite().getGlobalBounds().top  + (collidingSprite.getSprite().getGlobalBounds().height / 2);

  float collisionAngle = atan((abs(middleCharacter.y-middleColliding.y)/abs(middleCharacter.x-middleColliding.x)))*(360/(2*PI));
  if(middleCharacter.x == middleColliding.x)
  {
    if(middleCharacter.y >= middleColliding.y)
    {
      m_fyPos = collidingSprite.getSprite().getGlobalBounds().top+collidingSprite.getSprite().getGlobalBounds().height;
      m_fyVelocity = 0;
    }
    else if(middleCharacter.y < middleColliding.y)
    {
      m_fyPos = collidingSprite.getSprite().getGlobalBounds().top - this->getCSprite().getSprite().getGlobalBounds().height;
      m_fyVelocity = 0;
    }
  }
  else if(middleCharacter.y == middleColliding.y)
  {
    if(middleCharacter.x<middleColliding.x)
    {
      m_fxPos =  collidingSprite.getSprite().getGlobalBounds().left - this->getCSprite().getSprite().getGlobalBounds().width;
      m_fxVelocity = 0;
    }
    else if(middleCharacter.x>middleColliding.x)
    {
      m_fxPos =  collidingSprite.getSprite().getGlobalBounds().left + collidingSprite.getSprite().getGlobalBounds().width;
      m_fxVelocity = 0;
    }
  }
  else
  {
    if(middleCharacter.x>=middleColliding.x&&middleCharacter.y<=middleColliding.y)
    {
      collisionAngle = 90 - collisionAngle;
    }
    else if(middleCharacter.x>=middleColliding.x&&middleCharacter.y>middleColliding.y)
    {
      collisionAngle += 90;
    }
    else if(middleCharacter.x<middleColliding.x&&middleCharacter.y>middleColliding.y)
    {
      collisionAngle = 90-collisionAngle+180;
    }
    else if(middleCharacter.x<=middleColliding.x&&middleCharacter.y<=middleColliding.y)
    {
      collisionAngle += 270;
    }
  }
  if(collisionAngle>=45&&collisionAngle<135)
  {
    m_fxPos =  collidingSprite.getSprite().getGlobalBounds().left + collidingSprite.getSprite().getGlobalBounds().width;
    m_fxVelocity = 0;
  }
  else if(collisionAngle>=135&&collisionAngle<225)
  {
    m_fyPos = collidingSprite.getSprite().getGlobalBounds().top+collidingSprite.getSprite().getGlobalBounds().height;
    m_fyVelocity = 0;
  }
  else if(collisionAngle>=225&&collisionAngle<315)
  {
    m_fxPos =  collidingSprite.getSprite().getGlobalBounds().left - this->getCSprite().getSprite().getGlobalBounds().width;
    m_fxVelocity = 0;
  }
  else if(collisionAngle>=315||collisionAngle<45)
  {
    m_fyPos = collidingSprite.getSprite().getGlobalBounds().top - this->getCSprite().getSprite().getGlobalBounds().height;
    m_fyVelocity = 0;
  }
  m_pcharacterSprite.setPos(m_fxPos,m_fyPos);
}

void CCharacter::setViewDirection(float degrees){
  m_fviewDirection = degrees;
}

sf::Vector2f CCharacter::getPos(){
  sf::Vector2f tempPos(m_fxPos,m_fyPos);
  return tempPos;
}

void CCharacter::renderWeapon(){
  float tempViewDirection = m_fviewDirection;
    if(tempViewDirection==0||tempViewDirection==90||tempViewDirection==180||tempViewDirection==270)
      tempViewDirection++;

  m_CharacterWeapon.setRotation(tempViewDirection-90);
  float tempXPos;
  float tempYPos;
  tempXPos = this->getCSprite().getSprite().getGlobalBounds().left + (this->getCSprite().getSprite().getGlobalBounds().width / 2) ;
  tempYPos = this->getCSprite().getSprite().getGlobalBounds().top  + (this->getCSprite().getSprite().getGlobalBounds().height / 2);
  m_CharacterWeapon.setPosition(tempXPos,tempYPos);
  m_CharacterWeapon.render();
}
void CCharacter::shoot(){
  if(m_CharacterWeapon.m_fWeaponCooldown==0)
  {
    CShot* tempshot = new CShot;

    float tempXPos = m_fxPos+m_pcharacterSprite.getSprite().getGlobalBounds().width/2;
    float tempYPos = m_fyPos+m_pcharacterSprite.getSprite().getGlobalBounds().height/2;

    if(m_fviewDirection>=0&&m_fviewDirection<90)
    {
      tempYPos -= sin((90-m_fviewDirection)* M_PI/180)*(m_CharacterWeapon.m_fWidth+10);
      tempXPos += cos((90-m_fviewDirection)* M_PI/180)*(m_CharacterWeapon.m_fWidth+10);
    }
    if(m_fviewDirection>=90&&m_fviewDirection<180)
    {
      tempYPos += sin((m_fviewDirection-90)* M_PI/180)*(m_CharacterWeapon.m_fWidth+10);
      tempXPos += cos((m_fviewDirection-90)* M_PI/180)*(m_CharacterWeapon.m_fWidth+10);
    }
    if(m_fviewDirection>=180&&m_fviewDirection<270)
    {
      tempYPos += sin((270-m_fviewDirection)* M_PI/180)*(m_CharacterWeapon.m_fWidth+10);
      tempXPos -= cos((270-m_fviewDirection)* M_PI/180)*(m_CharacterWeapon.m_fWidth+10);
    }
    if(m_fviewDirection>=270&&m_fviewDirection<360)
    {
      tempYPos -= sin((m_fviewDirection-270)* M_PI/180)*(m_CharacterWeapon.m_fWidth+10);
      tempXPos -= cos((m_fviewDirection-270)* M_PI/180)*(m_CharacterWeapon.m_fWidth+10);
    }
    tempshot->init(tempXPos,tempYPos,600,m_fviewDirection);
    g_pInformation->addShot(tempshot);
    m_CharacterWeapon.m_fWeaponCooldown=0.15;
  }
}
