 
if(ANDROID)
    add_library(hello-qt-world SHARED
      main.cpp
      qml.qrc
    )
else()
    add_executable(hello-qt-world
      main.cpp
      qml.qrc
    )
endif()

target_compile_definitions(hello-qt-world
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(hello-qt-world
  PRIVATE Qt5::Core Qt5::Quick)

install(TARGETS hello-qt-world RUNTIME DESTINATION bin)