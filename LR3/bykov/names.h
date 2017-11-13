#ifndef NAMES_H_INCLUDED
#define NAMES_H_INCLUDED

#include <fstream>

template <typename S>
class myNames
{
private:
    S *name;        // массив имен
    int *numName;   // массив их идентификаторов
    bool **arrayOfChildren; // двумерный массив родства
    const int size; // размер
    int countOfNames;   // текущее количество имен
public:
    myNames(int = 10);  // конструктор
    ~myNames();         // деструктор
    void delName(int my_name);  // удаление имени
    void addNames();        // добавление имени
    int getCnt();
    S getName(int i);
    int getNumName(S i);
    bool realiseArray();       //создание 2мерного массива
    bool getArray(int i, int j);
    void printArray();
    void printArray2();
    int findNumName(S _name);   // нахождение идентификатора по имени
    S findName(int _numName);   // нахождение имени по идентификатору
};
template <typename S>
myNames<S>::myNames(int sizeNames) :
    size(sizeNames), countOfNames(0)
{
    name = new S[size + 1];
    numName = new int[size + 1];
    arrayOfChildren = new bool * [size + 1];
    for (int i = 0; i < size + 1; i++)
        arrayOfChildren[i] = new bool [size + 1];
}

template <typename S>
myNames<S>::~myNames()
{
    delete [] name;
    delete [] numName;
}

template <typename S>
void myNames<S>::addNames()
{
    ifstream names( "names.txt");
    while (names.peek()!= EOF)      // גגמה טלום טח פאיכא
    {
        names >> name[countOfNames];
        countOfNames++;
    }
    for (int i = 0; i < countOfNames; i++)
        numName[i] = i;
}

template <typename S>
int myNames<S>::getCnt()
{
    return countOfNames;
}

template <typename S>
S myNames<S>::getName(int i)
{
    return name[i];
}

template <typename S>
int myNames<S>::getNumName(S iname)
{
   for (int i = 0; i < countOfNames; i++)
   {
        if (iname == name[i])
        return i;
   }
   return -1;
}

template <typename S>
bool myNames<S>::realiseArray()
{
    bool flag = true;
    ifstream in( "children.txt");
    for (int i = 0; i < countOfNames; i++)
        for (int j = 0; j < countOfNames; j++)
            in >> arrayOfChildren[i][j];
    for (int i = 0; i < countOfNames; i++)
        for (int j = 0; j < countOfNames; j++)
        {
            if (arrayOfChildren[i][i] == 1)
                flag = false;
            if ((arrayOfChildren[i][j] == 1 || arrayOfChildren[j][i] == 1) && (arrayOfChildren[i][j] == arrayOfChildren[j][i]))
                flag = false;
        }
    return flag;
}

template <typename S>
bool myNames<S>::getArray(int i, int j)
{
    return arrayOfChildren[i][j];
}

template <typename S>
void myNames<S>::printArray()
{
    for (int i = 0; i < countOfNames; i++)
    {
        for (int j = 0; j < countOfNames; j++)
        {
            cout << arrayOfChildren[i][j] << " ";
        }
        cout << endl;
    }
}

template <typename S>
void myNames<S>::printArray2()
{
    for (int i = 0; i < countOfNames; i++)
    {
        for (int j = 0; j < countOfNames; j++)
        {
            if (arrayOfChildren[i][j])
                cout << "Descendant [ "<< name[i] << " ][ " << name[j] << " ] = " << arrayOfChildren[i][j] << endl;
        }
    }
}
template <typename S>
int myNames<S>::findNumName(S _name)
{
    for (int i = 0; i < countOfNames; i++)
    if (_name == name[i])
         return numName[i];
    return -1;
}

template <typename S>
S myNames<S>::findName(int _numName)
{
    for (int i = 0; i < countOfNames; i++)
    if (_numName == numName[i])
         return name[i];
    return "error";
}

template <typename S>
void myNames<S>::delName(int row)
{
    for (int k = row; k < countOfNames - 1; k++)
    {
        for (int z = 0; z < countOfNames; z++)
        {
            arrayOfChildren[k][z] = arrayOfChildren[k + 1][z];
            arrayOfChildren[z][k] = arrayOfChildren[z][k + 1];
        }
    }
    bool flag = false;
    int num = 0;
    S my_name = name[row];
    for (int i = 0; i < countOfNames; i++)
    if (my_name == name[i])
    {
        flag = true;
        num = i;
    }
    if (flag)
    {
        for (int i = num; i < countOfNames - 1; i++)
            name[i] = name[i + 1];
        countOfNames--;
    }
}
#endif // NAMES_H_INCLUDED
