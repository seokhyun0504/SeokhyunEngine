#include "EventDispatcher.h"

void EventDispatcher::subscribeEvents(std::function<void(Event &)> callback)
{
    m_GenericCallbacks.push_back(callback);
}

void EventDispatcher::Dispatch(Event &e)
{
    auto it = m_Callbacks.find(std::type_index(typeid(e)));
    if (it != m_Callbacks.end())
    {
        for (auto& callback : it->second)
        {
            callback(e);
        }
    }
    for (auto& generic : m_GenericCallbacks)
    {
        generic(e);
    }
}
