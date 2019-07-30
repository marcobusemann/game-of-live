#include "BoundlessEvolution.h"

#include <cassert>

using namespace GoL;

namespace
{
   int euclidean_reminder(int a, int b)
   {
      assert(b != 0);
      int r = a % b;
      return r >= 0 ? r : r + std::abs(b);
   }
}

Generation BoundlessEvolution::evolve(const Generation &generation)
{
   Generation next = generation.cloneEmpty();

   for (int r = 0; r < next.rows(); r++)
   {
      for (int c = 0; c < next.columns(); c++)
      {
         int neighbors = livingNeighbors(generation, r, c);
         if (isCellAlive(generation, r, c))
         {
            if (neighbors < 2)
               next.setCell(r, c, false);
            else if (neighbors > 3)
               next.setCell(r, c, false);
            else // neighbors == 2 || neighbors == 3
               next.setCell(r, c, true);
         }
         else
         {
            if (neighbors == 3)
               next.setCell(r, c, true);
            else
               next.setCell(r, c, false);
         }
      }
   }

   return next;
}

bool BoundlessEvolution::isCellAlive(Generation generation, int row, int col) const
{
   row = euclidean_reminder(row, generation.rows());
   col = euclidean_reminder(col, generation.columns());
   return generation.cell(row, col);
}

int BoundlessEvolution::livingNeighbors(Generation generation, int row, int col) const
{
   int living = 0;
   if (isCellAlive(generation, row - 1, col - 1)) living++;
   if (isCellAlive(generation, row - 1, col)) living++;
   if (isCellAlive(generation, row - 1, col + 1)) living++;
   if (isCellAlive(generation, row, col - 1)) living++;
   if (isCellAlive(generation, row, col + 1)) living++;
   if (isCellAlive(generation, row + 1, col - 1)) living++;
   if (isCellAlive(generation, row + 1, col)) living++;
   if (isCellAlive(generation, row + 1, col + 1)) living++;
   return living;
}
