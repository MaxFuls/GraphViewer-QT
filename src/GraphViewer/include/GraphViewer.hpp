#ifndef graphVIEWER_HPP
#define graphVIEWER_HPP

#include "Graph.hpp"

#include <QMainWindow>
#include <QtCore/QPointF>
#include <QtGui/QMouseEvent>
#include <QtGui/QWheelEvent>
#include <QtGui/QPainterPath>

class GraphViewer : public QWidget {
    
    Graph graph;
    int distance_price;
    double scale = 1.0;
    QPointF cam_pos = {0, 0};
    bool mouse_pressed = false;
    QPointF prev_mouse_pos;
    QPointF elllipse_coords;
public:
    GraphViewer(const Graph&, int, QWidget* parent = nullptr);
    void paintEvent(QPaintEvent*) override;
    void mousePressEvent(QMouseEvent*) override;
    void mouseReleaseEvent(QMouseEvent*) override;
    void mouseMoveEvent(QMouseEvent*) override;
    void resizeEvent(QResizeEvent*) override;
    void wheelEvent(QWheelEvent*) override;
    ~GraphViewer();
};

#endif