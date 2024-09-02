/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:35:58 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/02 18:16:06 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() : first_name(""), last_name(""), nickname(""),
						phone_number(""), darkest_secret("") {}

Contact::Contact(std::string fn, std::string ln, std::string nn,
					std::string pn, std::string ds)
				: first_name(fn), last_name(ln), nickname(nn),
					phone_number(pn), darkest_secret(ds) {}

Contact::~Contact() {}

std::string Contact::get_first_name() const
{
	return first_name;
}
std::string Contact::get_last_name() const
{
	return last_name;
}
std::string Contact::get_nickname() const
{
	return nickname;
}
std::string Contact::get_phone_number() const
{
	return phone_number;
}
std::string Contact::get_darkest_secret() const
{
	return darkest_secret;
}
