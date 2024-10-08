#include "MyFile4.h"

int main() {
    int i;
    char* chain[nb_ch];        // array of pointers to strings
    char choice;               // variable for the choice entered in menu()

    cout << endl << "Please enter 5 strings (max 20 characters each). Press Enter after each string." << endl;

    // Input strings
    for (i = 0; i < nb_ch; i++) {
        chain[i] = new char[size_ch];        // memory allocation
        cout << "Enter string " << i + 1 << ": ";
        cin.getline(chain[i], size_ch);      // Input the string
    }

    // Menu loop
    while (true) {
        choice = menu();  // Get user's choice from the menu
        switch (choice) {
            case '1': 
                display(chain, nb_ch);
                break;
            case '2': 
                replace(chain, nb_ch, size_ch);
                break;
            case '3': 
                sort(chain, nb_ch);
                break;
            case '4': 
                for (i=0; i < nb_ch; i++) {
                    delete[] chain[i];
                }
                cout << "Exiting program. Goodbye!" << endl;
                exit(0);
            default: 
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
}

/********************************************************************************/
/* Function menu which returns a character corresponding to the user's choice   */
/********************************************************************************/
char menu(void) {
    string choice;

    cout << endl << "\t\tMenu" << endl;
    cout << "1) Display strings." << endl;
    cout << "2) Replace a string." << endl;
    cout << "3) Sort strings." << endl;
    cout << "4) Exit program." << endl;
    cout << "Your choice (press Enter after input): ";
    getline(cin, choice);  // Read the entire line including the Enter key

    if (choice.length() == 1 && (choice[0] >= '1' && choice[0] <= '4')) {
        return choice[0];  // Return the first character of the input string
    } else {
        return '0';  // Return '0' for invalid input
    }
}

/********************************************************************************/
/* Function display which displays the strings                                  */
/********************************************************************************/
void display(char* tab[], int const& nbre) {
    for (int i = 0; i < nbre; i++) {
        cout << "String " << i << ": " << tab[i] << endl;
    }
}

/********************************************************************************/
/* Function replace which replaces one string by another                        */
/********************************************************************************/
void replace(char* tab[], int const& nbre, int const& size) {
    int numero;  // the string to modify
    char new_string[size];  // new string

    cout << "Enter the string number to modify (0 to " << nbre - 1 << "): ";
    cin >> numero;
    cin.ignore(INT_MAX, '\n');  // Clear the input buffer

    if (numero >= 0 && numero < nbre) {
        cout << "Enter the new string: ";
        cin.getline(new_string, size);

        // Replace the string
        strcpy(tab[numero], new_string);
    } else {
        cout << "Invalid string number!" << endl;
    }
}
/********************************************************************************/
/* Function sort to sort strings using insertion sort                           */
/********************************************************************************/
void sort(char* tab[], int const& nbre) {
    for (int i = 1; i < nbre; i++) {
        char* key = tab[i];
        int j = i - 1;

        while (j >= 0 && strcmp(tab[j], key) > 0) {
            tab[j + 1] = tab[j];
            j--;
        }
        tab[j + 1] = key;
    }

    cout << "Strings sorted successfully!" << endl;
