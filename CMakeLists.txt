cmake_minimum_required(VERSION 3.24)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

project(P2P VERSION 1.0.0.0 LANGUAGES CXX)
message(${PROJECT_NAME} ${P2P_VERSION})

include(FetchContent)
Set(FETCHCONTENT_QUIET FALSE)

# FetchContent_Declare(
#         Boost
# 		URL "https://github.com/boostorg/boost/releases/download/boost-1.81.0/boost-1.81.0.tar.xz"
# 		URL_MD5 "6cf0cdd797bca685910d527ae3c08cb3"
# 		DOWNLOAD_EXTRACT_TIMESTAMP ON
# 		FIND_PACKAGE_ARGS 1.81.0 #[[ COMPONENTS program_options ]]
# 		)
# set(BOOST_INCLUDE_LIBRARIES uuid asio)
# set(BOOST_EXCLUDE_LIBRARIES win32)
#
# FetchContent_MakeAvailable(Boost)
#
# get_cmake_property(_variableNames VARIABLES)
# list (SORT _variableNames)
# foreach (_variableName ${_variableNames})
#     message(STATUS "${_variableName}=${${_variableName}}")
# endforeach()

find_package(Threads REQUIRED)

configure_file(src/config.hpp.in config.hpp)
add_executable(${PROJECT_NAME} src/main.cpp src/task.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC Threads::Threads
	# PUBLIC Boost::numeric_conversion
	)
