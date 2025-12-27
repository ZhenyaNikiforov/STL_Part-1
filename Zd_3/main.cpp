/*-Аналог std::vector
(задание №3 в самостоятельной работе)-*/

#include <iostream>
using namespace std;

template <typename S>
class customVector
{
public:
  customVector() // конструктор;
  {
    this->customArray = new S[8];
    this->maximumSize = 8;
    this->factumSize = 0;
  };
  ~customVector() // деструктор;
  {
    delete[] this->customArray; // this->customArray и this->otherArray показывают на одну область памяти;
  };
  int size() // возвращает кол-во элементов в контейнере;
  {
    return this->factumSize;
  };
  int capacity() // возвращает, сколько элементов может вместить контейнер до нового выделения памяти;
  {
    return this->maximumSize - this->factumSize;
  };
  S &operator[](int index) // для записи;
  {
    return this->customArray[index];
  };
  void push_back(S value) // добавляет элемент в конец вектора;
  {
    if (this->factumSize < this->maximumSize)
    {
      this->customArray[this->factumSize] = value;
      this->factumSize++;
      return;
    };
    this->maximumSize *= 2;                      // увеличиваем макс. разм. в 2 раза;
    this->otherArray = new S[this->maximumSize]; // создаём другой массив увелич. разм.;
    for (int i = 0; i < this->factumSize; ++i)   // обходим старый массив по заполн. размеру;
    {
      this->otherArray[i] = this->customArray[i]; // копируем из старого массива в новый;
    };
    delete[] this->customArray;           // очищаем память под указателем старого массива;
    this->customArray = this->otherArray; // переносим указатель старого массива на новый массив;
    this->customArray[this->factumSize] = value;
    this->factumSize++;
    return;
  };

protected:
  S *customArray;
  S *otherArray;
  int maximumSize;
  int factumSize;
};

int main()
{
  /*-Тестовый фреймворк-*/
  customVector<int> myVector;
  cout << "elementyi tipa \"int\"" << endl;
  while (true)
  {
    cout << "Elementov v kontejnere: " << myVector.size() << endl;
    cout << "Do novogo vyideleniya pamyati ostalos: " << myVector.capacity() << endl;
    int element = 0;
    cout << "vvodim element: ";
    cin >> element;
    char symbol = ' ';
    cout << "prervat`? Y / N: ";
    cin >> symbol;
    if (symbol == 'Y')
    {
      break;
    };
    myVector.push_back(element);
    for (int i = 0; i < myVector.size(); ++i)
    {
      cout << myVector[i] << endl;
    };
  };
  /*----------------------------*/
  cout << endl;
  /*----------------------------*/
  customVector<double> doubleVector;
  cout << "elementyi tipa \"double\"" << endl;
  while (true)
  {
    cout << "Elementov v kontejnere: " << doubleVector.size() << endl;
    cout << "Do novogo vyideleniya pamyati ostalos: " << doubleVector.capacity() << endl;
    double element = 0;
    cout << "vvodim element: ";
    cin >> element;
    char symbol = ' ';
    cout << "prervat`? Y / N: ";
    cin >> symbol;
    if (symbol == 'Y')
    {
      break;
    };
    doubleVector.push_back(element);
    for (int i = 0; i < doubleVector.size(); ++i)
    {
      cout << doubleVector[i] << endl;
    };
  };
  return 0;
}