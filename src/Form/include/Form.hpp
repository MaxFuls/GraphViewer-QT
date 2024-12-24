#pragma once

#include <QtCore/QString>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

class Form : public QWidget {
   public:
    Form(const QString& label, QWidget* parent = nullptr);
    ~Form();
    QString get_data_from_edit() const;
    void clear_edit();

   private:
    QLabel* label_;
    QLineEdit* line_edit_;
};
