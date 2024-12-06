add_library(GraphViewer STATIC src/GraphViewer.cpp)

target_link_libraries(GraphViewer PUBLIC Qt6::Widgets)

target_include_directories(GraphViewer PUBLIC include)
target_include_directories(GraphViewer PUBLIC ../Graph/include)