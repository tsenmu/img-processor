#include "functionpool.h"
#include "multiimagewidget.h"
#include "commentedimage.h"
#include "homomorphicfilterdialog.h"
#include "brightnessnormalizationdialog.h"
#include <QStringList>
#include <QDebug>
#include <QProcess>
#include <QDir>
#include <QFileDialog>
#include <QMessageBox>
#include <QList>

FunctionPool::FunctionPool(QObject *parent) :
        QObject(parent)
{
    m_functionNameList.append("Homomorphic Filter");
    m_functionNameList.append("White Balance");
    m_functionNameList.append("Histogram Equalization");
    m_functionNameList.append("Brightness Normalization");
    setWorkSpace(QDir::currentPath());
    showSetWorkSpace();
    m_pixmaps = NULL;
    m_filenames = NULL;

    m_referencePixmap = NULL;
    this->m_modulepath = "./modules/";

    this->fpv_HomomorphicFilter_f_high = 0.5;
    this->fpv_HomomorphicFilter_f_low = 0.5;

    fpv_BrightnessNormalization_k = 0.02;
}

void FunctionPool::showSetWorkSpace()
{
    QString dirName = QFileDialog::getExistingDirectory(0,
                                                    tr("Setup Workspace: "),
                                                          QDir::currentPath());
    if( !dirName.isEmpty())
    {
        m_workSpace = dirName;
        QMessageBox::information(0,tr("Workspace Setup Successfully!"), QString(tr("Current workspace: \n")).append(dirName));
    }
    else
    {
        QMessageBox::information(0,tr("Workspace Setup Cancelled!"), QString(tr("Current workspace: \n")).append(m_workSpace));
    }
}

void FunctionPool::call(QString functionName)
{
    if(functionName == "Homomorphic Filter")
    {
        this->fp_HomomorphicFilter();
    }
    else if(functionName == "White Balance")
    {
        this->fp_WhiteBalance();
    }
    else if(functionName == "Histogram Equalization")
    {
        this->fp_HistogramEqualization();
    } else if(functionName == "Brightness Normalization")
    {
        this->fp_BrightnessNormalization();
    }
    clearWorkSpace();
}

void FunctionPool::properties(QString functionName)
{
    if(functionName == "Homomorphic Filter")
    {
        fpp_HomomorphicFilter();
    }
    else if(functionName == "White Balance")
    {
        fpp_WhiteBalance();
    }
    else if(functionName == "HistogramEqualization")
    {
        fpp_HistogramEqualization();
    } else if(functionName == "Brightness Normalization")
    {
        this->fpp_BrightnessNormalization();
    }
}

QStringList FunctionPool::functionNameList()
{
    return m_functionNameList;
}

void FunctionPool::setMultiImageWidget(MultiImageWidget* m)
{
    m_multiImageWidget = m;
}

void FunctionPool::setWorkSpace(QString ws)
{
    m_workSpace = ws;
}

QString FunctionPool::workSpace()
{
    return m_workSpace;
}


void FunctionPool::fp_HomomorphicFilter()
{
    for(int i = 0 ; i < m_pixmaps->size(); ++i)
    {
        saveInWorkSpace(m_filenames->at(i), m_pixmaps->at(i));
        runProcess("HomomorphicFilter.exe", m_filenames->at(i));
        QPixmap p = loadInWorkSpace(m_filenames->at(i));
        m_pixmaps->replace(i, p);
    }
    emit pixmapUpdated(*m_pixmaps);

}

void FunctionPool::fp_WhiteBalance()
{
    for(int i = 0 ; i < m_pixmaps->size(); ++i)
    {
        saveInWorkSpace(m_filenames->at(i), m_pixmaps->at(i));
        runProcess("WhiteBalance.exe", m_filenames->at(i));
        QPixmap p = loadInWorkSpace(m_filenames->at(i));
        m_pixmaps->replace(i, p);
    }
    emit pixmapUpdated(*m_pixmaps);
}



void FunctionPool::fpp_HomomorphicFilter()
{
    HomomorphicFilterDialog dialog;
    dialog.setFLow(this->fpv_HomomorphicFilter_f_low);
    dialog.setFHigh(this->fpv_HomomorphicFilter_f_high);

    int ret = dialog.exec();
    if(ret == QDialog::Accepted)
    {
        this->fpv_HomomorphicFilter_f_low = dialog.fLow();
        this->fpv_HomomorphicFilter_f_high = dialog.fHigh();
    }
}

