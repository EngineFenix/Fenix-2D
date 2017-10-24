#ifndef SPRITEANIMATIONSEQUENCE_H_INCLUDED
#define SPRITEANIMATIONSEQUENCE_H_INCLUDED

#include <list>

#pragma once

struct SpriteAnimationFrame
{
    int ID;
    std::string Action;
    std::string FrameSpriteSRC;
   // int NextFrameID;
};

namespace Animation {
    class SpriteAnimationSequence
    {
    private:
        std::list<SpriteAnimationFrame> FrameSequence;
    public:
        SpriteAnimationSequence();
        void AddNewFrame(std::string Action, std::string SRC);
        SpriteAnimationFrame ReturnFrameOnIndex(int Index);
        int FindLastIndex(std::string Action);
        void ViewSequence();
    };
};

#endif // SPRITEANIMATIONSEQUENCE_H_INCLUDED
