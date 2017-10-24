#ifndef COLOR__H_INCLUDED
#define COLOR__H_INCLUDED

#include "../Variables/Structures.h"

#pragma once

struct ColVector
{
    int R;
    int G;
    int B;
};

namespace Palette {
    class Color
    {
    private:
    public:
        ColVector ColorRGB;
        Color(int r, int g, int b);
        Color(double r, double g, double b);
        Color(std::string color);
        void darker(double percent);
        void lighten(double percent);
        int returnColor();
    };
}

#endif // COLOR__H_INCLUDED
