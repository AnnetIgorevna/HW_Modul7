#include <iostream>
#include <exception>
#include "IntArray.h"
#include "Exceptions.h"

IntArray::IntArray(int length) : _length{ length }
{
    if (length <= 0)
    {
        std::cout << "The length of the array cannot be less than or equal to zero" << std::endl;
        throw bad_length();
    }
    else
    {
        _data = new int[length] {};
    }
}

IntArray::~IntArray()
{
	delete[] _data;
}

std::ostream& operator<<(std::ostream& output, const IntArray& arr)
{
    for (int i = 0; i < arr._length; i++)
    {
        output << arr._data[i] << " ";
    }
    std::cout << std::endl;
    return output;
}

void IntArray::print()
{
    for (int i = 0; i < _length; ++i)
    {
        std::cout << _data[i] << " ";
    }
    std::cout << std::endl;
}

IntArray::IntArray(IntArray& other)
{
    if (other.getLength() <= 0)
    {
        std::cout << "The length of the array cannot be less than or equal to zero" << std::endl;
        throw bad_length();
    }
    _length = other._length;
    if (other._data)
    {
        _data = new int[_length];
        for (int i = 0; i < _length; ++i)
        {
            _data[i] = other._data[i];
        }
    }
    else _data = 0;
}

int IntArray::getLength() const
{
    return _length;
}

void IntArray::erase()
{
	delete[] _data;
	_data = nullptr;
	_length = 0;
    std::cout << "Массив очищен" << std::endl;
}

int& IntArray::operator[](int index)
{
    if (index < 0 || index > _length)
    {
        std::cout << "The specified index is outside the array" << std::endl;
        throw bad_range();
    }
    return _data[index];
}

IntArray& IntArray::operator=(const IntArray& other)
{
    if (this == &other)
    {
        return *this;
    }
    delete[] _data;
    _length = other._length;
    if (other._data)
    {
        _data = new int[_length];
        for (int i = 0; i < _length; ++i)
        {
            _data[i] = other._data[i];
        }
    }
    else _data = 0;
    return *this;
}

void IntArray::reallocate(int newLength)
{
    if (newLength <= 0)
    {
        std::cout << "The length of the array cannot be less than or equal to zero" << std::endl;
        throw bad_length();
    }
    erase();
	_data = new int[newLength];
	_length = newLength;
}

void IntArray::resize(int newLength)
{
    if (newLength == _length) return;
    if (newLength <= 0)
    {
        std::cout << "The length of the array cannot be less than or equal to zero" << std::endl;
        throw bad_length();
    }
    int* data = new int[newLength];
    if (_length > 0)
    {
        int elementsToCopy = newLength;
        for (int index = 0; index < elementsToCopy; ++index)
        {
            if (index < _length)
            {
                data[index] = _data[index];
            }
            else data[index] = 0;
        }
    }
    delete[] _data;
    _data = data;
    _length = newLength;
}

void IntArray::insertBefore(int value, int index)
{
    if (index < 0 || index > _length)
    {
        std::cout << "The specified index is outside the array" << std::endl;
        throw bad_range();
    }

    int newLength = _length + 1;
    int* data = new int[newLength];

    for (int before = 0; before < index; ++before)
        data[before] = _data[before];

    data[index] = value;

    for (int after = index; after < _length; ++after)
        data[after + 1] = _data[after];

    delete[] _data;
    _data = data;
    ++_length;
}

void IntArray::remove(int index)
{
    if (index < 0 || index > _length)
    {
        std::cout << "The specified index is outside the array" << std::endl;
        throw bad_range();
    }

    if (_length == 1)
    {
        erase();
        return;
    }
    int newLength = _length - 1;
    int* data = new int[newLength];
    for (int before{ 0 }; before < index; ++before)
        data[before] = _data[before];

    for (int after{ index + 1 }; after < _length; ++after)
        data[after - 1] = _data[after];

    delete[] _data;
    _data = data;
    --_length;
}

void IntArray::insertAtBeginning(int value)
{ 
    insertBefore(value, 0);
}
void IntArray::insertAtEnd(int value)
{
    insertBefore(value, _length);
}

void IntArray::searchByVal(int value)
{
    int ans[10];
    int h = 0;
    for (int i = 0; i < _length; i++)
    {
        if (_data[i] == value)
        {
            ans[h] = i;
            h++;
        }
    }
    if (h != 0)
    {
        for (int j = 0; j < h; j++)
        {
            std::cout << "Индекс элемента со значением " << value << " - " << ans[j] <<std::endl;
        }
    }
    else
    {
        std::cout << "Элементов со значением " << value << " в массиве нет" << std::endl;
    }
}

int IntArray::searchByIndex(int index)
{
    if (index < 0 || index > _length)
    {
        std::cout << "The specified index is outside the array" << std::endl;
        throw bad_range();
    }
    return _data[index];
}

