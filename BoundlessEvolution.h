#pragma once

#include "Evolution.h"

namespace GoL
{
   class BoundlessEvolution : public Evolution
   {
   public:
      virtual Generation evolve(const Generation &generation) override;

   private:
      bool isCellAlive(Generation generation, int row, int col) const;
      int livingNeighbors(Generation generation, int row, int col) const;
   };
}
