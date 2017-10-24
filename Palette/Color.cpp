#include "../BasicClasses.h"
#include "Color.h"

namespace Palette {
    Color::Color(int r, int g, int b)
    {
        try
        {
            if(r>255 or g > 255 or b > 255)
                throw 1;
            if(r<0 or g < 0 or b<0)
                throw 2;
            ColorRGB.R = r;
            ColorRGB.G = g;
            ColorRGB.B = b;
        }
        catch(int ex)
        {
            switch (ex)
            {
                case 1:
                    std::cout << ex << ". Incorect Color Value(over 255)";
                    break;
                case 2:
                    std::cout << ex << ". Incorect Color Value(negative)";
                    break;
            }
        }
    }

    Color::Color(double r, double g, double b)
    {
        try
        {
            if(r>1 or g > 1 or b > 1)
                throw 1;
            if(r<0 or g < 0 or b<0)
                throw 2;
            ColorRGB.R = floor(255 * r);
            ColorRGB.G = floor(255 * g);
            ColorRGB.B = floor(255 * b);

        }
        catch(int ex)
        {
            switch (ex)
            {
                case 1:
                    std::cout << ex << ". Incorect Color Value(over 255)";
                    break;
                case 2:
                    std::cout << ex << ". Incorect Color Value(negative)";
                    break;
            }

        }
    }

    Color::Color(std::string color)
    {
        try
        {
            if(color == "red"){
                ColorRGB.R = 255;
                ColorRGB.G = 0;
                ColorRGB.B = 0;
            } else if(color == "yellow"){
                ColorRGB.R = 255;
                ColorRGB.G = 255;
                ColorRGB.B = 0;
            } else if(color == "blue"){
                ColorRGB.R = 0;
                ColorRGB.G = 0;
                ColorRGB.B = 255;
            } else if(color == "black"){
                ColorRGB.R = 0;
                ColorRGB.G = 0;
                ColorRGB.B = 0;
            } else if(color == "white"){
                ColorRGB.R = 255;
                ColorRGB.G = 255;
                ColorRGB.B = 255;
            } else if(color == "green"){
                ColorRGB.R = 0;
                ColorRGB.G = 255;
                ColorRGB.B = 0;
            } else if(color == "purple"){
                ColorRGB.R = 153;
                ColorRGB.G = 51;
                ColorRGB.B = 255;
            } else if(color == "pink"){
                ColorRGB.R = 255;
                ColorRGB.G = 51;
                ColorRGB.B = 255;
            } else if(color == "orange"){
                ColorRGB.R = 255;
                ColorRGB.G = 153;
                ColorRGB.B = 51;
            } else {
                if(color[0] == '#') {
                    color = color.substr(1,6);
                }

                const char *r = color.substr(0,2).c_str();
                const char *g = color.substr(2,2).c_str();
                const char *b = color.substr(4,2).c_str();
                char * pEnd;

                ColorRGB.R = strtol (r,&pEnd,16);
                ColorRGB.G = strtol (g,&pEnd,16);
                ColorRGB.B = strtol (b,&pEnd,16);
            }

        }
        catch(int ex)
        {
            switch (ex)
            {
                case 0:
                    std::cout << ex << ". Incorect Color Value(over 255)";
                    break;
            }

        }
    }

    void Color::darker(double percent){
        percent=1-percent;
        ColorRGB.R = (ColorRGB.R*percent >=0 ? ColorRGB.R*percent : 0) ;
        ColorRGB.G = (ColorRGB.G*percent >=0 ? ColorRGB.G*percent : 0) ;
        ColorRGB.B = (ColorRGB.B*percent >= 0 ? ColorRGB.B*percent : 0) ;
    }

    void Color::lighten(double percent){
        percent=1+percent;
        ColorRGB.R = (ColorRGB.R*percent <= 255 ? ColorRGB.R*percent : 255) ;
        ColorRGB.G = (ColorRGB.G*percent <= 255 ? ColorRGB.G*percent : 255) ;
        ColorRGB.B = (ColorRGB.B*percent <= 255 ? ColorRGB.B*percent : 255) ;
    }

    int Color::returnColor()
    {
        return  makecol(ColorRGB.R, ColorRGB.G, ColorRGB.B);
    }
};
