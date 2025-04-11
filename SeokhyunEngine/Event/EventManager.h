#ifndef __EVENTMANAGER_H__
#define __EVENTMANAGER_H__

#include "EventDispatcher.h"
#include <mutex>

#include "Input/KeyBoard/KeyBoardEvent.h"
#include "Input/KeyBoard/KeyDownEvent.h"
#include "Input/KeyBoard/KeyUpEvent.h"
#include "Input/Mouse/MouseButtonEvent.h"
#include "Input/Mouse/MouseDownEvent.h"
#include "Input/Mouse/MouseUpEvent.h"
#include "Input/Mouse/MouseMoveEvent.h"
#include "Input/Mouse/MouseScrollEvent.h"

#include "Window/WindowMoveEvent.h"
#include "Window/WindowResizeEvent.h"
#include "Window/WindowFocusEvent.h"

#define addEvent(event, fn) Get()->subscribeEvent<event>(fn, this)
#define dispatch(event)     Get()->Dispatch(event)

class EventManager
{

private:

    EventDispatcher* m_dispatcher;
    static EventManager* m_instance;

    EventManager();
    ~EventManager();

    EventManager(const EventManager&) = delete;
    EventManager& operator = (const EventManager&) = delete;


public:

    static EventManager* Get();


    template<typename T>
    void subscribeEvent(std::function<void(T&)> callback) { m_dispatcher->subscribeEvent<T>(callback); }

    template<typename T, typename C>
    void subscribeEvent(void (C::*callback)(T&), C* instance) { m_dispatcher->subscribeEvent<T, C>(callback, instance); }

    void subscribeEvents(std::function<void(Event&)> callback);
    void Dispatch(Event& event);

};


#endif //__EVENTMANAGER_H__
