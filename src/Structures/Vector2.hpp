#pragma once
#include <iostream>

template <typename PointerType> class Vector2 {
    public:
        PointerType *x, *y;

        Vector2(PointerType *x, PointerType *y) {
            this->x = new PointerType(*x);
            this->y = new PointerType(*y);
        }
};