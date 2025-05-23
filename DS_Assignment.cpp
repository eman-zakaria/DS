#include <iostream>
#include <string>
using namespace std;

// Structure for each expense node
struct Expense {
    int id;               
    string category;       
    float amount;           
    string date;           
    Expense* next;          
};

Expense* head = NULL;
int expenseID = 1;  

void addExpense() {
    Expense* newExpense = new Expense();

    newExpense->id = expenseID++;
    cout << "Enter category: ";
    cin >> newExpense->category;
    cout << "Enter amount: ";
    cin >> newExpense->amount;
    cout << "Enter date (DD-MM-YYYY): ";
    cin >> newExpense->date;
    newExpense->next = NULL;

    if (head == NULL) {
        head = newExpense;
    } else {
        Expense* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newExpense;
    }

    cout << "Expense added successfully!\n";
}


void viewExpenses() {
    if (head == NULL) {
        cout << "No expenses to show.\n";
        return;
    }

    Expense* temp = head;
    cout << "\n--- All Expenses ---\n";
    while (temp != NULL) {
        cout << "ID: " << temp->id
             << ", Category: " << temp->category
             << ", Amount: $" << temp->amount
             << ", Date: " << temp->date << endl;
        temp = temp->next;
    }
}

// Function to edit an expense
void editExpense() {
    int id;
    cout << "Enter ID of the expense to edit: ";
    cin >> id;

    Expense* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            cout << "Enter new category: ";
            cin >> temp->category;
            cout << "Enter new amount: ";
            cin >> temp->amount;
            cout << "Enter new date: ";
            cin >> temp->date;
            cout << "Expense updated successfully!\n";
            return;
        }
        temp = temp->next;
    }

    cout << "Expense with ID " << id << " not found.\n";
}

// Function to delete an expense
void deleteExpense() {
    int id;
    cout << "Enter ID of the expense to delete: ";
    cin >> id;

    Expense* temp = head;
    Expense* prev = NULL;

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Expense with ID " << id << " not found.\n";
        return;
    }

    if (prev == NULL) {
        head = temp->next;  
    } else {
        prev->next = temp->next;
    }

    delete temp;
    cout << "Expense deleted successfully!\n";
}

int main() {
    int choice;

    do {
        cout << "\n--- Expense Tracker Menu ---\n";
        cout << "1. Add Expense\n";
        cout << "2. View All Expenses\n";
        cout << "3. Edit Expense\n";
        cout << "4. Delete Expense\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                viewExpenses();
                break;
            case 3:
                editExpense();
                break;
            case 4:
                deleteExpense();
                break;
            case 5:
                cout << "Exiting... Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
