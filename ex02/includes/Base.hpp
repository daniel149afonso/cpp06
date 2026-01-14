/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielafonso <danielafonso@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 12:35:41 by danielafons       #+#    #+#             */
/*   Updated: 2026/01/14 17:16:53 by danielafons      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  BASE_HPP
#define BASE_HPP
#include <iostream>
#include <cstdlib>
#include <unistd.h>

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