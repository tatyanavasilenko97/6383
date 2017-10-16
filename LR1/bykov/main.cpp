/*******************************************************************************************************
    Быков И. В. 6383 гр, л/р 1, вариант 3.
    Условие:
    Имеется n городов, пронумерованных от 1 до n. Некоторые пары городов соединены дорогами.
    Определить, можно ли попасть по этим дорогам из одного заданного города в другой заданный город.
    Входная информация о дорогах задаётся в виде последовательности пар чисел i и j (i < j и i, j 1..n),
    указывающих, что i-й и j-й города соединены дорогами.
*********************************************************************************************************/
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;


enum Errors
{
    N_IS_ODD_NUMBER,                // N - нечетное число
    I_IS_NOT_LESS_THAN_J,           // I >= J
    N_IS_NULL,                      // N = 0
    TOWN_IS_GREATER_THAN_N,         // введенный город > n
    INVALID_VALUES_IN_ARRAY,        // неправильное значение в введенных городах
    INVALID_VALUES_IN_MY_TOWNS,     // неправильное значение в городах, между которыми ищем путь
    GOOD                            // все ОК
};

/*  Функция, которая определяет, есть ли путь между двумя вершинами.
    Для этого создаем массив в котором храним номер компоненты связности для каждой вершины. Затем достаточно узнать,
    в одной ли компоненте связности находятся заданные вершины
    входные данные:
        предусловие:    n - число городов
                        town_i, town_j - интересующие города
        постусловие:    road - матрица смежности
    возвращает 1 или 0
*/
bool find_way(unsigned long long n, unsigned long long town_i, unsigned long long town_j, bool** road);

/*  Рекурсивная функция "Поиск в глубину"
    Идея: для каждой непройденной вершины находим все непройденные смежные вершины и повторяем писк для них
    Сложность O(V+E)
    входные данные:
        предусловие:    n - число городов
                        top - текущая вершина
        постусловие:    components - указатель на массив номеров компонент связности для каждой вершины
                        num_components - количество компонент связности вершины
                        visited - указатель на массив, в котром хранится информация о посещении вершин
                        road - двойной указатель на матрицу смежности
    ничего не возвращает
*/
void dfs(unsigned long long n, unsigned long long top, unsigned long long* components, unsigned long long& num_components, bool* visited, bool** road);

/*  Функция ввода массива городов и интеграция их в матрицу смежности
    входные данные:
        предусловие:    n - число городов
        постусловие:    road - указатель на булевый двумерный массив - матрица смежности
    возвращает возможную ошибку при вводе городов ( 0 < town < n )
*/
Errors input_and_test_town(unsigned long long n, bool** road,unsigned long long n_max, std::istream& in);

/*  Функция ввода количества городов
    входные данные:
        постусловие:    n - число городов
    возвращает возможную ошибку при вводе n (n > 0)
*/
Errors input_and_test_n(unsigned long long& n, std::istream& in);

/*  Функция ввода городов, между котрыми требуется узнать путь
    входные данные:
        предусловие:    n - число городов
        постусловие:    town - адрес на заданные города
    возвращает возможную ошибку при вводе town (0 < town < n)
*/
Errors input_and_test_my_towns(unsigned long long n, unsigned long long& town, std::istream& in);
Errors input_and_test_n_max(unsigned long long& n, std::istream& in);

