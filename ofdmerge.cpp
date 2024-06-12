#include "ofdmerge.h"
#include "ui_ofdmerge.h"
#include <QFileInfo>
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <xilou_convert.h>
ofdmerge::ofdmerge(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ofdmerge)
{
    ui->setupUi(this);
}

ofdmerge::~ofdmerge()
{
    delete ui;
}

void ofdmerge::on_sourceButton_clicked()
{
    m_src = QFileDialog::getOpenFileName(this, tr("打开"), tr(""), tr("版式文件(*.ofd)"));
    if (m_src.isEmpty())
    {
        return;
    }
    ui->sourcePathEdit->setText(m_src);
}

void ofdmerge::on_targetButton_clicked()
{
    m_target = QFileDialog::getOpenFileName(this, tr("打开"), tr(""), tr("版式文件(*.ofd)"));
    if(m_target.isEmpty()){
        return ;
    }
    ui->targetPathEdit->setText(m_target);
}

void ofdmerge::on_buttonBox_accepted()
{
    xilou_OfdMerge(m_target.toUtf8().data(), m_src.toUtf8().data());
}
