#include "GraphViewer.hpp"

#include <QtWidgets/QWidget>
#include <QtGui/QPainter>
#include <QtGui/QColor>

GraphViewer::GraphViewer(const Graph& graph, int distance_price, QWidget* parent) : 
                         QWidget(parent), graph(graph), distance_price(distance_price)  {
    int min_side = std::min(width(), height());
    double diag = graph.get_radius() * 2;
    scale = min_side / diag;
    elllipse_coords = QPointF(0, 0);
    repaint();
} 

GraphViewer::~GraphViewer() {}

void GraphViewer::paintEvent(QPaintEvent*) {
    int diam = graph.get_radius() * 2;
    int min_side = std::min(width(), height());
    QPainter painter(this);
    auto pen = QPen(Qt::black);
    painter.setPen(pen);
    painter.translate(-cam_pos*scale);
    painter.drawEllipse(elllipse_coords*scale, diam/2*scale, diam/2*scale);
    auto brush = QBrush(Qt::black);
    painter.setBrush(brush);
    auto vertxes = graph.get_vertexes();
    for(auto v :vertxes) {
        painter.drawEllipse(QPoint(v.first, v.second)*scale, static_cast<int>(5*scale), static_cast<int>(5*scale));
    }
    // pen.setWidth(scale);
    auto font = painter.font();
    font.setPixelSize((8*scale < 8) ? 8 : (8*scale > 16) ? 16 : 8*scale);
    painter.setPen(pen);
    painter.setFont(font);
    auto edges = graph.get_edges();
    auto distances = graph.get_distances();
    std::vector<std::vector<bool>> is_visited(vertxes.size(), std::vector<bool>(vertxes.size()));
    for(int i = 0, size = edges.size(); i < size; ++i) {
        for(int j = 0, sub_size = edges[i].size(), firstx, firsty, secondx, secondy; j < sub_size; ++j) {
            firstx = vertxes[i].first;
            firsty = vertxes[i].second;
            secondx = vertxes[edges[i][j]].first;
            secondy = vertxes[edges[i][j]].second;
            pen.setColor(Qt::black);
            painter.setPen(pen);
            painter.drawLine(QPoint(firstx, firsty)*scale, QPoint(secondx, secondy)*scale);
            if(!is_visited[i][edges[i][j]]) {
                pen.setColor(Qt::red);
                painter.setPen(pen);
                painter.drawText(scale*(firstx + (secondx - firstx)/2), scale*(firsty + (secondy - firsty)/2),
                     QString::fromStdString(std::to_string(static_cast<int>(distance_price * distances[i][j])) + "USD"));
            is_visited[i][edges[i][j]] = true;
            is_visited[edges[i][j]][i] = true;
            }
        }
    }
}

void GraphViewer::mousePressEvent(QMouseEvent* event) {
    mouse_pressed = true;
    prev_mouse_pos = event->pos();
}

void GraphViewer::mouseReleaseEvent(QMouseEvent* event) {
    mouse_pressed = false;
}

void GraphViewer::mouseMoveEvent(QMouseEvent* event) {
    if(mouse_pressed) {
        auto diff = event->pos() - prev_mouse_pos;
        cam_pos -= diff/scale;
        prev_mouse_pos = event->pos();
        repaint();
    }
}

void GraphViewer::resizeEvent(QResizeEvent*) {
    double diag = graph.get_radius() * 2;
    int min_side = std::min(width(), height());
    scale = min_side / diag;
    cam_pos = {-width()/(scale*2), -height()/(scale*2)};
    elllipse_coords = QPointF(0, 0);
    repaint();
}

void GraphViewer::wheelEvent(QWheelEvent* event) {
    const double coef = 1.1;
    double new_scale;
    if(event->angleDelta().y() > 0) {
        new_scale = scale * coef;
    } else {
        new_scale = scale / coef;
    }
    cam_pos += (event->position())*(1/scale - 1/new_scale);   
    scale = new_scale;
    prev_mouse_pos = event->position();
    repaint();
}