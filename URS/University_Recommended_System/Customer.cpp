#include <iostream>
#include<fstream>
#include <string>
#include <regex>
using namespace std;

//Create the structure of University Details
struct UniversityDetails {
	string id;
	string universityName;
	string locationCode;
	string location;
	double arScore;
	int arRank;
	double erScore;
	int erRank;
	double fsrScore;
	int fsrRank;
	double cpfScore;
	int cpfRank;
	double ifrScore;
	int ifrRank;
	double isrScore;
	int isrRank;
	double irnScore;
	int irnRank;
	double gerScore;
	int gerRank;
	double scoreScaled;
	//Pointer
	UniversityDetails* NextAddress;

}*head;

//global value for total details record in csv file
int totalUniversityDetails = 0;

//Create a class for University Details
class UniversityList {
	UniversityDetails* head = NULL;
	string university_file = "";

	//declare for the University File;
	string UniversityFile = "";

public:
	UniversityList(string university_file) {
		this->university_file = university_file;
	}

	UniversityDetails* createNewNode(string id, string universityName, string locationCode, string location, double arScore, int arRank, double erScore, int erRank, double fsrScore, int fsrRank, double cpfScore, int cpfRank, double ifrScore, int ifrRank, double isrScore, int isrRank, double irnScore, int irnRank, double gerScore, int gerRank, double scoreScaled) {

		//Create a new node for university details
		UniversityDetails* newnode = new UniversityDetails;

		//Fill up all the data
		newnode->id = id;
		newnode->universityName = universityName;
		newnode->locationCode = locationCode;
		newnode->location = location;
		newnode->arScore = arScore;
		newnode->arRank = arRank;
		newnode->erScore = erScore;
		newnode->erRank = erRank;
		newnode->fsrScore = fsrScore;
		newnode->fsrRank = fsrRank;
		newnode->cpfScore = cpfScore;
		newnode->cpfRank = cpfRank;
		newnode->ifrScore = ifrScore;
		newnode->ifrRank = ifrRank;
		newnode->isrScore = isrScore;
		newnode->isrRank = isrRank;
		newnode->irnScore = irnScore;
		newnode->irnRank = irnRank;
		newnode->gerScore = gerScore;
		newnode->gerRank = gerRank;
		newnode->scoreScaled = scoreScaled;
		newnode->NextAddress = NULL;

		//return the newnode address
		return newnode;

	}

	//Insert from the back taken from the csv file
	void Cus_InsertFromTheEnd(string id, string universityName, string locationCode, string location, double arScore, int arRank, double erScore, int erRank, double fsrScore, int fsrRank, double cpfScore, int cpfRank, double ifrScore, int ifrRank, double isrScore, int isrRank, double irnScore, int irnRank, double gerScore, int gerRank, double scoreScaled) {

		UniversityDetails* newnode = createNewNode(id, universityName, locationCode, location, arScore, arRank, erScore, erRank, fsrScore, fsrRank, cpfScore, cpfRank, ifrScore, ifrRank, isrScore, isrRank, irnScore, irnRank, gerScore, gerRank, scoreScaled);

		//check the head
		if (head == NULL) {
			head = newnode;
		}
		else {
			UniversityDetails* current = head;
			while (current->NextAddress != NULL) {
				// if not yet last node, move to the next item
				current = current->NextAddress;
			}
			//if found the last node, attach the new node after the last node
			current->NextAddress = newnode;
		}
		
	}
	/*
	//Insert from the front taken from the csv file
	void Cus_InsertFromTheFront(string UniID, string universityName, string locationCode, string location, double arScore, int arRank, double erScore, int erRank, double fsrScore, int fsrRank, double cpfScore, int cpfRank, double ifrScore, int ifrRank, double isrScore, int isrRank, double irnScore, int irnRank, double gerScore, int gerRank, double scoreScaled) {

		UniversityDetails* newnode = createNewNode(UniID, universityName, locationCode, location, arScore, arRank, erScore, erRank, fsrScore, fsrRank, cpfScore, cpfRank, ifrScore, ifrRank, isrScore, isrRank, irnScore, irnRank, gerScore, gerRank, scoreScaled);

		//check the head
		if (head == NULL) {
			head = newnode;
		}
		else {
			newnode->NextAddress = head;
			head = newnode;
		}

	}
	*/


