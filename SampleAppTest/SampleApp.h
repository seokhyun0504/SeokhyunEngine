#ifndef __SAMPLEAPP_H__
#define __SAMPLEAPP_H__

#include "SeokhyunEngine.h"

class SampleApp : public Application
{

private:

    Mesh* m_mesh;
    Program* m_program;

    glm::mat4 m_modelMat;
    glm::vec4 m_color;

public:

    SampleApp();
    ~SampleApp() override;

    void OnInit() override;
    void OnUpdate() override;

    void OnKeyDown(KeyDownEvent& e);
    void OnKeyUp(KeyUpEvent& e);
    void OnMouseUp(MouseUpEvent& e);
    void OnMouseDown(MouseDownEvent& e);
};


#endif //__SAMPLEAPP_H__
