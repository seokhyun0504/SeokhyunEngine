#ifndef __MOUSEMOVEEVENT_H__
#define __MOUSEMOVEEVENT_H__

#include "Event/Event.h"

class MouseMoveEvent : public Event
{

private:

    float m_xPos, m_yPos;


public:

    MouseMoveEvent(float xpos, float ypos) : m_xPos(xpos), m_yPos(ypos) { }

    float getX() { return m_xPos; }
    float getY() { return m_yPos; }

    EventType getEventType() const override { return EventType::MouseMove; }
    std::string toString() const override { return "MouseMoveEvent: " + std::to_string(m_xPos) + ", " + std::to_string(m_yPos); }

};


#endif //__MOUSEMOVEEVENT_H__
