#include "../BasicClasses.h"
#include "../Composition/Layer.h"

namespace Composition {
    Layer::Layer(std::string name)
    {
        this->name = name;
    }

    void Layer::show()
    {
        this->visible = true;
    }

    void Layer::hide()
    {
        this->visible = false;
    }

    void Layer::changePosition(int X, int Y)
    {
        this->relativePosition.X = X;
        this->relativePosition.Y = Y;
    }

    int Layer::returnRelPositionX()
    {
        return relativePosition.X;
    }

    int Layer::returnRelPositionY()
    {
        return relativePosition.Y;
    }

    void Layer::addShape(Objects::Shape newShape)
    {
        listOfShapes.push_front(newShape);
    }

    void Layer::addActor(Objects::Actor newActor)
    {
        listOfActors.push_front(newActor);
    }

    std::string Layer::returnName()
    {
        return name;
    }
};
