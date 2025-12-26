/*-Задание №1 по теме STL часть-1
(частота символов)-*/

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

int main()
{
  std::string line = "";
  std::cout << "[IN]: ";
  getline(std::cin, line);

  std::map<char, int> sumbolMap;        // пустая карта "символ-значение";
  for (int i = 0; i < line.size(); ++i) // обходим введённую строку;
  {
    if (sumbolMap.count(line[i])) // если символ строки по индексу "i" есть в карте, то...;
    {
      sumbolMap[line[i]]++; //...увеличиваем его сопутствующее число на 1;
    }
    else //...если символа такого ещё нет, то...
    {
      sumbolMap[line[i]] = 1; //...заносим символ в карту и даём ему число 1.
    }
  };

  std::vector<std::pair<char, int>> mezoSet(sumbolMap.begin(), sumbolMap.end()); // переносим карту в вектор;

  std::sort(mezoSet.begin(), mezoSet.end(), [](const auto &a, const auto &b)
            { return a.second > b.second; }); // сортируем вектор по убыванию второго члена каждой пары;

  std::cout << "[OUT]:" << std::endl;
  for (const auto &binom : mezoSet) // пробегаемся по отсортированному вектору;
  {
    std::cout << binom.first << ": " << binom.second << std::endl; // отображаем каждую пару;
  };

  return 0;
}