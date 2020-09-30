//@Date:15-3-19
//@author
//@comments:You need to install c++ "boost library" or you may not be able to run the program
//@you can get "boost library" from our references which is super-super-useful for c++ experience
//
//@Due to different IDE, you may need to change the path of the file (SEE LINE 244)
//@If you are Xcode users, you may change your scheme path(Editor-Edit Scheme-working directory)
//
//@The speed of program depands on computer performance,
//@you'd better not open other programs in the same time
//
//Thank you for your reviewing! Further questions can




#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <dirent.h>
#include <boost/algorithm/string.hpp>
#include <boost/progress.hpp>
#include <unordered_map>
#include <map>


using namespace std;
using namespace boost;
struct HashNode {
	string page;
	string formerword;
	int line;
	HashNode* Next;
};
class Document {
public:
	void Files_getOrigin(void);
	//Files save the original data while database dir save the data manipulated
	int stop_words = 0;
	//stop_words refer to those without actual meaning in the text
	int words_button = 0;
	//Control the words_count button and you can close it to speed up
	void SearchWord(string name);
	//Search the word in the document
	string Query(void);
	//search the elements in ducument
	int blank_number = 0;
	//record the blank number of every word
	void Searchphrase(string name);
	//Search the word in the document
	void SearchKey(string name);
	//Search key in the document
	void SearchSentence(string name);
	//Search for sentence
	//
private:
	int word_Camp(const string word);
	//whether the word is a stopword or not
	void Replace_annotation(string* content);
	//Replace anotation character with blank space
	void Document_LoadOrigin(const string path, const string name);
	//Load in the FILE CONTENT
	vector<string>number_wordscamp;
	//Save and find string in camp
	unordered_map<string, HashNode>HashTable;
	//Use unordered_map to store
	unordered_map<string, HashNode>::iterator Poslocator;
	//iterator to locate the content
	void HashInsert(string page, int line, struct HashNode* Header, string formerword);
	//Insert the elements into the hashtable and save its position
	map<string, int>Number_wordAppearence;
	//Sava each time every character appears
	static bool SortTerm(pair<string, int> &value1, pair<string, int> &value2);
};


int main()
{

	Document document;
	string query;

	document.Files_getOrigin();
	//load in the dir

	cout << endl << "The number of stop words is " << document.stop_words << endl;

	//To avoid the missing word
	do {
		cout << endl <<"Search your content" << endl;
		query = document.Query();
		if (query != "end") {
			if (query.find("key:") != query.npos)
				document.SearchKey(query);
			else if (document.blank_number >= 2)
				document.SearchSentence(query);
			else
				switch (document.blank_number) {
				case 0:
					cout << endl << "Searching for the word" << endl;
					document.SearchWord(query);
					break;
				case 1:
					cout << "Searching for phrase" << endl;
					document.Searchphrase(query);
				default:
					break;
				}

		}
	} while (query != "end");
	//Quit with "end"

	return 0;
}


void Document::Document_LoadOrigin(const string path, const string name)
{
	int word = 0;
	//Show The Document Function
	ifstream Origin_File("./"+path+"/" + name);
	//Load in the Origin FIle
	ofstream Rectify_File("./DataBase/" + name);
	//OUTPUT FILE
	string file_content;
	//GET FILE CONTENT
	vector<string> split_string;
	//SPLIT THE WHOLE STRING
	string formerword;
	//Save the former word in the page of the specific word
	while (getline(Origin_File, file_content))
	{
		transform(file_content.begin(), file_content.end(), file_content.begin(), ::tolower);
		Replace_annotation(&file_content);
		split(split_string, file_content, is_any_of(" "));

		for (int i = 0; i < split_string.size(); i++)
		{
			if (!word_Camp(split_string[i]) && split_string[i] != " ")
			{
				word++;
				Rectify_File << split_string[i] << " ";
				//Number_wordAppearence[split_string[i]]++;
				Poslocator = HashTable.find(split_string[i]);
				if (Poslocator != HashTable.end())//case 1:the key already exists
					HashInsert(name, word, &Poslocator->second, formerword);
				else//case 2:the key doesn't exist we need to create
				{
					HashNode *NewNode = new HashNode;
					NewNode->page = name;
					NewNode->line = word;
					NewNode->Next = NULL;
					NewNode->formerword = formerword;//Save its former word
					HashTable.insert(
						pair<string, HashNode>(split_string[i], *NewNode));
					//use pair to insert the element
				}
				formerword = split_string[i];
			}
			else//case 2: the word are stop_words
				stop_words++;

		}
	}

	Origin_File.close();
	Rectify_File.close();
}


