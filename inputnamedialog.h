#ifndef INPUTNAMEDIALOG_H
#define INPUTNAMEDIALOG_H

#include <QDialog>

namespace Ui {
class InputNameDialog;
}

class InputNameDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InputNameDialog(QWidget *parent = nullptr);
    ~InputNameDialog();



\
    signals:
    void nameEntered(QString name);

private:
    Ui::InputNameDialog *ui;


    private slots:
    void onSuccess();
};

#endif // INPUTNAMEDIALOG_H
