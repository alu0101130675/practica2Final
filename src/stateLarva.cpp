#include "../include/stateLarva.hpp"
char StateLarva::getState() const
{
  return 'l';
}
int StateLarva::vecinos(const Grid &board, int i, int j)
{
  int counter = 0;
  int larvas = 0;
  resto_ = 0;
  vecinaLarva_ = 0;
  // bucle para mirar todas las posiciones de las vecinas
  for (int k = i - 1; k <= i + 1; k++)
  {
    for (int l = j - 1; l <= j + 1; l++)
    {
      // evitamos contar la posicion en la que estamos
      if (k != i || l != j)
        // comprobamos si es adulta
        if (board.get_Malla()[k * board.get_Columnas() + l]->getState() == 'l')
          larvas++;
        else if (board.get_Malla()[k * board.get_Columnas() + l]->getState() != ' ')
        {
          counter++;
        }
    }
  }
  vecinaLarva_ = larvas;
  resto_ = counter;
  return 1;
}
State *StateLarva::nextState()
{
  if (vecinaLarva_ > resto_)
  {
    StateMuerta *ptr2 = new StateMuerta;
    return ptr2;
  }
  else
  {
    StatePupa *ptr2 = new StatePupa;
    return ptr2;
  }
}