cmake_minimum_required(VERSION 3.21)

project(
	"shibal"
	VERSION 0.1.0
	DESCRIPTION "A command-line utility for general management."
	HOMEPAGE_URL "https://github.com/novoseiversia/shibal"
	LANGUAGES CXX
)



file(
	DOWNLOAD
	https://github.com/cpm-cmake/CPM.cmake/releases/download/v0.40.4/CPM.cmake
	${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake
	EXPECTED_HASH SHA256=67dcc1deb6e12a2f0705647ccc5f7023e3d15746b944e14352b82373e09b8a0a
)

include(${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake)



add_executable(
	${PROJECT_NAME}
	"src/novoseiversia/shibal/main.cxx"
)

target_include_directories(${PROJECT_NAME} PRIVATE "include/")
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

if (MSVC)
	target_compile_options(${PROJECT_NAME} PRIVATE "/W4" "/w14640" "/permissive-")
else ()
	target_compile_options(${PROJECT_NAME} PRIVATE "-Wall" "-Wextra" "-Wshadow" "-Wnon-virtual-dtor" "-Wpedantic")
endif ()
