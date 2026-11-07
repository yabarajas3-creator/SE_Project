#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "task.h"
#include <vector>
#include <QMainWindow>
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_createTaskButton_clicked();

    void on_CreateTaskButton_clicked();

    void on_createTaskBackButton_clicked();

private:
    Ui::MainWindow *ui;
    vector<Task> tasks;
    void loadTasks();
    void viewTasks();
    void saveTask();
};
#endif // MAINWINDOW_H
