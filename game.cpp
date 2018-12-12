#include"game.hpp"
#include<iostream>

void CGame::init(){
  CCharacter* TestCharacter = new CCharacter;
  TestCharacter->init("Images/solider.png",0,0,100,10);
  characterList.push_back(TestCharacter);

  CObstacle* TestObstacle = new CObstacle;
  TestObstacle->init("Images/test3.png",-100,-100,100,100);
  obstacleList.push_back(TestObstacle);
  CObstacle* TestObstacle2 = new CObstacle;
  TestObstacle2->init("Images/test3.png",-200,-100,100,100);
  obstacleList.push_back(TestObstacle2);

}

void CGame::run(){

  std::list<CCharacter*>::iterator iteratorCCharacter;
  std::list<CObstacle*>::iterator iteratorCObstacle;
  iteratorCCharacter = characterList.begin();
  iteratorCObstacle = obstacleList.begin();
  Player = new CPlayer(*iteratorCCharacter);

  CWeapon testweapon;
  testweapon.init("Images/smg1.png",0,0);
  testweapon.setRotation(70);
  createBackground();
  float test1 = 0;
  while(g_pFramework->getWindow()->isOpen()==true)
  {
      testweapon.setRotation(test1);
      g_pFramework->update();
      handleEvents();
      Player->checkKeyboard();
      Player->checkMouse();
      checkCollision();
      for(int x = 0;x<29;x++)
      {
        for(int y = 0;y<29;y++)
        {
          background[x][y].render();
        }
      }

      for (iteratorCCharacter = characterList.begin();iteratorCCharacter!=characterList.end();iteratorCCharacter++)
      {
        (*iteratorCCharacter)->render();
      }

      for (iteratorCObstacle = obstacleList.begin();iteratorCObstacle!=obstacleList.end();iteratorCObstacle++)
      {

        (*iteratorCObstacle)->render();
      }
      testweapon.render();
      g_pFramework->render();
      test1++;
  }
}
void CGame::checkCollision(){
  std::list<CCharacter*>::iterator iteratorCCharacter;
  std::list<CObstacle*>::iterator iteratorCObstacle;

  for(iteratorCCharacter = characterList.begin();iteratorCCharacter != characterList.end();iteratorCCharacter++)
  {
    CSprite tempCharacterSprite = (*iteratorCCharacter)->getCSprite();
    sf::FloatRect boundingBoxCharacter = tempCharacterSprite.getSprite().getGlobalBounds();
    for(iteratorCObstacle = obstacleList.begin();iteratorCObstacle!=obstacleList.end();iteratorCObstacle++)
    {
      CSprite tempObstacleSprite = (*iteratorCObstacle)->getCSprite();
      sf::FloatRect boundingBoxObstacle = tempObstacleSprite.getSprite().getGlobalBounds();

      if (boundingBoxCharacter.intersects(boundingBoxObstacle))
      {
        (*iteratorCCharacter)->processCollision(tempObstacleSprite);
      }
    }

  }

}

CGame::CGame(){

}
void CGame::handleEvents(){

  switch (g_pFramework->getEvent().type)
  {
    case (sf::Event::Closed):

      g_pFramework->close();
    break;

  }
}

void CGame::createBackground(){

  for(int x = 0;x<29;x++)
  {
    for(int y = 0;y<29;y++)
    {
        switch (map[x][y])
        {
          case 1:
          background[x][y] = CBlock();
          background[x][y].init("Images/test3.png",x*100,y*100,100,100);
          break;

        }
    }
  }
}
