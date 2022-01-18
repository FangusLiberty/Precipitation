#include <iostream>
#include <iomanip>

using namespace std;

#include "precipitation.h"
#include "file_reader.h"
#include "constants.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Ћабораторна€ работа є8. GIT\n";
    cout << "¬ариант є3. ќсадки\n";
    cout << "јвтор: Ёдуард »гнатович\n\n";
    precipitation* precipitations[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", precipitations, size);
        cout << "***** ќсадки *****\n\n";
        for (int i = 0; i < size; i++)
        {
            /********** вывод даты **********/
            cout << "ƒень............: ";
            // вывод дн€
            cout << setw(2) << setfill('0') << precipitations[i]->day.day << "\n";
            cout << "ћес€ц...........: ";
            // вывод мес€ца
            cout << setw(2) << setfill('0') << precipitations[i]->day.month << "\n";
            /********** вывод количества **********/
            cout << " оличество......: ";
            // вывод количества осадков в мм
            cout << precipitations[i]->value << '\n';
            /********** вывод типа **********/
            cout << "’арактеристика..: ";
            // вывод типа осадков
            cout << precipitations[i]->type << '\n';
            cout << "\n";
        }
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }
    return 0;
}