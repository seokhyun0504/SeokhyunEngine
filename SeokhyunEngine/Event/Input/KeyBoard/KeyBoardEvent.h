#ifndef __KEYEVENT_H__
#define __KEYEVENT_H__

#include "Event/Event.h"

class KeyBoardEvent : public Event
{

protected:

    int m_keyCode;

    KeyBoardEvent(int key) : m_keyCode(key) { }


public:

    int getKeyCode() { return m_keyCode; }

};


#endif //__KEYEVENT_H__
