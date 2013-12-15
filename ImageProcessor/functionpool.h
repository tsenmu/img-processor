#ifndef FUNCTIONPOOL_H
#define FUNCTIONPOOL_H

#include <QWidget>
#include <QStringList>
class MultiImageWidget;
class CommentedImage;
class FunctionPool : public QObject
{
    Q_OBJECT
public:
    explicit FunctionPool(QObject *parent = 0);
    void properties(QString functionName);
    QStringList functionNameList();
    void setMultiImageWidget(MultiImageWidget* m);
    void setWorkSpace(QString ws);
    QString workSpace();
    void setData(QList<QPixmap> pixmaps, QList<QString> filenames, QPixmap* referencePixmap);
    void setModulePath(const QString& path);

signals:
    void pixmapUpdated(QList<QPixmap> pixmaps);
    void cursorBusy();
    void cursorNormal();
public slots:
    void showSetWorkSpace();
    void call(QString functionName);

private:
    QStringList m_functionNameList;
    MultiImageWidget* m_multiImageWidget;
    QString m_workSpace;
    QString m_modulepath;

    QList<QPixmap>* m_pixmaps;
    QList<QString>* m_filenames;
    QPixmap* m_referencePixmap;

    void saveInWorkSpace(const QString& filename, const QPixmap& p);
    QPixmap loadInWorkSpace(const QString& filename);
    void clearWorkSpace();
    void runProcess(const QString& filename, const QString& imagefile);
    void fp_HomomorphicFilter();
    void fpp_HomomorphicFilter();
    double fpv_HomomorphicFilter_f_high;
    double fpv_HomomorphicFilter_f_low;



    void fp_WhiteBalance();
    void fpp_WhiteBalance();

    void fp_HistogramEqualization();
    void fpp_HistogramEqualization();

    void fp_BrightnessNormalization();
    void fpp_BrightnessNormalization();
    double fpv_BrightnessNormalization_k;

};

#endif // FUNCTIONPOOL_H
