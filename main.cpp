#include <iostream>
#include <allegro.h>
#include <winalleg.h>
#include <map>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <sstream>
#include <cmath>
#include <exception>

#include "Variables/Structures.h"
#include "Variables/Static_Variables.h"
#include "Palette/Color.h"
#include "Components/BindAction.h"
#include "Objects/Objects.h"
#include "Composition/Scene.h"
#include "Composition/Layer.h"
#include "Engine/Engine.h"
#include "Animation/Animation.h"
#include "Animation/SpriteAnimationSequence.h"

using namespace Palette;
using namespace Objects;
using namespace Composition;
using namespace Animation;

using namespace std;

int main()
{
    map<string, bool> modules;

    GraphicEngine *engine = new GraphicEngine(640,480, "Testowa gra");

    modules["keyboard"] = true;
    modules["mouse"] = true;
    engine->initEngine(modules);

    engine->createWindow();

    engine->addScene("platform_1", new Color("#82a03c"));
    engine->setSceneColor("platform_1", new Color("254761"));
    engine->addScene("platform_2", new Color("red"));
    engine->addScene("platform_3", new Color("red"));

    engine->addLayerToScene("platform_1", "layer_1");
    engine->addLayerToScene("platform_1", "layer_2");

    engine->addActorToLayer("platform_1", "layer_2", Actor(0,0));

    Animation::SpriteAnimationSequence NewSequence;
    NewSequence.AddNewFrame("Jump", "okej.png");
    NewSequence.AddNewFrame("MoveRight", "okej.png");
    NewSequence.AddNewFrame("Jump", "okej.png");
    NewSequence.AddNewFrame("Lot", "okej.png");
    NewSequence.AddNewFrame("MoveRight", "okej.png");
    NewSequence.AddNewFrame("MoveRight", "okej.png");
    NewSequence.AddNewFrame("MoveRight", "okej.png");
    NewSequence.AddNewFrame("MoveRight", "okej.png");
    NewSequence.AddNewFrame("MoveRight", "okej.png");
    NewSequence.AddNewFrame("MoveLeft", "okej.png");
    NewSequence.AddNewFrame("MoveLeft", "okej.png");
    NewSequence.AddNewFrame("MoveLeft", "okej.png");
    NewSequence.AddNewFrame("MoveLeft", "okej.png");`
    NewSequence.ViewSequence();

    engine->runApplication("platform_1");

    delete engine;

    return 0;

}
END_OF_MAIN()
