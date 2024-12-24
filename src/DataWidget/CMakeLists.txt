add_library(DataWidget STATIC src/DataWidget.cpp)

target_include_directories(DataWidget PUBLIC include)
target_include_directories(DataWidget PUBLIC ../Form/include)
target_link_libraries(DataWidget PRIVATE Qt6::Gui)
target_link_libraries(DataWidget PRIVATE Qt6::Widgets)
target_link_libraries(DataWidget PRIVATE Form)
