#ifndef GRAPH_VIEWER_HPP
#define GRAPH_VIEWER_HPP

#include "Graph.hpp"

#include <QMainWindow>
#include <QtCore/QPointF>
#include <QtGui/QMouseEvent>
#include <QtGui/QWheelEvent>

class GraphViewer : public QWidget {
    
    Graph graph_;
    double scale_ = 1.0;
    QPointF cam_pos_ = {0, 0};
    bool mouse_pressed = false;
    QPointF prev_mouse_pos;
    QPointF elllipse_coords;
public:
    GraphViewer(const Graph&, QWidget* parent = nullptr);
    void paintEvent(QPaintEvent*) override;
    void mousePressEvent(QMouseEvent*) override;
    void mouseReleaseEvent(QMouseEvent*) override;
    void mouseMoveEvent(QMouseEvent*) override;
    void resizeEvent(QResizeEvent*) override;
    void wheelEvent(QWheelEvent*) override;
    ~GraphViewer();
};

#endif