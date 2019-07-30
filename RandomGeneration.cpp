#include "RandomGeneration.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h> 

using namespace GoL;

RandomGeneration::RandomGeneration(int rows, int columns)
   : Generation()
{
   m_rows = rows;
   m_columns = columns;

   std::srand((int)time(0));
   m_cells = std::vector<bool>(rows * columns);

   for (int i = 0; i < rows * columns; i++)
   {
      bool isAlive = rand() % 2 == 1;
      m_cells[i] = isAlive;
   }
}