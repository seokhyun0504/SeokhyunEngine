#ifndef __KEYRELEASEDEVENT_H__
#define __KEYRELEASEDEVENT_H__

#include "Event/Event.h"
#include "KeyBoardEvent.h"

class KeyUpEvent : public KeyBoardEvent
{

public:

    KeyUpEvent(int key) : KeyBoardEvent(key) { }

    EventType getEventType() const override { return EventType::KeyUp; }
    std::string toString() const override { return "KeyUpEvent: " + std::to_string(m_keyCode); }
};


#endif //__KEYRELEASEDEVENT_H__
