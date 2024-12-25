#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <memory>
#include <string>
#include <unordered_map>

class ButtonsWidget : public QWidget {
   public:
    ButtonsWidget(QWidget* parent = nullptr);
    ~ButtonsWidget();

   private:
    std::unordered_map<std::string, std::unique_ptr<QAbstractButton>> buttons_;

   private slots:
};