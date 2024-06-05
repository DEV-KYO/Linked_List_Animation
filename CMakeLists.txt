cmake_minimum_required(VERSION 3.15)

project(Linked_List_Animation)

# Tell CMake to build a executable
add_executable(${PROJECT_NAME} main.cpp
        Application.h
        Application.cpp
        Drawables/TextBox/TextBox.h
        Drawables/TextBox/TextBox.cpp
        Drawables/TextBox/LetterObject.h
        Drawables/TextBox/LetterObject.cpp
        Drawables/TextBox/Label.h
        Drawables/TextBox/Label.cpp
        Drawables/TextBox/Cursor.h
        Drawables/TextBox/Cursor.cpp
        Drawables/TextBox/_LOCAL_CONSTANTS.h
        States/States.h
        States/States.cpp
        States/EnumStates.h
        MouseEvents/MouseEvents.h
        MouseEvents/MouseEvents.cpp
        KeyboardShortcuts/KeyboardShortcuts.h
        KeyboardShortcuts/KeyboardShortcuts.cpp
        History/HistoryNode.h
        History/History.h
        History/History.cpp
        GUIComponents/GUIComponent.h
        GUIComponents/snapshot/SnapshotInterface.h
        GUIComponents/snapshot/Snapshot.h
        GUIComponents/snapshot/Snapshot.cpp
        GUIComponents/EventHandler/EventHandler.h
        Font/FontManager.h
        Font/FontManager.cpp
        Font/EnumFonts.h
        Drawables/Arrowshape/Arrowshape.cpp
        Drawables/Arrowshape/Arrowshape.h
        Drawables/EnumDrawables/EnumDirection.h
        System.cpp
        System.h
        Drawables/EnumDrawables/EnumDrawables.h
        Drawables/NodeShape/NodeShape.cpp
        Drawables/NodeShape/NodeShape.h
        LinkedList/LinkedList.cpp
        LinkedList/LinkedList.h
        LinkedList/Node.h
        LinkedList/Node.cpp

)

# CMake SFML Project uses C++17 features
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS NO CXX_STANDARD_REQUIRED YES)

# Set SFML_ROOT
set(SFML_ROOT "C:/SFML-2.6.1")

# Set SFML_DIR
set(SFML_DIR "C:/SFML-2.6.1/lib/cmake/SFML")

# Find SFML
find_package(SFML 2.6 COMPONENTS graphics system window REQUIRED)

# Link SFML
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-system sfml-window)

# Install executable
install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION .)
