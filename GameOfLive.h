#pragma once

#include "Evolution.h"
#include "Generation.h"

#include <functional>
#include <memory>

namespace GoL
{
   class GameOfLive
   {
   public:
      GameOfLive(
         const std::shared_ptr<Evolution> &evolutionStrategy,
         const std::function<void(const Generation &)> &onEvolved);
      GameOfLive(
         unsigned int maxGenerations, 
         const std::shared_ptr<Evolution> &evolutionStrategy,
         const std::function<void(const Generation &)> &onEvolved);

      void play(const Generation &firstGeneration);

   private:
      std::function<void(const Generation &)> m_onEvolved;
      std::shared_ptr<Evolution> m_evolutionStrategy;
      int m_maxGenerations;
   };
}

