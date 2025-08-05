/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luifer <luifer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:11:00 by luifer            #+#    #+#             */
/*   Updated: 2025/08/06 00:45:00 by luifer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main(){
    Data myData;
    myData.id = 42;
    myData.name = "Test object";
    myData.value = 3.14159;

    std::cout << "Original pointer: " << &myData << std::endl;

    //Serialize it
    uintptr_t raw = Serializer::serialize(&myData);
    std::cout << "Serialized int(dec): " << raw << std::endl;
    std::cout << "Serialized int(hex): 0x " << std::hex << raw << std::dec << std::endl;

    //compare with pointer
    std::cout << "Pointer as int (hex): 0x " << std::hex << reinterpret_cast<uintptr_t>(&myData) << std::dec << std::endl;

    //Deserialize it
    Data *ptr = Serializer::deserialize(raw);
    std::cout << "Deserialized pointer: " << ptr << std::endl;

    //verify if they match
    if(ptr == &myData){
        std::cout << "Pointers match!" << std::endl;
        std::cout << "Data id: " << ptr->id << ", name: " << ptr->name << ", value: " << ptr->value << std::endl;
    }
    else
        std::cout << "Pointers do not match!" << std::endl;
    return 0;
}