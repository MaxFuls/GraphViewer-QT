#ifndef GRAPH_VIEWER_HPP
#define GRAPH_VIEWER_HPP

#include "Graph.hpp"

#include <QMainWindow>
#include <QtCore/QPointF>

class GraphViewer : public QWidget {
    
    Graph graph_;
    double scale_ = 1.0;
    QPointF cam_pos_ = {0.0, 0.0};
public:
    GraphViewer(const Graph&, QWidget* parent = nullptr);
    void paintEvent(QPaintEvent*) override;
    ~GraphViewer();
};

#endif