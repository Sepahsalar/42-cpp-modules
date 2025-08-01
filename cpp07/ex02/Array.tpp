/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:23:10 by asohrabi          #+#    #+#             */
/*   Updated: 2025/08/01 14:44:49 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _data(nullptr), _size(0)
{
	std::cout << "Default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	std::cout << "Sized constructor called with size = " << _size << std::endl;
	if (n == 0)
	{
		_data = nullptr;
		return;
	}
	
	try
	{
		_data = new T[n];
		for (unsigned int i = 0; i < n; ++i)
			_data[i] = T();
	}
	catch (const std::bad_alloc &e)
	{
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;
		_data = nullptr;
		_size = 0;
	}
}

template <typename T>
Array<T>::Array(const Array &other) : _size(other._size)
{
	std::cout << "Copy constructor called" << std::endl;
	if (_size == 0)
	{
		_data = nullptr;
	}
	else 
	{
		try
		{
			_data = new T[_size];
		}
		catch (const std::exception &e)
		{
			std::cerr << "Exception in copy constructor: " << e.what() << std::endl;
			_data = nullptr;
			_size = 0;
			return ;
		}
		
		for (unsigned int i = 0; i < _size; ++i)
			_data[i] = other._data[i];
	}
}

template <typename T>
Array<T>	&Array<T>::operator=(const Array &other)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this == &other)
		return *this;

	if (_data)
		delete[] _data;
	if (other._size == 0)
	{
		_data = nullptr;
		_size = 0;
	}
	else
	{
		_size = other._size;
		try
		{
			_data = new T[_size];
		}
		catch (const std::exception &e)
		{
			std::cerr << "Exception in assignment operator: " << e.what() << std::endl;
			_data = nullptr;
			_size = 0;
			return *this;
		}
		
		for (unsigned int i = 0; i < _size; ++i)
			_data[i] = other._data[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	std::cout << "Destructor called" << std::endl;
	if (_data)
		delete[] _data;
}

template <typename T>
T	&Array<T>::operator[](int index)
{
	if (_size == 0)
		throw std::out_of_range("Array is empty");
	if (index >= static_cast<int>(_size) || index < 0)
		throw std::out_of_range("Index out of bounds");
	return _data[index];
}

template <typename T>
const T	&Array<T>::operator[](int index) const
{
	if (_size == 0)
		throw std::out_of_range("Array is empty");
	if (index >= static_cast<int>(_size) || index < 0)
		throw std::out_of_range("Index out of bounds");
	return _data[index];
}

template <typename T>
unsigned int	Array<T>::size() const
{
	return _size;
}
