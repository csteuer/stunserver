add_executable(stunclient clientmain.cpp)

target_link_libraries(stunclient stuntmancommon stuntmancore stuntmannetworkutils resources)

install(TARGETS stunclient EXPORT StuntmanTargets
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    INCLUDES DESTINATION include)