void Document::Replace_annotation(string* content)
{
	//These are words without specific meaning
	//We simply delete them from the text
	replace_all(*content, ",", "");
	replace_all(*content, ":", "");
	replace_all(*content, ";", "");
	replace_all(*content, "?", "");
	replace_all(*content, "[", "");
	replace_all(*content, "]", "");
	replace_all(*content, "]", "");
	replace_all(*content, "!", "");
	replace_all(*content, "'", "");
	replace_all(*content, ".", "");
	replace_all(*content, "-", "");

}


int Document::word_Camp(const string word)
{
	//The word in the stopword_Camp generates from the rank of highly frequency voca
	//which usually have no specific meaning
	vector<string> stopword_Camp = { "the","i","I","to","of","you","my","that","it","not",
		"were","was","he","helena","and","but","have","had","whice","must","what","how",
		"however","why","them","they","their","your","us","yet","base","but","fair","such",
		"if","issues","london","plebeians","unhappy","wellworthy","when","which","writ","Key"
		"had","love","so","him","her","with","wa","me","Her","|","are","if","end","which"
		"is","too","not","be","your","for","on","in","thee","an","am","sonnet","Sonnet"
	};


	if (find(stopword_Camp.begin(), stopword_Camp.end(), word) != stopword_Camp.end())
		//case 1:Find the word in the camp
		return 1;
	else
	{
		if (words_button) {
			auto index = find(number_wordscamp.begin(), number_wordscamp.end(), word);
			if (index == number_wordscamp.end())
			{
				number_wordscamp.push_back(word);
			}
		}
		//if it's not an stopword we record its repeated times
		return 0;
	}
	return 0;
}


void Document::Files_getOrigin(void)
//Get all the file in the directory
{
	struct dirent *dirp;
	string name;
	progress_display pd(195);
	DIR* dir = opendir("./FILE");//use dir pointer
	while ((dirp = readdir(dir)) != nullptr)
	{
		if (dirp->d_type == DT_REG)//case 1:it is a file
		{
			name = dirp->d_name;
			Document_LoadOrigin("FILE", name);
			++pd;
		}
	}
	closedir(dir);
}


void Document::HashInsert(string page, int line, struct HashNode* Header, string formerword)
//Similar to the link-list insertion,we find an empty postion and insert the new node
{
	HashNode *NewNode = new HashNode;
	HashNode *ptr = Header->Next;
	NewNode->page = page;
	NewNode->line = line;
	NewNode->Next = NULL;
	NewNode->formerword = formerword;
	//Because its entry has at least node, we can guarantee header isn't NULL
	Header->Next = NewNode;
	NewNode->Next = ptr;

	Header->Next = NewNode;
}



void Document::SearchWord(string name)
//Case 1 search for word
//we use unorder_map(Hashtable) to locate its position
//And we simply print the whole list store in the map
{
	struct HashNode* hashchain;
	Poslocator = HashTable.find(name);
	cout << endl;
	if (Poslocator == HashTable.end())
	{
		cout << "Element NOT Found" << endl;
		return;
	}
	cout << Poslocator->first << " : ";
	hashchain = &Poslocator->second;
	cout << "The search for " << name << endl;
	while (hashchain != NULL)
	{
		cout << hashchain->page << " " << hashchain->line << endl;
		hashchain = hashchain->Next;
	}
}


string Document::Query(void)
//Query function deals with different situations
//search for word and search for phrase
//the distinguish relies on the number of blank character
{
	string query;
	blank_number = 0;

	getline(cin, query);
	transform(query.begin(), query.end(), query.begin(), ::tolower);
	for (int i = 0; i < query.length(); i++)
	{
		if (query[i] == ' ')
			blank_number++;
	}
	return query;
}


