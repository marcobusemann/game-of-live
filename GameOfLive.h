#pragma once

#include "Generation.h"

#include <functional>
#include <optional>

namespace GoL
{
   class GameOfLive
   {
   public:
      GameOfLive(std::function<void(std::shared_ptr<Generation>)> onEvolved);
      GameOfLive(unsigned int maxGenerations, std::function<void(std::shared_ptr<Generation>)> onEvolved);

      void play(const std::shared_ptr<Generation> &firstGeneration);

   private:
      std::function<void(std::shared_ptr<Generation>)> m_onEvolved;
      int m_maxGenerations;
   };
}

