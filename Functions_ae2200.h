#pragma once

#include <iostream>
#include <map>
#include "Classes_ae2200.h"


//MainScreen and its choices
int MainScreen()
{
	std::cout << "Welcome to Ahmad Book!\n";
	std::cout << "1. Register a new user\n";
	std::cout << "2. Log in to an existing user\n";
	int choice;
	std::cin >> choice;
	return choice;
}

//Login screen and its choices
int LoginScreen() {
	std::cout << "1. Login to a user\n";
	std::cout << "2. Login to a page\n";
	int choice;
	std::cin >> choice;
	return choice;
}

//Register screen and its choices
int RegisterScreen() {
	std::cout << "1. Create a user\n";
	std::cout << "2. Create a page\n";
	int choice;
	std::cin >> choice;
	return choice;
}

//Features screen for users and its choices
int FeaturesScreenForUsers() {
	std::cout << "Welcome to the main menu!\n";
	std::cout << "1. Write a post\n";
	std::cout << "2. Check a profile\n";
	std::cout << "3. Follow a user\n";
	std::cout << "4. Exit program.\n";
	int choice;
	std::cin >> choice;
	return choice;
}

//Features screen for pages and its choices
int FeaturesScreenForPages() {
	std::cout << "Welcome to the main menu!\n";
	std::cout << "1. Write a post\n";
	std::cout << "2. Check a page\n";
	std::cout << "3. Add members\n";
	std::cout << "4. Exit program.\n";
	int choice;
	std::cin >> choice;
	return choice;
}


//The following is an overloaded function that checks whether a user or a page exist based on the username, page name, and/or password

//Checking if a user exists using a map iterator and the username and password entered by the user
bool CheckMemberExistence(std::string _UserOrPage, std::string _Password, std::map<int, User> PlaceHolder)
{
	//Start an iterator
	std::map<int, class User>::iterator iter;
	//Iterating through the map to check if the username and password already exists
	for (iter = PlaceHolder.begin(); iter != PlaceHolder.end(); ++iter)
	{
		//Condition that states if it exists return true
		if (iter->second.getUserName() == _UserOrPage && iter->second.getPassword() == _Password) return true;
	}
	return false;
}

//Checking if a user exists using a map iterator and the username entered by the user
bool CheckMemberExistence(std::string _UserOrPage, std::map<int, User> PlaceHolder)
{
	//Start an iterator
	std::map<int, class User>::iterator iter;
	//Iterating through the map to check if the inputted username exists
	for (iter = PlaceHolder.begin(); iter != PlaceHolder.end(); ++iter)
	{
		//Condition that states if it exists return true
		if (iter->second.getUserName() == _UserOrPage) return true;
	}
	return false;
}

//Checking if a page exists using a map iterator and the page name and password entered by the user
bool CheckMemberExistence(std::string _UserOrPage, std::string _Password, std::map<int, Page> PlaceHolder)
{
	//Start an iterator
	std::map<int, class Page>::iterator iter;
	//Iterating through the map to check if the username and password that were inputted already exist
	for (iter = PlaceHolder.begin(); iter != PlaceHolder.end(); ++iter)
	{
		//Condition that states if it exists return true
		if (iter->second.getPageName() == _UserOrPage && iter->second.getPassword() == _Password) return true;
	}
	return false;
}

//Checking if a page exists using a map iterator and the page name and password entered by the user
bool CheckMemberExistence(std::string _UserOrPage, std::map<int, Page> PlaceHolder)
{
	//Start an iterator
	std::map<int, class Page>::iterator iter;
	//Iterating through the map to check if the inputted page name exists
	for (iter = PlaceHolder.begin(); iter != PlaceHolder.end(); ++iter)
	{
		//Condition that states if it exists return true
		if (iter->second.getPageName() == _UserOrPage) return true;
	}
	return false;
}