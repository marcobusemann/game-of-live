#include "LinearCells.h"

using namespace GoL;

LinearCells::LinearCells(int rows, int columns, const std::vector<bool> &cells)
   : m_rows(rows)
   , m_columns(columns)
   , m_cells(cells)
{
}

int LinearCells::rows() const
{
   return m_rows;
}

int LinearCells::columns() const
{
   return m_columns;
}

bool LinearCells::cell(int row, int col) const
{
   return m_cells[cellIndex(row, col)];
}

void LinearCells::setCell(int row, int col, bool active)
{
   m_cells[cellIndex(row, col)] = active;
}

bool LinearCells::isValidCell(int row, int col) const
{
   int index = cellIndex(row, col);
   if (index < 0 || index >= (m_rows * m_columns))
      return false;
   return true;
}

LinearCells LinearCells::cloneEmpty() const
{
   return LinearCells(m_rows, m_columns, std::vector<bool>(m_rows * m_columns));
}

int LinearCells::cellIndex(int row, int col) const
{
   return (row * m_columns) + col;
}
