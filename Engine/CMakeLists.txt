add_library(Engine SHARED    
    "src/Core/Application.cpp"
    "src/Backends/GLFW/GLFW.cpp"    
    "src/Renderers/OpenGL/OpenGL.cpp"
    )
    
target_include_directories(Engine
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/vendor/GLFW/include
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include
    )
    
target_precompile_headers(Engine
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/Core/pch.h
    )

target_compile_definitions(Engine
	PUBLIC ${ENG_PLATFORM}
	PRIVATE ENG_BUILD_DLL
	)