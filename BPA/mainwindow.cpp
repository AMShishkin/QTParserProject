#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    MainWindow::pathFileLabel = new QLabel(" PATH FILE : ");
    MainWindow::timeWorkLabel = new QLabel("\t PARSING TIME : ");
    MainWindow::focusItemLabel = new QLabel("\t FOCUS : ");


    ui->setupUi(this);

    ui->MainStatusBar->addWidget(MainWindow::pathFileLabel);
    ui->MainStatusBar->addWidget(MainWindow::timeWorkLabel);
    ui->MainStatusBar->addWidget(MainWindow::focusItemLabel);

    MainWindow::model = new QStandardItemModel;











    QMenu *mnFile = new QMenu("File"); // создаём меню Файл
    QMenu *mnEdit = new QMenu("Edit");
    QMenu *mnService = new QMenu("Service");
    QMenu *mnHelp = new QMenu("Help");


    // Initialize menu bar items
    MainWindow::openFileAction = new QAction("Open file", mnFile);
    connect(MainWindow::openFileAction, SIGNAL(triggered()), this, SLOT(ClickOpenFile()));
    mnFile->addAction(MainWindow::openFileAction);
    mnFile->addSeparator();


    MainWindow::closeFileAction = new QAction("Close file",  mnFile);
    connect(MainWindow::closeFileAction, SIGNAL(triggered()), this, SLOT(ClickCloseFile()));
    mnFile->addAction(MainWindow::closeFileAction);





    ui->menuBar->addMenu(mnFile); // Добавляем пункты меню в menuBar, т.е. те, которые будут отображаться в гл. окне
    ui->menuBar->addMenu(mnEdit);
    ui->menuBar->addMenu(mnService);
    ui->menuBar->addMenu(mnHelp);

    MainWindow::setMenuWidget(ui->menuBar);


    MainWindow::isOpenFile = false;

    setAcceptDrops(true);

    ResetDataInterface();
}

MainWindow::~MainWindow()
{
    delete ui;
}








QString MainWindow::MimeDataFileType(const QMimeData *fileType)
{
    if(fileType->hasUrls())
    {
        foreach(const QUrl &url, fileType->urls())
        {
            QString _urlLocalFile = url.toLocalFile();

            if (!_urlLocalFile.isEmpty())
                if (QFileInfo(_urlLocalFile).suffix() == "txt")
                    return _urlLocalFile;
        }
    }
    return NULL;
}


void MainWindow::ResetGridInterface()
{
     MainWindow::model->clear();
     MainWindow::horizontalHeader.clear();
     MainWindow::verticalHeader.clear();
     MainWindow::model->setHorizontalHeaderLabels(MainWindow::horizontalHeader);
     MainWindow::model->setVerticalHeaderLabels(MainWindow::verticalHeader);
     ui->MainGrid->setModel(MainWindow::model);

}

void MainWindow::ResetDataInterface()
{
    MainWindow::ResetGridInterface();
    MainWindow::pathFileLabel->setText(" PATH FILE : ");
    MainWindow::timeWorkLabel->setText("\t PARSING TIME : ");
    MainWindow::focusItemLabel->setText("\t FOCUS : ");
    MainWindow::closeFileAction->setEnabled(false);
    MainWindow::isOpenFile = false;
}



void MainWindow::AddRatingItem(const int *index, const char *value)
{
    MainWindow::item = new QStandardItem(QString(value));
    MainWindow::model->setItem(*index, MainWindow::horizontalHeader.length() - 1, MainWindow::item);
}

void MainWindow::MainGridItemFocus(const QModelIndex &v1, const QModelIndex &v2)
{
    MainWindow::focusItemLabel->setText("FOCUS : " + MainWindow::model->item(v1.row(), v1.column())->text() + "\t");
}

