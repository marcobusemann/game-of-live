#include <iostream>
#include <thread>

#include "BoundlessEvolution.h"
#include "BoundedEvolution.h"
#include "RandomGeneration.h"
#include "FileGeneration.h"
#include "GameOfLive.h"

void PrintGeneration(const GoL::Generation &generation);
void LeaveConsoleOpenUntilInput();

int main()
{
   using namespace GoL;

   //const auto firstGeneration = FileGeneration("examples/glider.gol");
   //const auto firstGeneration = FileGeneration("examples/task.gol");
   const auto firstGeneration = RandomGeneration(20, 40);

   auto evolution = std::make_shared<BoundlessEvolution>();
   //auto evolution = std::make_shared<BoundedEvolution>();

   auto game = GameOfLive(evolution, [](auto generation)
   {
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
      system("CLS");
      PrintGeneration(generation);
   });
   game.play(firstGeneration);

   LeaveConsoleOpenUntilInput();
}

void PrintGeneration(const GoL::Generation &generation)
{
   for (int r = 0; r < generation.rows(); r++)
   {
      for (int c = 0; c < generation.columns(); c++)
         std::cout << (generation.cell(r, c) ? '*' : '.');

      std::cout << std::endl;
   }
}

void LeaveConsoleOpenUntilInput()
{
   int i;
   std::cin >> i;
}
