#ifndef SCENE_H_INCLUDED
#define SCENE_H_INCLUDED

#include "../Variables/Structures.h"
#include "../Palette/Color.h"
#include "../Composition/Layer.h"
#include <list>

#pragma once

namespace Composition {
    class Scene
    {
    private:
        std::string name;
        bool visible;
        Palette::Color *backgroundColor;
    public:
        std::list<Composition::Layer> listOfLayers;

        Scene(std::string name, Palette::Color *NewBackgroundColor, bool visible);
        void setBackgroundColor(Palette::Color *newColor);
        int returnBackgroundColor();
        void addLayer(Layer newLayer);
        void drawScene();
        void HideScene();
        void ShowScene();
        bool returnVisibleStatus();
        std::string returnName();
    };
};


#endif // SCENE_H_INCLUDED