	//Display all the University data
	void Cus_DisplayAllDetails() {
		UniversityDetails* current = head;
		while (current != NULL) {
			cout << "University Rank: " << current->id << endl;
			cout << "University Name: " << current->universityName << endl;
			cout << "University Location Code: " << current->locationCode << endl;
			cout << "University Location: " << current->location << endl;
			cout << "University Academic Reputation Score: " << current->arScore << endl;
			cout << "University Academic Reputation Rank: " << current->arRank << endl;
			cout << "University Employer Reputation Score: " << current->erScore << endl;
			cout << "University Employer Reputation Rank: " << current->erRank << endl;
			cout << "Univetsity Faculty/Student Ratio Score: " << current->fsrScore << endl;
			cout << "University Faculty/Student Ratio Rank: " << current->fsrRank << endl;
			cout << "University Citations Per Faculty Score: " << current->cpfScore << endl;
			cout << "University Citations Per Faculty Rank: " << current->cpfRank << endl;
			cout << "University International Faculty Ratio Score: " << current->ifrScore << endl;
			cout << "University International Faculty Ratio Rank: " << current->ifrRank << endl;
			cout << "University International Student Ratio Score: " << current->isrScore << endl;
			cout << "University International Student Ratio Rank: " << current->isrRank << endl;
			cout << "University International Research Network Score: " << current->irnScore << endl;
			cout << "University International Research Network Rank: " << current->irnRank << endl;
			cout << "University Employement Outcome Score: " << current->gerScore << endl;
			cout << "University Employement Outcome Rank: " << current->gerRank << endl;
			cout << "University Score Scaled: " << current->scoreScaled << endl<<endl;
		
			current = current->NextAddress;
			//record the value for total details

			totalUniversityDetails++;

		}
		cout << "University Details Display Ended Here!" << endl;
		cout << "Total University Details Are: " << totalUniversityDetails << endl << endl;
		

	}


	//Binary Search Algorithm
	int BinarySearchAlgorithm(int arrayValue[], int arraySize, int InputSearchValue) {

		//First Value of the array
		int firstValue = 0;
		//Last Value of the array
		int lastValue = arraySize - 1;

		//Algorithm used for the binary search
		while (firstValue <= lastValue) {
			//Formula used for finding middle value

			int middleValue = (firstValue + (lastValue - firstValue) / 2);


			//if the middle value match with the customer search value
			if (arrayValue[middleValue] == InputSearchValue) {
				return middleValue;
				break;
			}
			//if the middle value less than the customer search value
			if (arrayValue[middleValue] < InputSearchValue) {
				//first value will become value after the middle value
				firstValue = middleValue + 1;
			}
			else {
				//last value will become the value less than middle value
				lastValue = middleValue - 1;
			}

		}
		return -1;
	}

	//Bubble Sort Algorithm
	void BubbleSortAlgorithm(int arrayValue[], int size) {

		//Loop all each array element
		for (int loop = 0; loop < (size - 1); ++loop) {
			//this is for swaping condition
			int swapCondition = 0;

			//This is for compare two number
			for (int i = 0; i < (size - loop - 1); ++i) {

				//accesding order
				if (arrayValue[i] > arrayValue[i + 1]) {
					//Swapping done here
					int tempBox = arrayValue[i];
					arrayValue[i] = arrayValue[i + 1];
					arrayValue[i + 1] = tempBox;

					//Swapping completed
					swapCondition = 1;
				}
			}
		}
	}


