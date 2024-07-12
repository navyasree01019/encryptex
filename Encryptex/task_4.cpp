#include <bits/stdc++.h>
using namespace std;

struct taskList
{
    string taskName;
    bool isCompleted = false;
};

vector<taskList> tasks;

void addTask(const string& task)
{
    taskList newTask;
    newTask.taskName = task;
    tasks.push_back(newTask);
}

void displayTasks()
{
    if (tasks.empty())
    {
        cout << "No tasks to display." << endl;
    }
    else
    {
        cout << "To-Do List:" << endl;
        for (int i = 0; size_t(i) < tasks.size(); i++)
        {
            cout << i + 1 << ". " << tasks[i].taskName << " [" << (tasks[i].isCompleted ? "Done" : "Not Done") << "]" << endl;
        }
    }
}

void deleteTask(int index)
{
    if (index < 1 || size_t(index) > tasks.size())
    {
        cout << "Invalid task number." << endl;
    }
    else
    {
        cout << "Task deleted: " << tasks[index - 1].taskName << endl;
        tasks.erase(tasks.begin() + index - 1);
    }
}

void searchTask(const string& task)
{
    auto it = find_if(tasks.begin(), tasks.end(), [&task](const taskList& t) {
        return t.taskName == task;
    });
    
    if (it != tasks.end())
    {
        int position = distance(tasks.begin(), it) + 1;
        cout << "Task \"" << task << "\" found at position " << position << "." << endl;
    }
    else
    {
        cout << "Task \"" << task << "\" not found." << endl;
    }
}

void markAsDone(const string& task)
{
    auto it = find_if(tasks.begin(), tasks.end(), [&task](const taskList& t) {
        return t.taskName == task;
    });

    if (it != tasks.end())
    {
        if (!it->isCompleted)
        {
            it->isCompleted = true;
            cout << "Task \"" << task << "\" marked as completed." << endl;
        }
        else
        {
            cout << "The task is already completed." << endl;
        }
    }
    else
    {
        cout << "No such task is found." << endl;
    }
}

int main()
{
    int choice;
    string task;
    int taskNumber;

    do
    {
        cout << "\nTo-Do List Menu:\n";
        cout << "1. Add Task\n";
        cout << "2. Display Tasks\n";
        cout << "3. Delete Task\n";
        cout << "4. Search Task\n";
        cout << "5. Mark as Done\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore newline character left in the buffer

        switch (choice)
        {
        case 1:
            cout << "Enter task: ";
            getline(cin, task);
            addTask(task);
            break;

        case 2:
            displayTasks();
            break;

        case 3:
            if (tasks.empty())
            {
                cout << "The to-do list is empty.\n";
            }
            else
            {
                displayTasks();
                cout << "Enter task number to delete: ";
                cin >> taskNumber;
                deleteTask(taskNumber);
            }
            break;

        case 4:
            if (tasks.empty())
            {
                cout << "The to-do list is empty.\n";
            }
            else
            {
                cout << "Enter task to search: ";
                getline(cin, task);
                searchTask(task);
            }
            break;

        case 5:
            if (tasks.empty())
            {
                cout << "The to-do list is empty.\n";
            }
            else
            {
                displayTasks();
                cout << "Enter task to mark as done: ";
                getline(cin, task);
                markAsDone(task);
            }
            break;

        case 6:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}