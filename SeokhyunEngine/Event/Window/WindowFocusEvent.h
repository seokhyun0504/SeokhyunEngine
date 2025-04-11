#ifndef __WINDOWFOCUSEVENT_H__
#define __WINDOWFOCUSEVENT_H__

#include "WindowStateEvent.h"

class WindowFocusEvent : public WindowStateEvent
{

public:

    WindowFocusEvent(bool focus) : WindowStateEvent(focus) { }

    bool isFocus() { return getState(); }

    EventType getEventType() const override { return EventType::WindowFocus; }
    std::string toString() const override { return "WindowFocus: " + std::to_string(m_state); }
};


#endif //SEOKHYUNENGINE_WINDOWFOCUSEVENT_H
