#include "SampleApp.h"

SampleApp::SampleApp() : Application("SampleAppTest", "b1.0")
{

}

SampleApp::~SampleApp()
{

}

void SampleApp::OnInit()
{
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    m_mesh = Mesh::CreateSquare();
    m_program = Program::Create("./SampleAppTest/Resources/sample.vs", "./SampleAppTest/Resources/sample.fs");
}


void SampleApp::OnUpdate()
{
    m_program->use();
    m_mesh->draw();
}