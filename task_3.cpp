/*

Тема 3: Обработка массивов. Одномерные массивы
8. Переписать в массив Y положительные элементы,
    а в массив Z отрицательные элементы массива Х.

*/


#include <iostream>
#include <random>


int main(){

    using namespace std;

    #define ARRAY_X_SIZE 100

    int x[ARRAY_X_SIZE]{};

    //заполним массив x случайными числами

    for (int i = 0; i < ARRAY_X_SIZE; i++){
        x[i] = rand() % 200 - 100;
    }

    cout << "Массив x: ";

    for (int i = 0; i < ARRAY_X_SIZE; i++){
        cout << x[i] << " ";
    }

    cout << "\n\n";

    size_t positive_counter = 0;
    size_t negative_counter = 0;

    for (int i = 0; i < ARRAY_X_SIZE; i++){
        if (x[i] < 0) negative_counter++;
        else positive_counter++;
    }

    int *y = new int[positive_counter];
    int *z = new int[negative_counter];

    int curz = 0;
    int cury = 0;

    for (int i = 0; i < ARRAY_X_SIZE; i++){
        if (x[i] < 0){
            z[curz] = x[i];
            curz++;
        }
        else{
            y[cury] = x[i];
            cury++;
        }
    }

    cout << "Y массив: ";
    for (int i = 0; i < positive_counter; i++){
        cout << y[i] << " ";
    }
    cout << "\n\n";


    cout << "Z массив: ";
    for (int i = 0; i < negative_counter; i++){
        cout << z[i] << " ";
    }

    cout << endl;
    

    return 0;
}