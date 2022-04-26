// Тема 4: Многомерные массивы
// 8. Дан массив из n×· m элементов. Найти наибольший элемент массива в каждом столбце. 


#include <iostream>
#include <random>


int main(){

    using namespace std;

    size_t n = 10; //строк
    size_t m = 20; //стобцов

    int **arr = new int*[n];

    for (int y = 0; y < n; y++){
        arr[y] = new int[m];
    }


    //заполним таблицу случайными значениями

    for (int y = 0; y < n; y++){
        for (int x = 0; x < m; x++){
            arr[y][x] = rand() % 200 - 100;
            cout << arr[y][x] << " ";
        }
        cout  << endl;
    }


    for (int x = 0; x < m; x++){
        
        int maximum = arr[0][x];
        
        for (int y = 1; y < n; y++){
            maximum = max(maximum, arr[y][x]);
        }

        cout << "Максимум в столбце №" << x + 1 << ": " << maximum << endl;
    }



    return 0;
}