#ifndef DIALOGOPTIONS_H
#define DIALOGOPTIONS_H

#include <QDialog>
#include <QDebug>
#include <QSettings>

namespace Ui { class DialogOptions; }

class DialogOptions : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogOptions(QWidget *parent = 0);
    ~DialogOptions();
    
private:
    Ui::DialogOptions *ui;
    bool SaveOptions();
    void LoadOptions();

    QString PrintFormat;

private slots:
    void QuitWithChange();
    void QuitWithoutchange();
    void ApplyChange();
};

#endif // DIALOGOPTIONS_H
