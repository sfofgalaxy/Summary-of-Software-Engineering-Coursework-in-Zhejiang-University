#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void shuffle(vector<T> &v);

int main()
{
  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  v.push_back(5);
  v.push_back(6);

  shuffle(v);

  for (int i = 0; i < v.size(); i++)
    cout << v[i] << " ";

  return 0;
}

template<typename T>
void shuffle(vector<T> &v)
{
  srand(time(0));
  for (int i = 0; i < v.size(); i++)
  {
    int index = rand() % v.size();
    T temp = v[index];
    v[index] = v[i];
    v[i] = temp;
  }
}
