#ifndef __EVENT_H__
#define __EVENT_H__

#include <iostream>
#include <ostream>

enum class EventType
{
    None = 0,
    KeyUp, KeyDown,
    MouseUp, MouseDown, MouseScroll, MouseMove,
    WindowResize, WindowMove, WindowFocus
};


class Event
{

private:

    bool m_handled = false;


public:

    virtual ~Event() = default;

    virtual EventType getEventType() const = 0;
    virtual std::string toString() const { return "Event"; }

    friend std::ostream& operator << (std::ostream& os, const Event& e) { os << e.toString(); return os; }

};

#endif //__EVENT_H__
