# Sandwich Engine - Math library

file(GLOB_RECURSE MATH_SOURCES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/private *.cpp *.c)
file(GLOB_RECURSE MATH_INCLUDES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/public *.h *.hpp)

add_library(Math STATIC ${MATH_SOURCES} ${MATH_INCLUDES})

if(WIN32)
	set_property(TARGET Math PROPERTY
		MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")
endif()

set_property(TARGET Math PROPERTY FOLDER "SandwichCore/Math")

target_include_directories(Math PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/public>
	$<INSTALL_INTERFACE:Math/public>
	INTERFACE
		${CMAKE_CURRENT_SOURCE_DIR}/public
)