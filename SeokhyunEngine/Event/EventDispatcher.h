#ifndef __EVENTDISPATCHER_H__
#define __EVENTDISPATCHER_H__

#include "Event.h"

#include <functional>
#include <vector>
#include <unordered_map>
#include <typeindex>


class EventDispatcher
{

private:

    using EventFn = std::function<void(Event&)>;

    std::unordered_map<std::type_index, std::vector<EventFn>> m_Callbacks;
    std::vector<EventFn> m_GenericCallbacks;


public:

    template<typename T, typename C>
    void subscribeEvent(void (C::*callback)(T&), C* instance)
    {
        auto wrapper = [callback, instance](Event& event)
        {
            (instance->*callback)(static_cast<T&>(event));
        };

        m_Callbacks[std::type_index(typeid(T))].push_back(wrapper);
    }

    template<typename T>
    void subscribeEvent(void(*callback)(const T&))
    {
        auto wrapper = [callback](Event& event)
        {
            callback(static_cast<const T&>(event));
        };

        m_Callbacks[std::type_index(typeid(T))].push_back(wrapper);
    }

    void subscribeEvents(EventFn callback);
    void Dispatch(Event& e);

};




#endif //__EVENTDISPATCHER_H__
