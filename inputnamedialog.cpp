#include "inputnamedialog.h"
#include "ui_inputnamedialog.h"

#include <QMessageBox>

InputNameDialog::InputNameDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::InputNameDialog)
{
    ui->setupUi(this);
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &InputNameDialog::onSuccess);
}

InputNameDialog::~InputNameDialog()
{
    delete ui;
}

void InputNameDialog::onSuccess()
{
    if(ui->inputNameLineEdit->text().isEmpty()) {
        QMessageBox::warning(this, tr("Input Error"), tr("Please enter a name."));
    }

    emit nameEntered(ui->inputNameLineEdit->text());

}
