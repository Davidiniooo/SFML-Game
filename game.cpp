#include"game.hpp"
#include<iostream>
#include"shot.hpp"

void CGame::init(){
  CCharacter* TestCharacter = new CCharacter;
  TestCharacter->init("Images/solider.png",0,0,100,10);
  g_pInformation->addCharacter(TestCharacter);

  CCharacter* TestCharacter2 = new CCharacter;
  TestCharacter2->init("Images/solider.png",0,0,100,10);
  g_pInformation->addCharacter(TestCharacter2);

  CObstacle* TestObstacle = new CObstacle;
  TestObstacle->init("Images/test3.png",-100,-100,100,100);
  g_pInformation->addObstacle(TestObstacle);

  CObstacle* TestObstacle2 = new CObstacle;
  TestObstacle2->init("Images/test3.png",-200,-100,100,100);
  g_pInformation->addObstacle(TestObstacle2);

}

void CGame::run(){

  std::list<CCharacter*>::iterator iteratorCCharacter;
  std::list<CObstacle*>::iterator iteratorCObstacle;
  std::list<CShot*>::iterator iteratorShot;


  iteratorCCharacter = g_pInformation->characterList.begin();
  iteratorCObstacle = g_pInformation->obstacleList.begin();
  Player = new CPlayer(*iteratorCCharacter);

  createBackground();
  while(g_pFramework->getWindow()->isOpen()==true)
  {

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

      for (iteratorCObstacle = g_pInformation->obstacleList.begin();iteratorCObstacle!=g_pInformation->obstacleList.end();iteratorCObstacle++)
      {
        (*iteratorCObstacle)->render();
      }

      for (iteratorCCharacter = g_pInformation->characterList.begin();iteratorCCharacter!=g_pInformation->characterList.end();iteratorCCharacter++)
      {
        (*iteratorCCharacter)->render();
      }

      for (iteratorShot = g_pInformation->shotList.begin();iteratorShot!=g_pInformation->shotList.end();iteratorShot++)
      {
        (*iteratorShot)->move();
        (*iteratorShot)->render();
      }

      g_pFramework->render();
  }
}
void CGame::checkCollision(){
  std::list<CCharacter*>::iterator iteratorCCharacter;
  std::list<CObstacle*>::iterator iteratorCObstacle;

  for(iteratorCCharacter = g_pInformation->g_pInformation->characterList.begin();iteratorCCharacter != g_pInformation->characterList.end();iteratorCCharacter++)
  {
    CSprite tempCharacterSprite = (*iteratorCCharacter)->getCSprite();
    sf::FloatRect boundingBoxCharacter = tempCharacterSprite.getSprite().getGlobalBounds();
    for(iteratorCObstacle = g_pInformation->obstacleList.begin();iteratorCObstacle != g_pInformation->obstacleList.end();iteratorCObstacle++)
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
