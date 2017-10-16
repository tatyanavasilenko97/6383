/*******************************************************************************************************
    Áûêîâ È. Â. 6383 ãð, ë/ð 1, âàðèàíò 3.
    Óñëîâèå:
    Èìååòñÿ n ãîðîäîâ, ïðîíóìåðîâàííûõ îò 1 äî n. Íåêîòîðûå ïàðû ãîðîäîâ ñîåäèíåíû äîðîãàìè.
    Îïðåäåëèòü, ìîæíî ëè ïîïàñòü ïî ýòèì äîðîãàì èç îäíîãî çàäàííîãî ãîðîäà â äðóãîé çàäàííûé ãîðîä.
    Âõîäíàÿ èíôîðìàöèÿ î äîðîãàõ çàäà¸òñÿ â âèäå ïîñëåäîâàòåëüíîñòè ïàð ÷èñåë i è j (i < j è i, j 1..n),
    óêàçûâàþùèõ, ÷òî i-é è j-é ãîðîäà ñîåäèíåíû äîðîãàìè.
*********************************************************************************************************/
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;


enum Errors
{
    N_IS_ODD_NUMBER,                // N - íå÷åòíîå ÷èñëî
    I_IS_NOT_LESS_THAN_J,           // I >= J
    N_IS_NULL,                      // N = 0
    TOWN_IS_GREATER_THAN_N,         // ââåäåííûé ãîðîä > n
    INVALID_VALUES_IN_ARRAY,        // íåïðàâèëüíîå çíà÷åíèå â ââåäåííûõ ãîðîäàõ
    INVALID_VALUES_IN_MY_TOWNS,     // íåïðàâèëüíîå çíà÷åíèå â ãîðîäàõ, ìåæäó êîòîðûìè èùåì ïóòü
    GOOD                            // âñå ÎÊ
};

/*  Ôóíêöèÿ, êîòîðàÿ îïðåäåëÿåò, åñòü ëè ïóòü ìåæäó äâóìÿ âåðøèíàìè.
    Äëÿ ýòîãî ñîçäàåì ìàññèâ â êîòîðîì õðàíèì íîìåð êîìïîíåíòû ñâÿçíîñòè äëÿ êàæäîé âåðøèíû. Çàòåì äîñòàòî÷íî óçíàòü,
    â îäíîé ëè êîìïîíåíòå ñâÿçíîñòè íàõîäÿòñÿ çàäàííûå âåðøèíû
    âõîäíûå äàííûå:
        ïðåäóñëîâèå:    n - ÷èñëî ãîðîäîâ
                        town_i, town_j - èíòåðåñóþùèå ãîðîäà
        ïîñòóñëîâèå:    road - ìàòðèöà ñìåæíîñòè
    âîçâðàùàåò 1 èëè 0
*/
bool find_way(unsigned long long n, unsigned long long town_i, unsigned long long town_j, bool** road);

/*  Ðåêóðñèâíàÿ ôóíêöèÿ "Ïîèñê â ãëóáèíó"
    Èäåÿ: äëÿ êàæäîé íåïðîéäåííîé âåðøèíû íàõîäèì âñå íåïðîéäåííûå ñìåæíûå âåðøèíû è ïîâòîðÿåì ïèñê äëÿ íèõ
    Ñëîæíîñòü O(V+E)
    âõîäíûå äàííûå:
        ïðåäóñëîâèå:    n - ÷èñëî ãîðîäîâ
                        top - òåêóùàÿ âåðøèíà
        ïîñòóñëîâèå:    components - óêàçàòåëü íà ìàññèâ íîìåðîâ êîìïîíåíò ñâÿçíîñòè äëÿ êàæäîé âåðøèíû
                        num_components - êîëè÷åñòâî êîìïîíåíò ñâÿçíîñòè âåðøèíû
                        visited - óêàçàòåëü íà ìàññèâ, â êîòðîì õðàíèòñÿ èíôîðìàöèÿ î ïîñåùåíèè âåðøèí
                        road - äâîéíîé óêàçàòåëü íà ìàòðèöó ñìåæíîñòè
    íè÷åãî íå âîçâðàùàåò
*/
void dfs(unsigned long long n, unsigned long long top, unsigned long long* components, unsigned long long& num_components, bool* visited, bool** road);

/*  Ôóíêöèÿ ââîäà ìàññèâà ãîðîäîâ è èíòåãðàöèÿ èõ â ìàòðèöó ñìåæíîñòè
    âõîäíûå äàííûå:
        ïðåäóñëîâèå:    n - ÷èñëî ãîðîäîâ
        ïîñòóñëîâèå:    road - óêàçàòåëü íà áóëåâûé äâóìåðíûé ìàññèâ - ìàòðèöà ñìåæíîñòè
    âîçâðàùàåò âîçìîæíóþ îøèáêó ïðè ââîäå ãîðîäîâ ( 0 < town < n )
*/
Errors input_and_test_town(unsigned long long n, bool** road,unsigned long long n_max, std::istream& in);

/*  Ôóíêöèÿ ââîäà êîëè÷åñòâà ãîðîäîâ
    âõîäíûå äàííûå:
        ïîñòóñëîâèå:    n - ÷èñëî ãîðîäîâ
    âîçâðàùàåò âîçìîæíóþ îøèáêó ïðè ââîäå n (n > 0)
*/
Errors input_and_test_n(unsigned long long& n, std::istream& in);

