#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <chrono>
#include <thread>

#include "BoundlessGeneration.h"
#include "SimpleGeneration.h"
#include "GameOfLive.h"

void PrintGeneration(const std::shared_ptr<GoL::Generation> &generation)
{
   for (int r = 0; r < generation->rows(); r++)
   {
      for (int c = 0; c < generation->columns(); c++)
         std::cout << (generation->isCellAlive(r, c) ? '*' : '.');

      std::cout << std::endl;
   }
}

void PrintEmptyLine()
{
   std::cout << std::endl;
}

GoL::LinearCells CellsFromStream(std::istream &stream)
{
   std::string content{
      std::istreambuf_iterator<char>(stream),
      std::istreambuf_iterator<char>() };

   const auto regex = std::regex("(\\d+)\\s+(\\d+)[\\r\\n|\\r|\\n]([\\.\\*\\r\\n]*)");
   std::smatch results;
   if (!std::regex_match(content, results, regex))
      throw std::invalid_argument("File has invalid format");

   int rows = stoi(results[1]);
   int cols = stoi(results[2]);
   std::string field = results[3];

   std::vector<bool> fields(rows * cols);

   int i = 0;
   std::for_each(field.begin(), field.end(), [&fields, &i](auto cell)
   {
      if (cell == '*')
         fields[i++] = true;
      else if (cell == '.')
         fields[i++] = false;
   });

   return GoL::LinearCells(rows, cols, fields);
}

int main()
{
   using namespace GoL;

   std::ifstream example("examples/glider.gol");
   if (!example.is_open())
   {
      std::cout << "could not open file";
      return -1;
   }

   std::shared_ptr<Generation> currentGeneration = std::make_shared<BoundlessGeneration>(CellsFromStream(example));

   auto game = GameOfLive([](auto generation)
   {
      std::this_thread::sleep_for(std::chrono::milliseconds(200));
      system("CLS");
      PrintGeneration(generation);
   });
   game.play(currentGeneration);

   int i;
   std::cin >> i;
}