void Document::Searchphrase(string name)
//Case 2 search for phrase
//First we find the latter word
//we use unorder_map(Hashtable) to locate its position
//And we simply traverse the former word in its list chain
//Then we examine whether its position is the latter one's minus by one
//if equals,we find the right pairs
{
	cout << endl;
	vector<string>content;
	string formerword;
	split(content, name, is_any_of(" "));
	int Find_button = 1;//to show whether finding is success

	auto Poslocator_latter = HashTable.find(content[content.size() - 1]);
	struct HashNode* hashchain_latter = &Poslocator_latter->second;

	if (Poslocator_latter == HashTable.end())  //case 1: not find the latter word
	{
		cout << "Element not Found" << endl;
		return;
	}

	while (hashchain_latter != NULL)  //loop through the latter list
	{
		if (hashchain_latter->formerword == content[0])
		{
			if (Find_button == 1)
			{
				cout << "The search for" << endl;
				Find_button = 0;
			}
			cout << hashchain_latter->page << " " << hashchain_latter->line - 1 << endl;

		}
		hashchain_latter = hashchain_latter->Next;
	}

	if (Find_button == 1)
	{  //case 2: not find the phrase
		cout << "Element not Found" << endl;
	}
}


void Document::SearchKey(string name)
//Case 3 search key
//we count the times that "key" appears in each pages by map container
//And we output all the pages that key appears
{
	vector<string>content2, content;
	split(content2, name, is_any_of(":"));
	split(content, content2[1], is_any_of(" "));
	map<string, int>word_number;
	map<string, int>file_weight;
	for (int i = 0; i < content.size(); i++)  //Calculate the total number of each word appearance
	{
		Poslocator = HashTable.find(content[i]);
		if (Poslocator == HashTable.end()) continue;//we skip over the unknown word
		HashNode* hashchain = &Poslocator->second;
		while (hashchain != NULL)
		{
			word_number[content[i]]++;
			hashchain = hashchain->Next;
		}
	}

	int sum = 0;
	for (auto&i : word_number)  //Calculate the sum of each word appearance
		sum += i.second;
	int avg = 0;
	for (auto&i : word_number)  //Elimate the word which has small frequency comparing the sum
		if (i.second > sum / 100)
			avg += i.second;
		else
			i.second = 0;
	avg = double(avg) / word_number.size();
	map<string, double>ratio;  //Saving the ratio of each word
	for (auto&i : word_number)  //Calculate the ratio of each word
	{
		if (i.second > 0)
			ratio[i.first] = double(avg) / double(i.second);
		else
			ratio[i.first] = 0;
	}
	cout << "The ratio of each word is: " << endl;
	for (auto&i : ratio)
		cout << i.first << ": " << i.second << endl;

	for (int i = 0; i < content.size(); i++)//Calculate each weight of the pages
	{
		Poslocator = HashTable.find(content[i]);
		if (Poslocator == HashTable.end()) continue;
		HashNode* hashchain = &Poslocator->second;
		while (hashchain != NULL)
		{
			file_weight[hashchain->page] += ratio[content[i]];
			hashchain = hashchain->Next;
		}
	}

	vector<pair<string, int>>rank;
	for (auto&i : file_weight)//save it into the container to rank
	{
		rank.emplace_back(make_pair(i.first, i.second));
	}
	sort(rank.begin(), rank.end(), Document::SortTerm);//use sort function
	int j = 0;
	for (auto&i : rank)//Output he top 10 page
	{
		if (j++ > 9) break;
		cout << "The " << j << "th page is " << i.first << endl;
	}
}

void Document::SearchSentence(string name)
{
	cout << "Search for sentence";
	vector<string>content;
	split(content, name, is_any_of(" "));
	HashNode* newnode = NULL;
	for (int i = content.size() - 1; i > 0; i--)
	{
		Poslocator = HashTable.find(content[i]);
		if (Poslocator == HashTable.end()) return;
		auto hashchain = &Poslocator->second;
		while (hashchain != NULL)
		{
			if (hashchain->formerword == content[i - 1])
			{
				newnode = hashchain;
				break;
			}
			hashchain = hashchain->Next;
		}
		if (hashchain == NULL)
		{
			cout << "Can not find the sentence" << endl;
			return;
		}
	}
	cout << newnode->page << newnode->line << endl;
}

bool Document::SortTerm(pair<string, int> &value1, pair<string, int> &value2)
{
	return value1.second > value2.second;
}