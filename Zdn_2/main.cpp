/*-Подпрограмма, посвящённая приёму чисел,
исключению повторяющихся и сортированию
этих чисел по убыванию
(задание №2 в самостоятельной работе)-*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  vector<int> elements;
  int summaElements = 0;
  cout << "[IN]:\nvvodim kol-vo elementov: ";
  cin >> summaElements;

  /*-одно за другим вводим числа в массив-*/
  for (int i = 0; i < summaElements; ++i)
  {
    int element = 0;
    cin >> element;
    elements.push_back(element);
  };

  sort(elements.begin(), elements.end());                     // сортируем массив (пока по возрастанию)
  auto startPoint = unique(elements.begin(), elements.end()); // неповторяемые элементы в начало;
  // повторяемые начнутся со startPoint
  elements.erase(startPoint, elements.end());             // удаляем повторяемые
  sort(elements.begin(), elements.end(), greater<int>()); // сортируем по убыванию

  /*-показываем получившийся массив-*/
  cout << "[OUT]:" << endl;
  for (int i = 0; i < elements.size(); ++i)
  {
    cout << elements[i] << endl;
  };

  return 0;
}