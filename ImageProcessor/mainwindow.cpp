#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "multiimagewidget.h"
#include "commentedimage.h"
#include "functionpool.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <QPixmap>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/favicons/favicon_64x64.ico"));
    this->setWindowTitle(tr("Image Processor"));
    m_multiImageWidget = new MultiImageWidget(ui->scrollArea_multiImageWidget);
    m_appendImage = m_multiImageWidget->appendImage();
    ui->scrollArea_multiImageWidget->setWidget(m_multiImageWidget);

    ui->scrollArea_multiImageWidget->setBackgroundRole(QPalette::Dark);
    ui->scrollArea_multiImageWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->scrollArea_multiImageWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->progressBar->hide();
    ui->progressBar->setRange(0, 100);
    ui->label->setText("Nothing to be displayed.");

    m_functionPool =  new FunctionPool(this);
    m_functionPool->setMultiImageWidget(m_multiImageWidget);
    ui->functionWidget->setFunctionPool(m_functionPool);
    m_multiImageWidget->setFunctionPool(m_functionPool);
    createActions();
    createMenus();
    setMinimumSize(1024, 680);
    adjustSize();
    connect(m_appendImage, SIGNAL(clicked()), this, SLOT(import()));
    connect(m_multiImageWidget, SIGNAL(displayPixmap(QPixmap, QString)), ui->singleImageWidget, SLOT(load(QPixmap, QString)));
    connect(ui->singleImageWidget, SIGNAL(displayed(bool)), this, SLOT(updateActions(bool)));
    connect(this->m_actionFitToWindow, SIGNAL(triggered(bool)), ui->singleImageWidget, SLOT(fitToWindowChange(bool)));
    connect(ui->singleImageWidget, SIGNAL(displayed(bool)), this, SLOT(updateLabel()));
    connect(ui->functionWidget, SIGNAL(processStarted()), ui->progressBar, SLOT(show()));
    connect(ui->functionWidget, SIGNAL(processFinished()), ui->progressBar, SLOT(hide()));
    connect(ui->functionWidget, SIGNAL(processRefreshed(int)), ui->progressBar, SLOT(setValue(int)));
    connect(this, SIGNAL(processStarted()), ui->progressBar, SLOT(show()));
    connect(this, SIGNAL(processStarted()), this, SLOT(disable()));
    connect(this, SIGNAL(processFinished()), ui->progressBar, SLOT(hide()));
    connect(this, SIGNAL(processFinished()), this, SLOT(enable()));
    connect(this, SIGNAL(processRefreshed(int)), ui->progressBar, SLOT(setValue(int)));
    connect(ui->functionWidget, SIGNAL(processStarted()), this->m_multiImageWidget, SLOT(updateImages()));
    connect(m_functionPool, SIGNAL(pixmapUpdated(QList<QPixmap>)), m_multiImageWidget, SLOT(updatePixmaps(QList<QPixmap>)));
    connect(m_functionPool, SIGNAL(cursorBusy()), this, SLOT(cursorBusy()));
    connect(m_functionPool, SIGNAL(cursorNormal()), this, SLOT(cursorNormal()));
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createActions()
{
    this->m_actionImport = new QAction(tr("&Import..."), this);
    this->m_actionImport->setShortcut(tr("Ctrl+I"));
    connect(m_actionImport, SIGNAL(triggered()), this, SLOT(import()));

    this->m_actionExport = new QAction(tr("&Export..."), this);
    this->m_actionExport->setShortcut(tr("Ctrl+E"));
    connect(m_actionExport, SIGNAL(triggered()), this, SLOT(save()));

    m_actionSetupWorkSpace = new QAction(tr("Setup &Workspace..."), this);
    m_actionSetupWorkSpace->setShortcut(tr("Ctrl+W"));
    connect(m_actionSetupWorkSpace, SIGNAL(triggered()), this->m_functionPool, SLOT(showSetWorkSpace()));

    this->m_actionExit = new QAction(tr("E&xit"), this);
    this->m_actionExit->setShortcut(tr("Ctrl+Q"));
    connect(m_actionExit, SIGNAL(triggered()), this, SLOT(close()));

    this->m_actionAbout = new QAction(tr("&About"), this);
    connect(m_actionAbout, SIGNAL(triggered()), this, SLOT(about()));
    this->m_actionZoomIn = new QAction(tr("Zoom &In"), this);
    m_actionZoomIn->setShortcut(tr("Ctrl+="));
    m_actionZoomIn->setEnabled(false);
    connect(m_actionZoomIn, SIGNAL(triggered()), this->ui->singleImageWidget, SLOT(zoomIn()));

    this->m_actionZoomOut = new QAction(tr("Zoom &Out"), this);
    m_actionZoomOut->setShortcut(tr("Ctrl+-"));
    m_actionZoomOut->setEnabled(false);
    connect(m_actionZoomOut, SIGNAL(triggered()), this->ui->singleImageWidget, SLOT(zoomOut()));

    m_actionNormalSize = new QAction(tr("&Normal Size"), this);
    m_actionNormalSize->setEnabled(false);
    connect(m_actionNormalSize, SIGNAL(triggered()), this->ui->singleImageWidget, SLOT(normalSize()));
    m_actionFitToWindow = new QAction(tr("&Fit To Window"), this);
    m_actionFitToWindow->setCheckable(true);
    m_actionFitToWindow->setEnabled(false);
    connect(m_actionFitToWindow, SIGNAL(triggered(bool)), ui->singleImageWidget, SLOT(fitToWindowChange(bool)));



}

