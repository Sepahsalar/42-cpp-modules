/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:35:58 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/02 16:47:48 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

Contact::Contact(std::string fn, std::string ln,
	std::string nn, std::string pn, std::string ds)
    			: first_name(fn), last_name(ln),
		nickname(nn), phone_number(pn), darkest_secret(ds) {}

Contact::~Contact() {}
