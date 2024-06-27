#include <vector>
#include <string>

#ifndef __MAIN_HPP__
#define __MAIN_HPP__

struct sort_name;

class Item
{
protected:
public:
	int ID;
	std::string name, year;


	void virtual printOutInfo() = 0;
	virtual Item* findLocal(const std::string & input) = 0;
	virtual Item* findLocal(const int & input) = 0;
	virtual ~Item();
	friend sort_name;
};

// Journal related to the Database
class Journal : public Item
{
private:
public:
	std::string volume, issue;


	Journal(int id, std::string name, std::string volume, std::string issue, std::string year);
	Item* findLocal(const std::string& input) override;
	Item* findLocal(const int& input) override;
	void printOutInfo() override;
};

// Book related to the Database
class Book : public Item
{
private:
public:
	std::string author;


	Book(int id, std::string name, std::string author, std::string year);
	Item* findLocal(const std::string& input) override;
	Item* findLocal(const int& input) override;
	void printOutInfo() override;
};

class Database
{
public:
	std::vector<Item *> db;

	Database();
	~Database();
	void add(Item *a);
	void printOutDatabase() const;
	void findGlobal(const std::string &input);
	void eraseItem(const std::string &input);
	bool removeByID(const int &input);
	void sortingAlgorithm(const std::string &criterion, const std::string& order);
};

void list(const Database &);
int stringCheck(const std::string &string);
void commandExpectsArgument(const std::string &command);
bool compareByNameAsc(const Item*& a, const Item*& b);
bool compareByYearAsc(const Item*& a, const Item*& b);
bool compareByIDAsc(const Item*& a, const Item*& b);
bool compareByNameDesc(const Item*& a, const Item*& b);
bool compareByYearDesc(const Item*& a, const Item*& b);
bool compareByIDDesc(const Item*& a, const Item*& b);

// // declaration of the sort function according to name
// struct sort_name
// {
// 	inline bool operator()(const Item *a, const Item *b);
// };

#endif // __MAIN_HPP__
