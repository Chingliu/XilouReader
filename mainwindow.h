#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <fpdf_doc.h>
#include <fpdfview.h>
#include <xilou_view.h>
#include <xilou_convert.h>
#include <QScrollArea>
#include <map>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class CPackageManager{
    XILOU_PACKAGE m_pkg;
    XILOU_DOCUMENT m_doc;
    std::map<int, XILOU_PAGE> m_pages;
    int doc_idx;
    QString m_fpath;
  public:
    CPackageManager(QString fpath, QString password){
        m_pkg = xilou_OpenPackage(fpath.toUtf8().data(), NULL);
        m_doc = xilou_LoadDocument(m_pkg, 0);
        doc_idx = 0;
        m_fpath = fpath;
    }
    void ReleaseDoc(){
        if(m_doc){
          std::map<int, XILOU_PAGE>::iterator it = m_pages.begin();
          for(;it != m_pages.end(); ++it){
              xilou_DropPage(it->second);
          }
          xilou_DropDocument(m_doc);
          m_doc = NULL;
        }
    }
    ~CPackageManager(){
        ReleaseDoc();
    }
    QString GetFilePath()const{return m_fpath;}
    XILOU_DOCUMENT GetDoc(int index = 0){
        if(doc_idx != index && m_doc){
            ReleaseDoc();
        }
        if(m_doc) return m_doc;
        else{
            m_doc = xilou_LoadDocument(m_pkg, index);
            doc_idx = index;
        }
        return m_doc;
    }
    XILOU_PAGE GetPage(int index){
        std::map<int, XILOU_PAGE>::iterator it = m_pages.find(index);
        if(it != m_pages.end())
            return it->second;
        XILOU_PAGE page = xilou_LoadPage(m_doc, index);
        if(page){
            m_pages.insert(std::make_pair(index, page));
            return page;
        }
        return NULL;
    }
};
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionopen_triggered();

    void on_actionpre_triggered();

    void on_actionfirst_triggered();

    void on_actionnext_triggered();

    void on_actionlast_triggered();

    void on_actionzoomout_triggered();

    void on_actionzoomin_triggered();

    void on_actionToPDF_triggered();

private:
    void initView();
    void ConvertBetweenBGRAandRGBA(unsigned char *input, int pixel_width, int pixel_height, unsigned char *output);

private:
    friend class CScrollArea;
    Ui::MainWindow *ui;
    CPackageManager *m_pkg;
    int pageIndex;
    float m_scale;
    QImage m_pageImg;
};

class CScrollArea : public QScrollArea
{
    Q_OBJECT

public:
    CScrollArea(QWidget *parent = nullptr);
    ~CScrollArea();

protected:
    void paintEvent(QPaintEvent *);

private slots:
    void onVscrollBarChange(int);
    void onHscrollBarChange(int);

private:
    MainWindow *m_window;
};

#endif // MAINWINDOW_H
