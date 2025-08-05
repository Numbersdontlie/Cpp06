/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luifer <luifer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 10:18:01 by luifer            #+#    #+#             */
/*   Updated: 2025/08/05 10:37:45 by luifer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
    if(argc != 2){
        std::cerr << "Usage: .scalarconvert <literal>\n" << std::endl;
        return 1; 
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}
