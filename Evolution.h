#pragma once

#include "Generation.h"

namespace GoL
{
   class Evolution
   {
   public:
      virtual ~Evolution() = default;

      virtual Generation evolve(const Generation &generation) = 0;
   };
}
