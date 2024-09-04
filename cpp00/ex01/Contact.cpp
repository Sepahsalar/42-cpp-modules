/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:35:58 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/04 19:37:10 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() : _firstName(""), _lastName(""), _nickname(""),
						_phoneNumber(""), _darkestSecret("") {}

Contact::Contact(std::string fn, std::string ln, std::string nn,
					std::string pn, std::string ds)
				: _firstName(fn), _lastName(ln), _nickname(nn),
					_phoneNumber(pn), _darkestSecret(ds) {}

Contact::~Contact() {}

std::string	Contact::getFirstName() const
{
	return _firstName;
}
std::string	Contact::getLastName() const
{
	return _lastName;
}
std::string	Contact::getNickname() const
{
	return _nickname;
}
std::string	Contact::getPhoneNumber() const
{
	return _phoneNumber;
}
std::string	Contact::getDarkestSecret() const
{
	return _darkestSecret;
}
