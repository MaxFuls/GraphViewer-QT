#include "Form.hpp"

#include <QtWidgets/QHBoxLayout>

Form::Form(const QString& label, QWidget* parent)
    : QWidget(parent), label_(new QLabel(label)), line_edit_(new QLineEdit) {
    label_ = new QLabel(label);
    line_edit_ = new QLineEdit;
    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(label_);
    layout->addWidget(line_edit_);
    setLayout(layout);
}

QString Form::get_data_from_edit() const { return line_edit_->text(); }

void Form::clear_edit() { line_edit_->clear(); }

Form::~Form() {}