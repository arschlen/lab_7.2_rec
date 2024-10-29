#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void CreateRow(int** a, const int rowNo, const int N, const int Low, const int High, int colNo) {
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < N - 1)
        CreateRow(a, rowNo, N, Low, High, colNo + 1);
}

void CreateRows(int** a, const int k, const int N, const int Low, const int High, int rowNo) {
    CreateRow(a, rowNo, N, Low, High, 0);
    if (rowNo < k - 1)
        CreateRows(a, k, N, Low, High, rowNo + 1);
}

void PrintRow(int** a, const int rowNo, const int N, int colNo) {
    cout << setw(4) << a[rowNo][colNo];
    if (colNo < N - 1)
        PrintRow(a, rowNo, N, colNo + 1);
    else
        cout << endl;
}

void PrintRows(int** a, const int k, const int N, int rowNo) {
    PrintRow(a, rowNo, N, 0);
    if (rowNo < k - 1)
        PrintRows(a, k, N, rowNo + 1);
    else
        cout << endl;
}

int FindMaxIndex(int* row, const int N, int colNo = 0, int maxIndex = 0) {
    if (colNo >= N) return maxIndex;
    if (row[colNo] > row[maxIndex]) maxIndex = colNo;
    return FindMaxIndex(row, N, colNo + 1, maxIndex);
}

int FindMinIndex(int* row, const int N, int colNo = 0, int minIndex = 0) {
    if (colNo >= N) return minIndex;
    if (row[colNo] < row[minIndex]) minIndex = colNo;
    return FindMinIndex(row, N, colNo + 1, minIndex);
}

void SwapMaxMin(int** a, const int k, const int N, int rowNo) {
    if (rowNo >= k - 1) return;

    if (rowNo % 2 == 1 && rowNo + 1 < k) {
        int maxIndex = FindMaxIndex(a[rowNo + 1], N);
        int minIndex = FindMinIndex(a[rowNo], N);
        int temp = a[rowNo][minIndex];
        a[rowNo][minIndex] = a[rowNo + 1][maxIndex];
        a[rowNo + 1][maxIndex] = temp;
    }

    SwapMaxMin(a, k, N, rowNo + 1);
}

int main() {
    srand((unsigned)time(NULL));
    int k, n;
    cout << "k: "; cin >> k;
    cout << "n: "; cin >> n;

    int Low = 1, High = 100;
    int** a = new int* [k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    CreateRows(a, k, n, Low, High, 0);
    cout << "Original Matrix:" << endl;
    PrintRows(a, k, n, 0);

    SwapMaxMin(a, k, n, 0);
    cout << "Modified Matrix:" << endl;
    PrintRows(a, k, n, 0);

    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}
