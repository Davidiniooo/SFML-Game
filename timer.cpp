#include"timer.hpp"

CTimer::CTimer(){

}

float CTimer::getElapsed(){

  return timeasfloat;
}
void CTimer::reset(){
  elapsed = clock.restart();
  timeasfloat= elapsed.asSeconds();
}
