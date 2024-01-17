#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QPainter>
#include <QScrollBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), pageIndex(0), m_scale(1.0f)
{
    ui->setupUi(this);
    ui->verticalLayout->removeWidget(ui->scrollArea);
    ui->scrollArea = new CScrollArea(ui->centralwidget);
    ui->verticalLayout->addWidget(ui->scrollArea);
    xilou_InitLibrary();
    m_pkg = NULL;
}

MainWindow::~MainWindow()
{
    delete ui;
    if(m_pkg)
        delete m_pkg;
    xilou_DestroyLibrary();
}

void MainWindow::on_actionopen_triggered()
{
    QString filePath = QFileDialog::getOpenFileName(this, tr("打开"), tr(""), tr("版式文件(*.pdf *.ofd)"));
    if (filePath.isEmpty())
    {
        return;
    }
    if(m_pkg){
        delete m_pkg;
        m_pkg = NULL;
    }
    m_pkg = new CPackageManager(filePath, QString());
    if(!m_pkg)
    {
        QMessageBox::information(this, tr("错误"), tr("文件打开失败！"));
        return;
    }
    if (!m_pkg->GetDoc())
    {
        QMessageBox::information(this, tr("错误"), tr("文件打开失败！"));
        return;
    }
    // 布置阅读区
    initView();
}

void MainWindow::initView()
{
    if (!m_pkg->GetDoc())
    {
        return;
    }
    // 加载页
    XILOU_PAGE page = m_pkg->GetPage(pageIndex);//xilou_LoadPage(m_doc, pageIndex);
    if(!page)
        return;
    // 获取页大小
    double pageW = xilou_GetPageWidth(page);
    double pageH = xilou_GetPageHeight(page);
    pageW *= m_scale;
    pageH *= m_scale;
#if 0
    // 创建页图片
    FPDF_BITMAP pagePixmap = FPDFBitmap_Create(pageW, pageH, 1);
    FPDFBitmap_FillRect(pagePixmap, 0, 0, pageW, pageH, 0xFFFFFFFF);
    xilou_RenderPageBitmap(pagePixmap, page, 0, 0, pageW, pageH, 0, XILOUPAGRRENDER_ANNOT | XILOUPAGRRENDER_REVERSE_BYTE_ORDER);
    // 获取Buffer
    void* bgrAbuffer = FPDFBitmap_GetBuffer(pagePixmap);
    int pixmapW = FPDFBitmap_GetWidth(pagePixmap);
    int pixmapH = FPDFBitmap_GetHeight(pagePixmap);
    // BGRA转RGBA
    unsigned char* rgbAbuffer = (unsigned char* )malloc(sizeof(char) * pixmapW * pixmapH * 4);
    ConvertBetweenBGRAandRGBA((unsigned char* )bgrAbuffer, pixmapW, pixmapH, rgbAbuffer);
    // 转换为QImage
    m_pageImg = QImage(rgbAbuffer, pixmapW, pixmapH, QImage::Format_RGB32);
    FPDFBitmap_Destroy(pagePixmap);
#else
    m_pageImg =  QImage(pageW, pageH, QImage::Format_ARGB32);
    Q_ASSERT(!m_pageImg.isNull());
    m_pageImg.fill(0xFFFFFFFF);

    FPDF_BITMAP bitmap = FPDFBitmap_CreateEx(pageW, pageH,
                                             FPDFBitmap_BGRA,
                                             m_pageImg.scanLine(0), m_pageImg.bytesPerLine());
    Q_ASSERT(bitmap);
    xilou_RenderPageBitmap(bitmap, page, 0, 0, pageW, pageH, 0, XILOUPAGRRENDER_ANNOT);
    FPDFBitmap_Destroy(bitmap);
    bitmap = nullptr;
#endif
    if (pageW < ui->scrollArea->width())
    {
        ui->scrollArea->horizontalScrollBar()->setRange(0, 0);
    }
    else
    {
        ui->scrollArea->horizontalScrollBar()->setRange(0, pageW - ui->scrollArea->width());
        ui->scrollArea->horizontalScrollBar()->setPageStep(ui->scrollArea->viewport()->width());
        ui->scrollArea->horizontalScrollBar()->setSingleStep(pageW / 10);
    }

    if (pageH < ui->scrollArea->height())
    {
        ui->scrollArea->horizontalScrollBar()->setRange(0, 0);
    }
    else
    {
        ui->scrollArea->verticalScrollBar()->setRange(0, pageH - ui->scrollArea->height());
        ui->scrollArea->verticalScrollBar()->setPageStep(ui->scrollArea->viewport()->height());
        ui->scrollArea->verticalScrollBar()->setSingleStep(pageH / 10);
    }
    // 获取文档总数
    int pageCount = xilou_GetPageCount(m_pkg->GetDoc());
    ui->actionpagecount->setText(tr("%1/%2").arg(pageIndex + 1).arg(pageCount));
    ui->actionscale->setText(tr("%1%").arg(m_scale * 100, 0, 'f', 2));
    ui->scrollArea->viewport()->update();
}

