#include"game.hpp"
#include<iostream>

void CGame::init(){

}

void CGame::run(){

  CCharacter TestCharacter(100.0f,100.0f);
  TestCharacter.init("Images/test.png",100,10);

  CCharacter TestCharacter2(10.0f,10.0f);
  TestCharacter2.init("Images/test2.png",100,10);

  CCharacter TestCharacter3(25.0f,50.0f);
  TestCharacter3.init("Images/test2.png",100,10);

  CBlock TestBlock1;
  TestBlock1.init("Images/test3.png",100,100,100,100);


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
      TestBlock1.render();

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
  if(g_pFramework->getEvent().type!=sf::Event::Closed)

  switch (g_pFramework->getEvent().type)
  {
    case (sf::Event::Closed):
    {
      g_pFramework->close();
    }break;

  }
}
