#include "GraphBuilder.hpp"
#include "GraphViewer.hpp"
#include "mainwindow.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mainwin;
    mainwin.show(); 
    // GraphBuilder builder;
    // GraphViewer* viewer = new GraphViewer(builder.build_random_graph(50, 500, 2, 6), 10);
    // viewer->show();
    return a.exec();
}
