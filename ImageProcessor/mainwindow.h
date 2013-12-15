#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MultiImageWidget;
class QMenu;
class QAction;
class CommentedImage;
class FunctionPool;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:
    void processStarted();
    void processRefreshed(int);
    void processFinished();
private slots:
    void import();
    void save();
    void about();

    void disable();
    void enable();
public slots:
    void updateActions(bool fitToWindow);
    void updateLabel();
    void updateImages();
    void cursorBusy();
    void cursorNormal();
private:
    void createActions();
    void createMenus();
    Ui::MainWindow *ui;
    MultiImageWidget* m_multiImageWidget;
    const CommentedImage* m_appendImage;

    QAction* m_actionImport;
    QAction* m_actionExport;

    QAction* m_actionSetupWorkSpace;
    QAction* m_actionExit;
    QAction* m_actionAbout;

    QAction* m_actionZoomIn;
    QAction* m_actionZoomOut;
    QAction* m_actionNormalSize;
    QAction* m_actionFitToWindow;


    QMenu* m_menuFile;
    QMenu* m_menuImage;
    QMenu* m_menuHelp;

    FunctionPool* m_functionPool;



};

#endif // MAINWINDOW_H
