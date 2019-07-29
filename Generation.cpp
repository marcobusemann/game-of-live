#include "Generation.h"

using namespace GoL;

bool Generation::equals(const std::shared_ptr<Generation> &rhs)
{
   if (rows() != rhs->rows() || columns() != rhs->columns())
      return false;

   for (int r = 0; r < rows(); r++)
   {
      for (int c = 0; c < columns(); c++)
      {
         if (isCellAlive(r, c) != rhs->isCellAlive(r, c))
            return false;
      }
   }

   return true;
}
