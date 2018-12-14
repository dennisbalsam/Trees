#ifndef USERINFO
#define USERINFO

#include <iostream>
#include <string>

using namespace std;
class UserInfo {

private:
	//Data member for username
	string username;
	//Data member for password
	string password;


public:
	//Defualt constructor
	UserInfo();
	//COnstructor with username and password parameters
	UserInfo(const string& tempusernname, const string& temppassword);
	//Overload input operator to directly input username and password
	friend istream & operator>>(istream & in, UserInfo & data); //inputs from file directly into item
	//Overload  output operator to directly output password 
	friend ostream & operator<<(ostream & out, const UserInfo & data);// outputs password and username

	bool operator==(const UserInfo & datacompare)const; //compare address values only

	bool operator< (const UserInfo & datacompare) const;
	//Returns username
	string Getusername() const;
	//Returns password
	string Getpassword() const;

};

//Default Constructor
UserInfo::UserInfo(): username(" "), password(" ")
{
	//empty on purpose
}

//Constructor with 2 parameters
UserInfo::UserInfo(const string& tempusername, const string& temppassword): username(tempusername), password(temppassword)
{
	//empty on purpose
}

//Returns Username
string UserInfo::Getusername() const
{
	return username;
}
//Returns password
string UserInfo::Getpassword() const
{
	return password;
}


//Overloading input operator
istream & operator>>(istream & in, UserInfo & data)
{
	in >> data.username >> data.password;

	return in;
}
//Overloading output operator
ostream & operator<<(ostream & out, const UserInfo & data)
{
	//Outputs item a address
	out << "Username: " << data.username << ", Password: " << data.password << endl;
	//Outputs item a count

	out << endl;
	return out;
}
//Overloading compare operator
bool UserInfo::operator==(const UserInfo & datacomapre) const
{
	return username == datacomapre.username && password == datacomapre.password;
}

//Overloading < operator
bool UserInfo::operator<(const UserInfo & datacompare) const
{
	return username < datacompare.username;
}



















#endif