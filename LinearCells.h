#pragma once

#include <vector>

namespace GoL
{
   class LinearCells
   {
   public:
      LinearCells(int rows, int columns, const std::vector<bool> &cells);

      int rows() const;
      int columns() const;
      bool cell(int row, int col) const;
      void setCell(int row, int col, bool active);

      bool isValidCell(int row, int col) const;

      LinearCells cloneEmpty() const;

   private:
      int m_rows;
      int m_columns;
      std::vector<bool> m_cells;

      int cellIndex(int row, int col) const;
   };
}


