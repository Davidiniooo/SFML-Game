#ifndef TIMER_HPP
#define TIMER_HPP

#include<SFML/Graphics.hpp>
#include"singleton.hpp"

#define g_pTimer CTimer::Get()

class CTimer : public TSingleton<CTimer>
{
public:
  CTimer();
  float getElapsed();
  void reset();
private:
  sf::Clock clock;
  sf::Time elapsed;
  float timeasfloat;
};
#endif
