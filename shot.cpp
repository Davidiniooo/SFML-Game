#include"shot.hpp"
#include <math.h>
#include<iostream>

CShot::CShot(){

}

void CShot::init(float xPos, float yPos, float speed,float viewDirection){
  m_shotSprite.init("Images/shot.png");
  m_shotSprite.setScale(0.5);

  m_fxPos = xPos;
  m_fyPos = yPos;
  m_fspeed= speed;
  m_fviewDirection= viewDirection;

}
void CShot::move(){
  if(m_fviewDirection>=0&&m_fviewDirection<90)
  {
    m_fyPos -= sin(m_fviewDirection* M_PI/180)*m_fspeed;
    m_fxPos += cos(m_fviewDirection* M_PI/180)*m_fspeed;
  }
  if(m_fviewDirection>=90&&m_fviewDirection<180)
  {
    m_fyPos += sin(m_fviewDirection* M_PI/180)*m_fspeed;
    m_fxPos += cos(m_fviewDirection* M_PI/180)*m_fspeed;
  }
  if(m_fviewDirection>=180&&m_fviewDirection<270)
  {
    m_fyPos += sin(m_fviewDirection* M_PI/180)*m_fspeed;
    m_fxPos -= cos(m_fviewDirection* M_PI/180)*m_fspeed;
  }
  if(m_fviewDirection>=270&&m_fviewDirection<360)
  {
    m_fyPos -= sin(m_fviewDirection* M_PI/180)*m_fspeed;
    m_fxPos -= cos(m_fviewDirection* M_PI/180)*m_fspeed;
  }
}


void CShot::render(){
  m_shotSprite.rotate(90-m_fviewDirection);
  m_shotSprite.setPos(m_fxPos,m_fyPos);

  m_shotSprite.render();
}
