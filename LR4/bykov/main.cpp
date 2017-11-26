// Пример работы с АТД "Бинарное дерево" (в процедурно-модульной парадигме)
#include "BTree.h"


using namespace binTree_modul;

int readAction();

int main ()
{
   		//setlocale(LC_ALL, "Russian");
   	 	int flag, cnt;
		ifstream in("KLP.txt");
		binTree b = Create();
		base elem;
		b = enterBT(in);
        while (true)
        {
		switch (readAction())
		{
            case 1:
				if (isNull(b))
				{
					cout << "Дерево пустое.\n";
					break;
				}
                cout << "Введите элемент: ";
                cin >> elem;
                cnt = count(b, elem);
                cout << "Элемент " << elem << " встречается в дереве " << cnt << " раз.\n";
                break;
            case 2:
                cout << "Бинарное дерево в КЛП-представлении: " << endl;
                outBT(b);
                cout << endl;
                break;
            case 3:
                return 0;
            }
            cout << "Продолжить? 1 - да; 0 - нет. ";
            cin >> flag;
            cout << endl;
            if (flag == 0)
                return 0;
        }
	destroy (b);
    return 0;
}

int readAction()
{
	while (true)
	{
		cout <<"Выберите действие:\n1 - посчитать количество вхождений элемента;\n2 - вывод дерева\n3 -выход.\n";
		int action;
		cin >> action;
		if (action > 3 || action < 1)
		{
			printf("Ошибка!\n");
			continue;
		}
		return action;
	}
}
