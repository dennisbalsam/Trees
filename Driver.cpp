#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include "UserInfo.h"
#include "BST.h"


using namespace std;

int main()
{
	BST<UserInfo> Tree;
	string tempuser, temppassword;
	UserInfo TempObject;
	
	// Create ifstream file to import from
	ifstream infile;
	//Open the file
	infile.open("userinfo.txt");
	//Test to see if file opened
	if (infile.fail())
	{
		cout << "Input file did not open" << endl;

	}
	//Input the values into your structure variables
	while (!infile.eof())
	{
		// Input from file into UserInfo object
		infile >> TempObject;
		Tree.insert(TempObject);
	}

	//Close the file
	infile.close();

	//Char to control user input whether or not to continue loop
	char input;
	//Keeps loop going
	bool usercontinue = true;
	//Loop to enetr users and passwords and search the tree if it exists
	while (usercontinue == true)
	{
		//Asks for user input 
		system("cls");
		cout << "Enter your username: ";
		cin >> tempuser;
		cout << "Enter your password: ";
		cin >> temppassword;
		cout << endl;
		
		//UserInfo object to srearch for entered user and password
		UserInfo Search(tempuser, temppassword);

		//Searches tree to see if login is valid, and outputs the result
		if (Tree.search(Search))
			cout << "Successful Login, Welcome " << Search.Getusername() << endl;
		else
			cout << "Invalid Username or Password please retry" << endl;

		//Asks if user would like to continue
		Sleep(1000);
		cout << endl;
		cout << "Would you like to enter another login? (y for yes, anything else terminates):  ";
		cin >> input;
		if (input == 'y' || input == 'Y')
			usercontinue = true;
		else
			usercontinue = false;
	}

	//Proof that it works

	system("cls");
	//Using a valid login to demonstrate the tree working
	UserInfo LoginTest("50cent", "candyshop");
	cout << "Username: 50cent , Password: candyshop, will now be tested" << endl;
		if (Tree.search(LoginTest))
			cout << "Successful Login, Welcome " << LoginTest.Getusername() << endl;
		else
			cout << "Invalid Username or Password please retry" << endl;

		Sleep(6000);
		system("cls");
	//Outputting the whole tree inorder
		cout << "All valids usernames and passwords" << endl;
		cout << "------------------------------------" << endl;
	Tree.inorder(cout);
	cout << endl;
	system("pause");

	return 0;
}