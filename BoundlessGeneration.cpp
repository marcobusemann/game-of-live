#include "BoundlessGeneration.h"
#include <cassert>

using namespace GoL;

int euclidean_reminder(int a, int b)
{
   assert(b != 0);
   int r = a % b;
   return r >= 0 ? r : r + std::abs(b);
}

BoundlessGeneration::BoundlessGeneration(const LinearCells &cells)
   : SimpleGeneration(cells)
{
}

bool BoundlessGeneration::isCellAlive(int row, int col) const
{
   row = euclidean_reminder(row, rows());
   col = euclidean_reminder(col, columns());
   return __super::isCellAlive(row, col);
}

std::shared_ptr<Generation> BoundlessGeneration::factory(const LinearCells &cells) const
{
   return std::make_shared<BoundlessGeneration>(cells);
}
