#ifndef __SAMPLEAPP_H__
#define __SAMPLEAPP_H__

#include "SeokhyunEngine.h"

class SampleApp : public Application
{

private:

    Mesh* m_mesh;
    Program* m_program;

public:

    SampleApp();
    ~SampleApp() override;

    void OnInit() override;
    void OnUpdate() override;
};


#endif //__SAMPLEAPP_H__
