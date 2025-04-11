#ifndef __WINDOWMOVEEVENT_H__
#define __WINDOWMOVEEVENT_H__

#include "Event/Event.h"

class WindowMoveEvent : public Event
{

private:

    int m_xPos, m_yPos;


public:

    WindowMoveEvent(int x, int y) : m_xPos(x), m_yPos(y) { }

    int getX() { return m_xPos; }
    int getY() { return m_yPos; }

    EventType getEventType() const override { return EventType::WindowResize; }
    std::string toString() const override { return "WindowMoveEvent: " + std::to_string(m_xPos) + ", " + std::to_string(m_yPos); }

};


#endif //__WINDOWMOVEEVENT_H__
