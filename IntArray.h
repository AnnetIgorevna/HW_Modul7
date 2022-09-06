#pragma once
#ifndef INTARRAY_H
#define INTARRAY_H
#include <iostream>
#include <exception>

class IntArray
{
public:
    IntArray() = default; // конструктор по-умолчанию
    IntArray(int length);// создание массива - конструктор
    ~IntArray(); // деструктор
    IntArray(IntArray& other); // конструктор копирования
    void print();
    int getLength() const; // узнать длину массива
    void erase(); // очищение массива
    int& operator[](int index); // возвращает элемент по заданному индексу
    IntArray& operator=(const IntArray&); // перегрузка оператора присваивания
    friend std::ostream& operator<<(std::ostream& output, const IntArray& arr); // 
    void reallocate(int newLength); // изменение размера массива без сохранения элементов исходного
    void resize(int newLength); // изменение размера массива с сохранением элементов исходного
    void insertBefore(int value, int index); // вставить элемент перед элементом с указанным индексом
    void remove(int index); // удалить элемент с указанным индексом из массива
    void insertAtBeginning(int value); // вставить элемент в начало массива
    void insertAtEnd(int value); // вставить элемент в конец массива
    void searchByVal(int value); // поиск элемента по значению
private:
    int _length{};
    int* _data{};
};

#endif