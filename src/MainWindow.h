#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    QListWidget *todoList;
    QListWidget *inProgressList;
    QListWidget *doneList;
};

#endif // MAINWINDOW_H
