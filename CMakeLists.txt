cmake_minimum_required(VERSION 3.19)
project(curlman LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets LinguistTools)
find_package(CURL REQUIRED)

qt_standard_project_setup()

qt_add_executable(curlman
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    request.h
    request.cpp
    header.h
    header.cpp
    appsettings.cpp
    appsettings.h
    response.h
    response.cpp
    headervector.h
    headervector.cpp
)

qt_add_translations(
    TARGETS curlman
    TS_FILES curlman_en_US.ts
)

target_link_libraries(curlman
    PRIVATE
        Qt::Core
        Qt::Widgets
        ${CURL_LIBRARIES}
)

install(TARGETS curlman
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET curlman
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
