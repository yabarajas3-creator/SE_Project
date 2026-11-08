#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "task.h"
#include <QDate>
#include <fstream>
#include <QMessageBox>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadTasks();
    viewTasks();
    ui->StackedWidget->setCurrentWidget(ui->HomePage);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::saveTask()
{
    int i = tasks.size() -1;
    fstream myFile;
    myFile.open("all_Tasks.txt", ios::app);
    if (myFile.is_open())
    {
        myFile << "Title: " << tasks[i].getTitle() << "\n";
        myFile << "Description: " << tasks[i].getDescription() << "\n";
        myFile << "Category: " << tasks[i].getCategory() << "\n";
        myFile << "Priority: " << tasks[i].getPriority() << "\n";
        myFile << "Due Date: " << tasks[i].getDueDate().toString("yyyy-MM-dd").toStdString() << "\n";
        myFile << "Status: " << tasks[i].getStatus() << "\n";
        myFile << "------------------------\n";
    }
}
void MainWindow::viewTasks()
{
    ui->taskListPane->clear();
    for (size_t i = 0; i < tasks.size(); i++)
    {
        QString title = QString::fromStdString(tasks[i].getTitle());
        QString priority = QString::fromStdString(tasks[i].getPriority());
        QString status = QString::fromStdString(tasks[i].getStatus());
        QString category = QString::fromStdString(tasks[i].getCategory());
        QString display = title + "                        " + status + "\n" + category + ", " + priority;
        ui->taskListPane->addItem(display);
    }

}
void MainWindow::loadTasks()
{
    fstream myFile;
    myFile.open("all_tasks.txt", ios::in);
    if (myFile.is_open())
    {
        string title, description, category, priority, status, date, separator;
        while (getline(myFile, title))
        {
            if (!getline(myFile, description) ||
                !getline(myFile, category) ||
                !getline(myFile, priority) ||
                !getline(myFile, date) ||
                !getline(myFile, status) ||
                !getline(myFile, separator))
            {
                break;
            }
            title = title.substr(7);
            description = description.substr(13);
            category = category.substr(10);
            priority = priority.substr(10);
            date = date.substr(10);
            status = status.substr(8);

            QDate DD = QDate::fromString(QString::fromStdString(date), "yyyy-MM-dd");
            Task loadedTask(title, description, category, priority, DD, status);
            tasks.push_back(loadedTask);
        }

    }
}
void MainWindow::on_createTaskButton_clicked()
{
    QString title = ui->taskNameInput->text();
    if(title.trimmed().isEmpty())
    {
        QMessageBox::warning(this, "Invalid Task", "Task name must be filled.");
        return;
    }
    QString description = ui->taskDescriptionInput->toPlainText();
    QString category = ui->taskCategoryInput->currentText();
    QString priority = ui->TaskPriorityInput->currentText();
    QString status = ui->taskStatusInput->currentText();
    QDate dueDate = ui->taskDueDateInput->date();

    Task newTask(title.toStdString(), description.toStdString(), category.toStdString(), priority.toStdString(), dueDate, status.toStdString());
    tasks.push_back(newTask);

    saveTask();
    viewTasks();
    QMessageBox::information(this, "Success", "Task has been created");
    ui->StackedWidget->setCurrentWidget(ui->HomePage);


}


void MainWindow::on_CreateTaskButton_clicked()
{
    ui->StackedWidget->setCurrentWidget(ui->CreateTask);
}


void MainWindow::on_createTaskBackButton_clicked()
{
    ui->StackedWidget->setCurrentWidget(ui->HomePage);
}

