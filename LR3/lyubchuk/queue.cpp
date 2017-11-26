#include "queue.hpp"

Queue::Queue() : size(0), start(0) // Инициализация переменных
{}

void Queue::put(double a) // Определение функции добавления элемента a в очередь
{
    if (!isFull()) // Если в очереди есть место
    {
        arr[(start+size)%maxSize]=a; // То добавляем элемент после последнего(с номером (start+size)%maxSize)
        ++size;
    } else // Иначе ошибка переполнения
    {
        printf("Queue overflow.\n");
        exit(1);
    }
}
double Queue::take() // Определение функции получения элемента из очереди
{
    if (!isEmpty()) // Если в очереди есть элементы
    {
        double b = arr[start]; // Сохраняем первый элемент
        start=(++start%maxSize); // Меняем индекс первого элемента на следующий (если текущий элемент был 511 - то следующим будет 0)
        --size;
        return b;
    } else // Иначе ошибка
    {
        printf("Can't take an element from empty queue.\n");
        exit(1);
    }
}

bool Queue::isEmpty()
{
    return (size==0);
}

bool Queue::isFull()
{
    return (size==maxSize);
}
