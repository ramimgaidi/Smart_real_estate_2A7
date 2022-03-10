/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *Tab;
    QGroupBox *groupBox_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_3;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton;
    QComboBox *comboBox_2;
    QLineEdit *lineEdit_17;
    QLineEdit *lineEdit_18;
    QLabel *label_30;
    QLabel *label_31;
    QLineEdit *lineEdit_16;
    QWidget *tab_4;
    QGroupBox *groupBox_3;
    QLabel *label_5;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_6;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *pushButton_2;
    QComboBox *comboBox;
    QLineEdit *lineEdit_19;
    QLabel *label_32;
    QLabel *label_33;
    QLineEdit *lineEdit_20;
    QLineEdit *lineEdit_21;
    QWidget *tab_2;
    QGroupBox *groupBox_4;
    QLabel *label_9;
    QLineEdit *lineEdit_7;
    QPushButton *pushButton_3;
    QWidget *tab_3;
    QTableView *tableView;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(758, 475);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(20, 20, 721, 421));
        Tab = new QWidget();
        Tab->setObjectName(QStringLiteral("Tab"));
        groupBox_2 = new QGroupBox(Tab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 30, 701, 321));
        groupBox_2->setStyleSheet(QLatin1String("QGroupBox  {\n"
"    border: 1px solid gray;\n"
"    border-color: #FF17365D;\n"
"    margin-top: 27px;\n"
"    font-size: 14px;\n"
"    border-radius: 15px;\n"
"}\n"
"\n"
"QGroupBox::title  {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center;\n"
"    padding: 5px 8000px 5px 8000px;\n"
"    background-color: #FF17365D;\n"
"    color: rgb(255, 255, 255);\n"
"}"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 60, 61, 16));
        label->setCursor(QCursor(Qt::ArrowCursor));
        lineEdit = new QLineEdit(groupBox_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(120, 60, 113, 20));
        lineEdit_3 = new QLineEdit(groupBox_2);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(120, 140, 113, 20));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 100, 61, 20));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 140, 61, 20));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(36, 180, 61, 20));
        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(470, 260, 142, 23));
        pushButton->setMouseTracking(false);
        pushButton->setStyleSheet(QLatin1String("QPushButton {\n"
"    color: rgb(255, 255, 255);\n"
"  background-color: #FF17365D;\n"
"    border-style: outset;\n"
"    border-width: 0px;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    min-width: 10em;\n"
"    padding: 6px;\n"
"}\n"
"QPushButton:hover {\n"
"color: #fff;\n"
"    background-color: rgb(43, 163, 255);\n"
"    border-style: inset;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(43, 163, 255);\n"
"    border-style: inset;\n"
"}"));
        pushButton->setCheckable(false);
        pushButton->setAutoRepeat(false);
        pushButton->setAutoExclusive(false);
        comboBox_2 = new QComboBox(groupBox_2);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(120, 100, 111, 22));
        lineEdit_17 = new QLineEdit(groupBox_2);
        lineEdit_17->setObjectName(QStringLiteral("lineEdit_17"));
        lineEdit_17->setGeometry(QRect(120, 220, 113, 20));
        lineEdit_18 = new QLineEdit(groupBox_2);
        lineEdit_18->setObjectName(QStringLiteral("lineEdit_18"));
        lineEdit_18->setGeometry(QRect(120, 260, 113, 20));
        label_30 = new QLabel(groupBox_2);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(40, 220, 61, 20));
        label_31 = new QLabel(groupBox_2);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(40, 260, 61, 20));
        lineEdit_16 = new QLineEdit(groupBox_2);
        lineEdit_16->setObjectName(QStringLiteral("lineEdit_16"));
        lineEdit_16->setGeometry(QRect(120, 180, 113, 20));
        tabWidget->addTab(Tab, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        groupBox_3 = new QGroupBox(tab_4);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(0, 0, 691, 361));
        groupBox_3->setStyleSheet(QLatin1String("QGroupBox  {\n"
"    border: 1px solid gray;\n"
"    border-color: #FF17365D;\n"
"    margin-top: 27px;\n"
"    font-size: 14px;\n"
"    border-radius: 15px;\n"
"}\n"
"\n"
"QGroupBox::title  {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center;\n"
"    padding: 5px 8000px 5px 8000px;\n"
"    background-color: #FF17365D;\n"
"    color: rgb(255, 255, 255);\n"
"}"));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(40, 60, 61, 16));
        label_5->setCursor(QCursor(Qt::ArrowCursor));
        lineEdit_4 = new QLineEdit(groupBox_3);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(120, 60, 113, 20));
        lineEdit_6 = new QLineEdit(groupBox_3);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(120, 140, 113, 20));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(40, 100, 61, 20));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(40, 140, 61, 20));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(36, 180, 61, 20));
        pushButton_2 = new QPushButton(groupBox_3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(470, 260, 142, 23));
        pushButton_2->setMouseTracking(false);
        pushButton_2->setStyleSheet(QLatin1String("QPushButton {\n"
"    color: rgb(255, 255, 255);\n"
"  background-color: #FF17365D;\n"
"    border-style: outset;\n"
"    border-width: 0px;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    min-width: 10em;\n"
"    padding: 6px;\n"
"}\n"
"QPushButton:hover {\n"
"color: #fff;\n"
"    background-color: rgb(43, 163, 255);\n"
"    border-style: inset;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(43, 163, 255);\n"
"    border-style: inset;\n"
"}"));
        pushButton_2->setCheckable(false);
        pushButton_2->setAutoRepeat(false);
        pushButton_2->setAutoExclusive(false);
        comboBox = new QComboBox(groupBox_3);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(120, 100, 111, 22));
        lineEdit_19 = new QLineEdit(groupBox_3);
        lineEdit_19->setObjectName(QStringLiteral("lineEdit_19"));
        lineEdit_19->setGeometry(QRect(120, 180, 113, 20));
        label_32 = new QLabel(groupBox_3);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setGeometry(QRect(40, 230, 61, 20));
        label_33 = new QLabel(groupBox_3);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setGeometry(QRect(40, 270, 61, 20));
        lineEdit_20 = new QLineEdit(groupBox_3);
        lineEdit_20->setObjectName(QStringLiteral("lineEdit_20"));
        lineEdit_20->setGeometry(QRect(120, 230, 113, 20));
        lineEdit_21 = new QLineEdit(groupBox_3);
        lineEdit_21->setObjectName(QStringLiteral("lineEdit_21"));
        lineEdit_21->setGeometry(QRect(120, 270, 113, 20));
        tabWidget->addTab(tab_4, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        groupBox_4 = new QGroupBox(tab_2);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 40, 701, 321));
        groupBox_4->setStyleSheet(QLatin1String("QGroupBox  {\n"
"    border: 1px solid gray;\n"
"    border-color: #FF17365D;\n"
"    margin-top: 27px;\n"
"    font-size: 14px;\n"
"    border-radius: 15px;\n"
"}\n"
"\n"
"QGroupBox::title  {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center;\n"
"    padding: 5px 8000px 5px 8000px;\n"
"    background-color: #FF17365D;\n"
"    color: rgb(255, 255, 255);\n"
"}"));
        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(40, 60, 61, 16));
        label_9->setCursor(QCursor(Qt::ArrowCursor));
        lineEdit_7 = new QLineEdit(groupBox_4);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(120, 60, 113, 20));
        pushButton_3 = new QPushButton(groupBox_4);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(470, 260, 142, 23));
        pushButton_3->setMouseTracking(false);
        pushButton_3->setStyleSheet(QLatin1String("QPushButton {\n"
"    color: rgb(255, 255, 255);\n"
"  background-color: #FF17365D;\n"
"    border-style: outset;\n"
"    border-width: 0px;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    min-width: 10em;\n"
"    padding: 6px;\n"
"}\n"
"QPushButton:hover {\n"
"color: #fff;\n"
"    background-color: rgb(43, 163, 255);\n"
"    border-style: inset;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(43, 163, 255);\n"
"    border-style: inset;\n"
"}"));
        pushButton_3->setCheckable(false);
        pushButton_3->setAutoRepeat(false);
        pushButton_3->setAutoExclusive(false);
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tableView = new QTableView(tab_3);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(20, 21, 671, 331));
        tabWidget->addTab(tab_3, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 758, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gestion des Clients", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "logement", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "ref_log", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "type_log", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "adresse_log", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "surface_log", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "duplex", Q_NULLPTR)
         << QApplication::translate("MainWindow", "villa", Q_NULLPTR)
         << QApplication::translate("MainWindow", "appartement", Q_NULLPTR)
        );
        label_30->setText(QApplication::translate("MainWindow", "piece_log", Q_NULLPTR));
        label_31->setText(QApplication::translate("MainWindow", "dispo_log", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(Tab), QApplication::translate("MainWindow", "Ajouter logement", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Gestion des finances", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "ref_log", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "type_log", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "adresse_log", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "surface_log", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "duplex", Q_NULLPTR)
         << QApplication::translate("MainWindow", "villa", Q_NULLPTR)
         << QApplication::translate("MainWindow", "appartement", Q_NULLPTR)
        );
        label_32->setText(QApplication::translate("MainWindow", "piece_log", Q_NULLPTR));
        label_33->setText(QApplication::translate("MainWindow", "dispo_log", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Modifier logement", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Gestion des finances", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "ref_log", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Supprimer logement", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Afficher logement", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
