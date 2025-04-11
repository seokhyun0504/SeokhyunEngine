#ifndef __MOUSESCROLLEVENT_H__
#define __MOUSESCROLLEVENT_H__

#include "Event/Event.h"

class MouseScrollEvent : public Event
{

private:

    float m_xOffset, m_yOffset;


public:

    MouseScrollEvent(float xoffset, float yoffset) : m_xOffset(xoffset), m_yOffset(yoffset) { }

    float getxOffset() { return m_xOffset; }
    float getyOffset() { return m_yOffset; }

    EventType getEventType() const override { return EventType::MouseScroll; }
    std::string toString() const override { return "MouseScrollEvent: " + std::to_string(m_xOffset) + ", " + std::to_string(m_yOffset); }
};


#endif //__MOUSESCROLLEVENT_H__