void MainWindow::createMenus()
{
    this->m_menuFile = new QMenu(tr("&File"), this);
    m_menuFile->addAction(m_actionImport);
    m_menuFile->addAction(m_actionExport);
    m_menuFile->addSeparator();
    m_menuFile->addAction(m_actionSetupWorkSpace);
    m_menuFile->addSeparator();
    m_menuFile->addAction(m_actionExit);

    this->m_menuImage = new QMenu(tr("&Image"), this);
    m_menuImage->addAction(m_actionZoomIn);
    m_menuImage->addAction(m_actionZoomOut);
    m_menuImage->addAction(m_actionNormalSize);
    m_menuImage->addSeparator();
    m_menuImage->addAction(m_actionFitToWindow);

    this->m_menuHelp = new QMenu(tr("&Help"), this);
    m_menuHelp->addAction(m_actionAbout);


    menuBar()->addMenu(m_menuFile);
    menuBar()->addMenu(m_menuImage);
    menuBar()->addMenu(m_menuHelp);

}

void MainWindow::import()
{
    QStringList fileNames = QFileDialog::getOpenFileNames(this,
                                                    tr("Open File"),
                                                          QDir::currentPath(),
                                                          tr("Images (*.png)"));

    foreach(QString fileName,  fileNames)
    {


        if (!fileName.isEmpty()) {
            QImage image(fileName);
            if (image.isNull()) {
                QMessageBox::information(this, tr("Image Processor"),
                                         tr("Cannot load %1.").arg(fileName));
                continue;
            }
            QString comment = "";
            QStringList dirList = fileName.split(QRegExp("[\\\\/]"));
            if(dirList.size() != 0)
            {
                comment = dirList.at(dirList.size() - 1);
                m_multiImageWidget->append(QPixmap::fromImage(image), comment, fileName);
            }
        }
    }
}

void MainWindow::about()
{
    QMessageBox box;
    box.setIconPixmap(QPixmap::fromImage(QImage(":/images/logo.png")));
    box.setStandardButtons(QMessageBox::Ok);
    box.setDefaultButton(QMessageBox::Ok);
    box.setWindowTitle(tr("About Image Processor"));
    box.setText(tr("<p>The <b>Image Processor</b> is a software used for processing  "
                   "images. </p>"
                   "<p>The Image Processor Developing Team is dedicated to "
                   "provide better image processing experience. </p>"
                   "<p>Thank you for selecting us! We hope you will enjoy it! </p> "));
    box.exec();
}




void MainWindow::updateActions(bool fitToWindow)
{
    m_actionFitToWindow->setChecked(fitToWindow);
    m_actionFitToWindow->setEnabled(true);
    m_actionZoomIn->setEnabled(!m_actionFitToWindow->isChecked());
    m_actionZoomOut->setEnabled(!m_actionFitToWindow->isChecked());
    m_actionNormalSize->setEnabled(!m_actionFitToWindow->isChecked());
}

void MainWindow::updateLabel()
{
    ui->label->setText(ui->singleImageWidget->fileName());
}

void MainWindow::save()
{
    QString dirName = QFileDialog::getExistingDirectory(this,
                                                    tr("Open Directory: "),
                                                          QDir::currentPath());

    QList<CommentedImage*> images = this->m_multiImageWidget->commentedImages();


    if( !dirName.isEmpty())
    {
        emit processStarted();
        int currentPercentage = 0;
        emit processRefreshed(currentPercentage);
        int step = images.size() == 1 ? 100 :  100 / (images.size() - 1);
        foreach(CommentedImage* ci,  images)
        {
            if(ci != NULL && !ci->isAppendImage())
            {
                QPixmap* p= ci->pixmap();
                if(p != NULL)
                {
                    QString newFileName;
                    newFileName.append(dirName).append('/').append(ci->comment());
                    p->save(newFileName, "png",0);
                }
            }
            currentPercentage += step;
            emit processRefreshed(currentPercentage);
        }
    }
    emit processFinished();
}

void MainWindow::updateImages()
{
    qDebug() << "Before test";
    //this->m_multiImageWidget->test();
    qDebug() << "After test";
}

void MainWindow::cursorBusy()
{
    this->setCursor(Qt::ArrowCursor);
}

void MainWindow::cursorNormal()
{
    this->setCursor(Qt::WaitCursor);
}

void MainWindow::disable()
{
    this->setEnabled(false);
}

void MainWindow::enable()
{
    this->setEnabled(true);
}