	//This is the binary search for allow customer to search based on university details
	void searchUniversityRankDetails(int inputNumber) {
		UniversityDetails* current = head;
		int search_rank;
		//Create an empty array for adding the Rank data (dynamic allocate array)
		int* UniRankArray = new int[totalUniversityDetails + 1];

		
		//Check the case number
		//Rank Search Details
		if (inputNumber == 1) {
			//Adding value into the array
			for (int i = 0; i < totalUniversityDetails; i++) {
				if ((stoi(current->id) > 0)) {
					UniRankArray[i] = stoi(current->id);
					current = current->NextAddress;
				}
			}

		}
		else if (inputNumber == 2) {
			//Adding value into the array
			for (int i = 0; i < totalUniversityDetails; i++) {
				if (((current->arRank) > 0)) {
					UniRankArray[i] = (current->arRank);
					current = current->NextAddress;
				}
			}

		}
		else if (inputNumber == 3) {
			//Adding value into the array
			for (int i = 0; i < totalUniversityDetails; i++) {
				if (((current->erRank) > 0)) {
					UniRankArray[i] = (current->erRank);
					current = current->NextAddress;
				}
			}

		}
		else if (inputNumber == 4) {
			//Adding value into the array
			for (int i = 0; i < totalUniversityDetails; i++) {
				if (((current->fsrRank) > 0)) {
					UniRankArray[i] = (current->fsrRank);
					current = current->NextAddress;
				}
			}

		}
		else if (inputNumber == 5) {
			//Adding value into the array
			for (int i = 0; i < totalUniversityDetails; i++) {
				if (((current->cpfRank) > 0)) {
					UniRankArray[i] = (current->cpfRank);
					current = current->NextAddress;
				}
			}

		}
		else if (inputNumber == 6) {
			//Adding value into the array
			for (int i = 0; i < totalUniversityDetails; i++) {
				if (((current->ifrRank) > 0)) {
					UniRankArray[i] = (current->ifrRank);
					current = current->NextAddress;
				}
			}

		}
		else if (inputNumber == 7) {
			//Adding value into the array
			for (int i = 0; i < totalUniversityDetails; i++) {
				if (((current->isrRank) > 0)) {
					UniRankArray[i] = (current->isrRank);
					current = current->NextAddress;
				}
			}

		}
		else if (inputNumber == 8) {
			//Adding value into the array
			for (int i = 0; i < totalUniversityDetails; i++) {
				if (((current->irnRank) > 0)) {
					UniRankArray[i] = (current->irnRank);
					current = current->NextAddress;
				}
			}

		}
		else if (inputNumber == 9) {
			//Adding value into the array
			for (int i = 0; i < totalUniversityDetails; i++) {
				if (((current->gerRank) > 0)) {
					UniRankArray[i] = (current->gerRank);
					current = current->NextAddress;
				}
			}

		}
		//Score Search Details
		else if (inputNumber == 10) {
			//Adding value into the array
			for (int i = 0; i < totalUniversityDetails; i++) {
				if (((current->arScore) > 0)) {
					UniRankArray[i] = (current->arScore);
					current = current->NextAddress;
				}
			}

		}
		else {
			cout << "Please Try Again!, Input Number Error!" << endl;
		}

		//Sorting Done here
		if (inputNumber <= 9) {
			BubbleSortAlgorithm(UniRankArray, totalUniversityDetails);

		}


		//Linear Search Algorithm
		void LinearSearchAlgorithm(int arrayValue[], int size, int searchNumber) {
			//Create an array to store all the similiar search result

			//for loop to loop through all the element in arrayValue
			for (int linear = 0; linear < size; linear++) {
				if (arrayValue[linear] == searchNumber) {

				}
			}

		}


		//Input to search the rank
		cout << "Enter the value of rank to search. ";
		cin >> search_rank;

		//Binary Search Algorithm
		int searchRankResult = BinarySearchAlgorithm(UniRankArray, totalUniversityDetails, search_rank);


		if (searchRankResult != -1) {
			//Reason plus one beacase result will reduce 1 in array index
			//cout << search_rank << " Rank value found!"<<" located in "<< searchRankResult+1<<" index." << endl<<endl;
			//count what is the gap between the rank and the actual array element
			int numberLeft = 0;
			if ((searchRankResult + 1 >= search_rank)) {
				numberLeft = ((searchRankResult + 1) - search_rank);
			}
			else {
				numberLeft = (search_rank - (searchRankResult+1));
			}

			//Print out that university details
			//Display the result of search the rank (binary search)
			UniversityDetails* print = head;
			while (print != NULL) {
				if (inputNumber == 1) {

					if ((searchRankResult + 1) == stoi(print->id)) {

						cout << "University Rank: " << print->id << endl;
						cout << "University Name: " << print->universityName << endl;
						cout << "University Location Code: " << print->locationCode << endl;
						cout << "University Location: " << print->location << endl;
						cout << "University Academic Reputation Score: " << print->arScore << endl;
						cout << "University Academic Reputation Rank: " << print->arRank << endl;
						cout << "University Employer Reputation Score: " << print->erScore << endl;
						cout << "University Employer Reputation Rank: " << print->erRank << endl;
						cout << "Univetsity Faculty/Student Ratio Score: " << print->fsrScore << endl;
						cout << "University Faculty/Student Ratio Rank: " << print->fsrRank << endl;
						cout << "University Citations Per Faculty Score: " << print->cpfScore << endl;
						cout << "University Citations Per Faculty Rank: " << print->cpfRank << endl;
						cout << "University International Faculty Ratio Score: " << print->ifrScore << endl;
						cout << "University International Faculty Ratio Rank: " << print->ifrRank << endl;
						cout << "University International Student Ratio Score: " << print->isrScore << endl;
						cout << "University International Student Ratio Rank: " << print->isrRank << endl;
						cout << "University International Research Network Score: " << print->irnScore << endl;
						cout << "University International Research Network Rank: " << print->irnRank << endl;
						cout << "University Employement Outcome Score: " << print->gerScore << endl;
						cout << "University Employement Outcome Rank: " << print->gerRank << endl;
						cout << "University Score Scaled: " << print->scoreScaled << endl << endl;

						break;
					}
				}
				else if (inputNumber == 2) {
					if ((searchRankResult+1+numberLeft) == (print->arRank)) {

						cout << "University Rank: " << print->id << endl;
						cout << "University Name: " << print->universityName << endl;
						cout << "University Location Code: " << print->locationCode << endl;
						cout << "University Location: " << print->location << endl;
						cout << "University Academic Reputation Score: " << print->arScore << endl;
						cout << "University Academic Reputation Rank: " << print->arRank << endl;
						cout << "University Employer Reputation Score: " << print->erScore << endl;
						cout << "University Employer Reputation Rank: " << print->erRank << endl;
						cout << "Univetsity Faculty/Student Ratio Score: " << print->fsrScore << endl;
						cout << "University Faculty/Student Ratio Rank: " << print->fsrRank << endl;
						cout << "University Citations Per Faculty Score: " << print->cpfScore << endl;
						cout << "University Citations Per Faculty Rank: " << print->cpfRank << endl;
						cout << "University International Faculty Ratio Score: " << print->ifrScore << endl;
						cout << "University International Faculty Ratio Rank: " << print->ifrRank << endl;
						cout << "University International Student Ratio Score: " << print->isrScore << endl;
						cout << "University International Student Ratio Rank: " << print->isrRank << endl;
						cout << "University International Research Network Score: " << print->irnScore << endl;
						cout << "University International Research Network Rank: " << print->irnRank << endl;
						cout << "University Employement Outcome Score: " << print->gerScore << endl;
						cout << "University Employement Outcome Rank: " << print->gerRank << endl;
						cout << "University Score Scaled: " << print->scoreScaled << endl << endl;

						break;
					}
				}
				else if (inputNumber == 3) {
					if ((searchRankResult + 1 + numberLeft) == (print->erRank)) {

						cout << "University Rank: " << print->id << endl;
						cout << "University Name: " << print->universityName << endl;
						cout << "University Location Code: " << print->locationCode << endl;
						cout << "University Location: " << print->location << endl;
						cout << "University Academic Reputation Score: " << print->arScore << endl;
						cout << "University Academic Reputation Rank: " << print->arRank << endl;
						cout << "University Employer Reputation Score: " << print->erScore << endl;
						cout << "University Employer Reputation Rank: " << print->erRank << endl;
						cout << "Univetsity Faculty/Student Ratio Score: " << print->fsrScore << endl;
						cout << "University Faculty/Student Ratio Rank: " << print->fsrRank << endl;
						cout << "University Citations Per Faculty Score: " << print->cpfScore << endl;
						cout << "University Citations Per Faculty Rank: " << print->cpfRank << endl;
						cout << "University International Faculty Ratio Score: " << print->ifrScore << endl;
						cout << "University International Faculty Ratio Rank: " << print->ifrRank << endl;
						cout << "University International Student Ratio Score: " << print->isrScore << endl;
						cout << "University International Student Ratio Rank: " << print->isrRank << endl;
						cout << "University International Research Network Score: " << print->irnScore << endl;
						cout << "University International Research Network Rank: " << print->irnRank << endl;
						cout << "University Employement Outcome Score: " << print->gerScore << endl;
						cout << "University Employement Outcome Rank: " << print->gerRank << endl;
						cout << "University Score Scaled: " << print->scoreScaled << endl << endl;

						break;
					}
				}
				else if (inputNumber == 4) {
					if ((searchRankResult + 1 + numberLeft) == (print->fsrRank)) {

						cout << "University Rank: " << print->id << endl;
						cout << "University Name: " << print->universityName << endl;
						cout << "University Location Code: " << print->locationCode << endl;
						cout << "University Location: " << print->location << endl;
						cout << "University Academic Reputation Score: " << print->arScore << endl;
						cout << "University Academic Reputation Rank: " << print->arRank << endl;
						cout << "University Employer Reputation Score: " << print->erScore << endl;
						cout << "University Employer Reputation Rank: " << print->erRank << endl;
						cout << "Univetsity Faculty/Student Ratio Score: " << print->fsrScore << endl;
						cout << "University Faculty/Student Ratio Rank: " << print->fsrRank << endl;
						cout << "University Citations Per Faculty Score: " << print->cpfScore << endl;
						cout << "University Citations Per Faculty Rank: " << print->cpfRank << endl;
						cout << "University International Faculty Ratio Score: " << print->ifrScore << endl;
						cout << "University International Faculty Ratio Rank: " << print->ifrRank << endl;
						cout << "University International Student Ratio Score: " << print->isrScore << endl;
						cout << "University International Student Ratio Rank: " << print->isrRank << endl;
						cout << "University International Research Network Score: " << print->irnScore << endl;
						cout << "University International Research Network Rank: " << print->irnRank << endl;
						cout << "University Employement Outcome Score: " << print->gerScore << endl;
						cout << "University Employement Outcome Rank: " << print->gerRank << endl;
						cout << "University Score Scaled: " << print->scoreScaled << endl << endl;

						break;
					}
				}
				else if (inputNumber == 5) {
					if ((searchRankResult + 1 + numberLeft) == (print->cpfRank)) {

						cout << "University Rank: " << print->id << endl;
						cout << "University Name: " << print->universityName << endl;
						cout << "University Location Code: " << print->locationCode << endl;
						cout << "University Location: " << print->location << endl;
						cout << "University Academic Reputation Score: " << print->arScore << endl;
						cout << "University Academic Reputation Rank: " << print->arRank << endl;
						cout << "University Employer Reputation Score: " << print->erScore << endl;
						cout << "University Employer Reputation Rank: " << print->erRank << endl;
						cout << "Univetsity Faculty/Student Ratio Score: " << print->fsrScore << endl;
						cout << "University Faculty/Student Ratio Rank: " << print->fsrRank << endl;
						cout << "University Citations Per Faculty Score: " << print->cpfScore << endl;
						cout << "University Citations Per Faculty Rank: " << print->cpfRank << endl;
						cout << "University International Faculty Ratio Score: " << print->ifrScore << endl;
						cout << "University International Faculty Ratio Rank: " << print->ifrRank << endl;
						cout << "University International Student Ratio Score: " << print->isrScore << endl;
						cout << "University International Student Ratio Rank: " << print->isrRank << endl;
						cout << "University International Research Network Score: " << print->irnScore << endl;
						cout << "University International Research Network Rank: " << print->irnRank << endl;
						cout << "University Employement Outcome Score: " << print->gerScore << endl;
						cout << "University Employement Outcome Rank: " << print->gerRank << endl;
						cout << "University Score Scaled: " << print->scoreScaled << endl << endl;

						break;
					}
				}
				else if (inputNumber == 6) {
					if ((searchRankResult + 1 + numberLeft) == (print->ifrRank)) {

						cout << "University Rank: " << print->id << endl;
						cout << "University Name: " << print->universityName << endl;
						cout << "University Location Code: " << print->locationCode << endl;
						cout << "University Location: " << print->location << endl;
						cout << "University Academic Reputation Score: " << print->arScore << endl;
						cout << "University Academic Reputation Rank: " << print->arRank << endl;
						cout << "University Employer Reputation Score: " << print->erScore << endl;
						cout << "University Employer Reputation Rank: " << print->erRank << endl;
						cout << "Univetsity Faculty/Student Ratio Score: " << print->fsrScore << endl;
						cout << "University Faculty/Student Ratio Rank: " << print->fsrRank << endl;
						cout << "University Citations Per Faculty Score: " << print->cpfScore << endl;
						cout << "University Citations Per Faculty Rank: " << print->cpfRank << endl;
						cout << "University International Faculty Ratio Score: " << print->ifrScore << endl;
						cout << "University International Faculty Ratio Rank: " << print->ifrRank << endl;
						cout << "University International Student Ratio Score: " << print->isrScore << endl;
						cout << "University International Student Ratio Rank: " << print->isrRank << endl;
						cout << "University International Research Network Score: " << print->irnScore << endl;
						cout << "University International Research Network Rank: " << print->irnRank << endl;
						cout << "University Employement Outcome Score: " << print->gerScore << endl;
						cout << "University Employement Outcome Rank: " << print->gerRank << endl;
						cout << "University Score Scaled: " << print->scoreScaled << endl << endl;

						break;
					}
				}
				else if (inputNumber == 7) {
					if ((searchRankResult + 1 + numberLeft) == (print->isrRank)) {

						cout << "University Rank: " << print->id << endl;
						cout << "University Name: " << print->universityName << endl;
						cout << "University Location Code: " << print->locationCode << endl;
						cout << "University Location: " << print->location << endl;
						cout << "University Academic Reputation Score: " << print->arScore << endl;
						cout << "University Academic Reputation Rank: " << print->arRank << endl;
						cout << "University Employer Reputation Score: " << print->erScore << endl;
						cout << "University Employer Reputation Rank: " << print->erRank << endl;
						cout << "Univetsity Faculty/Student Ratio Score: " << print->fsrScore << endl;
						cout << "University Faculty/Student Ratio Rank: " << print->fsrRank << endl;
						cout << "University Citations Per Faculty Score: " << print->cpfScore << endl;
						cout << "University Citations Per Faculty Rank: " << print->cpfRank << endl;
						cout << "University International Faculty Ratio Score: " << print->ifrScore << endl;
						cout << "University International Faculty Ratio Rank: " << print->ifrRank << endl;
						cout << "University International Student Ratio Score: " << print->isrScore << endl;
						cout << "University International Student Ratio Rank: " << print->isrRank << endl;
						cout << "University International Research Network Score: " << print->irnScore << endl;
						cout << "University International Research Network Rank: " << print->irnRank << endl;
						cout << "University Employement Outcome Score: " << print->gerScore << endl;
						cout << "University Employement Outcome Rank: " << print->gerRank << endl;
						cout << "University Score Scaled: " << print->scoreScaled << endl << endl;

						break;
					}
				}
				else if (inputNumber == 8) {
					if ((searchRankResult + 1 + numberLeft) == (print->irnRank)) {

						cout << "University Rank: " << print->id << endl;
						cout << "University Name: " << print->universityName << endl;
						cout << "University Location Code: " << print->locationCode << endl;
						cout << "University Location: " << print->location << endl;
						cout << "University Academic Reputation Score: " << print->arScore << endl;
						cout << "University Academic Reputation Rank: " << print->arRank << endl;
						cout << "University Employer Reputation Score: " << print->erScore << endl;
						cout << "University Employer Reputation Rank: " << print->erRank << endl;
						cout << "Univetsity Faculty/Student Ratio Score: " << print->fsrScore << endl;
						cout << "University Faculty/Student Ratio Rank: " << print->fsrRank << endl;
						cout << "University Citations Per Faculty Score: " << print->cpfScore << endl;
						cout << "University Citations Per Faculty Rank: " << print->cpfRank << endl;
						cout << "University International Faculty Ratio Score: " << print->ifrScore << endl;
						cout << "University International Faculty Ratio Rank: " << print->ifrRank << endl;
						cout << "University International Student Ratio Score: " << print->isrScore << endl;
						cout << "University International Student Ratio Rank: " << print->isrRank << endl;
						cout << "University International Research Network Score: " << print->irnScore << endl;
						cout << "University International Research Network Rank: " << print->irnRank << endl;
						cout << "University Employement Outcome Score: " << print->gerScore << endl;
						cout << "University Employement Outcome Rank: " << print->gerRank << endl;
						cout << "University Score Scaled: " << print->scoreScaled << endl << endl;

						break;
					}
				}
				else if (inputNumber == 9) {
					if ((searchRankResult + 1 + numberLeft) == (print->gerRank)) {

						cout << "University Rank: " << print->id << endl;
						cout << "University Name: " << print->universityName << endl;
						cout << "University Location Code: " << print->locationCode << endl;
						cout << "University Location: " << print->location << endl;
						cout << "University Academic Reputation Score: " << print->arScore << endl;
						cout << "University Academic Reputation Rank: " << print->arRank << endl;
						cout << "University Employer Reputation Score: " << print->erScore << endl;
						cout << "University Employer Reputation Rank: " << print->erRank << endl;
						cout << "Univetsity Faculty/Student Ratio Score: " << print->fsrScore << endl;
						cout << "University Faculty/Student Ratio Rank: " << print->fsrRank << endl;
						cout << "University Citations Per Faculty Score: " << print->cpfScore << endl;
						cout << "University Citations Per Faculty Rank: " << print->cpfRank << endl;
						cout << "University International Faculty Ratio Score: " << print->ifrScore << endl;
						cout << "University International Faculty Ratio Rank: " << print->ifrRank << endl;
						cout << "University International Student Ratio Score: " << print->isrScore << endl;
						cout << "University International Student Ratio Rank: " << print->isrRank << endl;
						cout << "University International Research Network Score: " << print->irnScore << endl;
						cout << "University International Research Network Rank: " << print->irnRank << endl;
						cout << "University Employement Outcome Score: " << print->gerScore << endl;
						cout << "University Employement Outcome Rank: " << print->gerRank << endl;
						cout << "University Score Scaled: " << print->scoreScaled << endl << endl;

						break;
					}
				}

				//Score
				else if (inputNumber == 10) {
					if ((searchScoreResult + 1) == (print->arScore)) {

						cout << "University Rank: " << print->id << endl;
						cout << "University Name: " << print->universityName << endl;
						cout << "University Location Code: " << print->locationCode << endl;
						cout << "University Location: " << print->location << endl;
						cout << "University Academic Reputation Score: " << print->arScore << endl;
						cout << "University Academic Reputation Rank: " << print->arRank << endl;
						cout << "University Employer Reputation Score: " << print->erScore << endl;
						cout << "University Employer Reputation Rank: " << print->erRank << endl;
						cout << "Univetsity Faculty/Student Ratio Score: " << print->fsrScore << endl;
						cout << "University Faculty/Student Ratio Rank: " << print->fsrRank << endl;
						cout << "University Citations Per Faculty Score: " << print->cpfScore << endl;
						cout << "University Citations Per Faculty Rank: " << print->cpfRank << endl;
						cout << "University International Faculty Ratio Score: " << print->ifrScore << endl;
						cout << "University International Faculty Ratio Rank: " << print->ifrRank << endl;
						cout << "University International Student Ratio Score: " << print->isrScore << endl;
						cout << "University International Student Ratio Rank: " << print->isrRank << endl;
						cout << "University International Research Network Score: " << print->irnScore << endl;
						cout << "University International Research Network Rank: " << print->irnRank << endl;
						cout << "University Employement Outcome Score: " << print->gerScore << endl;
						cout << "University Employement Outcome Rank: " << print->gerRank << endl;
						cout << "University Score Scaled: " << print->scoreScaled << endl << endl;

						
					}
				}


				//Check for next address
				print = print->NextAddress;
			}
			cout << "University Details Display Ended Here!" << endl;

		}
		else {
			cout << search_rank << " Rank value not found!, Please Try Again!" << endl;
		}
	}



