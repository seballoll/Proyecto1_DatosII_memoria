#ifndef BIGWINDOW_H
#define BIGWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class BigWindow; }
QT_END_NAMESPACE

class BigWindow : public QMainWindow
{
    Q_OBJECT

public:
    BigWindow(QWidget *parent = nullptr);
    ~BigWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::BigWindow *ui;
};
#endif // BIGWINDOW_H
