add_library(Engine SHARED
    "src/Core/Application.cpp"
    "src/Backends/GLFW/GLFW.cpp"    
    "src/Renderers/OpenGL/OpenGL.cpp"
    "src/Core/Log.cpp"
    "src/Core/Layer.cpp"
    "src/Core/LayerStack.cpp"
    )
    
target_include_directories(Engine
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/vendor/Glad/include
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/vendor/GLFW/include
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog/include
    )

target_precompile_headers(Engine
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/Core/pch.h
	)

target_link_libraries(Engine
	PRIVATE glfw
	PRIVATE Glad
	PRIVATE spdlog::spdlog_header_only
	)

target_compile_definitions(Engine
	PUBLIC ${ENG_PLATFORM}
    PUBLIC ENG_ENABLE_ASSERTS
	PRIVATE ENG_BUILD_DLL
    PRIVATE GLFW_INCLUDE_NONE
	)