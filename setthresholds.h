#ifndef SETTHRESHOLDS_H
#define SETTHRESHOLDS_H

#include <QDialog>
#include <QIntValidator>
#include "iomanager.h"

namespace Ui {
class SetThresholds;
}

class SetThresholds : public QDialog
{
    Q_OBJECT

public:
    explicit SetThresholds(QWidget *parent = 0);
    ~SetThresholds();

private slots:
    void on_lineEdit_2_textEdited(const QString &arg1);

    void on_lineEdit_3_textEdited(const QString &arg1);

    void on_lineEdit_4_textEdited(const QString &arg1);

    void on_lineEdit_5_textEdited(const QString &arg1);

    void on_lineEdit_6_textEdited(const QString &arg1);

    void on_lineEdit_7_textEdited(const QString &arg1);

    void on_buttonBox_accepted();
    void CheckForValidity();

    void on_Apply_clicked();

private:
    Ui::SetThresholds *ui;
    QPalette palette;
    QPalette palette2;
    QPalette palette3;
    QPalette palette4;
    QPalette palette5;
    QPalette palette6;

    QValidator *validator;
    IOManager * p_IOControl;

    char correctValues[6];
    bool minTempGreaterThanMax;
    bool minHumGreaterThanMax;
    bool minLightGreaterThanMax;

};

#endif // SETTHRESHOLDS_H
