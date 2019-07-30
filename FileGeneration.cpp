#include "FileGeneration.h"

#include <fstream>
#include <regex>

using namespace GoL;

FileGeneration::FileGeneration(const std::string &file)
{
   std::ifstream example(file);
   if (!example.is_open())
      throw std::invalid_argument("Not able to open file!");

   std::string content{
      std::istreambuf_iterator<char>(example),
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

   m_rows = rows;
   m_columns = cols;
   m_cells = fields;
}