#ifndef __WINDOWSTATEEVENT_H__
#define __WINDOWSTATEEVENT_H__

#include "Event/Event.h"

class WindowStateEvent : public Event
{

protected:

    bool m_state;

    WindowStateEvent(bool state) : m_state(state) { }


public:

    bool getState() { return m_state; }
};


#endif //SEOKHYUNENGINE_WINDOWSTATEEVENT_H
