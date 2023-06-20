#include <iostream>
#include <vector>
#include <chrono>

class Task {
private:
    int taskId;
    std::chrono::steady_clock::time_point startTime;
    std::chrono::steady_clock::time_point endTime;

public:
    Task(int id) : taskId(id) {}

    void startTask() {
        startTime = std::chrono::steady_clock::now();
    }

    void stopTask() {
        endTime = std::chrono::steady_clock::now();
    }

    int getTaskId() const {
        return taskId;
    }

    std::chrono::steady_clock::time_point getStartTime() const {
        return startTime;
    }

    std::chrono::steady_clock::time_point getEndTime() const {
        return endTime;
    }
};

class TimeTracker {
private:
    std::vector<Task> tasks;

public:
    void addTask(const Task& task) {
        tasks.push_back(task);
    }

    void startTask(int taskId) {
        for (auto& task : tasks) {
            if (task.getTaskId() == taskId) {
                task.startTask();
                std::cout << "Task " << taskId << " started." << std::endl;
                return;
            }
        }
        std::cout << "Task not found." << std::endl;
    }

    void stopTask(int taskId) {
        for (auto& task : tasks) {
            if (task.getTaskId() == taskId) {
                task.stopTask();
                std::cout << "Task " << taskId << " stopped." << std::endl;
                return;
            }
        }
        std::cout << "Task not found." << std::endl;
    }
};

int main() {
    TimeTracker tracker;

    Task task1(1);
    Task task2(2);

    tracker.addTask(task1);
    tracker.addTask(task2);

    tracker.startTask(1);
    // Виконання завдання 1

    tracker.startTask(2);
    // Виконання завдання 2

    tracker.stopTask(1);
    tracker.stopTask(2);

    return 0;
}
