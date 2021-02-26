#pragma once

#include "Core/Application.h"

int main(int argc, char *argv[])
{
    eng::ApplicationProps AppProps;
    auto app = eng::CreateApplication(AppProps);
    app->Run(AppProps);
    delete app;
}