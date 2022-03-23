/********************************************************************************
** Form generated from reading UI file 'bigwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BIGWINDOW_H
#define UI_BIGWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BigWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *BigName;
    QMenuBar *menubar;
    QMenu *menuMemoryGame;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *BigWindow)
    {
        if (BigWindow->objectName().isEmpty())
            BigWindow->setObjectName(QString::fromUtf8("BigWindow"));
        BigWindow->resize(800, 600);
        centralwidget = new QWidget(BigWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(350, 360, 83, 29));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(90, 140, 152, 59));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout->addWidget(lineEdit);


        horizontalLayout->addLayout(verticalLayout);

        BigName = new QLabel(widget);
        BigName->setObjectName(QString::fromUtf8("BigName"));
        QFont font;
        font.setPointSize(24);
        BigName->setFont(font);

        horizontalLayout->addWidget(BigName);

        BigWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(BigWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menuMemoryGame = new QMenu(menubar);
        menuMemoryGame->setObjectName(QString::fromUtf8("menuMemoryGame"));
        BigWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(BigWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        BigWindow->setStatusBar(statusbar);

        menubar->addAction(menuMemoryGame->menuAction());

        retranslateUi(BigWindow);
        QObject::connect(lineEdit, &QLineEdit::textEdited, BigName, &QLabel::setText);

        QMetaObject::connectSlotsByName(BigWindow);
    } // setupUi

    void retranslateUi(QMainWindow *BigWindow)
    {
        BigWindow->setWindowTitle(QCoreApplication::translate("BigWindow", "BigWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("BigWindow", "PushButton", nullptr));
        label->setText(QCoreApplication::translate("BigWindow", "prueba de QT", nullptr));
        lineEdit->setText(QCoreApplication::translate("BigWindow", "nombre", nullptr));
        BigName->setText(QString());
        menuMemoryGame->setTitle(QCoreApplication::translate("BigWindow", "MemoryGame", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BigWindow: public Ui_BigWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BIGWINDOW_H
