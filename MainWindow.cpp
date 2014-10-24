#include <QMessageBox>
#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "SettingsDialog.h"
#include "PortOpenError.h"
#include "PortSendDataError.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize( this->size() );
    m_sender = new Sender;

    // Status Label
    m_statusLabel = new QLabel;
    m_statusLabel->setText( tr( "Select the COM-port" ) );
    ui->statusBar->addPermanentWidget( m_statusLabel, 1 );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionSettings_triggered()
{
    SettingsDialog dialog;
    dialog.setModal( true );
    connect( &dialog, SIGNAL( signalSetSettings( Sender ) ),
             this, SLOT( slotSetSettings( Sender ) ) );
    dialog.exec();
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::slotSetSettings( const Sender &sender )
{
    delete m_sender;

    m_sender = new Sender( sender );

    try {
        m_sender->open();
    } catch( const PortOpenError &e ) {
        QString message( e.what() );
        QMessageBox::critical( this, tr( "Error" ), message );
        return;
    }

    QString text = QString( "Port Name: %1, BaudRate: %2" ).
            arg( m_sender->getPortName() ).arg( m_sender->getBaudRate() );

    m_statusLabel->setText( text );
}

void MainWindow::on_sendButton_clicked()
{
    QString textStr = ui->textlineEdit->text();
    QByteArray data = QByteArray( textStr.toStdString().c_str() );

    try {
        m_sender->send( data );
    } catch( const PortError &e ) {
        QString message( e.what() );
        QMessageBox::critical( this, tr( "Error" ), message );
        return;
    } catch( ... ) {
        QMessageBox::critical( this, tr( "Error" ),
                               tr ( "Error: unknown exception." ) );
        return;
    }
}
