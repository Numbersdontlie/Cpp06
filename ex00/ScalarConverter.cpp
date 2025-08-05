/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luifer <luifer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 08:39:39 by luifer            #+#    #+#             */
/*   Updated: 2025/08/05 10:13:44 by luifer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

//interprets a string as a double (it discard any whitespace at the beginning and end of the string)
static double ft_stod(const std::string &str){
    char *end;
    double value = std::strtod(str.c_str(), &end);
    if (*end != '\0')
        throw std::invalid_argument("Invalid double");
    return (value);
}

//interprets a string as a float (it discard any whitespace at the beginning and end of the string)
float ft_stof(const std::string &str){
    return static_cast<float>(ft_stod(str));
}

//converter function it takes a string as parameter
// it interprets the string as a scalar type (char, int, float, double)
// and prints the corresponding values
void ScalarConverter::convert(const std::string &literal) {
    //Handle char literal: 'a'
    if(literal.size() == 3 && literal[0] == '\'' && literal[2] == '\'') {
        char c = literal[1];
        std::cout << "char: '" << c << "'\n";
        std::cout << "int: " << static_cast<int>(c) << "\n";
        std::cout << "float: " << static_cast<float>(c) << "f\n";
        std::cout << "double: " << static_cast<double>(c) << "\n";
        return;
    }
    //handle pseudoliterals
    if(literal == "nan" || literal == "+inf" || literal == "-inf"){
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: " << literal << "f\n";
        std::cout << "double: " << literal << "\n";
        return;
    }
    try {
        //detect float ending with f
        if(literal[literal.size() -1] == 'f'){
            float f = ft_stof(literal.substr(0, literal.size() - 1));
            if (std::isprint(static_cast<int>(f)))
                std::cout << "char: '" << static_cast<char>(f) << "'\n";
            else
                std::cout << "char: Non displayable\n";
            std::cout << "int: " <<static_cast<int>(f) << "\n";
            std::cout << "float: " << f << "f\n";
            std::cout << "double: " << static_cast<double>(f) << "\n";
        }
        else {
            //treat as double/int
            double d = ft_stod(literal);
            if(std::isprint(static_cast<int>(d)))
                std::cout << "char: '" << static_cast<char>(d) << "'\n";
            else
                std::cout << "char: Non displayable\n";
            std::cout << "int: " << static_cast<int>(d) << "\n";
            std::cout << "float: " << static_cast<float>(d) << "f\n";
            std::cout << "double: " << d << "\n";
        }
    }
    catch (std::exception &e){
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
    }
}

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    (void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}