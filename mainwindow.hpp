#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "GraphViewer.hpp"
#include "GraphBuilder.hpp"

#include <QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    GraphViewer* viewer;
private slots:
    void on_vertex_checkbox_stateChanged(int);
    void on_price_checkbox_stateChanged(int);
    void on_regeneration_button_clicked();
    void on_cheapest_button_clicked();
    
};
#endif // MAINWINDOW_H
