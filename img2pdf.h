#ifndef IMG2PDF_H
#define IMG2PDF_H

#include <QDialog>
#include <QString>
namespace Ui {
class img2pdf;
}

class img2pdf : public QDialog
{
    Q_OBJECT

public:
    explicit img2pdf(QWidget *parent = 0);
    ~img2pdf();

private slots:
    void on_selectImgBtn_clicked();

    void on_save2Btn_clicked();

    void on_selectTextBtn_clicked();

private:
    Ui::img2pdf *ui;
    QString m_imgpath;
    QString m_txtpath;
};

#endif // IMG2PDF_H
