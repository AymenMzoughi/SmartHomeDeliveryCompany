#include "envoyermail.h"
#include "ui_envoyermail.h"

Envoyermail::Envoyermail(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Envoyermail)
{
    ui->setupUi(this);
    connect(ui->sendBtn,SIGNAL(clicked()),this,SLOT(sendMail()));
    connect(ui->exitBtn, SIGNAL(clicked()),this, SLOT(close()));
     connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));

}
void Envoyermail::browse()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText( fileListString );

}

void Envoyermail::sendMail()
{
    Smtp* smtp = new Smtp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toInt());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->currentText(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->currentText(),ui->msg->toPlainText());
}

void Envoyermail::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}
Envoyermail::~Envoyermail()
{
    delete ui;
}
