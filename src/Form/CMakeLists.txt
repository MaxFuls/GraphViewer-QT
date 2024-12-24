add_library(Form STATIC src/Form.cpp)

target_include_directories(Form PUBLIC include)
target_link_libraries(Form PRIVATE Qt6::Widgets)
