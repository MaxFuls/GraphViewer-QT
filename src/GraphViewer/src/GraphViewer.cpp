#include "GraphViewer.hpp"

#include <QtWidgets/QWidget>
#include <QtGui/QPainter>
#include <QtGui/QColor>

GraphViewer::GraphViewer(const Graph& graph, QWidget* parent) : QWidget(parent), graph_(graph) {} 

GraphViewer::~GraphViewer() {}

void GraphViewer::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    QColor color(0, 0, 0, 255);
    auto pen = QPen(color);
    painter.setPen(pen);
    painter.drawEllipse({960, 500}, 480, 480);
    auto brush = QBrush(color);
    painter.setBrush(brush);
    painter.translate(960, 500);
    auto vertxes = graph_.get_vertexes();
    for(auto v :vertxes) {
        painter.drawEllipse(QPoint(v.first, v.second), 10, 10);
    }
    auto edges = graph_.get_edges();
    for(int i = 0, size = edges.size(); i < size; ++i) {
        for(int j = 0, sub_size = edges[i].size(); j < sub_size; ++j) {
            painter.drawLine(QPoint(vertxes[i].first, vertxes[i].second),
                             QPoint(vertxes[edges[i][j]].first, vertxes[edges[i][j]].second));
        }
    }
}

