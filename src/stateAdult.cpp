#include "../include/stateAdult.hpp"
char StateAdult::getState() const {
  return 'a';
}
int StateAdult::vecinos(const Grid &board, int i, int j)
{
  int counter = 0;
  vecinas_=0;

  // bucle para mirar todas las posiciones de las vecinas
 for (int k = i - 1; k <= i + 1; k++)
  {

    for (int s = j - 1; s <= j + 1; s++)
      {      
      
      // evitamos contar la posicion en la que estamos
      if (k != i || s != j)
        // comprobamos si es adulta
        if (board.get_Malla()[k * board.get_Columnas() + s]->getState() == 'a')
          counter++;
    }
  }
  vecinas_=counter;
  return 1;
}
State* StateAdult::nextState() {
  if (vecinas_>0)
  {
    StateEgg *ptr2 = new StateEgg;
    return 	ptr2;
  }  
  else {
        StateMuerta *ptr2 = new StateMuerta;
    return 	ptr2;
  }
}