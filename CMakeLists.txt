cmake_minimum_required(VERSION 3.27)
project(Customer_Support_Assistant)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "C:/Qt/6.7.0/mingw_64/lib/cmake")

find_package(
        Qt6
        COMPONENTS
        Core
        Network
        Gui
        Widgets
        REQUIRED)

add_executable(
        Customer_Support_Assistant
        main.cpp
        Domain/User.h
        Domain/User.cpp
        Domain/Agent.h
        Domain/Agent.cpp
        Domain/Inquiry.h
        Domain/Inquiry.cpp
        Domain/InquiryStatus.h
        Domain/UrgencyLevel.h
        Domain/AIModel.h
        Domain/AIModel.cpp
        Repository/BankRepository.h
        Repository/BankRepository.cpp
        Controller/BankController.h
        Controller/BankController.cpp
        Gui/ConfigurationView.h
        Gui/ConfigurationView.cpp
        Gui/ConfigurationView.ui
        Gui/ControllerView.h
        Gui/ControllerView.cpp
        Gui/ControllerView.ui
        Gui/ClientView.h
        Gui/ClientView.cpp
        Gui/ClientView.ui
        Gui/DepartmentView.h
        Gui/DepartmentView.cpp
        Gui/DepartmentView.ui
        Gui/InquiriesView.h
        Gui/InquiriesView.cpp
        Gui/InquiriesView.ui
        Gui/StatisticsView.h
        Gui/StatisticsView.cpp
        Gui/StatisticsView.ui
        Utils/ObserverPattern.h
        Utils/CustomTables.h
        Utils/CustomTables.cpp
        Utils/time.h
)

target_link_libraries(
        Customer_Support_Assistant
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Network
)

target_include_directories(Customer_Support_Assistant PRIVATE ${Qt6_INCLUDE_DIRS})

if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
