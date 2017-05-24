#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDropEvent>
#include <QDragLeaveEvent>
#include <QMimeData>
#include <QFileInfo>
#include <QFileDialog>
#include <QMessageBox>
#include <QtGui>
#include <QFile>
#include <QLabel>
#include <QByteArray>
#include <QDebug>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <QTableView>
#include <QMenu>
#include <QAction>

#include "Parser.h"
#include "QStandardItem"
#include "QStandardItemModel"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT



public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    // drop events
    void dropEvent(QDropEvent *e);
    void dragEnterEvent(QDragEnterEvent *e);
    void dragLeaveEvent(QDragLeaveEvent *e);
    // set drop file type
    QString MimeDataFileType(const QMimeData *fileType);
    // read file
    void ReadingFile(const QString &pathFile);
    // raiting
    void CalculationRating(const Parser *parser);
    // menu bar
    void OpenFileDialog();







    void ResetGridInterface();
    void ResetDataInterface();

    // Adding rating item
    void AddRatingItem(const int *index = 0, const char *value = "None");

    void FillDataGrid(Parser *parser);




public slots:
    void MainGridItemFocus(const QModelIndex &v1, const QModelIndex &v2);
    void ClickOpenFile();
    void ClickCloseFile();


private:
    Ui::MainWindow *ui;

    QAction *openFileAction, *closeFileAction;

    QLabel *pathFileLabel, *timeWorkLabel, *focusItemLabel;
    QFile *openFile;

    QStandardItemModel *model;
    QStandardItem *item;
    QStringList horizontalHeader;
    QStringList verticalHeader;

    bool isOpenFile;

};

#endif // MAINWINDOW_H
