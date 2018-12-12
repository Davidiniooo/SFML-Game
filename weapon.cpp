#include"weapon.hpp"

CWeapon::CWeapon(){

}

void CWeapon::init(const std::string texture,float xPos, float yPos){
  m_fxPos = xPos;
  m_fyPos = yPos;

  m_weaponSprite.init(texture);
  m_weaponSprite.setScale(3);
  m_weaponSprite.setPos(xPos,yPos);
}

void CWeapon::setRotation(float degrees){
  m_fRotation = degrees;
}

void CWeapon::render(){
  m_weaponSprite.rotate(m_fRotation);
  m_weaponSprite.render();
}
