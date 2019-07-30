#include "GameOfLive.h"

using namespace GoL;

GameOfLive::GameOfLive(
   const std::shared_ptr<Evolution> &evolutionStrategy,
   const std::function<void(const Generation &)> &onEvolved)
   : GameOfLive(-1, evolutionStrategy, onEvolved)
{
}

GameOfLive::GameOfLive(
   unsigned int maxGenerations,
   const std::shared_ptr<Evolution> &evolutionStrategy,
   const std::function<void(const Generation &)> &onEvolved)
   : m_onEvolved(onEvolved)
   , m_maxGenerations(maxGenerations)
   , m_evolutionStrategy(evolutionStrategy)
{
}

void GameOfLive::play(const Generation &firstGeneration)
{
   auto currentGeneration = firstGeneration;
   m_onEvolved(currentGeneration);

   int i = 0;
   while (m_maxGenerations == -1 || i++ < m_maxGenerations)
   {
      auto nextGeneration = m_evolutionStrategy->evolve(currentGeneration);

      m_onEvolved(nextGeneration);

      if (currentGeneration == nextGeneration)
         break;

      currentGeneration = nextGeneration;
   }
}