	//Question 2.3 Search University Details Based on Customer Decisions
	void Cus_SearchUniDetails() {
		int enterNumber, search_rank;

		cout << "Please Enter the number of University Details to Search: \n 1. University Rank\n 2. University Academic Reputation Rank\n 3. University Employer Reputation Rank\n 4. University Faculty/Student Ratio Rank\n 5. University Citations Per Faculty Rank\n 6. University International Faculty Ratio Rank\n 7. University International Student Ratio Rank\n 8. University International Research Network Rank\n 9. University Employement Outcome Rank\n 10. University Academic Reputation Score" <<endl;
		
		//User Input of Number
		cout << "Please Select The Number: ";
		cin >> enterNumber;

		switch (enterNumber) {
		//Rank
		case 1:
			searchUniversityRankDetails(1);
			break;
		case 2:
			searchUniversityRankDetails(2);
			break;
		case 3:
			searchUniversityRankDetails(3);
			break;
		case 4:
			searchUniversityRankDetails(4);
			break;
		case 5:
			searchUniversityRankDetails(5);
			break;
		case 6:
			searchUniversityRankDetails(6);
			break;
		case 7:
			searchUniversityRankDetails(7);
			break;
		case 8:
			searchUniversityRankDetails(8);
			break;
		case 9:
			searchUniversityRankDetails(9);
			break;

		//Score
		case 10:
			searchUniversityRankDetails(10);
			break;
		}

	}

};



