#include"shot.hpp"
#include <math.h>
#include<iostream>

CShot::CShot(){

}

CShot::~CShot(){

}

void CShot::init(float xPos, float yPos, float speed,float viewDirection){
  m_shotSprite.init("Images/shot.png");
  m_shotSprite.setScale(0.65);

  m_fxPos = xPos;
  m_fyPos = yPos;
  m_fspeed= speed;
  m_fviewDirection= viewDirection;

}
void CShot::move(){
  if(m_fviewDirection>=0&&m_fviewDirection<90)
  {
    m_fyPos -= sin((90-m_fviewDirection)* M_PI/180)*m_fspeed*g_pTimer->getElapsed();
    m_fxPos += cos((90-m_fviewDirection)* M_PI/180)*m_fspeed*g_pTimer->getElapsed();
  }
  if(m_fviewDirection>=90&&m_fviewDirection<180)
  {
    m_fyPos += sin((m_fviewDirection-90)* M_PI/180)*m_fspeed*g_pTimer->getElapsed();
    m_fxPos += cos((m_fviewDirection-90)* M_PI/180)*m_fspeed*g_pTimer->getElapsed();
  }
  if(m_fviewDirection>=180&&m_fviewDirection<270)
  {
    m_fyPos += sin((270-m_fviewDirection)* M_PI/180)*m_fspeed*g_pTimer->getElapsed();
    m_fxPos -= cos((270-m_fviewDirection)* M_PI/180)*m_fspeed*g_pTimer->getElapsed();
  }
  if(m_fviewDirection>=270&&m_fviewDirection<360)
  {
    m_fyPos -= sin((m_fviewDirection-270)* M_PI/180)*m_fspeed*g_pTimer->getElapsed();
    m_fxPos -= cos((m_fviewDirection-270)* M_PI/180)*m_fspeed*g_pTimer->getElapsed();
  }
}


void CShot::render(){
  m_shotSprite.rotate(m_fviewDirection);
  m_shotSprite.setPos(m_fxPos,m_fyPos);

  m_shotSprite.render();
}
