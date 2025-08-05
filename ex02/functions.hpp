/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luifer <luifer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 01:01:26 by luifer            #+#    #+#             */
/*   Updated: 2025/08/06 01:03:01 by luifer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_HPP
# define FUNCTIONS_HPP

#include "Base.hpp"
#include <cstdlib>
#include <ctime>

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif