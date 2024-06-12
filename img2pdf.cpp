#include "img2pdf.h"
#include "ui_img2pdf.h"
#include <xilou_convert.h>
#include <QFileInfo>
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QByteArray>
img2pdf::img2pdf(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::img2pdf)
{
    ui->setupUi(this);
}

img2pdf::~img2pdf()
{
    delete ui;
}

void img2pdf::on_selectImgBtn_clicked()
{
    m_imgpath = QFileDialog::getOpenFileName(this, tr("打开"), tr(""), tr("图像文件(*.png *.jpg)"));
    if (m_imgpath.isEmpty())
    {
        return;
    }
    ui->imgpathEdit->setText(m_imgpath);
}

void img2pdf::on_save2Btn_clicked()
{
    QString save2 = QFileDialog::getSaveFileName(this, tr("Save File"),
                                "",
                                tr("版式文件(*.pdf *.ofd)"));
    ui->dstpathEdit->setText(save2);
    QFileInfo file(save2);
    if(file.exists()){
        ;
    }else{
        XILOU_PACKAGE pkg = NULL;

        int iret = xilou_AppendImagePage(&pkg, m_imgpath.toUtf8().data());
        if(iret != 0)
        {
            QString msg=QString(tr("插入图片错误： %1")).arg(iret);
            QMessageBox::warning(this, "Error", msg);
            return;
        }
        if(!m_txtpath.isEmpty()){
            QFile jsonFile(m_txtpath);
            if(jsonFile.open(QIODevice::ReadOnly|QIODevice::Text)){
                QByteArray  ba = jsonFile.readAll();
                iret = xilou_AddTextOnPage(pkg, 0, ba.data());
                if(iret != 0){
                    QString msg=QString(tr("插入文字错误： %1")).arg(iret);
                    QMessageBox::warning(this, "Error", msg);
                }
            }else{
                QString msg=QString(tr("读取文件错误： %1")).arg(m_txtpath);
                QMessageBox::warning(this, "Error", msg);
            }

        }
        iret = xilou_Save2File(&pkg, save2.toUtf8().data());
        if(pkg){
            xilou_ClosePackage(pkg);
        }
        if(iret != 0)
        {
            QString msg=QString(tr("保存文件： %1")).arg(iret);
            QMessageBox::warning(this, "Error", msg);
            return;
        }
        QMessageBox::warning(this, "Suc", tr("转换成功"));
    }

}

void img2pdf::on_selectTextBtn_clicked()
{
    m_txtpath = QFileDialog::getOpenFileName(this, tr("打开"), tr(""), tr("文本文件(*.json)"));
    if (m_txtpath.isEmpty())
    {
        return;
    }
    ui->textpathEdit->setText(m_txtpath);
}
