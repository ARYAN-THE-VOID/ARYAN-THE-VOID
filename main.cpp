#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Employee {
    string name;
    double salary;
    double salaryIncrease; // To track the amount of salary increase
    double workTime;       // Hours worked per week
    string shift;          // Shift (e.g., "Morning", "Afternoon", "Night")
};

// Function prototypes
void addEmployees(vector<Employee>& employees);
void viewRecords(const vector<Employee>& employees);
void updateSalary(vector<Employee>& employees);
void sortAndDisplayBySalary(vector<Employee> employees, bool ascending);
void showMaxSalaryIncrease(const vector<Employee>& employees);
void updateWorkTimeAndShift(vector<Employee>& employees);
void displayMenu();

// Function to add 5 employees
void addEmployees(vector<Employee>& employees) {
    string name;
    double salary;
    double workTime;
    string shift;

    for (int i = 0; i < 5; ++i) {
        cout << "Enter Employee Name " << (i + 1) << ": ";
        cin >> ws; // Consume any leading whitespace
        getline(cin, name);
        cout << "Enter Current Salary: ";
        cin >> salary;
        cout << "Enter Work Time (hours per week): ";
        cin >> workTime;
        cout << "Enter Shift (Morning/Afternoon/Night): ";
        cin >> ws; // Consume any leading whitespace
        getline(cin, shift);

        employees.push_back({name, salary, 0, workTime, shift});
    }

    cout << "Employee records added successfully!" << endl;
}

// Function to view all employee records
void viewRecords(const vector<Employee>& employees) {
    if (employees.empty()) {
        cout << "No records found." << endl;
        return;
    }

    cout << "\nEmployee Records:" << endl;
    for (const auto& emp : employees) {
        cout << "Name: " << emp.name 
             << ", Current Salary: $" << emp.salary 
             << ", Work Time: " << emp.workTime << " hours/week"
             << ", Shift: " << emp.shift << endl;
    }
}

// Function to update salary for a specific employee
void updateSalary(vector<Employee>& employees) {
    if (employees.empty()) {
        cout << "No records found." << endl;
        return;
    }

    string nameToUpdate;
    cout << "Enter Employee Name to Update Salary: ";
    cin >> ws; // Consume any leading whitespace
    getline(cin, nameToUpdate);

    bool found = false;

    for (auto& emp : employees) {
        if (emp.name == nameToUpdate) {
            found = true;
            char choice;
            double amount;
            cout << "Current Salary for " << emp.name << " is $" << emp.salary << endl;
            cout << "Do you want to Increase or Decrease the salary? (i/d): ";
            cin >> choice;
            cout << "Enter the amount: ";
            cin >> amount;

            if (choice == 'i' || choice == 'I') {
                emp.salary += amount;
                emp.salaryIncrease += amount; // Track the total increase
            } else if (choice == 'd' || choice == 'D') {
                emp.salary -= amount;
            } else {
                cout << "Invalid choice!" << endl;
                return;
            }

            cout << "Salary updated to $" << emp.salary << endl;
        }
    }

    if (!found) {
        cout << "Employee " << nameToUpdate << " not found." << endl;
    }
}

// Function to update work time and shift for a specific employee
void updateWorkTimeAndShift(vector<Employee>& employees) {
    if (employees.empty()) {
        cout << "No records found." << endl;
        return;
    }

    string nameToUpdate;
    cout << "Enter Employee Name to Update Work Time and Shift: ";
    cin >> ws; // Consume any leading whitespace
    getline(cin, nameToUpdate);

    bool found = false;

    for (auto& emp : employees) {
        if (emp.name == nameToUpdate) {
            found = true;
            cout << "Current Work Time for " << emp.name << " is " << emp.workTime << " hours/week" << endl;
            cout << "Enter new Work Time (hours per week): ";
            cin >> emp.workTime;
            cout << "Current Shift for " << emp.name << " is " << emp.shift << endl;
            cout << "Enter new Shift (Morning/Afternoon/Night): ";
            cin >> ws; // Consume any leading whitespace
            getline(cin, emp.shift);

            cout << "Work Time and Shift updated successfully!" << endl;
        }
    }

    if (!found) {
        cout << "Employee " << nameToUpdate << " not found." << endl;
    }
}

// Function to sort and display employees by salary in either ascending or descending order
void sortAndDisplayBySalary(vector<Employee> employees, bool ascending) {
    if (employees.empty()) {
        cout << "No records found." << endl;
        return;
    }

    // Sort employees by salary
    if (ascending) {
        sort(employees.begin(), employees.end(), [](const Employee& a, const Employee& b) {
            return a.salary < b.salary;
        });
    } else {
        sort(employees.begin(), employees.end(), [](const Employee& a, const Employee& b) {
            return a.salary > b.salary;
        });
    }

    // Display sorted records
    cout << "\nEmployees sorted by Salary:" << endl;
    for (const auto& emp : employees) {
        cout << "Name: " << emp.name << ", Salary: $" << emp.salary 
             << ", Work Time: " << emp.workTime << " hours/week"
             << ", Shift: " << emp.shift << endl;
    }
}

// Function to show the employee with the highest salary increase
void showMaxSalaryIncrease(const vector<Employee>& employees) {
    if (employees.empty()) {
        cout << "No records found." << endl;
        return;
    }

    auto maxIncreaseIt = max_element(employees.begin(), employees.end(), [](const Employee& a, const Employee& b) {
        return a.salaryIncrease < b.salaryIncrease;
    });

    if (maxIncreaseIt != employees.end() && maxIncreaseIt->salaryIncrease > 0) {
        cout << "Employee with the highest salary increase:" << endl;
        cout << "Name: " << maxIncreaseIt->name << ", Salary Increase: $" << maxIncreaseIt->salaryIncrease << endl;
    } else {
        cout << "No salary increases have been made yet." << endl;
    }
}

// Function to display the menu
void displayMenu() {
    cout << "\nBroadway Infosys Employee Management System:" << endl;
    cout << "1. Add 5 Employee Records" << endl;
    cout << "2. View Employee Records" << endl;
    cout << "3. Update Salary" << endl;
    cout << "4. Update Work Time and Shift" << endl;
    cout << "5. Display Employees by Salary (Highest to Lowest)" << endl;
    cout << "6. Display Employees by Salary (Lowest to Highest)" << endl;
    cout << "7. Show Employee with Highest Salary Increase" << endl;
    cout << "8. Exit" << endl;
}

// Main function
int main() {
    vector<Employee> employees;

    while (true) {
        displayMenu();
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addEmployees(employees);
                break;
            case 2:
                viewRecords(employees);
                break;
            case 3:
                updateSalary(employees);
                break;
            case 4:
                updateWorkTimeAndShift(employees);
                break;
            case 5:
                sortAndDisplayBySalary(employees, false);
                break;
            case 6:
                sortAndDisplayBySalary(employees, true);
                break;
            case 7:
                showMaxSalaryIncrease(employees);
                break;
            case 8:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
