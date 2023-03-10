cmake_minimum_required(VERSION 3.24)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

project(P2P VERSION 1.0.0.0 LANGUAGES CXX)
message(${PROJECT_NAME} ${P2P_VERSION})

include(FetchContent)
Set(FETCHCONTENT_QUIET FALSE)

FetchContent_Declare(
        Poco
		URL "https://github.com/pocoproject/poco/archive/refs/tags/poco-1.12.4-release.tar.gz"
		# URL_MD5 "6cf0cdd797bca685910d527ae3c08cb3"
		DOWNLOAD_EXTRACT_TIMESTAMP ON
		FIND_PACKAGE_ARGS 1.12
		)

FetchContent_MakeAvailable(Poco)

set(ENABLE_FOUNDATION             ON)  #"Enable Foundation, required by all components except CppUnit" 
set(ENABLE_ENCODINGS              OFF)  #"Enable Encodings" 
set(ENABLE_ENCODINGS_COMPILER     OFF) #"Enable Encodings Compiler" 
set(ENABLE_XML                    OFF)  #"Enable XML" 
set(ENABLE_JSON                   OFF)  #"Enable JSON" 
set(ENABLE_MONGODB                OFF)  #"Enable MongoDB" 
set(ENABLE_DATA_SQLITE            OFF)  #"Enable Data SQlite" 
set(ENABLE_REDIS                  OFF)  #"Enable Redis" 
set(ENABLE_PROMETHEUS             OFF)  #"Enable Prometheus" 
set(ENABLE_PDF                    OFF) #"Enable PDF" 
set(ENABLE_UTIL                   OFF)  #"Enable Util" 
set(ENABLE_NET                    OFF)  #"Enable Net" 

set(ENABLE_SEVENZIP               OFF) #"Enable SevenZip" 
set(ENABLE_ZIP                    OFF)  #"Enable Zip" 
set(ENABLE_CPPPARSER              OFF) #"Enable C++ parser" 
set(ENABLE_POCODOC                OFF) #"Enable Poco Documentation Generator" 
set(ENABLE_PAGECOMPILER           OFF)  #"Enable PageCompiler" 
set(ENABLE_PAGECOMPILER_FILE2PAGE OFF)  #"Enable File2Page" 

set(ENABLE_ACTIVERECORD           OFF)  #"Enable ActiveRecord" 
set(ENABLE_ACTIVERECORD_COMPILER  OFF)  #"Enable ActiveRecord Compiler" 

# get_cmake_property(_variableNames VARIABLES)
# list (SORT _variableNames)
# foreach (_variableName ${_variableNames})
#     message(STATUS "${_variableName}=${${_variableName}}")
# endforeach()

find_package(Threads REQUIRED)

configure_file(src/config.hpp.in config.hpp)
add_executable(${PROJECT_NAME} src/main.cpp #[[ src/task.cpp ]]
	)
target_link_libraries(${PROJECT_NAME} PUBLIC Threads::Threads
	# PUBLIC Boost::numeric_conversion
	)
