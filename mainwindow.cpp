#include "mainwindow.hpp"
#include "./ui_mainwindow.h"

#include <stdexcept>
#include <string>
#include <QtCore/QtDebug>
#include <QtWidgets/QSizePolicy>
#include <QtCore/QDebug>
#include <QtWidgets/QLineEdit>
#include <QtCore/QString>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    GraphBuilder builder;
    viewer = new GraphViewer(this);
    viewer->setMinimumSize(200, 200);
    viewer->setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
    ui->gridLayout->addWidget(viewer);
}

void MainWindow::on_vertex_checkbox_stateChanged(int arg1) {
    if(arg1 == Qt::Checked) {
        viewer->hide_numbers();
    } else {
        viewer->show_numbers();
    }
}

void MainWindow::on_price_checkbox_stateChanged(int arg1) {
    if(arg1 == Qt::Checked) {
        viewer->hide_prices();
    } else {
        viewer->show_prices();
    }
}

void MainWindow::on_regeneration_button_clicked() {
    try {
        int vertex_num = std::stoi((ui->lineEdit_7->text()).toStdString());
        int radius = std::stoi((ui->lineEdit_6->text()).toStdString());
        int min_edges_count = std::stoi((ui->lineEdit_5->text()).toStdString());
        int max_edges_count = std::stoi((ui->lineEdit_2->text()).toStdString());
        int price = std::stoi((ui->lineEdit_8->text()).toStdString());
        viewer->regenerate_graph(vertex_num, radius, min_edges_count, max_edges_count);
        viewer->set_price(price);
    } catch (std::exception& ex) {
        qDebug() << ex.what();
        ui->lineEdit_7->clear();
        ui->lineEdit_6->clear();
        ui->lineEdit_5->clear();
        ui->lineEdit_2->clear();
        ui->lineEdit_8->clear();
    }    
}

MainWindow::~MainWindow()
{
    delete ui;
}

