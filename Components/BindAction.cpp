#include "../BasicClasses.h"
#include "BindAction.h"

BindAction::BindAction()
{
    // empty inside
}
void BindAction::BindKeyAction(int Action, void (*Function)(), int KeyNumber)
{
    KeyAction NewKeyAction;
    NewKeyAction.Action = Action;
    //NewKeyAction.Function = Function;
    NewKeyAction.Key = KeyNumber;
    KeyActionsArray [sizeof(KeyActionsArray) + 1] = NewKeyAction;
}
void BindAction::ok()
{

}