/*  Ôóíêöèÿ ââîäà ãîðîäîâ, ìåæäó êîòðûìè òðåáóåòñÿ óçíàòü ïóòü
    âõîäíûå äàííûå:
        ïðåäóñëîâèå:    n - ÷èñëî ãîðîäîâ
        ïîñòóñëîâèå:    town - àäðåñ íà çàäàííûå ãîðîäà
    âîçâðàùàåò âîçìîæíóþ îøèáêó ïðè ââîäå town (0 < town < n)
*/
Errors input_and_test_my_towns(unsigned long long n, unsigned long long& town, std::istream& in);
Errors input_and_test_n_max(unsigned long long& n, std::istream& in);

int main()
{
    setlocale(LC_ALL, "Russian");
    unsigned long long n = 0;               // êîëè÷åñòâî ãîðîäîâ
    bool **road;                            // ìàòðèöà ñìåæíîñòè
    unsigned long long town_j = 0;          // ãîðîä j
    unsigned long long town_i = 0;          // ãîðîä i
    unsigned long long n_max = 0;           // âñå ââîäèìûå ãîðîäà
    cout << "Ââåäèòå êîëè÷åñòâî ãîðîäîâ: " << endl;
    Errors res_n = input_and_test_n(n, cin);
    /*if (res_n == N_IS_ODD_NUMBER)
    {
        cout << "Ââåäåííîå êîëè÷åñòâî ãîðîäîâ ÍÅ÷åòíî. Íóæíî ââåñòè ÷åòíîå êîëè÷åñòâî ãîðîäîâ." << endl;
        return -1;
    }*/
    if (res_n == N_IS_NULL)
    {
        cout << "Âû ââåëè 0. ×èñëî ãîðîäîâ äîëæíî áûòü ïîëîæèòåëüíûì." << endl;
        return -1;
    }
    cout << "Ââåäèòå êîëè÷åñòâî ïóòåé: ";
    Errors res_n_max = input_and_test_n(n_max, cin);
    if (res_n_max == N_IS_NULL)
    {
        cout << "Âû ââåëè 0. ×èñëî ãîðîäîâ äîëæíî áûòü ïîëîæèòåëüíûì." << endl;
        return -1;
    }
    road = new bool*[n];
    for (unsigned long long i = 0; i < n; i++)
        road[i] = new bool[n];
    for (unsigned long long i = 0; i < n; i++)
        for (unsigned long long j = 0; j < n; j++)
            road[i][j] = 0;
    cout << "Ââåäèòå íîìåðà ãîðîäîâ: " << endl;
    Errors res_towns = input_and_test_town(n, road, n_max, cin);
    if (res_towns == INVALID_VALUES_IN_ARRAY)
    {
        cout << "Íåâåðíî ââåäåíû äàíííûå î ãîðîäàõ (âûõîä çà ïðåäåëû ãðàíèö 1<=town<=n)" << endl;
        return -1;
    }
    if (res_towns == I_IS_NOT_LESS_THAN_J)
    {
        cout << "Â ñîñåäíåé ïàðå i < j ïî óñëîâèþ. Îøèáêà!" << endl;
        return -1;
    }
    cout << "Ââåäèòå ãîðîäà, ìåæäó êîòîðûìè íóæíî óçíàòü ñóùåñòâîâàíèå ïóòè: " << endl;
    Errors res_town_i = input_and_test_my_towns(n, town_i,  cin);
    cout << endl;
    if (res_town_i == INVALID_VALUES_IN_MY_TOWNS)
    {
        cout << "Còàðòîâûé ãîðîä óêàçàí íåâåðíî." << endl;
        return -1;
    }
    Errors res_town_j = input_and_test_my_towns(n, town_j, cin);
    if (res_town_j == INVALID_VALUES_IN_MY_TOWNS)
    {
        cout << "Êîíå÷íûé ãîðîä óêàçàí íåâåðíî." << endl;
        return -1;
    }
    cout << "Ìàòðèöà ñìåæíîñòè: \n";
    for (unsigned long long i = 0; i < n; i++)
    {
        for (unsigned long long j = 0; j < n; j++)
            cout << road[i][j] << " ";
        cout << endl;
    }
    if(find_way(n, town_i, town_j, road))
        cout << "\nÏóòü ìåæäó ãîðîäàìè " << town_i + 1 << " è " << town_j + 1 << " ñóùåñòâóåò." << endl;
    else
        cout << "\nÏóòü ìåæäó ãîðîäàìè " << town_i + 1 << " è " << town_j + 1 << " ÍÅ ñóùåñòâóåò." << endl;
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
    bool *visited;                              //  ìàññèâ ïîñåùåíèÿ âåðøèí
    unsigned long long *components;             //  ìàññèâ, â êîòîðîì óêàçàíû íîìåðà êîìïîíåíò äëÿ êàæäîé âåðøèíû
    unsigned long long num_components = 0;      //  íîìåð êîìïîíåíòû ñâÿçíîñòè äëÿ âåðøèíû
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
