#include <iostream>
using namespace std;

struct Process {
    string name;
    int burstTime;
    int remainingTime;
    Process* next;
};

class RoundRobinScheduler {
private:
    Process* head = nullptr;
    int timeQuantum;

public:
    RoundRobinScheduler(int tq) : timeQuantum(tq) {}

    void addProcess(string name, int burstTime) {
        Process* newProcess = new Process{name, burstTime, burstTime, nullptr};
        if (!head) {
            head = newProcess;
            head->next = head;
        } else {
            Process* temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newProcess;
            newProcess->next = head;
        }
    }

    void execute() {
        Process* current = head;
        Process* prev = nullptr;

        while (head) {
            cout << "Executing " << current->name << " for ";
            int execTime = min(timeQuantum, current->remainingTime);
            current->remainingTime -= execTime;
            cout << execTime << " units. Remaining: " << current->remainingTime << endl;

            if (current->remainingTime <= 0) {
                cout << current->name << " completed.\n";
                if (current == current->next) {
                    delete current;
                    head = nullptr;
                    break;
                } else {
                    if (current == head) head = head->next;
                    prev->next = current->next;
                    delete current;
                    current = prev->next;
                }
            } else {
                prev = current;
                current = current->next;
            }
        }
    }
};

int main() {
    RoundRobinScheduler scheduler(3); // Time quantum = 3 units

    scheduler.addProcess("P1", 5);
    scheduler.addProcess("P2", 8);
    scheduler.addProcess("P3", 6);

    scheduler.execute();

    return 0;
}