void testCustomer() {

	UniversityList UniversityFile("2023 QS World University Ranking");


	//CSV file of 2023 QS World University Ranking 
	string tempLine;
	//Start Read CSV file
	ifstream university_file("test.csv");
	getline(university_file, tempLine);
	while (getline(university_file, tempLine)) {
		string id, universityName, locationCode, location, arScore, erScore, fsrScore, cpfScore, ifrScore, isrScore, irnScore, gerScore, scoreScaled, arRank, erRank, fsrRank, cpfRank, ifrRank, isrRank, irnRank, gerRank;

		//Read University Ranking (ID)
		//Will find the comma in which location
		int pos_id = tempLine.find(",");
		//Take the value from 0 to the comma value and assign it to the id
		id = tempLine.substr(0, pos_id);
		//Erase the temporary line for assign the next value
		tempLine.erase(0, pos_id + 1);

		//Read the University Name
		//If the value start with "" (Quotations)
		if (tempLine[0] == '\"')
		{
			//If Name contains a comma
			//Find the comma within the string value
			int pos_name = tempLine.find("\",");
			//Take the value start from the 1 and before that comma(next column)
			universityName = tempLine.substr(1, pos_name - 1);
			tempLine.erase(0, pos_name + 2);
		}
		else
		{
			//If name does not contain a comma
			int pos_name = tempLine.find(",");
			universityName = tempLine.substr(0, pos_name);
			tempLine.erase(0, pos_name + 1);
		}

		//Read the location code
		int pos_locationCode = tempLine.find(",");
		locationCode = tempLine.substr(0, pos_locationCode);
		tempLine.erase(0, pos_locationCode + 1);


		//Read the Location 
		if (tempLine[0] == '\"')
		{
			//If Location contains a comma
			int pos_location = tempLine.find("\",");
			location = tempLine.substr(1, pos_location - 1);
			tempLine.erase(0, pos_location + 2);
		}
		else
		{
			//If Location does not contain a comma
			int pos_location = tempLine.find(",");
			location = tempLine.substr(0, pos_location);
			tempLine.erase(0, pos_location + 1);
		}

		
		int pos_arScore = tempLine.find(",");
		arScore = tempLine.substr(0, pos_arScore);
		tempLine.erase(0, pos_arScore + 1);

		int pos_arRank = tempLine.find(",");
		arRank = tempLine.substr(0, pos_arRank);
		tempLine.erase(0, pos_arRank + 1);

		int pos_erScore = tempLine.find(",");
		erScore = tempLine.substr(0, pos_erScore);
		tempLine.erase(0, pos_erScore + 1);

		int pos_erRank = tempLine.find(",");
		erRank = tempLine.substr(0, pos_erRank);
		tempLine.erase(0, pos_erRank + 1);
		
		int pos_fsrScore = tempLine.find(",");
		fsrScore = tempLine.substr(0, pos_fsrScore);
		tempLine.erase(0, pos_fsrScore + 1);

		int pos_fsrRank = tempLine.find(",");
		fsrRank = tempLine.substr(0, pos_fsrRank);
		tempLine.erase(0, pos_fsrRank + 1);

		int pos_cpfScore = tempLine.find(",");
		cpfScore = tempLine.substr(0, pos_cpfScore);
		tempLine.erase(0, pos_cpfScore + 1);
		
		int pos_cpfRank = tempLine.find(",");
		cpfRank = tempLine.substr(0, pos_cpfRank);
		tempLine.erase(0, pos_cpfRank + 1);

		int pos_ifrScore = tempLine.find(",");
		ifrScore = tempLine.substr(0, pos_ifrScore);
		tempLine.erase(0, pos_ifrScore + 1);

		int pos_ifrRank = tempLine.find(",");
		ifrRank = tempLine.substr(0, pos_ifrRank);
		tempLine.erase(0, pos_ifrRank + 1);

		int pos_isrScore = tempLine.find(",");
		isrScore = tempLine.substr(0, pos_isrScore);
		tempLine.erase(0, pos_isrScore + 1);

		int pos_isrRank = tempLine.find(",");
		isrRank = tempLine.substr(0, pos_isrRank);
		tempLine.erase(0, pos_isrRank + 1);

		int pos_irnScore = tempLine.find(",");
		irnScore = tempLine.substr(0, pos_irnScore);
		tempLine.erase(0, pos_irnScore + 1);

		int pos_irnRank = tempLine.find(",");
		irnRank = tempLine.substr(0, pos_irnRank);
		tempLine.erase(0, pos_irnRank + 1);

		int pos_gerScore = tempLine.find(",");
		gerScore = tempLine.substr(0, pos_gerScore);
		tempLine.erase(0, pos_gerScore + 1);

		int pos_gerRank = tempLine.find(",");
		gerRank = tempLine.substr(0, pos_gerRank);
		tempLine.erase(0, pos_gerRank + 1);

		scoreScaled = tempLine;

	

	//while (university_file.good()) {
	//	getline(university_file, id, ',');
	//	getline(university_file, universityName, ',');
	//	getline(university_file, locationCode, ',');
	//	getline(university_file, location, ',');
	//	getline(university_file, arScore, ',');
	//	getline(university_file, arRank, ',');
	//	getline(university_file, erScore, ',');
	//	getline(university_file, erRank, ',');
	//	getline(university_file, fsrScore, ',');
	//	getline(university_file, fsrRank, ',');
	//	getline(university_file, cpfScore, ',');
	//	getline(university_file, cpfRank, ',');
	//	getline(university_file, ifrScore, ',');
	//	getline(university_file, ifrRank, ',');
	//	getline(university_file, isrScore, ',');
	//	getline(university_file, isrRank, ',');
	//	getline(university_file, irnScore, ',');
	//	getline(university_file, irnRank, ',');
	//	getline(university_file, gerScore, ',');
	//	getline(university_file, gerRank, ',');
	//	getline(university_file, scoreScaled);

		//if the first line is header details, ignore that line
		if (id == "Rank" || universityName == "Institution") {
			continue;
		}
		//if there is no more line
		else if (id == "") {
			break;	
		}

		//Check if there is an empty value for Rank Data, if found replace with -1
		if (arRank.empty() || erRank.empty() || fsrRank.empty() || cpfRank.empty()|| ifrRank.empty() || isrRank.empty() || irnRank.empty() || gerRank.empty()) {
			arRank = "-1";
			erRank = "-1";
			fsrRank = "-1";
			cpfRank = "-1";
			ifrRank = "-1";
			isrRank = "-1";
			irnRank = "-1";
			gerRank = "-1";
		}
		//Check if there is an empty value for Score Data, if found replace with 9999
		if (arScore.empty() || erScore.empty() || fsrScore.empty() || cpfScore.empty() || ifrScore.empty() || isrScore.empty() || irnScore.empty() || gerScore.empty() || scoreScaled.empty()) {
			arScore = "0";
			erScore = "0";
			fsrScore = "0";
			cpfScore = "0";
			ifrScore = "0";
			isrScore = "0";
			irnScore = "0";
			gerScore = "0";
			scoreScaled = "0";
		}

		//If there is a dash in scorescaled
		if (scoreScaled == "-") {
			scoreScaled = "0";
		}

		//Insert From the Back (Customer View)
		UniversityFile.Cus_InsertFromTheEnd(id, universityName, locationCode, location, stod(arScore), stoi(arRank), stod(erScore), stoi(erRank), stod(fsrScore), stoi(fsrRank), stod(cpfScore), stoi(cpfRank), stod(ifrScore), stoi(ifrRank), stod(isrScore), stoi(isrRank), stod(irnScore), stoi(irnRank), stod(gerScore), stoi(gerRank), stod(scoreScaled));

	}

	university_file.close();
	cout << "2023 QS World University Ranking CSV Data Listed As Below " << endl << endl;
	UniversityFile.Cus_DisplayAllDetails();
	cout << endl << string(100, '=') << endl;

	//Execute the search university details function start here
	UniversityFile.Cus_SearchUniDetails();
}