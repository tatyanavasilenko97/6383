/* Быков И.В. Лабораторная работа № 3 3 вариант
Рассматриваются следующие типы данных:
type имя = (Анна, ..., Яков);
дети = array [имя, имя] of Boolean;
потомки = file of имя.
Задан массив Д типа дети (Д [x, y] = true, если человек по имени y
является ребенком человека по имени x). Для введенного пользователем
имени И записать в файл П типа потомки имена всех потомков человека с
именем И в следующем порядке: сначала - имена всех его детей, затем -
всех его внуков, затем - всех правнуков и т. д.
В задании требуется использовать очередь.
*/
#include "queue.h"
#include <clocale>
#include "names.h"
#define MAX 1000
using namespace std;

int readAction();
/*
Функция, которая выводит потомков заданного лица
предусловие:    	my_num_name  – идентификатор заданного лица
                    _names – класс имен
                    _queue – очередь
возвращает true, если потомки есть, false – в обратном случае.
*/
bool findChld(int my_num_name, myNames<string> &_names, Queue<string> &_queue, std::ostream& out);

int main()
{
    ofstream out("output.txt");
    setlocale(LC_CTYPE, "rus");
    myNames<string> _names(MAX);
    Queue<string> namesQueue(MAX);
    string my_name;
    int my_num_name;
    bool num;
    int flag;
    _names.addNames();
    if (!_names.realiseArray())
    {
        cout << "Ошибка при составлении матрицы потомков!";
        return -1;
    }
    while (true)
        {
		switch (readAction())
		{
        case 1:
            cout << "Введите требуемое имя из списка: ";
            cin >> my_name;
            my_num_name = _names.findNumName(my_name);
            if (my_num_name == -1)
            {
                cout << "Имя не найдено в базе! Ошибка." << endl;
                break;
            }
            num = findChld(my_num_name, _names, namesQueue, cout);
            if (!num)
                cout << "Потомки отсутствуют!" << endl;
            break;
        case 2:
            cout << "Список имен: ";
            for (int i = 0; i < _names.getCnt(); i++)
                cout << _names.getName(i) << " ";
            break;
        case 3:
            cout << "Матрица потомков: " << endl;
            _names.printArray();
            cout << endl;
            break;
        case 4:
            cout << "Список потомков: " << endl;
            _names.printArray2();
            break;
        case 5:
            return 0;
		}
        cout << "Продолжить? 1 - да; 0 - нет. ";
        cin >> flag;
        cout << endl;
        if (flag == 0)
            return 0;
    }
}

bool findChld(int my_num_name, myNames<string> &_names, Queue<string> &_queue, std::ostream& out)
{
    bool cnt = false;
    _queue.enqueue(_names.getName(my_num_name));
    bool used[_names.getCnt()];
    for (int i = 0; i < _names.getCnt(); i++)
        used[i] = 0;
    int cur = my_num_name;
    while(!_queue.isEmpty())
    {
        cur = _names.getNumName(_queue.dequeue());
        out << _names.getName(cur) << " ";
        for (int i = 0; i < _names.getCnt(); i++)
            if ((_names.getArray(cur, i) == true) && !used[i])
            {
                cnt = true;
                _queue.enqueue(_names.getName(i));
                used[i] = 1;
            }
    }
    return cnt;
}

int readAction()
{
	while (true)
	{
		cout <<"Выберите действие:\n1 - ввод имени и вывод потомков;\n2 - вывод списка имен;\n3 - вывод матрицы потомков;\n4 - вывод списка потомков;\n5 - выход.\n";
		int action;
		cin >> action;
		if (action > 5 || action < 1)
		{
			printf("Ошибка!\n");
			continue;
		}
		return action;
	}
}
