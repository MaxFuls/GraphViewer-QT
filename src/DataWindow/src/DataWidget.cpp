#include "DataWidget.hpp"

#include <QtCore/QString>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <optional>

Form::Form(const QString& label, QWidget* parent)
    : QWidget(parent), label_(new QLabel(label)), line_edit_(new QLineEdit) {
    label_ = new QLabel(label);
    line_edit_ = new QLineEdit;
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
    vertex_count_validator_ = new QIntValidator(1, 100, this);
    edges_count_validator_ = new QIntValidator(1, 99, this);
    radius_validator_ = new QIntValidator(100, 1000, this);
    price_validator_ = new QIntValidator(1, 100, this);
}

std::optional<int> DataWidget::get_vertex_count() {
    auto* form = forms_["vertex_count"];
    auto data = form->get_data_from_edit();
    int pos = 0;
    auto is_valid = vertex_count_validator_->validate(data, pos);
    if (is_valid = QValidator::Acceptable) {
        return std::stoi(data.toStdString());
    } else if (is_valid = QValidator::Intermediate) {
        qDebug() << "incorrect range, acceptable range for vertex_count is " << vertex_count_validator_->bottom()
                 << " to " << vertex_count_validator_->top() << '\n';
    } else {
        qDebug() << "incorrect value type for vertex_count, correct value type is integer\n";
    }
    form->clear_edit();
    return std::nullopt;
}

std::optional<int> DataWidget::get_radius() {
    auto* form = forms_["radius"];
    auto data = form->get_data_from_edit();
    int pos = 0;
    auto is_valid = radius_validator_->validate(data, pos);
    if (is_valid = QValidator::Acceptable) {
        return std::stoi(data.toStdString());
    } else if (is_valid = QValidator::Intermediate) {
        qDebug() << "incorrect range, acceptable range for radius is " << radius_validator_->bottom() << " to "
                 << radius_validator_->top() << '\n';
    } else {
        qDebug() << "incorrect value type for radius, correct value type is integer\n";
    }
    form->clear_edit();
    return std::nullopt;
}

std::optional<int> DataWidget::get_price() {
    auto* form = forms_["price"];
    auto data = form->get_data_from_edit();
    int pos = 0;
    auto is_valid = price_validator_->validate(data, pos);
    if (is_valid = QValidator::Acceptable) {
        return std::stoi(data.toStdString());
    } else if (is_valid = QValidator::Intermediate) {
        qDebug() << "incorrect range, acceptable range for price is " << price_validator_->bottom() << " to "
                 << price_validator_->top() << '\n';
    } else {
        qDebug() << "incorrect value type for price, correct value type is integer\n";
    }
    form->clear_edit();
    return std::nullopt;
}

std::optional<std::pair<int, int>> DataWidget::get_edges_count() {
    auto* min_form = forms_["min_edges_count"];
    auto* max_form = forms_["max_edges_count"];
    auto min_data = min_form->get_data_from_edit();
    auto max_data = max_form->get_data_from_edit();
    int pos = 0;
    auto is_min_valid = edges_count_validator_->validate(min_data, pos);
    auto is_max_valid = edges_count_validator_->validate(max_data, pos);
    if (is_min_valid == QValidator::Acceptable && is_max_valid == QValidator::Acceptable) {
        int min = std::stoi(min_data.toStdString());
        int max = std::stoi(max_data.toStdString());
        if (min < max) {
            return std::pair{min, max};
        } else {
            qDebug() << "min edges count can not be more then max edges count\n";
        }
    } else {
        if (is_min_valid == QValidator::Intermediate || is_min_valid == QValidator::Invalid) {
            if (is_min_valid == QValidator::Intermediate) {
                qDebug() << "incorrect range, acceptable range for min edges count is " << price_validator_->bottom()
                         << " to " << price_validator_->top() << '\n';
            } else {
                qDebug() << "incorrect value type for price, correct value type is integer\n";
            }
            min_form->clear_edit();
        }
        if (is_max_valid == QValidator::Intermediate || is_max_valid == QValidator::Invalid) {
            max_form->clear_edit();
            if (is_max_valid == QValidator::Intermediate) {
                qDebug() << "incorrect range, acceptable range for max edges count is " << price_validator_->bottom()
                         << " to " << price_validator_->top() << '\n';
            } else {
                qDebug() << "incorrect value type for price, correct value type is integer\n";
            }
            min_form->clear_edit();
        }
    }
}

DataWidget::~DataWidget() {}