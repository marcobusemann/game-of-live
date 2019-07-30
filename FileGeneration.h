#pragma once

#include "Generation.h"

namespace GoL
{
   class FileGeneration : public Generation
   {
   public:
      FileGeneration(const std::string &file);
   };
}

