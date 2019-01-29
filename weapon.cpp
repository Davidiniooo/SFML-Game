#include"weapon.hpp"


CWeapon::CWeapon(){

}

void CWeapon::init(const std::string texture,float xPos, float yPos){
  m_fxPos = xPos;
  m_fyPos = yPos;

  m_fWeaponCooldown = 0.15f;

  m_weaponSprite.init(texture);
  m_weaponSprite.setScale(3);
  m_weaponSprite.setPos(xPos,yPos);

  m_fWidth = m_weaponSprite.getSprite().getGlobalBounds().width;
  m_fHeight = m_weaponSprite.getSprite().getGlobalBounds().height;
  m_weaponSprite.setOrigin(0,3);
}

void CWeapon::setRotation(float degrees){
  m_fRotation = degrees;
}

void CWeapon::setPosition(float xPos,float yPos){
  m_fxPos = xPos;
  m_fyPos = yPos;
}

void CWeapon::render(){

  m_fWeaponCooldown -= g_pTimer->getElapsed();
  if(m_fWeaponCooldown<0)
    m_fWeaponCooldown = 0;

  m_weaponSprite.setPos(m_fxPos,m_fyPos);
  m_weaponSprite.rotate(m_fRotation);

  m_weaponSprite.render();
}
