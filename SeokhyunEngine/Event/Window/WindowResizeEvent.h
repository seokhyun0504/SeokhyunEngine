#ifndef __WINDOWRESIZEEVENT_H__
#define __WINDOWRESIZEEVENT_H__

#include "Event/Event.h"

class WindowResizeEvent : public Event
{

private:

    int m_width, m_height;


public:

    WindowResizeEvent(int w, int h) : m_width(w), m_height(h) { }

    int getWidth()  { return m_width;  }
    int getHeight() { return m_height; }

    EventType getEventType() const override { return EventType::WindowResize; }
    std::string toString() const override { return "WindowResizeEvent: " + std::to_string(m_width) + ", " + std::to_string(m_height); }
};


#endif //__WINDOWRESIZEEVENT_H__
