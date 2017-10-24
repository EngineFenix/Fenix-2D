#include "../BasicClasses.h"
#include "../Composition/Layer.h"
#include "../Composition/Scene.h"

namespace Composition {
    Scene::Scene(std::string name, Palette::Color *NewBackgroundColor, bool visible)
    {
        this->name = name;
        this->visible = visible;
        this->backgroundColor = NewBackgroundColor;
    }

    void Scene::setBackgroundColor(Palette::Color *newColor)
    {
        this->backgroundColor = newColor;
    }

    int Scene::returnBackgroundColor()
    {
        return this->backgroundColor->returnColor();
    }

    void Scene::HideScene()
    {
        this->visible = false;
    }

    void Scene::ShowScene()
    {
        this->visible = true;
    }

    void Scene::addLayer(Layer newLayer)
    {
        listOfLayers.push_front(newLayer);
    }

    void Scene::drawScene()
    {
        for (std::list<Layer>::iterator layerIt = listOfLayers.begin(); layerIt != listOfLayers.end(); ++layerIt )
        {
            for (std::list<Objects::Shape>::iterator shapeIt = layerIt->listOfShapes.begin(); shapeIt != layerIt->listOfShapes.end(); ++shapeIt )
            {
            }
        }
    }

    bool Scene::returnVisibleStatus()
    {
        return visible;
    }

    std::string Scene::returnName()
    {
        return name;
    }
};
