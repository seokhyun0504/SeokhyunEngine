#ifndef __KEYPRESSEDEVENT_H__
#define __KEYPRESSEDEVENT_H__

#include "Event/Event.h"
#include "KeyBoardEvent.h"

class KeyDownEvent : public KeyBoardEvent
{

public:

    KeyDownEvent(int key) : KeyBoardEvent(key) { }

    EventType getEventType() const override { return EventType::KeyDown; }
    std::string toString() const override { return "KeyDownEvent: " + std::to_string(m_keyCode); }
};


#endif //__KEYPRESSEDEVENT_H__
