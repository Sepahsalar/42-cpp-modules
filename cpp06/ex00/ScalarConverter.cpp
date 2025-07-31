/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 23:51:21 by asohrabi          #+#    #+#             */
/*   Updated: 2025/07/31 12:25:07 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &) {}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &)
{
	return *this;
}

static bool	isCharLiteral(const std::string &str)
{
	return str.length() == 1 && !std::isdigit(str[0]);
}

static bool	isFloatLiteral(const std::string &str)
{
	return str.length() > 1 && str.back() == 'f' &&
		str != "nanf" && str != "+inff" && str != "-inff" && str != "inff";
}

static bool	isPseudoLiteral(const std::string &str)
{
	return str == "nanf" || str == "+inff" || str == "-inff" ||
		str == "nan"  || str == "+inf"  || str == "-inf" ||
		str == "inf" || str == "inff";
}

void	ScalarConverter::convert(const std::string &str)
{
	double value = 0.0;

	if (str.empty())
	{
		std::cout << "Invalid input: '" << str << "'" << std::endl;
		return;
	}

	if (isCharLiteral(str))
	{
		char c = str[0];
		value = static_cast<double>(c);
	}
	else if (isPseudoLiteral(str))
	{
		if (str == "nanf" || str == "nan")
			value = std::numeric_limits<float>::quiet_NaN();
		else if (str == "+inff" || str == "+inf" || str == "inff" || str == "inf")
			value = std::numeric_limits<float>::infinity();
		else if (str == "-inff" || str == "-inf")
			value = -std::numeric_limits<float>::infinity();
	}
	else if (str.find("nan") != std::string::npos)
	{
		std::cout << "Invalid input: '" << str << "'" << std::endl;
		return;
	}

	else
	{
		std::string	cleaned = str;

		if (isFloatLiteral(str))
			cleaned.pop_back();
		
		char	*end;

		value = std::strtod(cleaned.c_str(), &end);
		if (*end != '\0')
		{
			std::cout << "Invalid input: '" << str << "'" << std::endl;
			return;
		}	
	}

	// CHAR
	std::cout << "char: ";

	if (std::isnan(value) || value < 0 || value > 127)
		std::cout << "impossible" << std::endl;
	else if (std::isprint(static_cast<char>(value)))
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;

	// INT
	std::cout << "int: ";
	
	if (std::isnan(value)
			|| value < std::numeric_limits<int>::min()
			|| value > std::numeric_limits<int>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;

	// FLOAT
	std::cout << "float: " << std::fixed << std::setprecision(1)
			<< static_cast<float>(value) << "f" << std::endl;

	// DOUBLE
	std::cout << "double: " << std::fixed << std::setprecision(1)
			<< static_cast<double>(value) << std::endl;
}
