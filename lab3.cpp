#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum Priority { LOW, MEDIUM, HIGH };

class Task {
public:
    virtual void display() = 0;
    virtual bool isCompleted() = 0;
    virtual void markAsCompleted() = 0;
};

class TaskItem : public Task {
private:
    string title;
    string description;
    bool completed;
    Priority priority;

public:
    TaskItem(string t, string d, Priority p) : title(t), description(d), completed(false), priority(p) {}

    void display() override {
        cout << "Title: " << title << "\nDescription: " << description 
             << "\nPriority: " << (priority == LOW ? "Low" : priority == MEDIUM ? "Medium" : "High")
             << "\nCompleted: " << (completed ? "Yes" : "No") << "\n";
    }

    bool isCompleted() override {
        return completed;
    }

    void markAsCompleted() override {
        completed = true;
    }

    friend bool operator<(const TaskItem& a, const TaskItem& b);
    friend bool operator>(const TaskItem& a, const TaskItem& b);
    friend bool operator==(const TaskItem& a, const TaskItem& b);
};

bool operator<(const TaskItem& a, const TaskItem& b) {
    return a.priority < b.priority;
}

bool operator>(const TaskItem& a, const TaskItem& b) {
    return a.priority > b.priority;
}

bool operator==(const TaskItem& a, const TaskItem& b) {
    return a.priority == b.priority && a.title == b.title;
}

class Note {
private:
    string content;

public:
    Note(string c) : content(c) {}

    void display() {
        cout << "Note: " << content << "\n";
    }

    bool operator==(const Note& other) {
        return content == other.content;
    }
};

class TaskList {
private:
    vector<TaskItem> tasks;
    vector<Note> notes;

public:
    void addTask(const TaskItem& task) {
        tasks.push_back(task);
    }

    void addNote(const Note& note) {
        notes.push_back(note);
    }

    void displayAll() {
        cout << "Tasks:\n";
        for (auto& task : tasks) {
            task.display();
        }
        cout << "Notes:\n";
        for (auto& note : notes) {
            note.display();
        }
    }

    TaskItem& getTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            return tasks[index];
        }
        throw out_of_range("Invalid task index");
    }

    Note& getNote(int index) {
        if (index >= 0 && index < notes.size()) {
            return notes[index];
        }
        throw out_of_range("Invalid note index");
    }

    int getTotalTasks() const {
        return tasks.size();
    }
};

void displayMenu() {
    cout << "Menu:\n";
    cout << "1. Add Task\n";
    cout << "2. Add Note\n";
    cout << "3. Display All\n";
    cout << "4. Mark Task as Completed\n";
    cout << "5. Compare Tasks by Priority\n";
    cout << "6. Exit\n";
}

int main() {
    TaskList list;
    int choice;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string title, description;
                int priority;
                cout << "Enter title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter description: ";
                getline(cin, description);
                cout << "Enter priority (0: Low, 1: Medium, 2: High): ";
                cin >> priority;
                list.addTask(TaskItem(title, description, static_cast<Priority>(priority)));
                break;
            }
            case 2: {
                string content;
                cout << "Enter note content: ";
                cin.ignore();
                getline(cin, content);
                list.addNote(Note(content));
                break;
            }
            case 3:
                list.displayAll();
                break;
            case 4: {
                int index;
                cout << "Enter task index to mark as completed: ";
                cin >> index;
                try {
                    list.getTask(index).markAsCompleted();
                } catch (const out_of_range& e) {
                    cout << e.what() << "\n";
                }
                break;
            }
            case 5: {
                int index1, index2;
                cout << "Enter first task index: ";
                cin >> index1;
                cout << "Enter second task index: ";
                cin >> index2;
                try {
                    TaskItem& task1 = list.getTask(index1);
                    TaskItem& task2 = list.getTask(index2);
                    if (task1 < task2) {
                        cout << "Task 1 has lower priority than Task 2\n";
                    } else if (task1 > task2) {
                        cout << "Task 1 has higher priority than Task 2\n";
                    } else {
                        cout << "Task 1 and Task 2 have the same priority\n";
                    }
                } catch (const out_of_range& e) {
                    cout << e.what() << "\n";
                }
                break;
            }
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
                break;
        }
    } while (choice != 6);

    return 0;
}
