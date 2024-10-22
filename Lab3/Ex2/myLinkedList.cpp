/*Ex2 - a3 CSI2372A*/

#include "myLinkedList.h"

int main()
{
	Evaluation* first = nullptr;
	int choice;
	int number = 0;
	cout << "Enter the first student into the list" << endl;
	first = add(first,number);
	
	
	do
	{
		cout << endl << endl << "1) Display  of the complete linked list.\n";
		cout << "2) Insert an element\n";
		cout << "3) Remove an element.\n";
		cout << "4) Calculation of the class average.\n";
		cout << "5) Exit the program.\n" << endl << endl;
		cout << "Your choice ??:";
		cin >> choice;

		switch (choice)
		{
		case 1: display(first);
			break;
		case 2: first = add(first, number);
			break;
		case 3: first = remove(first, number);
			break;
		case 4: average(first, number);
			break;
		case 5: exit(0);
		default:
			break;
		}
	} while (1);
	return 0;
}



/*s
*add() Function*
**/
Evaluation* add(Evaluation* p, int& number)
{
	//YOUR CODE COMES HERE
	int hold;
    cout << "After which element you want to insert? (0 for start): ";
    cin >> hold;

	if(hold <0 || hold > number){
		cout<< "Invalid position" <<endl;
		return p;
	}
	Evaluation* added = new Evaluation;
	cout<< "Enter the student: ";
	cin>> added->student;
	cout<< "Enter the grade: ";
	cin>> added->grade;
	added->next = nullptr;

	if(hold ==0){
		added ->next = p;
		p = added;
	} else{
		Evaluation* current = p;
		for(int i = 1; i< hold;i++){
			current = current->next;
		}
		added->next = current->next;
		current->next = added;
	}
	number++;
	return p;

	
}


/**
*remove() Function*
**/

Evaluation* remove(Evaluation* p, int& number)
{
	//YOUR CODE COMES HERE
	int hold;
    cout << "What is the number of the elemenet to delete?: ";
    cin >> hold;

	if(hold <0 || hold > number){
		cout<< "Invalid position" <<endl;
		return p;
	}
	Evaluation* removed = new Evaluation;

	if(hold ==1){
		p = p->next;
		delete removed;
	}
	else{
		Evaluation* current = p;
		for(int i = 1; i< hold-1;i++){
			current = current->next;
		}
		removed = current->next;
		current->next = removed->next;
		delete removed;
	}


	number--;
	return p;
}



/**
*display() Function *
**/
void display(Evaluation* p)
{
	//YOUR CODE COMES HERE
	if(p == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    Evaluation* current = p;
    while (current != nullptr) {
        cout << "Student: " << current->student << endl;
        cout << "The grade is: " << current->grade << endl;
        current = current->next;
    }
}



/**
*average() Function *
***/
int average(Evaluation* p, int const& nbre)
{
	//YOUR CODE COMES HERE
	if(p == nullptr){
		cout << "Empty List" <<endl;
		return 0;
	}
	Evaluation* current = p;
	double sum = 0;
	
	while (current != nullptr){
		sum += current->grade;
		current = current->next;
	}
	cout << "The average of the class is: " << sum / nbre <<endl;




	return 1;
}






