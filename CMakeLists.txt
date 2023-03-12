cmake_minimum_required(VERSION 3.24)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

project(P2P VERSION 1.0.0.0 LANGUAGES CXX)
message(${PROJECT_NAME} ${P2P_VERSION})

include(FetchContent)
Set(FETCHCONTENT_QUIET FALSE)

# 
# Poco
#
FetchContent_Declare(
	Poco
	URL "https://github.com/pocoproject/poco/archive/refs/tags/poco-1.12.4-release.tar.gz"
	# URL_MD5 "6cf0cdd797bca685910d527ae3c08cb3"
	DOWNLOAD_EXTRACT_TIMESTAMP ON
	FIND_PACKAGE_ARGS 1.12
	)
FetchContent_MakeAvailable(Poco)

# Ne dela
# set(POCO_ENABLE_FOUNDATION             ON)  #"Enable Foundation, required by all components except CppUnit" 
# set(POCO_ENABLE_ENCODINGS              OFF)  #"Enable Encodings" 
# set(POCO_ENABLE_ENCODINGS_COMPILER     OFF) #"Enable Encodings Compiler" 
# set(POCO_ENABLE_XML                    OFF)  #"Enable XML" 
# set(POCO_ENABLE_JSON                   OFF)  #"Enable JSON" 
# set(POCO_ENABLE_MONGODB                OFF)  #"Enable MongoDB" 
# set(POCO_ENABLE_DATA_SQLITE            OFF)  #"Enable Data SQlite" 
# set(POCO_ENABLE_REDIS                  OFF)  #"Enable Redis" 
# set(POCO_ENABLE_PROMETHEUS             OFF)  #"Enable Prometheus" 
# set(POCO_ENABLE_PDF                    OFF) #"Enable PDF" 
# set(ENABLE_UTIL  	                   OFF)  #"Enable Util" 
# set(POCO_ENABLE_NET                    OFF)  #"Enable Net" 
# set(POCO_ENABLE_SEVENZIP               OFF) #"Enable SevenZip" 
# set(POCO_ENABLE_ZIP                    OFF)  #"Enable Zip" 
# set(POCO_ENABLE_CPPPARSER              OFF) #"Enable C++ parser" 
# set(POCO_ENABLE_POCODOC                OFF) #"Enable Poco Documentation Generator" 
# set(POCO_ENABLE_PAGECOMPILER           OFF)  #"Enable PageCompiler" 
# set(POCO_ENABLE_PAGECOMPILER_FILE2PAGE OFF)  #"Enable File2Page" 
# set(POCO_ENABLE_ACTIVERECORD           OFF)  #"Enable ActiveRecord" 
# set(POCO_ENABLE_ACTIVERECORD_COMPILER  OFF)  #"Enable ActiveRecord Compiler" 

# get_cmake_property(_variableNames VARIABLES)
# list (SORT _variableNames)
# foreach (_variableName ${_variableNames})
#     message(STATUS "${_variableName}=${${_variableName}}")
# endforeach()

find_package(Threads REQUIRED)

configure_file(src/config.hpp.in config.hpp)
add_executable(${PROJECT_NAME}
	src/task.cpp
	src/logger.cpp
	src/main.cpp
	)
target_link_libraries(${PROJECT_NAME}
	PUBLIC Threads::Threads
	PUBLIC Poco::Foundation
	# PUBLIC Boost::numeric_conversion
	)
