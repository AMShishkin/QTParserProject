/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave_as;
    QAction *actionExit;
    QAction *actionClose_file;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTableView *MainGrid;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QStatusBar *MainStatusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(918, 517);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(640, 480));
        MainWindow->setAutoFillBackground(true);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionOpen->setShortcutContext(Qt::WindowShortcut);
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QStringLiteral("actionSave_as"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionClose_file = new QAction(MainWindow);
        actionClose_file->setObjectName(QStringLiteral("actionClose_file"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        centralWidget->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        MainGrid = new QTableView(centralWidget);
        MainGrid->setObjectName(QStringLiteral("MainGrid"));
        MainGrid->setEnabled(true);
        MainGrid->setFrameShape(QFrame::Box);
        MainGrid->setFrameShadow(QFrame::Raised);
        MainGrid->setLineWidth(1);
        MainGrid->setMidLineWidth(0);
        MainGrid->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        MainGrid->setAlternatingRowColors(true);
        MainGrid->setShowGrid(true);
        MainGrid->setGridStyle(Qt::DashLine);
        MainGrid->setSortingEnabled(false);
        MainGrid->setWordWrap(false);
        MainGrid->setCornerButtonEnabled(false);
        MainGrid->horizontalHeader()->setVisible(true);
        MainGrid->horizontalHeader()->setCascadingSectionResizes(true);
        MainGrid->horizontalHeader()->setHighlightSections(true);
        MainGrid->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        MainGrid->horizontalHeader()->setStretchLastSection(true);
        MainGrid->verticalHeader()->setCascadingSectionResizes(true);
        MainGrid->verticalHeader()->setProperty("showSortIndicator", QVariant(true));
        MainGrid->verticalHeader()->setStretchLastSection(false);

        verticalLayout->addWidget(MainGrid);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 918, 18));
        menuBar->setContextMenuPolicy(Qt::DefaultContextMenu);
        menuBar->setLayoutDirection(Qt::LeftToRight);
        menuBar->setDefaultUp(false);
        menuBar->setNativeMenuBar(true);
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuFile->setEnabled(false);
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(menuFile->sizePolicy().hasHeightForWidth());
        menuFile->setSizePolicy(sizePolicy2);
        QFont font;
        font.setFamily(QStringLiteral("Sakkal Majalla"));
        menuFile->setFont(font);
        menuFile->setTearOffEnabled(false);
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuEdit->setEnabled(false);
        MainWindow->setMenuBar(menuBar);
        MainStatusBar = new QStatusBar(MainWindow);
        MainStatusBar->setObjectName(QStringLiteral("MainStatusBar"));
        MainStatusBar->setEnabled(true);
        MainWindow->setStatusBar(MainStatusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionClose_file);
        menuFile->addSeparator();
        menuFile->addAction(actionSave_as);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Booking Parser Application", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0));
        actionSave_as->setText(QApplication::translate("MainWindow", "Save as", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionClose_file->setText(QApplication::translate("MainWindow", "Close file", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
