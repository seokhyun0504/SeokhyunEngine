#ifndef __MOUSEBUTTONEVENT_H__
#define __MOUSEBUTTONEVENT_H__

#include "Event/Event.h"

class MouseButtonEvent : public Event
{

protected:

    int m_button;

    MouseButtonEvent(int button) : m_button(button) { }

public:

    int getButton() { return m_button; }

};


#endif //__MOUSEBUTTONEVENT_H__
