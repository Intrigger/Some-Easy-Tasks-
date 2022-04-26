// Тема 8: Файлы.

// 8. Имеется текстовый файл, в каждой строке которого
// первые два символа являются буквами.
// Получить слово, образованное вторыми буквами каждой строки.


#include <iostream>
#include <fstream>


int main(){

    using namespace std;

    ifstream fin;
    fin.open("my_text_file.txt");

    string str = "";

    while (getline(fin, str)){
        cout << str[1];
    }


    return 0;
}