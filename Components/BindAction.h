#ifndef BINDACTION_H_INCLUDED
#define BINDACTION_H_INCLUDED

#include "../Variables/Structures.h"
#include "../Objects/Objects.h"

#pragma once

struct KeyAction
{
    int Action; // 0 - click, 1 - relased
    void (*Function)();
    int Key;
};

struct MouseAction
{
    int Action;
    void (*Function)();
    int Type; // 0 - lewy klawisz, 1 - prawy klawisz, 2 - scroll w dó³, 3 - scroll w góre
};

class BindAction
{
private:
    KeyAction KeyActionsArray[];
    MouseAction MouseActionsArray[];
public:
    BindAction();
    void BindKeyAction(int Action, void (*Function)(), int KeyNumber);
    void BindMouseAction(int Action, void (*Function)(), int Type);
    void ok();
};

#endif // BINDACTION_H_INCLUDED
