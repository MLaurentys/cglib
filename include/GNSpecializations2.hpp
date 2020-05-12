#ifndef _GNSPECIALIZATION_H
#define _GNSPECIALIZATION_H

#include <vector>
#include <variant>
#include <any>
#include <iostream>

#include "definitions.h"


template <GNRepresentation repr> class GNSpecialized {};

template <>
class GNSpecialized <GNRepresentation::sets> {
    public:
        GNSpecialized () {left = {}; right = {};}
        GNSpecialized (const std::vector<GNSpecialized *>& l,
                const std::vector<GNSpecialized *>& r) {
            left = l;
            right = r;
        } 

        float to_float() {
            return 0;
        }
    private:
        std::vector<GNSpecialized *> left;
        std::vector<GNSpecialized *> right;
};

template <>
class GNSpecialized <GNRepresentation::integer> {
    public:
        GNSpecialized () {n = 0;}
        GNSpecialized (int m) {n = m;}

        float to_float () {
            std::cout << "int to float: " << float(n) << "\n";
            return (float)n;
        }

        void print_n() {std::cout << "n = " << n << "\n";}
    private:
        int n;
};

template <>
class GNSpecialized <GNRepresentation::real> {
    public:
        GNSpecialized () {n = 0;}
        GNSpecialized (float m) {n = m;}

        float to_float () {return n;}
    private:
        float n;
};

#endif