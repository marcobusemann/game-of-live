#include "GameOfLive.h"

using namespace GoL;

GameOfLive::GameOfLive(std::function<void(std::shared_ptr<Generation>)> onEvolved)
   : GameOfLive(-1, onEvolved)
{
}

GameOfLive::GameOfLive(unsigned int maxGenerations, std::function<void(std::shared_ptr<Generation>)> onEvolved)
   : m_onEvolved(onEvolved)
   , m_maxGenerations(maxGenerations)
{
}

void GameOfLive::play(const std::shared_ptr<Generation> &firstGeneration)
{
   auto currentGeneration = firstGeneration;
   m_onEvolved(currentGeneration);

   int i = 0;
   while (m_maxGenerations == -1 || i++ < m_maxGenerations)
   {
      auto nextGeneration = currentGeneration->evolved();

      m_onEvolved(nextGeneration);

      if (currentGeneration->equals(nextGeneration))
         break;

      currentGeneration = nextGeneration;
   }
}
