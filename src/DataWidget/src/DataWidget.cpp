#include "DataWidget.hpp"

#include <QtCore/QDebug>
#include <optional>

DataWidget::DataWidget(QWidget* parrent) : QWidget(parrent) {
    forms_.insert({"vertex_count", std::make_unique<Form>(QString("Количество вершин"))});
    forms_.insert({"radius", std::make_unique<Form>(QString("Радиус"))});
    forms_.insert({"min_edges_count", std::make_unique<Form>(QString("Мнимальное количество рёбер"))});
    forms_.insert({"max_edges_count", std::make_unique<Form>(QString("Максимальное количество рёбер"))});
    forms_.insert({"price", std::make_unique<Form>(QString("Цена еденицы расстояния"))});

    QVBoxLayout* layout = new QVBoxLayout;

    layout->addWidget(forms_["vertex_count"].get());
    layout->addWidget(forms_["radius"].get());
    layout->addWidget(forms_["min_edges_count"].get());
    layout->addWidget(forms_["max_edges_count"].get());
    layout->addWidget(forms_["price"].get());
    setLayout(layout);

    vertex_count_validator_ = new QIntValidator(1, 100);
    edges_count_validator_ = new QIntValidator(1, 99);
    radius_validator_ = new QIntValidator(100, 1000);
    price_validator_ = new QIntValidator(1, 100);
}

std::optional<int> DataWidget::get_vertex_count() {
    auto& form = forms_["vertex_count"];
    auto data = form->get_data_from_edit();
    if (data.isEmpty()) {
        qDebug() << "vertex count field can not be empty\n";
        return std::nullopt;
    }
    int pos = 0;
    auto is_valid = vertex_count_validator_->validate(data, pos);
    if (is_valid == QValidator::Acceptable) {
        return std::stoi(data.toStdString());
    } else if (is_valid == QValidator::Intermediate) {
        qDebug() << "incorrect range, acceptable range for vertex_count is " << vertex_count_validator_->bottom()
                 << " to " << vertex_count_validator_->top() << '\n';
    } else {
        qDebug() << "incorrect value type for vertex_count, correct value type is integer\n";
    }
    forms_["vertex_count"]->clear_edit();
    return std::nullopt;
}

std::optional<int> DataWidget::get_radius() {
    auto& form = forms_["radius"];
    auto data = form->get_data_from_edit();
    if (data.isEmpty()) {
        qDebug() << "radius field can not be empty\n";
        return std::nullopt;
    }
    int pos = 0;
    auto is_valid = radius_validator_->validate(data, pos);
    if (is_valid == QValidator::Acceptable) {
        return std::stoi(data.toStdString());
    } else if (is_valid == QValidator::Intermediate) {
        qDebug() << "incorrect range, acceptable range for radius is " << radius_validator_->bottom() << " to "
                 << radius_validator_->top() << '\n';
    } else {
        qDebug() << "incorrect value type for radius, correct value type is integer\n";
    }
    form->clear_edit();
    return std::nullopt;
}

std::optional<int> DataWidget::get_price() {
    auto& form = forms_["price"];
    auto data = form->get_data_from_edit();
    if (data.isEmpty()) {
        qDebug() << "price field can not be empty\n";
        return std::nullopt;
    }
    int pos = 0;
    auto is_valid = price_validator_->validate(data, pos);
    if (is_valid == QValidator::Acceptable) {
        return std::stoi(data.toStdString());
    } else if (is_valid == QValidator::Intermediate) {
        qDebug() << "incorrect range, acceptable range for price is " << price_validator_->bottom() << " to "
                 << price_validator_->top() << '\n';
    } else {
        qDebug() << "incorrect value type for price, correct value type is integer\n";
    }
    form->clear_edit();
    return std::nullopt;
}

std::optional<std::pair<int, int>> DataWidget::get_edges_count() {
    auto& min_form = forms_["min_edges_count"];
    auto& max_form = forms_["max_edges_count"];
    auto min_data = min_form->get_data_from_edit();
    auto max_data = max_form->get_data_from_edit();
    if (min_data.isEmpty() || max_data.isEmpty()) {
        if (min_data.isEmpty()) {
            qDebug() << "min vertex field can not be empty\n";
        }
        if (max_data.isEmpty()) {
            qDebug() << "max vertex field can not be empty\n";
        }
        return std::nullopt;
    }
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
                qDebug() << "incorrect value type for price, correct value type is integer";
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
    return std::nullopt;
}

DataWidget::~DataWidget() {}