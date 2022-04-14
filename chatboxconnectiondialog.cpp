#include "chatboxconnectiondialog.h"
#include "ui_ChatboxConnectionDialog.h"
namespace DuarteCorporation{
ChatboxConnectionDialog::ChatboxConnectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChatboxConnectionDialog)
{
    ui->setupUi(this);
}

ChatboxConnectionDialog::~ChatboxConnectionDialog()
{
    delete ui;
}

void ChatboxConnectionDialog::on_ok_clicked()
{
   nHostname = ui->hostname->text();
   nPort = ui->port->value();
   accept();
}

void ChatboxConnectionDialog::on_cancel_clicked()
{
reject();
}
}
