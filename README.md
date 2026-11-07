# SE_Project
This is the task organizer application by Yahshua Barajas.  This software is meant to display create and manage tasks that a person has from work, school, or personal.  I used QT creator for assembling my code and creating a gui. 

Prerequisites
In order to run this application the following software is required:
Qt Creator
Qt 6.12.0 with Qt Widgets support
MinGW 64-bit C++ compiler
Git (for downloading the repository)

Install Qt Creator and the required Qt and MinGW components.
Clone the GitHub repository using the following command:
git clone https://github.com/yabarajas3-creator/SE_Project.git
Open Qt Creator.
Select File > Open File or Project.
Navigate to the downloaded repository and open SE_sprint1.pro.
Select the Desktop Qt 6.12.0 MinGW 64-bit kit and configure the project.

Running the Application
Open the project in Qt Creator.
Click the green Run button to build and launch the application.
The application will open on the Home Page and display any previously saved tasks.
Click Create Task to open the task creation page.
Enter the task title, description, category, priority, status, and due date.
Click Create Task to save the task and return to the Home Page.
The new task should appear in the task list.
Close and reopen the application to verify that saved tasks are loaded again.

Configuration
Tasks are saved locally on a text file named all_tasks.txt, located in the application's working directory. The file is created when a task is first saved if it does not already exist.

Run through guide
In this version of the project you start at a home page that shows a list of tasks currently saved.  This home page also displays a button you can press called create task.  
Upon pressing it you are taken to a page allowing you to create a task.  You are prompted to input a task title, description, category, priority level, status, and due date.  
There is also a back button in case you want to return from the page.  Once those fields have been filled at the bottom there is a create task button that saves your inputs as all a part of one task.  
Once pressed, you are brought back to the homepage with an updated list of your tasks.

Known Limitations
In this version there is no functionality to remove or edit tasks yet and the gui is still in a more crude state.
Task information is stored in a local file rather than a database.  