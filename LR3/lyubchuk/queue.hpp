#pragma once
#include <stdlib.h>
#include <stdio.h>

class Queue
{
    public:
    Queue();
    void put(double); 		// Функция добавления элемента в очередь
    double take(); 			// Функция получения элемента из очереди
    bool isEmpty(); 		// Функция проверки на пустоту очереди
    bool isFull(); 			// Функция проверки на наличие свободного места в очереди
    private:
    static const int maxSize=512; 	// Максимальное количество элементов в очереди
    double arr[maxSize]; 			// Массив, в котором хранятся элементы очереди
    int start, size; 				// Индекс первого элемента и их кол-во
};
