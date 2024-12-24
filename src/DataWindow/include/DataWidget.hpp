#pragma once
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>
#include <optional>
#include <string>
#include <unordered_map>

class Form : public QWidget {
    Q_OBJECT
   public:
    Form(const QString& label, QWidget* parent = nullptr);
    ~Form();
    QString get_data_from_edit() const;
    void clear_edit();

   private:
    QLabel* label_;
    QLineEdit* line_edit_;
};

class DataWidget : public QWidget {
    Q_OBJECT

   public:
    DataWidget(QWidget* parent = nullptr);
    ~DataWidget();

    std::optional<int> get_vertex_count();
    std::optional<int> get_radius();
    std::optional<int> get_min_vertex_count();
    std::optional<int> get_max_vertex_count();
    std::optional<int> get_price();

   private:
    std::unordered_map<std::string, Form*> forms_;
};