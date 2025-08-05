/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luifer <luifer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 01:13:56 by luifer            #+#    #+#             */
/*   Updated: 2025/08/06 01:22:06 by luifer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.hpp"
#include <iostream>

int main(){
    std::srand(std::time(NULL));

    for(int i = 0; i < 10; i++) {
        Base *obj = generate();

        std::cout << "Identify by pointer: ";
        identify(obj);

        std::cout << "Identify by reference: ";
        identify(*obj);

        delete obj;
        std::cout << "------" <<std::endl;
    }

    return 0;
}