/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 00:11:36 by asohrabi          #+#    #+#             */
/*   Updated: 2025/07/31 12:48:20 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "Serializer.hpp"
// #include <iostream>

// int	main()
// {
// 	// Create and initialize a Data object
// 	Data	original;

// 	original.id = 101;
// 	original.tag = 'Z';
// 	original.value = 42.42;

// 	// Serialize
// 	uintptr_t	raw = Serializer::serialize(&original);

// 	std::cout << "Serialized address: " << raw << std::endl;

// 	// Deserialize
// 	Data	*result = Serializer::deserialize(raw);

// 	std::cout << "Deserialized data:" << std::endl;
// 	std::cout << "ID: " << result->id << std::endl;
// 	std::cout << "Tag: " << result->tag << std::endl;
// 	std::cout << "Value: " << result->value << std::endl;

// 	// Validate pointer integrity
// 	if (result == &original)
// 		std::cout << "✅ Pointers match!" << std::endl;
// 	else
// 		std::cout << "❌ Pointers do not match!" << std::endl;

// 	return 0;
// }

#include "Serializer.hpp"
#include <iostream>

void	printData(const Data* data, const std::string &label)
{
	if (!data)
	{
		std::cout << label << " is nullptr" << std::endl;
		return;
	}

	std::cout << label << ":" << std::endl;
	std::cout << "  ID:    " << data->id << std::endl;
	std::cout << "  Tag:   " << data->tag << std::endl;
	std::cout << "  Value: " << data->value << std::endl;
}

void	checkPointerMatch(const Data *original, const Data *result)
{
    if (original == result)
        std::cout << "✅ Pointers match" << std::endl;
    else
        std::cout << "❌ Pointers do not match" << std::endl;
}

int	main()
{
	std::cout << "🧪 Test 1: Normal serialization/deserialization" << std::endl;
	
	Data		original = {101, 'Z', 42.42};
	uintptr_t	raw = Serializer::serialize(&original);
	Data		*result = Serializer::deserialize(raw);

	std::cout << "Serialized address: " << raw << std::endl;
	printData(result, "Deserialized data");
	checkPointerMatch(&original, result);

	std::cout << std::endl << "🧪 Test 2: Serialize original, but deserialize different object" << std::endl;

    Data		another = {202, 'X', 99.99};
    uintptr_t	rawAnother = Serializer::serialize(&another);
    Data		*resultAnother = Serializer::deserialize(rawAnother);

	std::cout << "Serialized address: " << rawAnother << std::endl;
    printData(resultAnother, "Deserialized data");
	checkPointerMatch(&another, resultAnother); // Should be okay

	std::cout << std::endl << "⚠️  Checking 'original' pointer match with 'another' deserialized result:" << std::endl;
    checkPointerMatch(&original, resultAnother); // Should not match

	std::cout << std::endl << "🧪 Test 3: Serialize nullptr" << std::endl;
	
	Data		*nullPtr = nullptr;
	uintptr_t	nullRaw = Serializer::serialize(nullPtr);
	
	std::cout << "Serialized address: " << nullRaw << std::endl;

	Data	*deserializedNull = Serializer::deserialize(nullRaw);
	
	printData(deserializedNull, "Deserialized from nullptr");

	return 0;
}