// Menu bar events
void MainWindow::ClickOpenFile()
{
    QString _pathFile;
    QMessageBox::StandardButton _reply;

    // open the file?
    if (MainWindow::isOpenFile)
    {
        _reply = QMessageBox::question(this, QString::fromUtf8("WARNING"), QString::fromUtf8("Close the current data?"), QMessageBox::Yes | QMessageBox::No);

        if (_reply == QMessageBox::Yes)
        {
            MainWindow::ResetDataInterface();
            MainWindow::ClickOpenFile();
        }
    }
    else
    {
        MainWindow::ResetDataInterface();

        _pathFile = QFileDialog::getOpenFileName(this, QString::fromUtf8("Open file"), QDir::currentPath(), "Booking, Logs (*.txt)");

        if (_pathFile != "")
        {
            MainWindow::pathFileLabel->setText(" PATH FILE : " + _pathFile + "\t");
            MainWindow::ResetGridInterface();
            MainWindow::closeFileAction->setEnabled(true);

            // timer start
            float _start_time = clock();
            MainWindow::ReadingFile(_pathFile);
            // timer end
            float _end_time = clock();

            MainWindow::timeWorkLabel->setText("PARSING TIME : " + QString::number((_end_time - _start_time) / 1000.0f) + " sec.\t");
            MainWindow::focusItemLabel->setText("FOCUS : empty\t");
            MainWindow::isOpenFile = true;
        }
    }
}

void MainWindow::ClickCloseFile()
{
    QMessageBox::StandardButton _reply;

    // Open the file?
    if (MainWindow::isOpenFile)
    {
        _reply = QMessageBox::question(this, QString::fromUtf8("WARNING"), QString::fromUtf8("Close the current data?"), QMessageBox::Yes | QMessageBox::No);

        if (_reply == QMessageBox::Yes)
            MainWindow::ResetDataInterface();
    }
}



// Drag events
void MainWindow::dragEnterEvent(QDragEnterEvent *e)
{
    if (!MimeDataFileType(e->mimeData()).isEmpty())
        e->acceptProposedAction();
}

void MainWindow::dropEvent(QDropEvent *e)
{
    QMessageBox::StandardButton _reply;

    // open the file?
    if (MainWindow::isOpenFile)
    {
        _reply = QMessageBox::question(this, QString::fromUtf8("WARNING"), QString::fromUtf8("Close the current data?"), QMessageBox::Yes | QMessageBox::No);

        if (_reply == QMessageBox::Yes)
        {
            MainWindow::ResetDataInterface();
            MainWindow::dropEvent(e);
        }
    }
    else
    {
        MainWindow::closeFileAction->setEnabled(true);
        MainWindow::isOpenFile = true;

        // timer start
        float _start_time = clock();

        foreach (const QUrl &url, e->mimeData()->urls())
        {
            MainWindow::pathFileLabel->setText(" PATH FILE : " + url.toLocalFile() + "\t");
            MainWindow::ResetGridInterface();
            ReadingFile(url.toLocalFile());
        }

        // timer end
        float _end_time = clock();

        MainWindow::timeWorkLabel->setText("PARSING TIME : " + QString::number((_end_time - _start_time) / 1000.0f) + " sec.\t");
        MainWindow::focusItemLabel->setText("FOCUS : empty\t");
    }
}

void MainWindow::dragLeaveEvent(QDragLeaveEvent *e)
{
}


