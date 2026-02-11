/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daafonso <daafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 12:35:41 by danielafons       #+#    #+#             */
/*   Updated: 2026/02/10 17:27:33 by daafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  BASE_HPP
#define BASE_HPP
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <ctime>

class Base {
    public:
        virtual ~Base(); // allow you to use dynamic_cast to identify the object's type
        static Base * generate(void);
        static void identify(Base* p);
        static void identify(Base& p);
};

class A: public Base {

};

class B: public Base {

};

class C: public Base {

};
#endif
