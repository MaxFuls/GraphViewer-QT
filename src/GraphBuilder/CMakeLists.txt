add_library(GraphBuilder STATIC src/GraphBuilder.cpp)

target_include_directories(GraphBuilder PUBLIC include)
target_include_directories(GraphBuilder PUBLIC ../Randomizer/include)
target_include_directories(GraphBuilder PUBLIC ../Graph/include)
