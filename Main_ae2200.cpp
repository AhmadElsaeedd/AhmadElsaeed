#include <iostream>
#include <string>
#include "Classes_ae2200.h"
#include "Functions_ae2200.h"

int main()
{
	//Declaring maps of users and pages to add samples of users and pages
	std::map<int, User> Users;
	std::map<int, Page> Pages;
	//Initializing an object of class User and an object of classes Page to help with calling functions
	User U;
	Page P;

	//Adding sample objects to the maps
	Users.insert(std::make_pair<int, User>(1, User("AhmadElsaeed", "As.27122002", 50, 3)));
	Users.insert(std::make_pair<int, User>(2, User("OmarElkammah", "Ome.162002", 60, 4)));
	Users.insert(std::make_pair<int, User>(3, User("MariamAhmed", "Ma.562003", 70, 5)));
	Pages.insert(std::make_pair<int, Page>(1, Page("AhmadPage", "As.27122002", 30,3)));
	Pages.insert(std::make_pair<int, Page>(2, Page("OmarPage", "Ome.162002", 40,4)));
	Pages.insert(std::make_pair<int, Page>(3, Page("MariamPage", "Ma.562003", 50,5)));

	int LoggedinUser(0), LoggedinPage(0);
	//Main Screen display
	switch (MainScreen()) {
	case 1:
	{
		//Register Screen Display
		switch (RegisterScreen()) {
		case 1:
		{
			bool flag1 = 0;
			std::string _Username;
			//Repeat asking for username until a new username is entered
			do
			{
				//Asking for username from user
				std::cout << "Please enter username:\n";
				std::cin >> _Username;
				//Checking if the username is already taken
				if (CheckMemberExistence(_Username, Users) == true)
				{
					std::cout << "This username is already taken. Please enter a new one.\n";
				}
				//If the username doesn't exist make the flag 1 to exit the loop
				else flag1 = 1;
			} while (flag1 != 1);
			//Ask for password from the user
			std::cout << "Plase enter password:\n";
			std::string _Password;
			std::cin >> _Password;
			//Create a new user with the username and password inputter by the user
			Users.insert(std::make_pair<int, User>(4, User(_Username, _Password, 0, 0)));
			//Initialize the logged in user index to be the number of users in the map (because a created user is put at the end of the map)
			LoggedinUser = Users.size();
			bool flag5 = 0;
			//Repeat the features display until the user asks to to exit
			do
			{
				//Features screen display
				switch (FeaturesScreenForUsers()) {
				case 1:
				{
					//Write a post using the logged in user
					Users[LoggedinUser].WritePost(Users, LoggedinUser);
					//Incrementing the number of posts made by one user
					Users[LoggedinUser].setNoOfPosts(Users[LoggedinUser].AddPost(Users,LoggedinUser));
					break;
				}
				case 2: {
					//View someone's profile
					//List out the existing users to choose from
					U.ListOutMembers(Users);
					std::cout << "Enter the number of the user that you want to view: \n";
					int index(0);
					//Asking the user which user they would like to view
					std::cin >> index;
					//Print the details of the user inputted by the console
					Users[LoggedinUser].printMemberDetails(Users, index);
					break;
				}
				case 3: {
					//Code for following a user
					//List out the existing users to choose which to follow
					U.ListOutMembers(Users);
					bool flag10 = 0;
					int index;
					//Repeat asking the user which user they'd like to follow until they enter a number that is not themselves
					do
					{
						std::cout << "Enter the number of the user that you want to follow: \n";
						std::cin >> index;
						if (index == LoggedinUser) std::cout << "You cannot follow yourself man.\nChoose another user.\n";
						//Escape the function when flag is 1 when the user chooses a correct user
						else flag10 = 1;
					} while (flag10 != 1);
					//Output to help with the presentation on the console
					std::cout << "Before, " << Users[index].getUserName() << " had " << Users[index].getNoOfFollowers() << " followers.\n";
					//Setting the new number of followers of the user that was followed
					Users[index].setNoOfFollowers(U.AddFollower(Users, index));
					std::cout << "After, " << Users[index].getUserName() << " has " << Users[index].getNoOfFollowers() << " followers.\n";
					break;
				}
				case 4: {
					//Exit the program when flag is 1
					flag5 = 1;
					break;
				}
				default:
				{
					std::cout << "You have entered an incorrect selection\n";
					break;
				}
				}
			} while (flag5!=1);
			break;
		}
		case 2:
		{
			bool flag6 = 0;
			std::string _Pagename;
			//Repeat asking for pagename until a new pagename is entered
			do
			{
				//Asking for page name from user
				std::cout << "Please enter page name:\n";
				std::cin >> _Pagename;
				//Checking if the page name is already taken
				if (CheckMemberExistence(_Pagename, Pages) == true)
				{
					std::cout << "This page name is already taken. Please enter a new one.\n";
				}
				//If the username doesn't exist make the flag 1 to exit the loop
				else flag6 = 1;
			} while (flag6 != 1);
			//Ask for password from the user
			std::cout << "Please enter password:\n";
			std::string _Password;
			std::cin >> _Password;
			//Create a new page
			Pages.insert(std::make_pair<int, Page>(4, Page(_Pagename, _Password, 0,0)));
			//Initialize the logged in page index to be the number of pages in the map (because a created page is put at the end of the map)
			LoggedinPage = Pages.size();
			bool flag4 = 0;
			//Repeat the features display until the user asks to to exit
			do
			{
				//Features screen display
				switch (FeaturesScreenForPages()) {
				case 1:
				{
					//Write a post using on the logged in page
					Pages[LoggedinPage].WritePost(Pages, LoggedinPage);
					//Incrementing the number of posts made on a page
					Pages[LoggedinPage].setNoOfPosts(Pages[LoggedinPage].AddPost(Pages, LoggedinPage));
					break;
				}
				case 2: {
					//Code to view someone's profile
					P.ListOutMembers(Pages);
					//List out the existing users to choose from
					std::cout << "Enter the number of the page that you want to view: \n";
					int index(0);
					std::cin >> index;
					//Print the details of the page inputted by the console
					Pages[LoggedinUser].printMemberDetails(Pages, index);
					break;
				}
				case 3: {
					//Code for adding a number of members
					//Asking how many members the user would like to add to the page
					std::cout << "How many members do you want to add to " << Pages[LoggedinPage].getPageName() << "?\n";
					int number;
					std::cin >> number;
					//Output to help with the presentation on the console
					std::cout << Pages[LoggedinPage].getPageName() << " had " << Pages[LoggedinPage].getNoOfMembers() << " members before you added members.\n";
					//Setting the new number of members of the page
					Pages[LoggedinPage].setNoOfMembers(P.AddMembers(Pages, LoggedinPage, number));
					std::cout << Pages[LoggedinPage].getPageName() << " has " << Pages[LoggedinPage].getNoOfMembers() << " members after you added members.\n";
					break;
				}
				case 4: {
					//Exit the program when flag is 1
					flag4 = 1;
					break;
				}
				default:
				{
					std::cout << "You have entered an incorrect selection\n";
					break;
				}
				}
			} while (flag4!=1);
			break;
		}
		default: {
			std::cout << "You have inputted the wrong selection.\n";
			break;
		}
		}
		break;
	}	
	case 2:
	{
		//Login Screen Display
		switch (LoginScreen()) {
		case 1:
		{
			bool flag7 = 0;
			std::string _Username;
			//Repeat asking for username and password until both are correct
			do
			{
				std::cout << "Please enter username:\n";
				std::cin >> _Username;
				std::cout << "Please enter password:\n";
				std::string _Password;
				std::cin >> _Password;
				//Checking that the username and password that were inputted are correct
				if (CheckMemberExistence(_Username, _Password, Users) == true) {
					//Exit the loops when username and password are correct
					std::cout << "Successfully logged in!\n";
					flag7 = 1;
				}
				//If they are not correct print out a statement and repeat
				else std::cout << "Wrong username or password. Please try again.\n";
			} while (flag7 != 1);
			//Assign the logged in user integer the index of the object that you have logged in to
			LoggedinUser = U.getIndexinMap(Users, _Username);
			bool flag3 = 0;
			//Repeat the features display until the user asks to to exit
			do
			{
				//Start of the features screen
				switch (FeaturesScreenForUsers()) {
				case 1:
				{
					//Write a post using the logged in user
					Users[LoggedinUser].WritePost(Users, LoggedinUser);
					//Incrementing the number of posts made by one user
					Users[LoggedinUser].setNoOfPosts(Users[LoggedinUser].AddPost(Users, LoggedinUser));
					break;
				}
				case 2: {
					//Code for viewing someone's profile
					//List out the existing users to choose from
					U.ListOutMembers(Users);
					std::cout << "Enter the number of the user that you want to view: \n";
					int index(0);
					//Asking the user which user they would like to view
					std::cin >> index;
					//Print details of the user that is wanted
					Users[LoggedinUser].printMemberDetails(Users, index);
					break;
				}
				case 3: {
					//Code for following a user
					//List out the existing users to choose from
					U.ListOutMembers(Users);
					bool flag9 = 0;
					int index;
					//Repeat asking the user which user they'd like to follow until they enter a number that is not themselves
					do
					{
						std::cout << "Enter the number of the user that you want to follow: ";
						std::cin >> index;
						if (index == LoggedinUser) std::cout << "You cannot follow yourself man.\n Choose another user.\n";
						//Escape the function when flag is 1 when the user chooses a correct user
						else flag9 = 1;
					} while (flag9!=1);
					//Output to help with the presentation on the console
					std::cout << "Before, " << Users[index].getUserName() << " had " << Users[index].getNoOfFollowers() << " followers.\n";
					//Setting the new number of followers of the user that was followed
					Users[index].setNoOfFollowers(U.AddFollower(Users, index));
					std::cout << "After, " << Users[index].getUserName() << " has " << Users[index].getNoOfFollowers() << " followers.\n";
					break;
				}
				case 4: {
					//Exit the program when 4 is selected
					flag3 = 1;
					break;
				}
				default: {
					std::cout << "You have entered an incorrect selection\n";
					break;
				}
				}
			} while (flag3 !=1);
			break;
		}
		case 2:
		{
			bool flag8 = 0;
			std::string _Pagename;
			//Repeat asking for pagename and password until both are correct
			do
			{
				std::cout << "Please enter page name:\n";
				std::cin >> _Pagename;
				std::cout << "Please enter password:\n";
				std::string _Password;
				std::cin >> _Password;
				//Checking that the page name and password that were inputted are correct
				if (CheckMemberExistence(_Pagename, _Password, Pages) == true) {
					std::cout << "Successfully logged in!\n";
					flag8 = 1;
				}
				//If they are not correct print out a statement and repeat
				else std::cout << "Wrong page name or password. Please try again.\n";
			} while (flag8 != 1);
			//Assign the logged in user the index of the object that you have logged in to
			LoggedinPage = P.getIndexinMap(Pages, _Pagename);
			bool flag2 = 0;
			//Repeat the features display until the user asks to to exit
			do
			{
				//Start of the features screen
				switch (FeaturesScreenForPages()) {
				case 1:
				{
					//Write a post on the logged in page
					Pages[LoggedinPage].WritePost(Pages, LoggedinPage);
					//incrementing the number of posts made on a page
					Pages[LoggedinPage].setNoOfPosts(Pages[LoggedinPage].AddPost(Pages, LoggedinPage));
					break;
				}
				case 2: {
					//Code for viewing someone's profile
					//List out the existing pages to choose from
					P.ListOutMembers(Pages);
					std::cout << "Enter the number of the page that you want to view: \n";
					//Asking the user which page they would like to view
					int index(0);
					std::cin >> index;
					//Print details of the page that is wanted
					Pages[LoggedinPage].printMemberDetails(Pages, index);
					break;
				}
				case 3: {
					//Code for adding a number of members
					//Asking the user how many members they want to add
					std::cout << "How many members do you want to add to " << Pages[LoggedinPage].getPageName() << "?\n";
					int number;
					std::cin >> number;
					//Output to help with the presentation on the console
					std::cout << Pages[LoggedinPage].getPageName() << " had " << Pages[LoggedinPage].getNoOfMembers() << " members before you added members.\n";
					//Setting the new number of members of the page that had members added to it
					Pages[LoggedinPage].setNoOfMembers(P.AddMembers(Pages, LoggedinPage, number));
					std::cout << Pages[LoggedinPage].getPageName() << " has " << Pages[LoggedinPage].getNoOfMembers() << " members after you added members.\n";
					break;
				}
				case 4: {
					//Exit the program when 4 is selected
					flag2 = 1;
					break;
				}
				default:
				{
					std::cout << "You have entered an incorrect selection\n";
					break;
				}
				}
			} while (flag2!=1);
			break;
		}
		default:
		{
			std::cout << "You have entered an incorrect selection\n";
			break;
		}
		}
		break;
	}
	}
}