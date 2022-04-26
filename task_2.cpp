/*
Задание 2.

Дано натуральное число N. Выведите слово YES, если число N является
точной степенью двойки, или слово NO в противном случае.
Операцией возведения в степень пользоваться нельзя! 

(необходимо использовать рекурсию)

*/

#include <iostream>
#include <limits>

bool is_power_of_2(size_t value){
    if (value == 0) return false;
    if (value == 1) return true;
    if (value % 2 == 0){
        if (value == 2) return true;
        return is_power_of_2(value / 2);
    }
    else return false;
}

int main(){

    using namespace std;

    size_t value = 0;

    cout << "Введите значение value: ";

    while (!(cin >> value)){
        cout << "Проверьте корректность ввода и повторите ввод.\n";
        cout << "Введите значение value: ";
        cin.clear(); // на случай, если предыдущий ввод завершился с ошибкой
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Число " << value << (is_power_of_2(value) ? "" : " не") << 
    " является степенью двойки\n";



    return 0;
}