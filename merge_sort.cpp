// 归并法，一个分解，一个合并,外加一个随机测试
#include <iostream>
#include <vector>
#include <limits>
#include <ctime>
#include <cstdlib>
#define random(a, b) (rand() % (b - a + 1) + a)
using namespace std;

void merge(vector<int> &arr, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], R[n2];
    for (int i = p; i <= q; i++)
    {
        L[i - p] = arr[i];
    }
    for (int i = q + 1; i <= r; i++)
    {
        R[i - q - 1] = arr[i];
    }

    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    int i = 0, j = 0;
    for (int k = p; k <= r; k++)
    {
        if (L[i] < R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
    }
}

void merge_sort(vector<int> &arr, int p, int r)
{
    if (p < r)
    {
        int q = (r + p) / 2;
        merge_sort(arr, p, q);
        merge_sort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

int main()
{
    // 随机生成一个范围在1到100的随机数组，长度为20，然后对数组进行排序
    srand((unsigned)time(NULL));
    vector<int> a;
    for (int i = 0; i < 20; i++)
    {
        a.push_back(random(1, 100));
    }
    merge_sort(a, 0, 19);
    for (auto &k : a)
    {
        cout << k << endl;
    }
}
