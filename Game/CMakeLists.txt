add_executable(Game
    "src/Game.cpp"
    )

target_include_directories(Game
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
	#PRIVATE ${CMAKE_SOURCE_DIR}/Engine/include
	)

target_link_libraries(Game
	PRIVATE Engine
	)