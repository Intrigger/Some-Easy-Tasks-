/*

Организация подпрограмм.
Функции пользователя.

Вычислить 

y = f(c) - f(b) - f(a),
f(x) = (tg(x) - sin(x)) / x^3

*/


#include <iostream>
#include <limits>
#include <cmath>

double f(double x){
    return (tan(x) - sin(x)) / pow(x, 3);
}


int main(){

    using namespace std;

    //Просьба к вводу констант a, b, c

    double a = 0.0, b = 0.0, c = 0.0;

    //Проверка корректности ввода

    cout << "Введите параметр a: ";

    while (!(cin >> a)){
        cout << "Проверьте корректность ввода и повторите ввод.\n";
        cout << "Введите параметр a: ";
        cin.clear(); // на случай, если предыдущий ввод завершился с ошибкой
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Введите параметр b: ";

    while (!(cin >> b)){
        cout << "Проверьте корректность ввода и повторите ввод.\n";
        cout << "Введите параметр b: ";
        cin.clear(); // на случай, если предыдущий ввод завершился с ошибкой
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Введите параметр c: ";

    while (!(cin >> c)){
        cout << "Проверьте корректность ввода и повторите ввод.\n";
        cout << "Введите параметр c: ";
        cin.clear(); // на случай, если предыдущий ввод завершился с ошибкой
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    auto y = f(c) - f(b) - f(a);

    cout << "Ваш ответ: " << y << endl;


    return 0;
}