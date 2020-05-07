#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_comboBox_activated(const QString &arg1);

    void on_comboBox_activated(int index);

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_comboBox_editTextChanged(const QString &arg1);

    void on_comboBox_textActivated(const QString &arg1);

    void on_comboBox_highlighted(const QString &arg1);

    void on_pushButton_clicked(bool checked);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
