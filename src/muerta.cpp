#include "../include/muerta.hpp"

char StateMuerta::getState() const
{
  return ' ';
}
int StateMuerta::vecinos(const Grid &board, int i, int j)
{
  int counter = 0;
  // bucle para mirar todas las posiciones de las vecinas
  for (int k = i - 1; k <= i + 1; k++)
  {
    for (int l = j - 1; l <= j + 1; l++)
    {
      // evitamos contar la posicion en la que estamos
      if (k != i || l != j)
        // comprobamos si es adulta
        if (board.get_Malla()[k * board.get_Columnas() + l]->getState() == 'a')
          counter++;
    }
  }

  vecinas_ = counter;
  return 1;
}
State *StateMuerta::nextState()
{
  if (vecinas_ > 1)
  {
    StateAdult *ptr2 = new StateAdult;
    return ptr2;
  }
  else
  {
    StateMuerta *ptr2 = new StateMuerta;
    return ptr2;
  }
}
