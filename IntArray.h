#pragma once
#ifndef INTARRAY_H
#define INTARRAY_H
#include <iostream>
#include <exception>

class IntArray
{
public:
    IntArray() = default; // ����������� ��-���������
    IntArray(int length);// �������� ������� - �����������
    ~IntArray(); // ����������
    IntArray(IntArray& other); // ����������� �����������
    void print();
    int getLength() const; // ������ ����� �������
    void erase(); // �������� �������
    int& operator[](int index); // ���������� ������� �� ��������� �������
    IntArray& operator=(const IntArray&); // ���������� ��������� ������������
    friend std::ostream& operator<<(std::ostream& output, const IntArray& arr); // 
    void reallocate(int newLength); // ��������� ������� ������� ��� ���������� ��������� ���������
    void resize(int newLength); // ��������� ������� ������� � ����������� ��������� ���������
    void insertBefore(int value, int index); // �������� ������� ����� ��������� � ��������� ��������
    void remove(int index); // ������� ������� � ��������� �������� �� �������
    void insertAtBeginning(int value); // �������� ������� � ������ �������
    void insertAtEnd(int value); // �������� ������� � ����� �������
    void searchByVal(int value); // ����� �������� �� ��������
private:
    int _length{};
    int* _data{};
};

#endif