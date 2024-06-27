#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include "main.hpp"

Item::~Item()
{
	// std::cout << "bye bye" << std::endl;
}

Journal::Journal(int id, std::string name, std::string volume, std::string issue, std::string year)
{
	this->ID = id;
	this->name = name;
	this->volume = volume;
	this->issue = issue;
	this->year = year;
}
void Journal::printOutInfo()
{
	std::string tmpVolumeIssue = volume + '(' + issue + ')';
	std::cout << "|  " << ID << " | " << std::setw(52) << std::left << name << "|" << std::endl
			  << "|    | " << year << ", " << std::setw(46) << std::left << tmpVolumeIssue << "|" << std::endl
			  << "+----+-----------------------------------------------------+" << std::endl;
}
Item *Journal::findLocal(const std::string &input)
{
	if (volume.find(input) != std::string::npos || issue.find(input) != std::string::npos || name.find(input) != std::string::npos || year.find(input) != std::string::npos)
	{
		return this;
	}
	return nullptr;
}
Item *Journal::findLocal(const int &input)
{
	if (input == ID)
	{
		return this;
	}
	return nullptr;
}

Book::Book(int id, std::string name, std::string author, std::string year)
{
	this->ID = id;
	this->name = name;
	this->author = author;
	this->year = year;
}
void Book::printOutInfo()
{
	std::cout << "|  " << ID << " | " << std::setw(52) << std::left << name << "|" << std::endl
			  << "|    | " << year << ", " << std::setw(46) << std::left << author << "|" << std::endl
			  << "+----+-----------------------------------------------------+" << std::endl;
}
Item *Book::findLocal(const std::string &input)
{
	if (author.find(input) != std::string::npos || name.find(input) != std::string::npos || year.find(input) != std::string::npos)
	{
		return this;
	}
	return nullptr;
}
Item *Book::findLocal(const int &input)
{
	if (input == ID)
	{
		return this;
	}
	return nullptr;
}

Database::Database()
{
	// Database constructor
}
void Database::printOutDatabase() const
{
	for (auto it = db.begin(); it != db.end(); it++)
	{
		(*it)->printOutInfo();
	}
}
void Database::findGlobal(const std::string &input)
{
	Database tmpdb;
	for (auto it = db.begin(); it != db.end(); it++)
	{
		Item *tmpPointer = (*it)->findLocal(input);
		if (tmpPointer != nullptr)
		{
			// Add a copy of the found item to the temporary database
			if (dynamic_cast<Journal *>(tmpPointer))
			{
				const Journal *journal = dynamic_cast<Journal *>(tmpPointer);
				tmpdb.add(new Journal(journal->ID, journal->name, journal->volume, journal->issue, journal->year));
			}
			else if (dynamic_cast<Book *>(tmpPointer))
			{
				const Book *book = dynamic_cast<Book *>(tmpPointer);
				tmpdb.add(new Book(book->ID, book->name, book->author, book->year));
			}
		}
	}
	list(tmpdb);
}
void Database::eraseItem(const std::string &input)
{
	for (auto it = db.begin(); it != db.end();)
	{
		Item *tmpPointer = (*it)->findLocal(input);
		if (tmpPointer != nullptr)
		{
			delete *it;
			auto newEnd = std::remove(db.begin(), db.end(), tmpPointer);
			db.erase(newEnd, db.end());
			// if (it == db.end())
			// {
			// 	break;
			continue;
		}
		++it;
	}


	// list(*this);
}
bool Database::removeByID(const int &input)
{
	for (auto it = db.begin(); it != db.end();)
	{
		Item *tmpPointer = (*it)->findLocal(input);
		if (tmpPointer != nullptr)
		{
			delete *it;
			auto newEnd = std::remove(db.begin(), db.end(), tmpPointer);
			db.erase(newEnd, db.end());
			// if (it == db.end())
			// {
			// 	break;
			return 1;
		}
		++it;
	}
	// list(*this);
	return 0;
}

void Database::sortingAlgorithm(const std::string &criterion, const std::string &order = "asc")
{
	// std::cout << "I'm inside the function!!!" << std::endl;
	if (criterion == "name")
	{
		if (order == "desc")
		{
			std::sort(db.begin(), db.end(), [](const Item *const &a, const Item *const &b)
					  { return a->name > b->name; });
		}
		else
		{
			std::sort(db.begin(), db.end(), [](const Item *const &a, const Item *const &b)
					  { return a->name < b->name; });
		}
	}
	else if (criterion == "year")
	{
		if (order == "desc")
		{
			std::sort(db.begin(), db.end(), [](const Item *const &a, const Item *const &b)
					  { return a->year > b->year; });
		}
		else
		{
			std::sort(db.begin(), db.end(), [](const Item *const &a, const Item *const &b)
					  { return a->year < b->year; });
		}
	}
	else if (criterion == "id")
	{
		if (order == "desc")
		{
			std::sort(db.begin(), db.end(), [](const Item *const &a, const Item *const &b)
					  { return a->ID > b->ID; });
		}
		else
		{
			std::sort(db.begin(), db.end(), [](const Item *const &a, const Item *const &b)
					  { return a->ID < b->ID; });
		}
	}
}

