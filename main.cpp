#include "GraphBuilder.hpp"
#include "GraphViewer.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GraphBuilder builder;
    GraphViewer viewer(builder.build_random_graph(15, 480, 1, 3));
    viewer.show();
    return a.exec();
}