void FunctionPool::fpp_WhiteBalance()
{

}


void FunctionPool::setData(QList<QPixmap> pixmaps, QList<QString> filenames, QPixmap* referencePixmap)
{
    if(m_pixmaps != NULL)
    {
        delete m_pixmaps;
    }
    if(m_filenames != NULL)
    {
        delete m_filenames;
    }
    if(this->m_referencePixmap != NULL)
    {
        delete m_referencePixmap;
    }
    m_pixmaps = new QList<QPixmap>(pixmaps);
    m_filenames = new QList<QString>(filenames);
    if(referencePixmap != NULL)
    {
        m_referencePixmap = new QPixmap(*referencePixmap);
    } else
    {
        m_referencePixmap = NULL;
    }

}

void FunctionPool::saveInWorkSpace(const QString& filename, const QPixmap& p)
{
    QString path = workSpace().append("/__").append(filename);
    p.save(path, "png", 0);
}

QPixmap FunctionPool::loadInWorkSpace(const QString& filename)
{
    QString path = workSpace().append("/__").append(filename);
    return QPixmap::fromImage(QImage(path));
}

void FunctionPool::runProcess(const QString& filename, const QString& imagefile)
{
    QProcess* proc = new QProcess(this);
    QString procPath = m_modulepath;
    procPath.append(filename);
    proc->start(procPath);
    if(filename == "BrightnessNormalization.exe")
    {
        QString referencePath = QString("'").append(workSpace()).append("/__reference.png").append("'\n");
        proc->write(referencePath.toUtf8());
    }
    QString path = QString("'").append(workSpace()).append("/__").append(imagefile).append("'\n");
    proc->write(path.toUtf8());
    if(filename == "HomomorphicFilter.exe")
    {
        proc->write(QString::number(this->fpv_HomomorphicFilter_f_high).append("\n").toUtf8());
        proc->write(QString::number(this->fpv_HomomorphicFilter_f_low).append("\n").toUtf8());
    } else if(filename == "BrightnessNormalization.exe")
    {

        proc->write(QString::number(this->fpv_BrightnessNormalization_k).append("\n").toUtf8());
    }
    proc->waitForFinished(-1);
    proc->kill();
    delete proc;
}

void FunctionPool::setModulePath(const QString& path)
{
    this->m_modulepath = path;
}

void FunctionPool::fp_HistogramEqualization()
{
    for(int i = 0 ; i < m_pixmaps->size(); ++i)
    {
        saveInWorkSpace(m_filenames->at(i), m_pixmaps->at(i));
        runProcess("HistogramEqualization.exe", m_filenames->at(i));
        QPixmap p = loadInWorkSpace(m_filenames->at(i));
        m_pixmaps->replace(i, p);
    }
    emit pixmapUpdated(*m_pixmaps);

}

void FunctionPool::fpp_HistogramEqualization()
{

}

void FunctionPool::fp_BrightnessNormalization()
{
    if(m_referencePixmap == NULL)
    {
        QMessageBox::warning(NULL, "No reference selected!", "No reference selected!");
        return;
    }
    saveInWorkSpace("reference.png", *m_referencePixmap);
    for(int i = 0 ; i < m_pixmaps->size(); ++i)
    {
        saveInWorkSpace(m_filenames->at(i), m_pixmaps->at(i));
        runProcess("BrightnessNormalization.exe", m_filenames->at(i));
        QPixmap p = loadInWorkSpace(m_filenames->at(i));
        m_pixmaps->replace(i, p);
    }
    emit pixmapUpdated(*m_pixmaps);
}


void FunctionPool::fpp_BrightnessNormalization()
{
    BrightnessNormalizationDialog dialog;
    dialog.setK(this->fpv_BrightnessNormalization_k);
    if(dialog.exec() == QDialog::Accepted)
    {
        this->fpv_BrightnessNormalization_k = dialog.k();
    }
}

void FunctionPool::clearWorkSpace()
{
    QDir dir(workSpace());
    QStringList filters;
    filters << "*.png";
    dir.setNameFilters(filters);
    QStringList list = dir.entryList();
    foreach(QString str, list)
    {
        str = dir.path().append("/").append(str);
       // qDebug() << str;
        QFile::remove(str);
    }
}
