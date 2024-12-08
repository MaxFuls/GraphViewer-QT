#include "GraphBuilder.hpp"
#include "GraphViewer.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GraphBuilder builder;
    GraphViewer viewer(builder.build_random_graph(50, 500, 2, 6), 10);
    viewer.show();
    return a.exec();
}
