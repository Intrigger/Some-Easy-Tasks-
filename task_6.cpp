// Тема 6: Алгоритмы обработки строк.

// 8 В заданной строке удалить последний символ

#include <iostream>
#include <string>

int main(){

    using namespace std;

    string source = "";

    cout << "Введите строку: ";
    cin >> source;

    string new_str = source;
    new_str[source.length() - 1] = '\0';

    cout << "New string: " << new_str << endl;

    //но лучше сделать не так, т.к. неизвестно, как оно работает внутри
    //лучше сделать так

    new_str = "";

    for (int i = 0; i < source.length() - 1; i++){
        new_str += source[i];
    }

    cout << "New string: " << new_str << endl;

}