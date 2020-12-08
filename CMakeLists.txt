cmake_minimum_required(VERSION 3.2.2 FATAL_ERROR)
project(stuntman VERSION 1.2.16 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Threads REQUIRED)

option(with_configfile_support "The server can be configured with a json file (requires boost)" OFF)
if (with_configfile_support)
    find_package(Boost REQUIRED)
endif()

add_subdirectory(common)
add_subdirectory(networkutils)
add_subdirectory(resources)
add_subdirectory(stuncore)
add_subdirectory(testcode)
add_subdirectory(server)
add_subdirectory(client)

##########################################################################################################
# Package config installation
##########################################################################################################

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
     "${CMAKE_CURRENT_BINARY_DIR}/StuntmanConfigVersion.cmake"
    VERSION ${stuntman_VERSION}
    COMPATIBILITY AnyNewerVersion
)
export(EXPORT StuntmanTargets
    NAMESPACE Stuntman::
)

install(EXPORT StuntmanTargets
    NAMESPACE Stuntman::
    DESTINATION lib/cmake/stuntman
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/StuntmanConfigVersion.cmake"
    "${CMAKE_CURRENT_SOURCE_DIR}/StuntmanConfig.cmake"
    DESTINATION lib/cmake/stuntman
)
