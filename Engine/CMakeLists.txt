add_library(Engine SHARED    
    "src/Core/Application.cpp"
    )
    
target_include_directories(Engine
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include
    )
    
target_precompile_headers(Engine
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/Core/pch.h
    )

target_compile_definitions(Engine
	PUBLIC ${ENG_PLATFORM}
	PRIVATE ENG_BUILD_DLL
	)