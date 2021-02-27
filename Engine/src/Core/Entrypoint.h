#pragma once

#include "Core/Application.h"

int main(int argc, char *argv[])
{
    eng::ApplicationSettings Settings;
    auto app = eng::CreateApplication(Settings);
    app->Run(Settings);
    delete app;
}