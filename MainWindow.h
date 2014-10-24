#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "Sender.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow( QWidget *parent = 0 );
    ~MainWindow();

private slots:
    void on_actionSettings_triggered();
    void on_actionExit_triggered();
    void slotSetSettings( const Sender &sender );

    void on_sendButton_clicked();

private:
    Ui::MainWindow *ui;
    Sender *m_sender;
    QLabel *m_statusLabel;
};

#endif // MAINWINDOW_H
