#include"game.hpp"
#include<iostream>


void CGame::run(){

  CCharackter Solider(0.1f);
  Solider.init("test.png",100,10);

  CCharackter Solider2(0.1f);
  Solider2.init("test2.png",100,10);

  CPlayer Player(&Solider);

  float secondsGone = 0;
  float framesGone = 0;

  while(g_pFramework->getWindow()->isOpen()==true)
    {

      g_pFramework->update();
      secondsGone += g_pTimer->getElapsed();
      framesGone++;
      handleEvents();
      Player.checkKeyboard();

      //Solider2.move(RIGHT,UP);

      Solider.render();
      Solider2.render();

      g_pFramework->render();

      std::cout << framesGone / secondsGone << '\n';
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
