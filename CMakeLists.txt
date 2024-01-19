cmake_minimum_required(VERSION 3.25)

project(CppMake VERSION 0.0.1 LANGUAGES CXX)

add_library(CppMakeLib)
target_include_directories(CppMakeLib PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/lib>
        $<INSTALL_INTERFACE:lib>
)

set(CPPMAKE_LIB_HEADERS
        lib/CppMake/Project.hpp
        lib/CppMake/Target.hpp
        lib/CppMake/Application.hpp
        lib/CppMake/Utils.hpp
)

target_sources(CppMakeLib PRIVATE
        ${CPPMAKE_LIB_HEADERS}
        lib/Project.cpp
        lib/Application.cpp
        lib/Target.cpp
)

set_target_properties(CppMakeLib PROPERTIES
        PUBLIC_HEADER "${CPPMAKE_LIB_HEADERS}"
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
)

if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.9)
    get_property(isMultiConfig GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)
elseif(CMAKE_CONFIGURATION_TYPES)
    set(isMultiConfig TRUE)
endif()

install(TARGETS CppMakeLib
        EXPORT CppMakeTargets
        PUBLIC_HEADER DESTINATION lib/CppMake
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
        CppMakeConfigVersion.cmake
        VERSION ${PACKAGE_VERSION}
        COMPATIBILITY AnyNewerVersion
)

install(EXPORT CppMakeTargets
        FILE CppMakeTargets.cmake
        NAMESPACE CppMake::
        DESTINATION lib/cmake/CppMake
)

configure_file(CppMakeConfig.cmake.in CppMakeConfig.cmake @ONLY)
install(FILES
        "${CMAKE_CURRENT_BINARY_DIR}/CppMakeConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/CppMakeConfigVersion.cmake"
        CppMakeBuilder.cmake
        DESTINATION lib/cmake/CppMake
)

export(TARGETS CppMakeLib NAMESPACE CppMake:: FILE CppMakeTargets.cmake)