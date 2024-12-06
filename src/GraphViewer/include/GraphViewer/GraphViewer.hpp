#ifndef GRAPH_VIEWER_HPP
#define GRAPH_VIEWER_HPP

#include "Graph.hpp"

#include <QtWidgets/QWidget>

class GraphViewer : public QWidget {
    Q_OBJECT
    Graph graph_;
public:
    GraphViewer(const Graph&, QWidget* parent = nullptr);
    void paintEvent(QPaintEvent*);
};

#endif