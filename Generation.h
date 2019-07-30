#pragma once

#include <vector>

namespace GoL
{
   class Generation
   {
   public:
      Generation();
      Generation(int rows, int columns, const std::vector<bool> &cells);

      bool operator==(const Generation &rhs) const;

      int rows() const;
      int columns() const;
      bool cell(int row, int col) const;
      void setCell(int row, int col, bool active);

      bool isValidCell(int row, int col) const;

      Generation cloneEmpty() const;

   protected:
      int m_rows;
      int m_columns;
      std::vector<bool> m_cells;

      int cellIndex(int row, int col) const;
   };
}


