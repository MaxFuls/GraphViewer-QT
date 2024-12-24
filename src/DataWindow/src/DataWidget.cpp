#include "DataWidget.hpp"

#include <QtCore/QString>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <optional>

Form::Form(const QString& label, QWidget* parent)
    : QWidget(parent), label_(new QLabel(label)), line_edit_(new QLineEdit) {
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(label_);
    layout->addWidget(line_edit_);
    setLayout(layout);
}

QString Form::get_data_from_edit() const { return line_edit_->text(); }

void Form::clear_edit() { line_edit_->clear(); }

DataWidget::DataWidget(QWidget* parrent) : QWidget(parrent) {
    forms_.insert({"vertex_count", new Form(QString("Количество вершин"), this)});
    forms_.insert({"radius", new Form(QString("Радиус"), this)});
    forms_.insert({"min_vertex_count", new Form(QString("Мнимальное количество рёбер"), this)});
    forms_.insert({"max_vertex_count", new Form(QString("Максимальное количество рёбер"), this)});
    forms_.insert({"price", new Form(QString("Цена еденицы расстояния"), this)});
    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(forms_["vertex_count"]);
    layout->addWidget(forms_["radius"]);
    layout->addWidget(forms_["min_vertex_count"]);
    layout->addWidget(forms_["max_vertex_count"]);
    layout->addWidget(forms_["price"]);
}

std::optional<int> DataWidget::get_vertex_count() {
    auto* form = forms_["vertex_count"];
    auto data = form->get_data_from_edit();
    int value;
    try {
        value = std::stoi(data.toStdString());
    } catch (std::exception& e) {
        qDebug() << e.what();
        form->clear_edit();
        return std::nullopt;
    }
    if (value <= 0) {
        form->clear_edit();
        return std::nullopt;
    } else {
        return {value};
    }
}

std::optional<int> DataWidget::get_radius() {
    auto* form = forms_["radius"];
    auto data = form->get_data_from_edit();
    int value;
    try {
        value = std::stoi(data.toStdString());
    } catch (std::exception& e) {
        qDebug() << e.what();
        form->clear_edit();
        return std::nullopt;
    }
    if (value <= 0) {
        form->clear_edit();
        return std::nullopt;
    } else {
        return {value};
    }
}

std::optional<int> DataWidget::get_min_vertex_count() {
    auto* form = forms_["min_vertex_count"];
    auto data = form->get_data_from_edit();
    int value;
    try {
        value = std::stoi(data.toStdString());
    } catch (std::exception& e) {
        qDebug() << e.what();
        form->clear_edit();
        return std::nullopt;
    }
    if (value <= 0) {
        form->clear_edit();
        return std::nullopt;
    } else {
        return {value};
    }
}

std::optional<int> DataWidget::get_max_vertex_count() {
    auto* form = forms_["max_vertex_count"];
    auto data = form->get_data_from_edit();
    int value;
    try {
        value = std::stoi(data.toStdString());
    } catch (std::exception& e) {
        qDebug() << e.what();
        form->clear_edit();
        return std::nullopt;
    }
    if (value <= 0) {
        form->clear_edit();
        return std::nullopt;
    } else {
        return {value};
    }
}

std::optional<int> DataWidget::get_price() {
    auto* form = forms_["price"];
    auto data = form->get_data_from_edit();
    int value;
    try {
        value = std::stoi(data.toStdString());
    } catch (std::exception& e) {
        qDebug() << e.what();
        form->clear_edit();
        return std::nullopt;
    }
    if (value <= 0) {
        form->clear_edit();
        return std::nullopt;
    } else {
        return {value};
    }
}

DataWidget::~DataWidget() {}