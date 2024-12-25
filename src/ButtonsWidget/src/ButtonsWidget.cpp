#include "ButtonsWidget.hpp"

#include <QtWidgets/QVBoxLayout>

ButtonsWidget::ButtonsWidget(QWidget* parent) : QWidget(parent) {
    buttons_.insert({"regenerate", std::make_unique<QPushButton>("Перегенерировать граф")});
    buttons_.insert({"route", std::make_unique<QPushButton>("Построить кратчайший маршрут")});

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(buttons_["regenerate"].get());
    layout->addWidget(buttons_["route"].get());
}