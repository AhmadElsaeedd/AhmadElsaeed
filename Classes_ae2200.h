#ifndef Classes_ae2200.h
#define Classes_ae2200

#include <string>
#include <map>
#include <iostream>

//Base Class Account
class Account {
protected:
	//Members that are shared between both child classes
	std::string Password;
	int Index;
	int NoOfPosts = 0;
public:
	//Default constructor
	Account() { Password = " "; }

	//Virtual destructor of class Account
	virtual ~Account() {}

	//Functions that are overloaded and will be used and overriden in the inherited classes
	virtual int getIndexinMap() {
		std::cout << "I am an overloaded function and I will be overriden";
		return 0;
	};
	virtual void printMemberDetails() { std::cout << "I am an overloaded function and I will be overriden"; };
	virtual void ListOutMembers() { std::cout << "I am an overloaded function and I will be overriden"; };
	virtual void WritePost() { std::cout << "I am an overloaded function and I will be overriden"; };
	virtual inline int AddFollower() {
		std::cout << "I will be overriden";
		return 0;
	};
	virtual inline int AddMembers() {
		std::cout << "I will be overriden";
		return 0;
	};
	virtual inline int AddPost() {
		std::cout << "I am an overloaded function and I will be overriden";
		return 0;
	}
	

};

class User : public Account {
private:
	//private members of class user
	std::string UserName;
	int NoOfFollowers;
public:
	//Default Constructor
	User()
	{
		UserName = " ";
		NoOfFollowers = 0;
		NoOfPosts = 0;
	}
	//Parametrized Constructor
	User(std::string _UserName, std::string _Password, int _NoOfFollowers,
		int _NoOfPosts)
	{
		UserName = _UserName;
		Password = _Password;
		NoOfFollowers = _NoOfFollowers;
		NoOfPosts = _NoOfPosts;
	}
	//Virtual Destructor
	virtual ~User() {}
	//Setters and Getters
	std::string getUserName() { return UserName; }
	std::string getPassword() { return Password; }
	int getNoOfFollowers() { return NoOfFollowers; }
	int getNoOfPosts() { return NoOfPosts; }
	void setNoOfFollowers(int _NoOfFollowers) { NoOfFollowers = _NoOfFollowers; }
	void setNoOfPosts(int _NoOfPosts) { NoOfPosts = _NoOfPosts; }

	//Function to get the index of the object inside the map using the username of the object
	int getIndexinMap(std::map<int, User> PlaceHolder, std::string _UserName)
	{
		//First initialize the index to be one
		Index = 1;
		//Start an iterator to iterate through the map
		std::map<int, User>::iterator iter;
		//Loop to iterate through the map
		for (iter = PlaceHolder.begin(); iter != PlaceHolder.end(); ++iter)
		{
			//Condition to check if the username of the object is the same as the username inputted
			if (iter->second.getUserName() == _UserName) break;//If that condition is true return the index of that object
			Index++;
		}
		return Index;
	}

	//Printing details of one user using the index to find the object
	void printMemberDetails(std::map<int, User> PlaceHolder, int index) {
		//Printing the username of the object
		std::cout << "The username of this user is: " << PlaceHolder[index].getUserName() << "\n";
		//Printing the number of followers of the object
		std::cout << "The number of followers of this user is: " << PlaceHolder[index].getNoOfFollowers() << "\n";
		//Printing the number of posts of the object
		std::cout << "The number of posts of this user is: " << PlaceHolder[index].getNoOfPosts() << "\n\n\n";
	}

	//Function to print all the users using the map iterator
	void ListOutMembers(std::map<int, User> PlaceHolder) {
		//Start an iterator
		std::map<int, User>::iterator iter;
		//Print statements that help with the presentation of the program
		std::cout << "Existing users on Ahmad Book: \n";
		std::cout << "User Number" << '\t' << "User Name" << '\n';
		//Loop to print out the users
		for (iter = PlaceHolder.begin(); iter != PlaceHolder.end(); ++iter)
		{
			//Printing out the user number and the user name
			std::cout << iter->first << "\t\t" << iter->second.getUserName();
			std::cout << "\n\n";
		}
	}

	//Function to write a post by a user
	void WritePost(std::map<int, User> PlaceHolder, int index) {
		//Printing out a sentence to ask the user for input
		std::cout << "What is on your mind today " << PlaceHolder[index].getUserName() << "?(Max. characters: 280)\n";
		//String to ask for content
		std::string PostContent;
		//Getting input from the user without skipping the white space
		std::getline(std::cin >> std::ws, PostContent);
		//Outputting the content that the user inputted as a "post"
		std::cout << PlaceHolder[index].getUserName() << " posted: " << PostContent << "\n\n";
	}

