// Тема 7: Структуры.

// 8. Составить программу решения следующей задачи. Описать структуру,
// содержащую поля: № Авиарейса, Время вылета, Время прилета, Направление,
// Наличие билетов, Расстояние. Вывести данные об авиарейсе с максимальной скоростью.
// Вывести информацию об авиарейсах определенного направления (направление вводится с клавиатуры), на которые имеются свободные места.

#include <iostream>
#include <string>
#include <random>



struct aeroflight{
    size_t id;
    size_t time_start;
    size_t time_stop;
    std::string direction;
    bool tickets_available;
    size_t distance;
};


int main(){

    using namespace std;

    srand(time(0));

    #define flights_number 10

    aeroflight flights[flights_number];

    for (int i = 0; i < flights_number; i++){
        flights[i].id = i + 1;
        flights[i].time_start = (size_t)rand() % INT64_MAX;
        flights[i].time_stop = flights[i].time_start + rand() % INT64_MAX;
        flights[i].tickets_available = ((rand() % 3) != 0);
        flights[i].distance = (rand() % 3000) + 500;


        cin >> flights[i].direction;

        cout << "\n\n";
        cout << "Flight #" << flights[i].id << endl;
        cout << "Time start: " << flights[i].time_start << endl;
        cout << "Time stop: " << flights[i].time_stop << endl;
        cout << "Direction: " << flights[i].direction << endl;
        cout << "Tickets available: " << flights[i].tickets_available << endl;
        cout << "Distance: " << flights[i].distance << endl;

    }

    //Вывести данные об авиарейсе с максимальной скоростью.

    double max_speed = 0.0;
    int max_speed_index = -1;

    for (int i = 0; i < flights_number; i++){
        double speed = double(flights[i].distance) / (double(flights[i].time_stop) - double(flights[i].time_start));
        if ((speed > max_speed) and (flights[i].tickets_available == true)){
            max_speed = speed;
            max_speed_index = i;
        }
    }

    if (max_speed_index != -1){
        cout << "Полет с максимальной скоростью: ";
        cout << "\n\n";
        cout << "Flight #" << flights[max_speed_index].id << endl;
        cout << "Time start: " << flights[max_speed_index].time_start << endl;
        cout << "Time stop: " << flights[max_speed_index].time_stop << endl;
        cout << "Direction: " << flights[max_speed_index].direction << endl;
        cout << "Tickets available: " << flights[max_speed_index].tickets_available << endl;
        cout << "Distance: " << flights[max_speed_index].distance << endl;
    }
    else{
        cout << "Извините, билетов на самый быстрый самолет нет.";
    }




    return 0;
}