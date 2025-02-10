#include "SeokhyunEngine.h"
#include "SampleApp.h"

int main(const int argc, const char ** argv)
{
    AppLauncher *launcher = Launcher::CreateLauncher();
    return launcher->run(new SampleApp());
}