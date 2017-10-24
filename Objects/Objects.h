#ifndef OBJECTS_H_INCLUDED
#define OBJECTS_H_INCLUDED

#include "../Variables/Static_Variables.h"
#include "../Components/BindAction.h"

namespace Objects {
    class Object
    {
    public:
        DVector relativePosition;
        int returnRelPositionX()
        {
            return relativePosition.X;
        }

        int returnRelPositionY()
        {
            return relativePosition.Y;
        }
    };

    class Shape : public Object
    {
        // empty inside
    };

    class Point
    {
    private:
        double x;
        double y;

    public:
        Point()
        {
            x=0;
            y=0;
        }
        Point(double vX, double vY)
        {
            x=vX;
            y=vY;
        }

        double getX()
        {
            return x;
        }
        double getY()
        {
            return y;
        }
        std::string toString()
        {
            std::ostringstream tmp;
            tmp <<"(" << x << ";" << y<< ")";
            return tmp.str();
        }
        Point& operator+ (Point a)
        {
            Point tmp = *(new Point(x+a.getX(),y+a.getY()));
            return tmp;

        }
        void rotate(double angle)
        {
            angle = angle * M_PI;
            double old_x = x;
            x = x*cos(angle) + y*sin(angle);
            y = -old_x*sin(angle) + y*cos(angle);
        }
    };

    class Line {
        // empty inside
    };

    class Actor : public Object
    {
    private:
        std::string name;
        DVector startingPosition;
        int sizeWidth;
        int sizeHeight;
        bool player = false;
        bool staticPosition;
        BITMAP *bmp = NULL;
    public:
        Actor(int X, int Y)
        {
            this->startingPosition.X = this->relativePosition.X = X;
            this->startingPosition.Y = this->relativePosition.Y = Y;
            loadSprite();
        }

        void loadSprite(char name[] = "default.bmp")
        {
            this->bmp = load_bitmap(name, NULL);
            if( !bmp )
            {
                set_gfx_mode( GFX_TEXT, 0, 0, 0, 0 );
                allegro_message( "Nie można załadować obrazka '%s'!", name );
                allegro_exit();
            }
            this->sizeWidth = bmp->w;
            this->sizeHeight = bmp->h;
        }

        void tick(BITMAP *buffer, int time, int e){
            if(e == KEY_RIGHT){
                this->relativePosition.X = this->relativePosition.X + 3;
            }
            if(e == KEY_LEFT){
                this->relativePosition.X = this->relativePosition.X - 3;
            }
            masked_blit(bmp, buffer, 0, 0, this->relativePosition.X , this->relativePosition.Y, this->sizeWidth, this->sizeHeight); // MOZNA ZASTĄPIĆ : draw_sprite(screen, bmp, this->relativePositionX , this->relativePositionY);
        }

        void WOW()
        {
            std::cout<<"OK"<<std::endl;
        }

        void BindAction()
        {
            //Components::BindAction *ih = new Components::BindAction();
            //ih->BindKeyAction(KEY_PRESSED, WOW, KEY_UP);
        }
    };
};

#endif // OBJECTS_H_INCLUDED
