#pragma once

#include <memory>

namespace GoL
{
   class Generation
   {
   public:
      virtual ~Generation() = default;

      virtual int rows() const = 0;
      virtual int columns() const = 0;
      virtual bool isCellAlive(int row, int col) const = 0;
      virtual bool equals(const std::shared_ptr<Generation> &rhs);

      virtual std::shared_ptr<Generation> evolved() const = 0;
   };
}