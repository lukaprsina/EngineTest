#pragma once

#include "Core/Window.h"
#include "Core/pch.h"
#include "Core/Base.h"
#include "Core/Layer.h"

#include "Events/Event.h"

namespace eng
{
    class ENG_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run(ApplicationSettings &AppProps);

        void OnEvent(Event &e);

        void PushLayer(Layer *layer);
        void PopLayer(Layer *layer);

        void BringLayerToFront(Layer *layer);
        void SendLayerToBack(Layer *layer);

        void BringLayerForward(Layer *layer, unsigned int count = 1);
        void SendLayerBackward(Layer *layer, unsigned int count = 1);

    private:
        bool m_Running = true;
        std::vector<Layer *> m_Layers;
    };

    extern Application *CreateApplication(ApplicationSettings &Settings);
}