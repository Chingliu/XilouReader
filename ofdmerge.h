#ifndef OFDMERGE_H
#define OFDMERGE_H

#include <QDialog>
#include <QString>
namespace Ui {
class ofdmerge;
}

class ofdmerge : public QDialog
{
    Q_OBJECT

public:
    explicit ofdmerge(QWidget *parent = 0);
    ~ofdmerge();

private slots:
    void on_sourceButton_clicked();

    void on_targetButton_clicked();

    void on_buttonBox_accepted();

private:
    Ui::ofdmerge *ui;
    QString m_src;
    QString m_target;
};

#endif // OFDMERGE_H
