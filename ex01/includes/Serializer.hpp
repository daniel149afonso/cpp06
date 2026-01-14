/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielafonso <danielafonso@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 10:25:37 by danielafons       #+#    #+#             */
/*   Updated: 2026/01/13 19:49:41 by danielafons      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  SERIALIZER_HPP
#define SERIALIZER_HPP
#include <iostream>
#include <stdint.h>

struct Data;

class Serializer {

    private:
        Serializer();
        Serializer(const Serializer&);
        Serializer& operator=(const Serializer&);
        ~Serializer();
    
    public:
        static uintptr_t serialize(Data *ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif