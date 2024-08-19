#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Employee {
    string name;
    double salary;
    double salaryIncrease; // To track the amount of salary increase
};

// Function prototypes
void addEmployees(vector<Employee>& employees);
void viewRecords(const vector<Employee>& employees);
void updateSalary(vector<Employee>& employees);
void sortAndDisplayBySalary(vector<Employee> employees, bool ascending);
void showMaxSalaryIncrease(const vector<Employee>& employees);
void displayMenu();

// Function to add 5 employees
void addEmployees(vector<Employee>& employees) {
    string name;
    double salary;

    for (int i = 0; i < 5; ++i) {
        cout << "Enter Employee Name " << (i + 1) << ": ";
        cin >> ws; // Consume any leading whitespace
        getline(cin, name);
        cout << "Enter Current Salary: ";
        cin >> salary;

        employees.push_back({name, salary, 0});
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
        cout << "Name: " << emp.name << ", Current Salary: $" << emp.salary << endl;
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
        cout << "Name: " << emp.name << ", Salary: $" << emp.salary << endl;
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
    cout << "4. Display Employees by Salary (Highest to Lowest)" << endl;
    cout << "5. Display Employees by Salary (Lowest to Highest)" << endl;
    cout << "6. Show Employee with Highest Salary Increase" << endl;
    cout << "7. Exit" << endl;
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
                sortAndDisplayBySalary(employees, false);
                break;
            case 5:
                sortAndDisplayBySalary(employees, true);
                break;
            case 6:
                showMaxSalaryIncrease(employees);
                break;
            case 7:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}

