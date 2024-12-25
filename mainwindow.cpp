#include "mainwindow.hpp"

#include <QtCore/QDebug>
#include <QtCore/QString>
#include <QtCore/QtDebug>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSizePolicy>
#include <stdexcept>
#include <string>

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), viewer(new GraphViewer()), data_widget(new DataWidget()) {
    ui->setupUi(this);
    data_widget->setSizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
    viewer->setMinimumSize(200, 200);
    viewer->setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
    ui->gridLayout->addWidget(viewer.get());
    ui->verticalLayout_2->addWidget(data_widget.get());
}

void MainWindow::on_vertex_checkbox_stateChanged(int arg1) {
    if (arg1 == Qt::Checked) {
        viewer->hide_numbers();
    } else {
        viewer->show_numbers();
    }
}

void MainWindow::on_price_checkbox_stateChanged(int arg1) {
    if (arg1 == Qt::Checked) {
        viewer->hide_prices();
    } else {
        viewer->show_prices();
    }
}

void MainWindow::on_regeneration_button_clicked() {
    auto vertex_count = data_widget->get_vertex_count();
    auto radius = data_widget->get_radius();
    auto edges_count = data_widget->get_edges_count();
    auto price = data_widget->get_price();
    if (vertex_count.has_value() && radius.has_value() && edges_count.has_value() && price.has_value()) {
        viewer->regenerate_graph(vertex_count.value(), radius.value(), edges_count.value().first,
                                 edges_count.value().second);
        viewer->set_price(price.value());
    }
}

void MainWindow::on_cheapest_button_clicked() {
    // int end;
    // try {
    //     end = std::stoi((ui->lineEdit->text()).toStdString());
    // } catch (std::exception& ex) {
    //     qDebug() << ex.what();
    //     ui->lineEdit->clear();
    // }
    // qDebug() << end;
    // auto p = viewer->graph.find_cheapest_way_from_begin(end);
    // if (p.second.empty()) {
    //     ui->textBrowser->setText("Пути в данную вершину не существует\n");
    // } else {
    //     qDebug() << p.first;
    //     std::string str = "Общая стоимость - " + std::to_string(p.first) + "\n";
    //     str += std::to_string(p.second[0]);
    //     for (int i = 1; i < p.second.size(); ++i) {
    //         str += " -> " + std::to_string(p.second[i]);
    //     }
    //     ui->textBrowser->setText(QString::fromStdString(str));
    // }
}

MainWindow::~MainWindow() { delete ui; }