int main()
{
    setlocale(LC_ALL, "Russian");
    unsigned long long n = 0;               // количество городов
    bool **road;                            // матрица смежности
    unsigned long long town_j = 0;          // город j
    unsigned long long town_i = 0;          // город i
    unsigned long long n_max = 0;           // все вводимые города
    cout << "Введите количество городов: " << endl;
    Errors res_n = input_and_test_n(n, cin);
    /*if (res_n == N_IS_ODD_NUMBER)
    {
        cout << "Введенное количество городов НЕчетно. Нужно ввести четное количество городов." << endl;
        return -1;
    }*/
    if (res_n == N_IS_NULL)
    {
        cout << "Вы ввели 0. Число городов должно быть положительным." << endl;
        return -1;
    }
    cout << "Введите количество путей: ";
    Errors res_n_max = input_and_test_n(n_max, cin);
    if (res_n_max == N_IS_NULL)
    {
        cout << "Вы ввели 0. Число городов должно быть положительным." << endl;
        return -1;
    }
    road = new bool*[n];
    for (unsigned long long i = 0; i < n; i++)
        road[i] = new bool[n];
    for (unsigned long long i = 0; i < n; i++)
        for (unsigned long long j = 0; j < n; j++)
            road[i][j] = 0;
    cout << "Введите номера городов: " << endl;
    Errors res_towns = input_and_test_town(n, road, n_max, cin);
    if (res_towns == INVALID_VALUES_IN_ARRAY)
    {
        cout << "Неверно введены даннные о городах (выход за пределы границ 1<=town<=n)" << endl;
        return -1;
    }
    if (res_towns == I_IS_NOT_LESS_THAN_J)
    {
        cout << "В соседней паре i < j по условию. Ошибка!" << endl;
        return -1;
    }
    cout << "Введите города, между которыми нужно узнать существование пути: " << endl;
    Errors res_town_i = input_and_test_my_towns(n, town_i,  cin);
    cout << endl;
    if (res_town_i == INVALID_VALUES_IN_MY_TOWNS)
    {
        cout << "Cтартовый город указан неверно." << endl;
        return -1;
    }
    Errors res_town_j = input_and_test_my_towns(n, town_j, cin);
    if (res_town_j == INVALID_VALUES_IN_MY_TOWNS)
    {
        cout << "Конечный город указан неверно." << endl;
        return -1;
    }
    cout << "Матрица смежности: \n";
    for (unsigned long long i = 0; i < n; i++)
    {
        for (unsigned long long j = 0; j < n; j++)
            cout << road[i][j] << " ";
        cout << endl;
    }
    if(find_way(n, town_i, town_j, road))
        cout << "\nПуть между городами " << town_i + 1 << " и " << town_j + 1 << " существует." << endl;
    else
        cout << "\nПуть между городами " << town_i + 1 << " и " << town_j + 1 << " НЕ существует." << endl;
    for (unsigned long long i = 0; i < n; i++)
        delete [] road[i];
    delete [] road;
    road = NULL;
    return 0;
}

Errors input_and_test_town(unsigned long long n, bool** road, unsigned long long n_max, std::istream& in)
{
    unsigned long long town_i, town_j, k = 2;
    while (k <= n_max * 2)
    {
        in >> town_i;
        in >> town_j;
        if (town_i >= town_j)
            return I_IS_NOT_LESS_THAN_J;
        if ((town_i < 1) || (town_i > n) || (town_j < 1) || (town_j > n))
            return INVALID_VALUES_IN_ARRAY;
        road[town_i - 1][town_j - 1] = true;
        road[town_j - 1][town_i - 1] = true;
        k += 2;
    }
    return GOOD;
}

bool find_way(unsigned long long n, unsigned long long town_i, unsigned long long town_j, bool** road)
{
    bool *visited;                              //  массив посещения вершин
    unsigned long long *components;             //  массив, в котором указаны номера компонент для каждой вершины
    unsigned long long num_components = 0;      //  номер компоненты связности для вершины
    components = new unsigned long long[n];
    visited = new bool[n];
    for (unsigned long long i = 0; i < n; i++)
    {
        visited[i] = false;
        components[i] = 0;
    }
    for (unsigned long long i = 0; i < n; i++)
        if (!visited[i])
        {
            dfs(n, i, components, num_components, visited, road);
            num_components++;
        }
    for (unsigned long long i = 0; i < n; i++)
    if (components[town_i] == components[town_j])
        return true;
    else return false;
}

void dfs(unsigned long long n,unsigned long long top, unsigned long long* components, unsigned long long& num_components, bool* visited, bool** road)
{
    components[top] = num_components;
    visited[top] = true;
    for (unsigned long long j = 0; j < n; j++)
        if (road[top][j] != 0)
                if (!visited[j])
                    dfs(n, j, components, num_components, visited, road);
}


Errors input_and_test_n(unsigned long long& n, std::istream& in)
{
    in >> n;
    if (n < 1)
        return N_IS_NULL;
    return GOOD;
}

Errors input_and_test_n_max(unsigned long long& n, std::istream& in)
{
    in >> n;
    if (n < 1)
        return N_IS_NULL;
    if (n % 2 != 0)
        return N_IS_ODD_NUMBER;
    return GOOD;
}

Errors input_and_test_my_towns(unsigned long long n, unsigned long long& town, std::istream& in)
{
    in >> town;
    if (town < 1 || town > n)
        return INVALID_VALUES_IN_MY_TOWNS;
    town--;
    return GOOD;
}
