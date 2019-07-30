#include "Generation.h"

using namespace GoL;

Generation::Generation(int rows, int columns, const std::vector<bool> &cells)
   : m_rows(rows)
   , m_columns(columns)
   , m_cells(cells)
{
}

Generation::Generation()
   : Generation(0, 0, std::vector<bool>())
{
}

bool Generation::operator==(const Generation &rhs) const
{
   return std::equal(m_cells.begin(), m_cells.end(), rhs.m_cells.begin(), rhs.m_cells.end());
}

int Generation::rows() const
{
   return m_rows;
}

int Generation::columns() const
{
   return m_columns;
}

bool Generation::cell(int row, int col) const
{
   return m_cells[cellIndex(row, col)];
}

void Generation::setCell(int row, int col, bool active)
{
   m_cells[cellIndex(row, col)] = active;
}

bool Generation::isValidCell(int row, int col) const
{
   int index = cellIndex(row, col);
   if (index < 0 || index >= (m_rows * m_columns))
      return false;
   return true;
}

Generation Generation::cloneEmpty() const
{
   return Generation(m_rows, m_columns, std::vector<bool>(m_rows * m_columns));
}

int Generation::cellIndex(int row, int col) const
{
   return (row * m_columns) + col;
}
