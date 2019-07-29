#pragma once

#include "SimpleGeneration.h"
#include "LinearCells.h"

#include <vector>

namespace GoL
{
   class BoundlessGeneration : public SimpleGeneration
   {
   public:
      BoundlessGeneration(const LinearCells &cells);

      bool isCellAlive(int row, int col) const override;

   protected:
      virtual std::shared_ptr<Generation> factory(const LinearCells &cells) const override;
   };
}
