#pragma once

template <typename PointerType> class Vector2 {
    public:
        PointerType *x, *y;

        Vector2(PointerType *x, PointerType *y) {
            this->x = x;
            this->y = y;
        }
};