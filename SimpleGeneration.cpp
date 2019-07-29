#include "SimpleGeneration.h"

using namespace GoL;

SimpleGeneration::SimpleGeneration(const LinearCells &cells)
   : m_cells(cells)
{
}

std::shared_ptr<Generation> SimpleGeneration::evolved() const
{
   LinearCells cells = m_cells.cloneEmpty();

   for (int r = 0; r < cells.rows(); r++)
   {
      for (int c = 0; c < cells.columns(); c++)
      {
         int neighbors = livingNeighbors(r, c);
         if (isCellAlive(r, c))
         {
            if (neighbors < 2)
               cells.setCell(r, c, false);
            else if (neighbors > 3)
               cells.setCell(r, c, false);
            else // neighbors == 2 || neighbors == 3
               cells.setCell(r, c, true);
         }
         else
         {
            if (neighbors == 3)
               cells.setCell(r, c, true);
            else
               cells.setCell(r, c, false);
         }
      }
   }

   return factory(cells);
}

int SimpleGeneration::rows() const
{
   return m_cells.rows();
}

int SimpleGeneration::columns() const
{
   return m_cells.columns();
}

bool SimpleGeneration::isCellAlive(int row, int col) const
{
   if (!m_cells.isValidCell(row, col))
      return false;
   return m_cells.cell(row, col);
}

int SimpleGeneration::livingNeighbors(int row, int col) const
{
   int living = 0;
   if (isCellAlive(row - 1, col - 1)) living++;
   if (isCellAlive(row - 1, col)) living++;
   if (isCellAlive(row - 1, col + 1)) living++;
   if (isCellAlive(row, col - 1)) living++;
   if (isCellAlive(row, col + 1)) living++;
   if (isCellAlive(row + 1, col - 1)) living++;
   if (isCellAlive(row + 1, col)) living++;
   if (isCellAlive(row + 1, col + 1)) living++;
   return living;
}

std::shared_ptr<Generation> SimpleGeneration::factory(const LinearCells &cells) const
{
   return std::make_shared<SimpleGeneration>(cells);
}
