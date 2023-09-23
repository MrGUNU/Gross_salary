#include <iostream>
using namespace std;

// Define a class employees
class employees {
    // Declare private data members
    private:
        int emp_no;
        string name;
        double basic_salary;
        double hra;
        double da;
        double gross_salary;

    // Declare public member functions
    public:
        // Input data for one employee
        void input_data() {
            cout << "Enter employee number: ";
            cin >> emp_no;
            cout << "Enter employee name: ";
            cin >> name;
            cout << "Enter basic salary: ";
            cin >> basic_salary;
            // Calculate HRA and DA
            hra = 0.15 * basic_salary;
            da = 0.25 * basic_salary;
            // Calculate gross salary
            gross_salary = basic_salary + hra + da;
        }

        // Display the employee detail
        void display_detail() {
            cout << "Employee number: " << emp_no << endl;
            cout << "Employee name: " << name << endl;
            cout << "Basic salary: " << basic_salary << endl;
            cout << "Gross salary: " << gross_salary << endl;
        }

        // Return the gross salary of the employee
        double get_gross_salary() {
            return gross_salary;
        }
};

// Define a function to find the average salary of the employees
double find_average(employees e[], int n) {
    // Declare a variable to store the sum of salaries
    double sum = 0;
    // Loop through the array of employees and add their salaries to the sum
    for (int i = 0; i < n; i++) {
        sum += e[i].get_gross_salary();
    }
    // Return the average by dividing the sum by the number of employees
    return sum / n;
}

// Define a function to display the employees information based on their salary
void display_info(employees e[], int n, double avg) {
    // Declare variables to store the indices of the employees having maximum and minimum salary
    int max_index = 0;
    int min_index = 0;
    // Loop through the array of employees and compare their salaries with the maximum and minimum values
    for (int i = 1; i < n; i++) {
        if (e[i].get_gross_salary() > e[max_index].get_gross_salary()) {
            max_index = i;
        }
        if (e[i].get_gross_salary() < e[min_index].get_gross_salary()) {
            min_index = i;
        }
    }
    // Display the average salary
    cout << "The average salary of the employees is: " << avg << endl;
    // Display the employee having maximum salary
    cout << "The employee having maximum salary is: " << endl;
    e[max_index].display_detail();
    // Display the employee having minimum salary
    cout << "The employee having minimum salary is: " << endl;
    e[min_index].display_detail();
    // Display the employees getting more than average salary
    cout << "The employees getting more than average salary are: " << endl;
    for (int i = 0; i < n; i++) {
        if (e[i].get_gross_salary() > avg) {
            e[i].display_detail();
        }
    }
    // Display the employees getting less than average salary
    cout << "The employees getting less than average salary are: " << endl;
    for (int i = 0; i < n; i++) {
        if (e[i].get_gross_salary() < avg) {
            e[i].display_detail();
        }
    }
}

// Define the main function
int main() {
    // Declare a constant to store the number of employees
    const int N = 5;
    // Declare an array of employees objects
    employees emp[N];
    // Loop through the array and input data for each employee
    for (int i = 0; i < N; i++) {
        cout << "Enter data for employee " << i + 1 << ":" << endl;
        emp[i].input_data();
    }
    // Find the average salary of the employees
    double average = find_average(emp, N);
    // Display the employees information based on their salary
    display_info(emp, N, average);
    
}