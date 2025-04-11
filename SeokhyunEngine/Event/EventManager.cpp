#include "EventManager.h"

EventManager* EventManager::m_instance = nullptr;

EventManager::EventManager()
{
    m_dispatcher = new EventDispatcher();
}

EventManager::~EventManager()
{
    delete m_dispatcher;
}

EventManager *EventManager::Get()
{
    static std::mutex mtx;
    std::lock_guard<std::mutex> lock(mtx);

    if (!m_instance)
        m_instance = new EventManager();

    return m_instance;
}

void EventManager::subscribeEvents(std::function<void(Event&)> callback)
{
    m_dispatcher->subscribeEvents(callback);
}

void EventManager::Dispatch(Event &event)
{
    m_dispatcher->Dispatch(event);
}