// add item to the database
void Database::add(Item *a)
{
	db.push_back(a);
}

Database::~Database()
{
	for (auto i = db.begin(); i != db.end(); i++)
	{
		// std::cout << "clearing the database " << std::endl;
		delete *i;
	}
	db.clear();
}

void list(const Database &database)
{
	database.printOutDatabase();
	std::cout << "| Total: " << database.db.size() << "                                                 |" << std::endl
			  << "+----------------------------------------------------------+" << std::endl;
}

int stringCheck(const std::string &string)
{
	if (string.empty())
	{
		// std::cout << "Search string is empty. Please provide a valid search string." << std::endl;
		return 1; // Exit the function with an error code
	}
	return 0;
}
void commandExpectsArgument(const std::string &command)
{
	std::string tempString = "Command \"" + command + "\" expects some argument";
	std::cout << "+----------------------------------------------------------+" << std::endl
			  << "| " << std::setw(57) << std::left << tempString << "|" << std::endl
			  << "+----------------------------------------------------------+" << std::endl;
}

// // definition of the sort function according to name
// bool sort_name::operator()(const Item *a, const Item *b)
// {
// }

int main()
{
	Database db;
	db.add(new Journal(1, "IEEE Transaction on Computers", "C-35", "10", "1986"));
	db.add(new Journal(2, "IEEE Transaction on Computers", "C-35", "11", "1986"));
	db.add(new Journal(3, "IEEE Transactions on Communications", "28", "8", "1980"));
	db.add(new Book(4, "Dva roky prazdnin", "Jules Verne", "1888"));
	db.add(new Book(5, "Tajuplny ostrov", "Jules Verne", "1874"));
	db.add(new Book(6, "Ocelove mesto", "Jules Verne", "1879"));

		std::string input;
	while (std::getline(std::cin, input))
	{

		std::istringstream iss(input);
		std::string command, criterion, sortingOrder;
		std::getline(iss, command, ':');   // Read the command part up until the colon and discard it
		std::getline(iss, criterion, ':'); // Read the criterion part up until the colon and discard it
		std::getline(iss, sortingOrder);   // Read the sorting order
										   // std::cout << "Sorting order is " << sortingOrder << std::endl;
		if (command == "list")
		{
			std::cout << "+----------------------------------------------------------+" << std::endl
					  << "| List of all records                                      |" << std::endl
					  << "+----+-----------------------------------------------------+" << std::endl;
			list(db);
		}
		else if (command == "find")
		{
			if (stringCheck(criterion))
			{
				commandExpectsArgument(command);
				continue;
			}
			std::string tempString = '\"' + criterion + '\"';
			std::cout << "+----------------------------------------------------------+" << std::endl
					  << "| Search for " << std::setw(46) << std::left << tempString << "|" << std::endl
					  << "+----+-----------------------------------------------------+" << std::endl;
			db.findGlobal(criterion);
		}
		else if (command == "erase")
		{
			if (stringCheck(criterion))
			{
				commandExpectsArgument(command);
				continue;
			}
			db.eraseItem(criterion);
		}
		else if (command == "remove")
		{
			if (stringCheck(criterion))
			{
				commandExpectsArgument(command);
				continue;
			}
			
			if (!db.removeByID(std::stoi(criterion)))
			{
				std::string tempString = "ID = " + criterion + " is not in the database";
				std::cout << "+----------------------------------------------------------+" << std::endl
						  << "| " << std::setw(57) << std::left << tempString << "|" << std::endl
						  << "+----------------------------------------------------------+" << std::endl;
			}
		}
		else if (command == "sort")
		{
			if (stringCheck(criterion))
			{
				commandExpectsArgument(command);
			}
			db.sortingAlgorithm(criterion, sortingOrder);
			// list(db);
		}
		else
		{
			std::string unknown = "Unknown command \"" + command + "\"";
			std::cout << "+----------------------------------------------------------+" << std::endl
					  << "| " << std::setw(57) << std::left << unknown << "|" << std::endl
					  << "+----------------------------------------------------------+" << std::endl;
		}
	}

	return 0;
}