	//Function that increments the number of followers when one user follows another user
	inline int AddFollower(std::map<int, User> PlaceHolder, int index) {
		//Incrementing the number of followers the user has
		PlaceHolder[index].setNoOfFollowers(PlaceHolder[index].getNoOfFollowers() + 1);
		//Returning the number of followers of a user
		return PlaceHolder[index].getNoOfFollowers();
	}

	inline int AddPost(std::map<int, User> PlaceHolder, int index) {
		int result;
		result = PlaceHolder[index].getNoOfPosts() + 1;
		return result;
	}
};

//Inherited class Page from Account
class Page : public Account {
private:
	//Private members of the function
	std::string PageName;
	int NoOfMembers;
public:
	//Default constructor
	Page() {
		PageName = " ";
		NoOfMembers = 0;
		NoOfPosts = 0;
	}
	//Parametrized constructor
	Page(std::string _PageName, std::string _Password, int _NoOfMembers, int _NoOfPosts)
	{
		PageName = _PageName;
		Password = _Password;
		NoOfMembers = _NoOfMembers;
		NoOfPosts = _NoOfPosts;
	}
	//Virtual destructor
	virtual ~Page() {}
	//Setters and getters
	std::string getPageName() { return PageName; }
	std::string getPassword() { return Password; }
	int getNoOfMembers() { return NoOfMembers; }
	int getNoOfPosts() { return NoOfPosts; }
	void setNoOfMembers(int _NoOfMembers) { NoOfMembers = _NoOfMembers; }
	void setNoOfPosts(int _NoOfPosts) { NoOfPosts = _NoOfPosts; }

	//Function to get the index of the object inside the map
	int getIndexinMap(std::map<int, Page> PlaceHolder, std::string _PageName)
	{
		//First initialize the index to be one
		Index = 1;
		//Start an iterator to iterate through the map
		std::map<int, Page>::iterator iter;
		//Loop to iterate through the map
		for (iter = PlaceHolder.begin(); iter != PlaceHolder.end(); ++iter)
		{
			//Condition to check if the username of the object is the same as the username inputted
			if (iter->second.getPageName() == _PageName) break;//If that condition is true return the index of that object
			Index++;
		}
		return Index;
	}

	//Printing the details of an individual member of the map using the index of the object in the map
	void printMemberDetails(std::map<int, Page> PlaceHolder, int index) {
		//Printing out the page name
		std::cout << "The page name of this page is: " << PlaceHolder[index].getPageName() << "\n";
		//Printing out the number of members of the page
		std::cout << "The number of members of this page is: " << PlaceHolder[index].getNoOfMembers() << "\n";
		//Printing out the number of posts made on the page
		std::cout << "The number of posts of this page is: " << PlaceHolder[index].getNoOfPosts() << "\n\n";
	}

	//Printing out the content of the map using a map iterator
	void ListOutMembers(std::map<int, Page> PlaceHolder) {
		//Start an iterator
		std::map<int, Page>::iterator iter;
		//Print statements that help with the presentation of the program
		std::cout << "Existing pages on Ahmad Book: \n";
		std::cout << "Page Number" << '\t' << "Page Name" << '\n';
		//Loop to print out the users	 
		for (iter = PlaceHolder.begin(); iter != PlaceHolder.end(); ++iter)
		{
			//Printing out the user number and the user name
			std::cout << iter->first << "\t\t" << iter->second.getPageName();
			std::cout << '\n';
		}
	}

	//Function to write a post by a user
	void WritePost(std::map<int, Page> PlaceHolder, int index) {
		//Asking the user for input
		std::cout << "What is happening that " << PlaceHolder[index].getPageName() << " should know?\n";
		//Asking for content from user
		std::string PostContent;
		//Getting input from the user without skipping the white space
		std::getline(std::cin >> std::ws, PostContent);
		//Printing what was inputted by the user as a post on the page
		std::cout << PostContent << " was posted on " << PlaceHolder[index].getPageName() << "\n\n";
	}

	//Function that adds a number of members when one user adds members to their page
	inline int AddMembers(std::map<int, Page> PlaceHolder, int index, int number) {
		//Adding the members
		PlaceHolder[index].setNoOfMembers(PlaceHolder[index].getNoOfMembers() + number);
		//returning the number of members of the page
		return PlaceHolder[index].getNoOfMembers();
	}

	inline int AddPost(std::map<int, Page> PlaceHolder, int index) {
		int result;
		result = PlaceHolder[index].getNoOfPosts() + 1;
		return result;
	}
};

#endif 