#ifndef Engine_H
#define Engine_H

volatile long speed = 0;

void increment_speed()
{
    speed++;
}
END_OF_FUNCTION( increment_speed );

LOCK_VARIABLE( speed );
LOCK_FUNCTION( increment_speed );

class GraphicEngine{
private:
    std::map<std::string, int> config;
    std::string gameTitle;
    std::list<Composition::Scene> listOfScenes;
    BindAction BindAction();
public:
    GraphicEngine(int width, int height, std::string title){
        config["width"] = width;
        config["height"] = height;
        this->gameTitle = title;
    }

    void initEngine(std::map<std::string, bool> installModule)
    {
        allegro_init();
        if(installModule["keyboard"]) install_keyboard();
        if(installModule["mouse"]) install_mouse();
        install_timer();
        install_int_ex( increment_speed,  BPS_TO_TIMER( 100 ) );
    }

    void BindAllActions()
    {
        for (std::list<Composition::Scene>::iterator sceneIt = listOfScenes.begin(); sceneIt != listOfScenes.end(); ++sceneIt )
        {
            for (std::list<Composition::Layer>::iterator layerIt = sceneIt->listOfLayers.begin(); layerIt != sceneIt->listOfLayers.end(); ++layerIt )
            {
                for (std::list<Objects::Actor>::iterator actorIt = layerIt->listOfActors.begin(); actorIt != layerIt->listOfActors.end(); ++actorIt )
                {

                }
            }
        }
    }

    void runApplication(std::string StartScene)
    {
        BindAllActions();

        int val = 0;
        BITMAP *buffer = create_bitmap(SCREEN_W, SCREEN_H);
        while( this->returnSpeed() > 0 || !key[ KEY_ESC ])
        {
            while (!keypressed()) {
                for (std::list<Composition::Scene>::iterator sceneIt = listOfScenes.begin(); sceneIt != listOfScenes.end(); ++sceneIt )
                {
                    if((sceneIt->returnName() == StartScene && StartScene != "/") || (sceneIt->returnVisibleStatus() && StartScene == "/")){
                        void (*pfnWskaznik)();
                        clear_bitmap(buffer);
                        int SceneBackgroundColor = sceneIt->returnBackgroundColor();
                        clear_to_color(buffer, SceneBackgroundColor);
                        for (std::list<Composition::Layer>::iterator layerIt = sceneIt->listOfLayers.begin(); layerIt != sceneIt->listOfLayers.end(); ++layerIt )
                        {
                            for (std::list<Objects::Actor>::iterator actorIt = layerIt->listOfActors.begin(); actorIt != layerIt->listOfActors.end(); ++actorIt )
                            {
                                actorIt->tick(buffer, this->returnSpeed(), (val >> 8));
                            }
                        }
                        blit( buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
                        val = 0;
                        break;
                    }
                }
            }
            val = readkey();
            if((val >> 8) == KEY_ESC) break;
            if((val >> 8) == KEY_D) {
                StartScene = "/";
                SetSceneActive("platform_2");
            }
            this->setSpeed(this->returnSpeed() - 1);
        }
    }

    void createWindow()
    {
        set_color_depth(32);
        set_gfx_mode(GFX_SAFE, config["width"], config["height"], 0, 0);
        set_window_title(this->gameTitle.c_str());
    }

    void setSceneColor(std::string scene, Palette::Color *newColor)
    {
        for (std::list<Composition::Scene>::iterator sceneIt = listOfScenes.begin(); sceneIt != listOfScenes.end(); ++sceneIt )
        {
            if(sceneIt->returnName() == scene){
                sceneIt->setBackgroundColor(newColor);
            }
        }
    }

    volatile long returnSpeed()
    {
        return speed;
    }

    volatile long setSpeed(int value)
    {
        speed = value;
    }

    void addScene(std::string newScene, Palette::Color *newColor, bool active = false)
    {
        listOfScenes.push_front(Composition::Scene(newScene, newColor, active));
    }

    void addLayerToScene(std::string scene, std::string newLayer)
    {
        for (std::list<Composition::Scene>::iterator sceneIt = listOfScenes.begin(); sceneIt != listOfScenes.end(); ++sceneIt )
        {
            if(sceneIt->returnName() == scene){
                sceneIt->addLayer(Composition::Layer(newLayer));
            }
        }
    }

    void addActorToLayer(std::string scene, std::string layer, Objects::Actor newActor)
    {
        for (std::list<Composition::Scene>::iterator sceneIt = listOfScenes.begin(); sceneIt != listOfScenes.end(); ++sceneIt )
        {
            if(sceneIt->returnName() == scene){
                for (std::list<Composition::Layer>::iterator layerIt = sceneIt->listOfLayers.begin(); layerIt != sceneIt->listOfLayers.end(); ++layerIt )
                {
                    if(layerIt->returnName() == layer){
                        layerIt->addActor(newActor);
                    }
                    break;
                }
                break;
            }
        }
    }

    void SetSceneActive(std::string scene)
    {
        for (std::list<Composition::Scene>::iterator sceneIt = listOfScenes.begin(); sceneIt != listOfScenes.end(); ++sceneIt )
        {
            if(sceneIt->returnName() == scene){
                sceneIt->ShowScene();
            } else {
                sceneIt->HideScene();
            }
        }
    }

    ~GraphicEngine()
    {
        remove_int( increment_speed );
        allegro_exit(); // zwolnienie zasobów biblioteki
    }
};

#endif // Engine_H
