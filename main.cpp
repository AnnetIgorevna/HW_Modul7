#include <iostream>
#include <exception>
#include "IntArray.h"
#include "Exceptions.h"

int main()
{
    setlocale(LC_ALL, "rus");
    try
    {
        // ��������: �������� ������� � ������������ ��������� ����� ��� �������
        //IntArray arr(0);
        //IntArray arr(-5);
        IntArray arr(10);
        for (int i = 0; i < 10; i++)
        {
            arr[i] = i + 11;
        }
        std::cout << "�������� ������:" << std::endl;
        arr.print();
        IntArray arrCopy = arr;
        std::cout << "����� �������:" << std::endl;
        arrCopy.print();
        // ��������: ��������� ������� ������� �� �������
        //std::cout << "�������� ������ ������� �� 0:" << std::endl;
        //arr.resize(0);
        std::cout << "��������� ������� � ������� ������� (���� 10, ����� 12):" << std::endl;
        arr.resize(12);
        arr.print();
        std::cout << "��������� ������� � ������� ������� (���� 12, ����� 9):" << std::endl;
        arr.resize(9);
        arr.print();
        // ��������: ���� ������� �������� ��� �������� �������
        //std::cout << "�������� �������� �� ��������� 20 ����� ��������� � �������� 11:" << std::endl;
        //arr.insertBefore(20, 11);
        //arr.print();
        std::cout << "�������� ������� �� ��������� 20 ����� ��������� � �������� 5:" << std::endl;
        arr.insertBefore(20, 5);
        arr.print();
        std::cout << "�������� � ����� ������� ������� �� ��������� 30:" << std::endl;
        arr.insertAtEnd(30);
        arr.print();
        std::cout << "�������� � ������ ������� ������� �� ��������� 40:" << std::endl;
        arr.insertAtBeginning(40);
        arr.print();
        // ��������: �������� �������� ������� � �������� ��� �������� �������
        //std::cout << "������� ������� ������� � �������� 20:" << std::endl;
        //arr.remove(20);
        std::cout << "������� ������� ������� � �������� 3:" << std::endl;
        arr.remove(3);
        arr.print();
        std::cout << "����� �������� ������� �� ��������� 20 (� ������ ������ ���������� ������ ���������� ��������):" << std::endl;
        arr.searchByVal(20);
        std::cout << "����� �������� ������� �� ��������� 50 (� ������ ������ ���������� ������ ���������� ��������):" << std::endl;
        arr.searchByVal(50);
        // ��������: ��������� ������� ������� �� �������
        //std::cout << "��������� ������� ������� ��� ���������� ������:" << std::endl;
        //arr.reallocate(0);
        std::cout << "��������� ������� ������� ��� ���������� ������:" << std::endl;
        arr.reallocate(14);
        std::cout << "����� ������ �������: " << arr.getLength() << std::endl;
        std::cout << "������� �������:" << std::endl;
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
