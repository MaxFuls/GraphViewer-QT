#include "GraphViewer.hpp"

#include <QtWidgets/QWidget>
#include <QtGui/QPainter>
#include <QtGui/QColor>

GraphViewer::GraphViewer(const Graph& graph, QWidget* parent) : QWidget(parent), graph_(graph) {
    int min_side = std::min(width(), height());
    double diag = graph_.get_radius() * 2;
    scale_ = min_side / diag;
    elllipse_coords = QPointF(0, 0);
    repaint();
} 

GraphViewer::~GraphViewer() {}

void GraphViewer::paintEvent(QPaintEvent*) {
    int diam = graph_.get_radius() * 2;
    int min_side = std::min(width(), height());
    QPainter painter(this);
    QColor color(0, 0, 0, 255);
    auto pen = QPen(color);
    painter.setPen(pen);
    painter.translate(-cam_pos_*scale_);
    painter.drawEllipse(elllipse_coords*scale_, diam/2*scale_, diam/2*scale_);
    auto brush = QBrush(color);
    painter.setBrush(brush);
    auto vertxes = graph_.get_vertexes();
    for(auto v :vertxes) {
        painter.drawEllipse(QPoint(v.first, v.second)*scale_, 5, 5);
    }
    auto edges = graph_.get_edges();
    for(int i = 0, size = edges.size(); i < size; ++i) {
        for(int j = 0, sub_size = edges[i].size(); j < sub_size; ++j) {
            painter.drawLine(QPoint(vertxes[i].first, vertxes[i].second)*scale_,
                             QPoint(vertxes[edges[i][j]].first, vertxes[edges[i][j]].second)*scale_);
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
        cam_pos_ -= diff/scale_;
        prev_mouse_pos = event->pos();
        repaint();
    }
}

void GraphViewer::resizeEvent(QResizeEvent*) {
    double diag = graph_.get_radius() * 2;
    int min_side = std::min(width(), height());
    scale_ = min_side / diag;
    cam_pos_ = {-width()/(scale_*2), -height()/(scale_*2)};
    elllipse_coords = QPointF(0, 0);
    repaint();
}

void GraphViewer::wheelEvent(QWheelEvent* event) {
    const double coef = 1.1;
    double new_scale;
    if(event->angleDelta().y() > 0) {
        new_scale = scale_ * coef;
    } else {
        new_scale = scale_ / coef;
    }
    cam_pos_ += (event->position())*(1/scale_ - 1/new_scale);   
    scale_ = new_scale;
    prev_mouse_pos = event->position();
    repaint();
}