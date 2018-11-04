#include"game.hpp"
#include<iostream>

void CGame::init(){
  CCharacter TestCharacter;
  TestCharacter.init("Images/test.png",0,0,10,10);

  CCharacter TestCharacter2;
  TestCharacter2.init("Images/test2.png",0,0,100,100);

  CCharacter TestCharacter3;
  TestCharacter3.init("Images/test2.png",0,0,100,100);

  characterList.push_back(TestCharacter);
  characterList.push_back(TestCharacter2);
  characterList.push_back(TestCharacter3);

}

void CGame::run(){


  std::list<CCharacter>::iterator iteratorCCharacter;
  Player= new CPlayer;
  createBackground();

  while(g_pFramework->getWindow()->isOpen()==true)
    {

      g_pFramework->update();
      handleEvents();

      Player->checkKeyboard();

      for (iteratorCCharacter = characterList.begin();iteratorCCharacter!=iteratorCCharacter;iteratorCCharacter++)
      {
        iteratorCCharacter->render();
      }

      for(int x = 0;x<29;x++){
      {
        for(int y = 0;y<29;y++)
        {
          background[x][y].render();
        }
      }
      g_pFramework->render();

    }
}
CGame::CGame(){

}

void CGame::handleEvents(){

  switch (g_pFramework->getEvent().type)
  {
    case (sf::Event::Closed):
    {
      g_pFramework->close();
    }break;

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
