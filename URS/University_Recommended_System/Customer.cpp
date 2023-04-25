#include <iostream>
#include<fstream>
#include <string>
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
		cout << "Total University Details Are:" << totalUniversityDetails << endl << endl;
	}


	//Binary Search Algorithm
	int BinarySearchAlgorithm(int arrayValue[], int arraySize, int InputSearchValue) {

		//First Value of the array
		int firstValue = 0;
		//Last Value of the array
		int lastValue = arraySize - 1;

		//Algorithm used for the binary search
		while (firstValue < lastValue) {
			//Formula used for finding middle value

			int middleValue = (firstValue + (lastValue - firstValue) / 2);
			middleValue = middleValue + 1;
			

			if (arrayValue[middleValue] == InputSearchValue) {
				return middleValue;
			}
			if (arrayValue[middleValue] < InputSearchValue) {
				firstValue = middleValue + 1;
			}
			else {
				lastValue = middleValue - 1;
			}

		}
		return -1;
	}



	//Question 2.3 Search University Details Based on Customer Decisions
	void Cus_SearchUniDetails() {
		int enterNumber, search_rank;

		cout << "Please Enter the number of University Details to Search: \n 1. Rank\n 2. University Academic Reputation Rank\n 3. University Employer Reputation Rank\n 4. University Faculty/Student Ratio Rank\n 5. University Citations Per Faculty Rank\n 6. University International Faculty Ratio Rank\n 7. University International Student Ratio Rank\n 8. University International Research Network Rank\n 9. University Employement Outcome Rank\n" <<endl;
		
		//User Input of Number
		cout << "Please Select The Number: ";
		cin >> enterNumber;

		switch (enterNumber) {
		case 1:
			UniversityDetails * current = head;

			//Create an empty array for adding the Rank data (dynamic allocate array)
			int* UniRankArray = new int[totalUniversityDetails];

			//Adding value into the array
			for(int i=0; i< totalUniversityDetails; i++){
				//Check the first character is it a integer value, if true add in into the array
				if (isdigit((current->id)[0])) {
					UniRankArray[i] = stoi(current->id);
					current = current->NextAddress;
				}

			}

			//Input to search the rank
			cout << "Enter the value of rank to search. ";
			cin >> search_rank;

			int searchRankResult = BinarySearchAlgorithm(UniRankArray, totalUniversityDetails, search_rank);
			cout << "Value of resech result is: " << searchRankResult << endl;
				if (searchRankResult != -1) {
					//Reason plus one beacase result will reduce 1 in array index
					cout << search_rank << " Rank value found!"<<" located in "<< searchRankResult + 1<<" index." << endl;

					//Print out that university details
					//Display the result of search the rank (binary search)
					UniversityDetails* print = head;
					while (print != NULL) {

						if ((searchRankResult+1) == stoi(print->id)) {
							cout << "University Rank: " << print->id << endl;
							cout << "University Name: " << print->universityName << endl;
							//cout << "University Location Code: " << print->locationCode << endl;
							//cout << "University Location: " << print->location << endl;
							//cout << "University Academic Reputation Score: " << print->arScore << endl;
							//cout << "University Academic Reputation Rank: " << print->arRank << endl;
							//cout << "University Employer Reputation Score: " << print->erScore << endl;
							//cout << "University Employer Reputation Rank: " << print->erRank << endl;
							//cout << "Univetsity Faculty/Student Ratio Score: " << print->fsrScore << endl;
							//cout << "University Faculty/Student Ratio Rank: " << print->fsrRank << endl;
							//cout << "University Citations Per Faculty Score: " << print->cpfScore << endl;
							//cout << "University Citations Per Faculty Rank: " << print->cpfRank << endl;
							//cout << "University International Faculty Ratio Score: " << print->ifrScore << endl;
							//cout << "University International Faculty Ratio Rank: " << print->ifrRank << endl;
							//cout << "University International Student Ratio Score: " << print->isrScore << endl;
							//cout << "University International Student Ratio Rank: " << print->isrRank << endl;
							//cout << "University International Research Network Score: " << print->irnScore << endl;
							//cout << "University International Research Network Rank: " << print->irnRank << endl;
							//cout << "University Employement Outcome Score: " << print->gerScore << endl;
							//cout << "University Employement Outcome Rank: " << print->gerRank << endl;
							//cout << "University Score Scaled: " << print->scoreScaled << endl << endl;

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

	}

};



void testCustomer() {

	UniversityList UniversityFile("2023 QS World University Ranking");

	//CSV file of 2023 QS World University Ranking 
	string id, universityName, locationCode, location, arScore, erScore, fsrScore, cpfScore, ifrScore, isrScore, irnScore, gerScore, scoreScaled, arRank, erRank, fsrRank, cpfRank, ifrRank, isrRank, irnRank, gerRank;

	//Start Read CSV file
	ifstream university_file("test.csv");

	while (university_file.good()) {
		getline(university_file, id, ',');
		getline(university_file, universityName, ',');
		getline(university_file, locationCode, ',');
		getline(university_file, location, ',');
		getline(university_file, arScore, ',');
		getline(university_file, arRank, ',');
		getline(university_file, erScore, ',');
		getline(university_file, erRank, ',');
		getline(university_file, fsrScore, ',');
		getline(university_file, fsrRank, ',');
		getline(university_file, cpfScore, ',');
		getline(university_file, cpfRank, ',');
		getline(university_file, ifrScore, ',');
		getline(university_file, ifrRank, ',');
		getline(university_file, isrScore, ',');
		getline(university_file, isrRank, ',');
		getline(university_file, irnScore, ',');
		getline(university_file, irnRank, ',');
		getline(university_file, gerScore, ',');
		getline(university_file, gerRank, ',');
		getline(university_file, scoreScaled);

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
			arScore = "9999";
			erScore = "9999";
			fsrScore = "9999";
			cpfScore = "9999";
			ifrScore = "9999";
			isrScore = "9999";
			irnScore = "9999";
			gerScore = "9999";
			scoreScaled = "9999";
		}


		//Insert From the Back (Customer View)
		UniversityFile.Cus_InsertFromTheEnd(id, universityName, locationCode, location, stod(arScore), stoi(arRank), stod(erScore), stoi(erRank), stod(fsrScore), stoi(fsrRank), stod(cpfScore), stoi(cpfRank), stod(ifrScore), stoi(ifrRank), stod(isrScore), stoi(isrRank), stod(irnScore), stoi(irnRank), stod(gerScore), stoi(gerRank), stod(scoreScaled));

	}

	university_file.close();
	cout << "2023 QS World University Ranking CSV Data Listed As Below " << endl << endl;
	UniversityFile.Cus_DisplayAllDetails();
	cout << endl << string(100, '=') << endl;


	UniversityFile.Cus_SearchUniDetails();
}