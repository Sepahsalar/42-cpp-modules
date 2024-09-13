/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:59:21 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/13 14:55:27 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
	// std::cout << "Int constructor called" << std::endl;
	_value = num << _fractionalBits;
}

Fixed::Fixed(const float num)
{
	// std::cout << "Float constructor called" << std::endl;
	_value = roundf(num * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &other)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed	&Fixed::operator=(const Fixed &other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_value = other.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits() const
{
	return this->_value;
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

int	Fixed::toInt(void) const
{
	return _value >> _fractionalBits;
}

float	Fixed::toFloat(void) const
{
	return (float)_value / (1 << _fractionalBits);
}

bool	Fixed::operator>(const Fixed &other) const
{
	return _value > other._value;
}

bool	Fixed::operator<(const Fixed &other) const
{
	return _value < other._value;
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return _value >= other._value;
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return _value <= other._value;
}

bool	Fixed::operator==(const Fixed &other) const
{
	return _value == other._value;
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return _value != other._value;
}

Fixed	Fixed::operator+(const Fixed &other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	if (other._value == 0)
		throw std::runtime_error("Division by zero");
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed	&Fixed::operator++()
{
	_value++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp = *this;
	_value++;
	return temp;
}

Fixed	&Fixed::operator--()
{
	_value--;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp = *this;
	_value--;
	return temp;
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}
