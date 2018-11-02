#include"game.hpp"
#include<iostream>


void CGame::run(){

  CCharacter TestCharacter(0.1f);
  TestCharacter.init("test.png",100,10);

  CCharacter TestCharacter2(0.1f);
  TestCharacter2.init("test2.png",100,10);

  CCharacter TestCharacter3(0.1f);
  TestCharacter3.init("test2.png",100,10);

  CPlayer Player(&TestCharacter);

  float secondsGone = 0;
  float framesGone = 0;

  while(g_pFramework->getWindow()->isOpen()==true)
    {

      g_pFramework->update();
      secondsGone += g_pTimer->getElapsed();
      framesGone++;
      handleEvents();

      Player.checkKeyboard();

      TestCharacter2.move(RIGHT,NO);
      TestCharacter3.move(RIGHT,UP);

      TestCharacter.render();
      TestCharacter2.render();
      TestCharacter3.render();

      g_pFramework->render();

      if(framesGone>300)
      {
        secondsGone = 0;
        framesGone = 0;
      }
    }

}

CGame::CGame(){}

void CGame::handleEvents(){

  switch (g_pFramework->getEvent().type)
  {
    case (sf::Event::Closed):
    {
      g_pFramework->close();
    }
      break;

  }
}
