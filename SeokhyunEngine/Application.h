#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include <string>

/**
 * @class Application
 * @brief Base unit for programs utilizing SeokhyunEngine
 */
class Application
{
private:

    std::string m_name;
    std::string m_version;

public:

    Application(const std::string& name, const std::string& version);
    virtual ~Application();


    const std::string& getName() const    { return m_name; }
    const std::string& getVersion() const { return m_version; }


    virtual void onInit();
    virtual void onUpdate();
    virtual void onRender();
    virtual void onShutdown();
};

#endif //__APPLICATION_H__