void MainWindow::FillDataGrid(Parser *parser)
{
    MainWindow::horizontalHeader.append("NAME");
    MainWindow::horizontalHeader.append("PAGE_NAME");
    MainWindow::horizontalHeader.append("MINRATE");
    MainWindow::horizontalHeader.append("HOTEL_TYPE_ID");
    MainWindow::horizontalHeader.append("CURRENCE_CODE");
    MainWindow::horizontalHeader.append("CITY");
    MainWindow::horizontalHeader.append("ADDRESS");
    MainWindow::horizontalHeader.append("RATING");

    MainWindow::model->setHorizontalHeaderLabels(MainWindow::horizontalHeader);
    MainWindow::model->setVerticalHeaderLabels(MainWindow::verticalHeader);

    for (ushort i = 0; i < ui->MainGrid->horizontalHeader()->count(); ++i)
        ui->MainGrid->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);

    for (unsigned int i = 0; i < parser->Elements.size(); ++i)
    {
        MainWindow::model->setItem(i, 0, new QStandardItem(QString(parser->Elements[i].Name.c_str())));
        MainWindow::model->setItem(i, 1, new QStandardItem(QString(parser->Elements[i].PageName.c_str())));
        MainWindow::model->setItem(i, 2, new QStandardItem(QString(parser->Elements[i].Minrate.c_str())));
        MainWindow::model->setItem(i, 3, new QStandardItem(QString(parser->Elements[i].HotelTypeId.c_str())));
        MainWindow::model->setItem(i, 4, new QStandardItem(QString(parser->Elements[i].CurrencyCode.c_str())));
        MainWindow::model->setItem(i, 5, new QStandardItem(QString(parser->Elements[i].City.c_str())));
        MainWindow::model->setItem(i, 6, new QStandardItem(QString(parser->Elements[i].Address.c_str())));
     }
}



void MainWindow::ReadingFile(const QString &pathFile)
{
    QFile _file(pathFile);
    QByteArray _data;

    if (!_file.open(QIODevice::ReadOnly)) return;

    _data = _file.readAll();

     //!!!!!!!!!
        Parser parser;





     const char *str;

      QByteArray ba;
      ba = pathFile.toLatin1();
      str = ba.data();

     parser.pFile = fopen(str, "r");

     if (parser.pFile == NULL) return;
     else
     {
         fseek(parser.pFile, 0 , SEEK_END);
         parser.lBufferSize = ftell(parser.pFile);
         parser.buffer = (char*)malloc(sizeof(char)*parser.lBufferSize);
         fseek(parser.pFile, 0, SEEK_SET);
         fread(parser.buffer, 1, parser.lBufferSize, parser.pFile);
         parser.SearchData(&parser.lBufferSize, parser.buffer);

         if (parser.Minrates.size() > 0)
         {
             MainWindow::FillDataGrid(&parser);
             std::sort(parser.Minrates.begin(), parser.Minrates.end());
             MainWindow::CalculationRating(&parser);
             ui->MainGrid->setModel(MainWindow::model);
             ui->MainGrid->horizontalHeader()->setSectionsMovable(true);
             // read only cells
             for (ushort i = 0; i < MainWindow::model->rowCount(); ++i)
                 for (ushort j = 0; j < MainWindow::model->columnCount(); ++j)
                     MainWindow::model->item(i, j)->setFlags((Qt::ItemIsSelectable | Qt::ItemIsEnabled));

             QObject::connect(ui->MainGrid->selectionModel(), SIGNAL(currentChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(MainGridItemFocus(const QModelIndex &, const QModelIndex &)));
          }
       }
       fclose(parser.pFile);
       free(parser.buffer);
       _file.close();
       _file.destroyed();
}



void MainWindow::CalculationRating(const Parser *parser)
{
    int avIndex, avValue;
    char *str;

    int tmp;


    QByteArray ba;

    if (parser->Minrates.size() > 0)
    {
        if ((parser->Minrates.size() - 1) % 2 == 0)
        {
            avIndex = parser->Minrates.size() / 2;
            avValue = parser->Minrates[avIndex];
        }
        else
        {
            avIndex = (parser->Minrates.size() - 1) / 2;
            avValue = parser->Minrates[avIndex];
        }

        for (int i = 0; i < MainWindow::model->rowCount(); ++i)
        {
            ba = MainWindow::model->item(i, 2)->text().toLatin1();
            str = ba.data();

            tmp = atoi(str);

            if (tmp < (0.7f * avValue))
                MainWindow::AddRatingItem(&i, "$");
            else if (tmp > (0.7f * avValue) && tmp < (1.3f * avValue))
                MainWindow::AddRatingItem(&i, "$$");
            else if (tmp > (1.3f * avValue))
                MainWindow::AddRatingItem(&i, "$$$");
        }
    }
}













