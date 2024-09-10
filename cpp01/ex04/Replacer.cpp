/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 00:03:55 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/10 16:07:20 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

Replacer::Replacer(const std::string &filename
	, const std::string &s1, const std::string &s2)
	: _filename(filename), _s1(s1), _s2(s2) {}

Replacer::~Replacer() {}

void	Replacer::_handleError(const std::string &message) const
{
	std::cerr << message << std::endl;
	std::exit(EXIT_FAILURE);
}

std::string	Replacer::_replaceOccurrences(const std::string &content) const
{
	std::string	result;
	std::size_t	pos = 0;
	std::size_t	found = content.find(_s1, pos);

	while (found != std::string::npos)
	{
		result.append(content.substr(pos, found - pos));
		result.append(_s2);
		pos = found + _s1.length();
		found = content.find(_s1, pos);
	}
	result.append(content.substr(pos));
	return result;
}

void Replacer::replaceAndSave() const
{
	std::stringstream	buffer;
	std::string			content;
	std::string			replacedContent;
	
	std::ifstream	inputFile(_filename.c_str());
	if (!inputFile.is_open())
		_handleError("Error: Could not open file " + _filename);
	buffer << inputFile.rdbuf();
	content = buffer.str();
	inputFile.close();

	replacedContent = _replaceOccurrences(content);
	std::ofstream outputFile((_filename + ".replace").c_str());
	if (!outputFile.is_open())
		_handleError("Error: Could not create file " + _filename + ".replace");
	outputFile << replacedContent;
	outputFile.close();
}
