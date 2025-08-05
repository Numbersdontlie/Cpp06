/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luifer <luifer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 01:03:15 by luifer            #+#    #+#             */
/*   Updated: 2025/08/06 01:12:26 by luifer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <stdexcept>

Base *generate(void) {
    int r = std::rand() % 3;
    if(r == 0){
        std::cout << "[generate] Created A" << std::endl;
        return new A();
    }
    else if(r == 1){
        std::cout << "[generate] Created B" << std::endl;
        return new B();
    }
    else {
        std::cout << "[generate] Created C" << std::endl;
        return new C();
    }
}

void identify(Base *p){
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        throw std::runtime_error("Unknown type"); 
}

void identify(Base &p){
    try{
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (std::bad_cast&) {}

    try{
        (void)dynamic_cast<B&>(P);
        std::cout << "B" << std::endl;
        return;
    } catch (std::bad_cast&) {}

    try{
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (std::bad_cast&) {}

    std::cout << "Unknown type" << std::endl;
}