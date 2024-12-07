#include "GraphViewer.hpp"

#include <QtWidgets/QWidget>
#include <QtGui/QPainter>
#include <QtGui/QColor>
#include<iostream>

GraphViewer::GraphViewer(const Graph& graph, QWidget* parent) : QWidget(parent), graph_(graph) {} 

GraphViewer::~GraphViewer() {}

void GraphViewer::paintEvent(QPaintEvent* event) {
    
    double diam = 2 * graph_.get_radius();
    int h = height();
    int w = width();
    int min_side = std::min(h, w);
    double scale = min_side / diam;
    QPainter painter(this);
    QColor color(0, 0, 0, 255);
    auto pen = QPen(color);
    painter.setPen(pen);
    painter.drawEllipse(w/2 - min_side/2, h/2 - min_side/2, diam*scale, diam*scale);
    auto brush = QBrush(color);
    painter.setBrush(brush);
    auto vertxes = graph_.get_vertexes();
    painter.translate(w/2, h/2);
    for(auto v :vertxes) {
        painter.drawEllipse(QPoint(v.first, v.second)*scale, 5, 5);
    }
    auto edges = graph_.get_edges();
    for(int i = 0, size = edges.size(); i < size; ++i) {
        for(int j = 0, sub_size = edges[i].size(); j < sub_size; ++j) {
            painter.drawLine(QPoint(vertxes[i].first, vertxes[i].second)*scale,
                             QPoint(vertxes[edges[i][j]].first, vertxes[edges[i][j]].second)*scale);
        }
    }
}

