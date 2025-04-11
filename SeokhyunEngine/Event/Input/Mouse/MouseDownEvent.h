#ifndef __MOUSEDOWNEVENT_H__
#define __MOUSEDOWNEVENT_H__

#include "MouseButtonEvent.h"

class MouseDownEvent : public MouseButtonEvent
{

public:

    MouseDownEvent(int button) : MouseButtonEvent(button) { }

    EventType getEventType() const override { return EventType::MouseDown; }
    std::string toString() const override { return "MouseDownEvent: " + std::to_string(m_button); }

};


#endif //__MOUSEDOWNEVENT_H__
