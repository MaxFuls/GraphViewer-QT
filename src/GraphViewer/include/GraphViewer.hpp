#ifndef GRAPH_VIEWER_HPP
#define GRAPH_VIEWER_HPP

#include "Graph.hpp"

#include <QMainWindow>

class GraphViewer : public QWidget {
    // Q_OBJECT
    Graph graph_;
public:
    GraphViewer(const Graph&, QWidget* parent = nullptr);
    void paintEvent(QPaintEvent*) override;
    ~GraphViewer();
};

#endif