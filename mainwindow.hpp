#pragma once

#include <QMainWindow>
#include <QtWidgets/QWidget>

#include "GraphBuilder.hpp"
#include "GraphViewer.hpp"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

   public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

   private:
    Ui::MainWindow *ui;
    GraphViewer *viewer;
   private slots:
    void on_vertex_checkbox_stateChanged(int);
    void on_price_checkbox_stateChanged(int);
    void on_regeneration_button_clicked();
    void on_cheapest_button_clicked();
};