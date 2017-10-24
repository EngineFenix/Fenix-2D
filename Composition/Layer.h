#ifndef LAYER_H_INCLUDED
#define LAYER_H_INCLUDED

#include <list>
#include "../Variables/Structures.h"
#include "../Objects/Objects.h"

#pragma once

namespace Composition {
    class Layer
    {
    private:
        std::string name;
        DVector relativePosition;
        bool visible;
    public:
        std::list<Objects::Shape> listOfShapes;
        std::list<Objects::Actor> listOfActors;

        Layer(std::string name);
        void show();
        void hide();
        void changePosition(int X, int Y);
        int returnRelPositionX();
        int returnRelPositionY();
        void addShape(Objects::Shape newShape);
        void addActor(Objects::Actor newActor);
        std::string returnName();
    };
};

#endif // LAYER_H_INCLUDED
