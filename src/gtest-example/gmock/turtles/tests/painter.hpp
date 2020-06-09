#ifndef _PAINTER_HPP_
#define _PAINTER_HPP_

#include "turtle.hpp"

class Painter
{
  private:
    Turtle& m_turtle;

  public:
    Painter(Turtle& turtle);
    ~Painter();

    bool DrawCircle(int x, int y, int z);
};

Painter::Painter(Turtle& turtle)
    : m_turtle(turtle)
{
}

Painter::~Painter()
{
}

bool Painter::DrawCircle(int x, int y, int z)
{
    m_turtle.PenDown();
    return true;
}


#endif // _PAINTER_HPP_