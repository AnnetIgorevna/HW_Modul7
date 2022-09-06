#include <iostream>
#include <exception>
#include "IntArray.h"
#include "Exceptions.h"

int main()
{
    setlocale(LC_ALL, "rus");
    try
    {
        // ПРОВЕРКА: создание массива с отрицатльным значением длины или нулевым
        //IntArray arr(0);
        //IntArray arr(-5);
        IntArray arr(10);
        for (int i = 0; i < 10; i++)
        {
            arr[i] = i + 11;
        }
        std::cout << "Исходный массив:" << std::endl;
        arr.print();
        IntArray arrCopy = arr;
        std::cout << "Копия массива:" << std::endl;
        arrCopy.print();
        // ПРОВЕРКА: изменение размера массива на нулевой
        //std::cout << "Изменить размер массива на 0:" << std::endl;
        //arr.resize(0);
        std::cout << "Изменение размера в бОльшую сторону (было 10, стало 12):" << std::endl;
        arr.resize(12);
        arr.print();
        std::cout << "Изменение размера в меньшую сторону (было 12, стало 9):" << std::endl;
        arr.resize(9);
        arr.print();
        // ПРОВЕРКА: ввод индекса элемента вне пределов массива
        //std::cout << "Добавить элемента со значением 20 перед элементов с индексом 11:" << std::endl;
        //arr.insertBefore(20, 11);
        //arr.print();
        std::cout << "Добавить элемент со значением 20 перед элементов с индексом 5:" << std::endl;
        arr.insertBefore(20, 5);
        arr.print();
        std::cout << "Добавить в конец массива элемент со значением 30:" << std::endl;
        arr.insertAtEnd(30);
        arr.print();
        std::cout << "Добавить в начало массива элемент со значением 40:" << std::endl;
        arr.insertAtBeginning(40);
        arr.print();
        // ПРОВЕРКА: удаление элемента массива с индексом вне пределов массива
        //std::cout << "Удалить элемент массива с индексом 20:" << std::endl;
        //arr.remove(20);
        std::cout << "Удалить элемент массива с индексом 3:" << std::endl;
        arr.remove(3);
        arr.print();
        std::cout << "Поиск элемента массива со значением 20 (в случае успеха возвращает индекс найденного элемента):" << std::endl;
        arr.searchByVal(20);
        std::cout << "Поиск элемента массива со значением 50 (в случае успеха возвращает индекс найденного элемента):" << std::endl;
        arr.searchByVal(50);
        // ПРОВЕРКА: изменение размера массива на нулевой
        //std::cout << "Изменение размера массива без сохранения данных:" << std::endl;
        //arr.reallocate(0);
        std::cout << "Изменение размера массива без сохранения данных:" << std::endl;
        arr.reallocate(14);
        std::cout << "Новый размер массива: " << arr.getLength() << std::endl;
        std::cout << "Очистка массива:" << std::endl;
        arr.erase();
    }
    catch (bad_length& bl)
    {
        std::cout << bl.what() << std::endl;
    }
    catch (bad_range& br)
    {
        std::cout << br.what() << std::endl;
    }
    return 0;
}
