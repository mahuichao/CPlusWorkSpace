#include <iostream>
using namespace std;

template <class T>
int getLength(T &data)
{
    return sizeof(data) / sizeof(data[0]);
}

template <class T>
void sortArr(T &data)
{
    int dsize = getLength(data);
    for (int j = 1; j < dsize; j++)
    {
        int key = data[j];
        int i = j - 1;
        while (i >= 0 && key < data[i])
        { // 从左到右依此增加 大的放右边
            data[i + 1] = data[i];
            i--;
        } // 此时i为需要插入的地址-1
        data[i + 1] = key;
    }
}

int main()
{
    int a[9] = {2, 1, 8, 5, 7, 6, 9, 4, 3};
    sortArr(a);
    for (int i : a)
    {
        cout << i << " ";
    }
    cout << endl;
}