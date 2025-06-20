#include "MainWindow.h"

#include <QGroupBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QTime>

enum TaskRoles {
    TimeRole = Qt::UserRole + 1,
    SummaryRole,
    DescriptionRole
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *central = new QWidget(this);
    QHBoxLayout *layout = new QHBoxLayout(central);

    auto createColumn = [layout](const QString &title) -> QListWidget * {
        QGroupBox *box = new QGroupBox(title);
        QVBoxLayout *vbox = new QVBoxLayout(box);
        QListWidget *list = new QListWidget(box);
        list->setSelectionMode(QAbstractItemView::SingleSelection);
        list->setDragEnabled(true);
        list->setAcceptDrops(true);
        list->setDropIndicatorShown(true);
        list->setDragDropMode(QAbstractItemView::InternalMove);
        vbox->addWidget(list);
        box->setLayout(vbox);
        layout->addWidget(box);
        return list;
    };

    todoList = createColumn("Todo");
    inProgressList = createColumn("In Progress");
    doneList = createColumn("Done");

    setCentralWidget(central);

    // Example task
    QListWidgetItem *item = new QListWidgetItem("Example task");
    item->setData(TimeRole, QTime::currentTime().toString());
    item->setData(SummaryRole, "Short description");
    item->setData(DescriptionRole, "Full description of the task");
    todoList->addItem(item);
}
