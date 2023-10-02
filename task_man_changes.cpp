#include <iostream>
#include <vector>
#include <string>

// Task structure
struct Task {
    std::string description;
    bool completed;
};

// Function to add a task
void addTask(std::vector<Task>& tasks) {
    Task task;
    std::cout << "Enter task description: ";
    std::cin.ignore();
    std::getline(std::cin, task.description);
    task.completed = false;
    tasks.push_back(task);
    std::cout << "Task added successfully!" << std::endl;
}

// Function to display all tasks
void displayTasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks found." << std::endl;
        return;
    }
    std::cout << "Tasks:" << std::endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". ";
        if (tasks[i].completed) {
            std::cout << "[X] ";
        } else {
            std::cout << "[ ] ";
        }
        std::cout << tasks[i].description << std::endl;
    }
}

// Function to mark a task as completed
void markTaskCompleted(std::vector<Task>& tasks, size_t index) {
    if (index >= 0 && index < tasks.size()) {
        tasks[index].completed = true;
        std::cout << "Task marked as completed!" << std::endl;
    } else {
        std::cout << "Invalid task index." << std::endl;
    }
}

// Function to delete a task
void deleteTask(std::vector<Task>& tasks, size_t index) {
    if (index >= 0 && index < tasks.size()) {
        tasks.erase(tasks.begin() + index);
        std::cout << "Task deleted successfully!" << std::endl;
    } else {
        std::cout << "Invalid task index." << std::endl;
    }
}

int main() {
    std::vector<Task> tasks;

    while (true) {
        std::cout << "Options:" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. Display Tasks" << std::endl;
        std::cout << "3. Mark Task as Completed" << std::endl;
        std::cout << "4. Delete Task" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                displayTasks(tasks);
                break;
            case 3:
                std::cout << "Enter the task index to mark as completed: ";
                size_t index;
                std::cin >> index;
                markTaskCompleted(tasks, index - 1);
                break;
            case 4:
                std::cout << "Enter the task index to delete: ";
                std::cin >> index;
                deleteTask(tasks, index - 1);
                break;
            case 5:
                std::cout << "Exiting program." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }

    return 0;
}
