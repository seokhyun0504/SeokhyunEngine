#ifndef __MOUSEUPEVENT_H__
#define __MOUSEUPEVENT_H__

#include "MouseButtonEvent.h"

class MouseUpEvent : public MouseButtonEvent
{

public:

    MouseUpEvent(int button) : MouseButtonEvent(button) { }

    EventType getEventType() const override { return EventType::MouseUp; }
    std::string toString() const override { return "MouseUpEvent: " + std::to_string(m_button); }

};


#endif //__MOUSEUPEVENT_H__
