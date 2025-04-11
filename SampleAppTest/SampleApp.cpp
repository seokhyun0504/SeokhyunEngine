#include "SampleApp.h"

SampleApp::SampleApp() : Application("SampleAppTest", "b1.0")
{
    EventManager::addEvent(KeyDownEvent, &SampleApp::OnKeyDown);
    EventManager::addEvent(KeyUpEvent, &SampleApp::OnKeyUp);
    EventManager::addEvent(MouseDownEvent, &SampleApp::OnMouseDown);
    EventManager::addEvent(MouseUpEvent, &SampleApp::OnMouseUp);
}

SampleApp::~SampleApp()
{

}

void SampleApp::OnInit()
{
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    m_mesh = Mesh::CreateSquare();
    m_program = Program::Create("./SampleAppTest/Resources/sample.vs", "./SampleAppTest/Resources/sample.fs");

    m_modelMat = glm::mat4(1.0f);
    m_color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
}


void SampleApp::OnUpdate()
{
    m_program->use();
    m_program->setUniform("u_color", m_color);
    m_program->setUniform("u_modelMat", m_modelMat);

    m_mesh->draw();
}

void SampleApp::OnKeyDown(KeyDownEvent &e)
{
    if (e.getKeyCode() == GLFW_KEY_SPACE)
    {
        m_color = glm::vec4(0.0f, 1.0f, 0.0f, 1.0f);
    }
}

void SampleApp::OnKeyUp(KeyUpEvent &e)
{
    if (e.getKeyCode() == GLFW_KEY_SPACE)
    {
        m_color = glm::vec4(1.0f);
    }
}

void SampleApp::OnMouseUp(MouseUpEvent& e)
{
    if (e.getButton() == GLFW_MOUSE_BUTTON_1)
    {
        m_modelMat = glm::scale(glm::vec3(1.0f));
    }
}

void SampleApp::OnMouseDown(MouseDownEvent& e)
{
    if (e.getButton() == GLFW_MOUSE_BUTTON_1)
    {
        m_modelMat = glm::scale(glm::vec3(0.9f));
    }
}
