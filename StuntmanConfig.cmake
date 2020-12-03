include(CMakeFindDependencyMacro)

find_dependency(Threads REQUIRED)
find_dependency(OpenSSL REQUIRED)

include("${CMAKE_CURRENT_LIST_DIR}/StuntmanTargets.cmake")