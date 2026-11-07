#ifndef TASK_H
#define TASK_H
#include <iostream>
#include <QDate>
#include <string>
using namespace std;

class Task {
private:
    string title;
    string description;
    string category;
    string priority;
    QDate dueDate;
    string status;

public:
    Task(string t, string d, string c, string p, QDate dd, string s)
        : title(t), description(d), category(c), priority(p), dueDate(dd), status(s) {
    }
    string getTitle() const {
        return title;
    }
    string getDescription() const {
        return description;
    }
    string getCategory() const {
        return category;
    }
    string getPriority() const {
        return priority;
    }
    QDate getDueDate() const {
        return dueDate;
    }
    string getStatus() const {
        return status;
    }
};

#endif // TASK_H
