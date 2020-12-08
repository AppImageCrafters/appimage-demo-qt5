 
if(ANDROID)
    add_library(appimage-demo-qt5 SHARED
      main.cpp
      qml.qrc
    )
else()
    add_executable(appimage-demo-qt5
      main.cpp
      qml.qrc
    )
endif()

target_compile_definitions(appimage-demo-qt5
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(appimage-demo-qt5
  PRIVATE Qt5::Core Qt5::Quick)

install(TARGETS appimage-demo-qt5 RUNTIME DESTINATION bin)