void MainWindow::ConvertBetweenBGRAandRGBA(unsigned char* input, int pixel_width,
    int pixel_height, unsigned char* output)
{
    int offset = 0;

    for (int y = 0; y < pixel_height; y++)
    {
        for (int x = 0; x < pixel_width; x++)
        {
            output[offset] = input[offset + 2];
            output[offset + 1] = input[offset + 1];
            output[offset + 2] = input[offset];
            output[offset + 3] = input[offset + 3];
            offset += 4;
        }
    }
}

void MainWindow::on_actionpre_triggered()
{
    pageIndex = qMax(0, pageIndex - 1);
    initView();
}

void MainWindow::on_actionfirst_triggered()
{
    pageIndex = 0;
    initView();
}

void MainWindow::on_actionnext_triggered()
{
    // 获取文档总数
    int pageCount = xilou_GetPageCount(m_pkg->GetDoc());
    pageIndex = qMin(pageCount - 1, pageIndex + 1);
    initView();
}

void MainWindow::on_actionlast_triggered()
{
    // 获取文档总数
    int pageCount = xilou_GetPageCount(m_pkg->GetDoc());
    pageIndex = pageCount - 1;
    initView();
}

void MainWindow::on_actionzoomout_triggered()
{
    m_scale = qMin<float>(64.0f, m_scale + 0.1);
    initView();
}

void MainWindow::on_actionzoomin_triggered()
{
    m_scale = qMax<float>(0.1f, m_scale - 0.1);
    initView();
}


CScrollArea::CScrollArea(QWidget *parent):
    QScrollArea(parent)
{
    m_window = qobject_cast<MainWindow*>(window());
    setFrameStyle(QScrollArea::NoFrame);
    // 绑定滚动信号
    connect(verticalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(onVscrollBarChange(int)));
    connect(horizontalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(onHscrollBarChange(int)));
}

CScrollArea::~CScrollArea()
{

}

void CScrollArea::paintEvent(QPaintEvent *)
{
    if (m_window->m_pageImg.isNull())
    {
        return;
    }
    QPainter painter(viewport());
    int pageW = m_window->m_pageImg.width();
    int pageH = m_window->m_pageImg.height();
    int deltaX = 0;
    int deltaY = 0;
    if (pageW < width())
    {
        deltaX = (width() - pageW) * 0.5;
    }
    else
    {
        deltaX = -horizontalScrollBar()->value();
    }

    if (pageH < height())
    {
        deltaY = (height() - pageH) * 0.5;
    }
    else
    {
        deltaY = -verticalScrollBar()->value();
    }

    painter.drawImage(deltaX, deltaY, m_window->m_pageImg);
}

void CScrollArea::onVscrollBarChange(int)
{
    viewport()->update();
}

void CScrollArea::onHscrollBarChange(int)
{
    viewport()->update();
}

void MainWindow::on_actionToPDF_triggered()
{
    QString save2 = QFileDialog::getSaveFileName(this, tr("Save File"),
                                "",
                                tr("版式文件(*.pdf *.ofd *.txt)"));
    xilou_Convert(m_pkg->GetFilePath().toUtf8().data(), save2.toUtf8().data(), QString("*").toUtf8().data());
}

void MainWindow::on_actionverify_triggered()
{
    if(m_pkg && m_pkg->GetDoc()){
        long count = xilou_docsign_count(m_pkg->GetDoc());
        QString allmsg;
        ;
        QString verify_msg("");
        if(count <0){
            QMessageBox::information(NULL, "verify", "error! not support");
            return;
        }
        if(count ==0){
            QMessageBox::information(NULL, "verify", "no signature!");
            return;
        }
        while(count >0){
            unsigned long vret = xilou_verify(m_pkg->GetDoc(), count -1);
            if(vret != XILOU_E_SUC){
                unsigned char *utf8_msg;
                size_t len = xilou_sig_errmsg(m_pkg->GetDoc(), count -1, &utf8_msg);
                verify_msg = QString::fromUtf8((const char *)utf8_msg, len);
            }
           allmsg += QString("sign[%1] verify result[%2] message[%3]\r\n\r\n").arg(count -1).arg(vret == XILOU_E_SUC ? "success":"failed").arg(verify_msg);
            count--;
        }
        QMessageBox::information(NULL, "verify", allmsg);
    }
}
