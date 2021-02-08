#pragma once

#include <map>
#include <string>
#include <iostream>
#include "InputEvents.hpp"

class InputEventMap {
    private:
        static std::map<std::string, InputEvents> const inputMap;
    public:
        static const InputEvents GetEventForString(std::string str);
};