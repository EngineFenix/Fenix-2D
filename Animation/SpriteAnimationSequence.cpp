#include "../BasicClasses.h"
#include "../Animation/SpriteAnimationSequence.h"

Animation::SpriteAnimationSequence::SpriteAnimationSequence()
{
    // empty inside
}

void Animation::SpriteAnimationSequence::AddNewFrame(std::string Action, std::string SRC)
{
    int SequenceLenght = sizeof(FrameSequence);
    SpriteAnimationFrame NewFrame;
    NewFrame.Action = Action;
    int FindLastIndexAction = Animation::SpriteAnimationSequence::FindLastIndex(Action);
    if(FindLastIndexAction == -1) NewFrame.ID = 0;
    else {
        NewFrame.ID = FindLastIndexAction + 1;
    }
    NewFrame.FrameSpriteSRC = SRC;
    FrameSequence.push_back(NewFrame);
}

SpriteAnimationFrame Animation::SpriteAnimationSequence::ReturnFrameOnIndex(int Index)
{
    for (std::list<SpriteAnimationFrame>::iterator FrameSequenceIT = FrameSequence.begin(); FrameSequenceIT != FrameSequence.end(); ++FrameSequenceIT )
    {
        if(FrameSequenceIT->ID == Index)
        {
            return *FrameSequenceIT;
        }
    }
}

int Animation::SpriteAnimationSequence::FindLastIndex(std::string Action)
{
    int LastIndex = -1;
    for (std::list<SpriteAnimationFrame>::iterator FrameSequenceIT = FrameSequence.begin(); FrameSequenceIT != FrameSequence.end(); ++FrameSequenceIT )
    {
        if(FrameSequenceIT->Action == Action)
        {
            LastIndex = FrameSequenceIT->ID;
        }
    }
    return LastIndex;
}

void Animation::SpriteAnimationSequence::ViewSequence()
{
    for (std::list<SpriteAnimationFrame>::iterator FrameSequenceIT = FrameSequence.begin(); FrameSequenceIT != FrameSequence.end(); ++FrameSequenceIT )
    {
        std::cout<<FrameSequenceIT->ID<<", "<<FrameSequenceIT->Action<<", "<<FrameSequenceIT->FrameSpriteSRC<<std::endl;
    }
}
