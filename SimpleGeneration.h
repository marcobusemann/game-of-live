#pragma once

#include "LinearCells.h"
#include "Generation.h"

#include <vector>

namespace GoL
{
   class SimpleGeneration : public Generation
   {
   public:
      SimpleGeneration(const LinearCells &cells);

      std::shared_ptr<Generation> evolved() const override;

      int rows() const override;
      int columns() const override;
      bool isCellAlive(int row, int col) const override;

   protected:
      virtual std::shared_ptr<Generation> factory(const LinearCells &cells) const;

   private:
      LinearCells m_cells;

      int livingNeighbors(int row, int col) const;
   };
}
