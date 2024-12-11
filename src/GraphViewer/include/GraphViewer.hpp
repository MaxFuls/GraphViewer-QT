#ifndef graphVIEWER_HPP
#define graphVIEWER_HPP

#include "Graph.hpp"

#include <QMainWindow>
#include <QtCore/QPointF>
#include <QtGui/QMouseEvent>
#include <QtGui/QWheelEvent>

class GraphViewer : public QWidget {
private:   
    int distance_price;
    double scale = 1.0;
    QPointF cam_pos = {0, 0};
    bool mouse_pressed = false;
    QPointF prev_mouse_pos;
    QPointF elllipse_coords;
    bool is_numbers_hiden = false;
    bool is_prices_hiden = false;
    bool is_setted;
public:
    Graph graph;
    GraphViewer(QWidget* parent = nullptr);
    void paintEvent(QPaintEvent*) override;
    void mousePressEvent(QMouseEvent*) override;
    void mouseReleaseEvent(QMouseEvent*) override;
    void mouseMoveEvent(QMouseEvent*) override;
    void resizeEvent(QResizeEvent*) override;
    void wheelEvent(QWheelEvent*) override;
    void show_numbers();
    void hide_numbers();
    void show_prices();
    void hide_prices();
    void regenerate_graph(int, int, int, int);
    void set_price(int);
    ~GraphViewer();
};

#endif