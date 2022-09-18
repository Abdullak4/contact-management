#include <iostream>
#include <stdlib.h>
#include<string>
#include <vector>
#include <fstream>

using namespace std;

void listAllContacts();
void addContact(int);
void deleteContact();
void editContact();

int main()
{
  cout << "Contact Management System" << endl;

  do
  {
    cout << "Choose a task to perform:" << endl;
    string tasks[5] = {"[1] List All Contacts", "[2] Add a new contact", "[3] Delete a contact", "[4] Edit a contact", "[0] Exit"};

    for (int i = 0; i < 5; i++)
    {
      cout << tasks[i] << endl;
    }

    cout << "Enter choice: ";

    int choice;
    cin >> choice;

    // cout << "You entered " << choice << endl;

    switch (choice)
    {
    case 1:
      listAllContacts();
      break;
    case 2:
      cout << "How many contacts do you want to enter?" << endl;
      int n;
      cin >> n;
      addContact(n);
      break;
    case 3:
      deleteContact();
      cout<<endl;
      break;
    case 4:
     editContact();
     cout<<endl;
      break;
    case 0:
      exit(0);
    }
  } while (1);
}

void listAllContacts()
{
  string contacts;
  ifstream contactFile;
  contactFile.open("contacts.txt");

  while (contactFile)
  {
    // getline(contactFile, contacts);
    contacts = contactFile.get();

    cout << contacts;
  }
	cout<<endl;
  contactFile.close();
}

void addContact(int n)
{
  ofstream contactFile;
  contactFile.open("contacts.txt", ios::app);
  for (int i = 0; i < n; i++)
  {
    string name;
    int num;

    cout << "Enter name " << i + 1 << ": ";
    cin >> name;
    cout << "Enter phone number " << i + 1 << ": ";
    cin >> num;

    contactFile << name << ":" << num << endl;
  }
}

void deleteContact()	
{
	string number;
	cout<<"Enter name and number in format name:number : ";
	cin>>number;
	ifstream contactFile;
	contactFile.open("contacts.txt");
	vector<string> line;
	string lines;
	while(getline(contactFile,lines)){
		line.push_back(lines);
	}
	contactFile.close();
	ofstream contactFile1;
	contactFile1.open("contacts.txt");
	for(int i=0;i<line.size();i++){
	
		if(line[i] != number){
			contactFile1<<line[i]<<endl;
		}
	} 
}

void editContact()	
{
	string number;
	string new1;
	cout<<"Enter contact name u want to edit ";
	cin>>number;
	ifstream contactFile;
	contactFile.open("contacts.txt");
	vector<string> line;
	string lines;
	while(getline(contactFile,lines)){
		line.push_back(lines);
	}
	contactFile.close();
	ofstream contactFile1;
	contactFile1.open("contacts.txt");
	for(int i=0;i<line.size();i++){
		if(line[i]!=number){
			contactFile1<<line[i]<<endl;
		}
	}
	contactFile1.close();
 	addContact(1);
}

	
