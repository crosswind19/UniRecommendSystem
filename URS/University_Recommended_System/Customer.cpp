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
	/*int arRank;
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
	double scoreScaled;*/
	//Pointer
	UniversityDetails* NextAddress;

}*head;

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

	//, int arRank, double erScore, int erRank, double fsrScore, int fsrRank, double cpfScore, int cpfRank, double ifrScore, int ifrRank, double isrScore, int isrRank, double irnScore, int irnRank, double gerScore, int gerRank, double scoreScaled
	UniversityDetails* createNewNode(string id, string universityName, string locationCode, string location, double arScore) {

		//Create a new node for university details
		UniversityDetails* newnode = new UniversityDetails;

		//Fill up all the data
		newnode->id = id;
		newnode->universityName = universityName;
		newnode->locationCode = locationCode;
		newnode->location = location;
		newnode->arScore = arScore;
	/*	newnode->arRank = arRank;
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
		newnode->scoreScaled = scoreScaled;*/
		newnode->NextAddress = NULL;

		//return the newnode address
		return newnode;

	}

	//Insert from the back taken from the csv file
		//, int arRank, double erScore, int erRank, double fsrScore, int fsrRank, double cpfScore, int cpfRank, double ifrScore, int ifrRank, double isrScore, int isrRank, double irnScore, int irnRank, double gerScore, int gerRank, double scoreScaled
	void Cus_InsertFromTheEnd(string id, string universityName, string locationCode, string location, double arScore) {


		//, arRank, erScore, erRank, fsrScore, fsrRank, cpfScore, cpfRank, ifrScore, ifrRank, isrScore, isrRank, irnScore, irnRank, gerScore, gerRank, scoreScaled
		UniversityDetails* newnode = createNewNode(id, universityName, locationCode, location, arScore);

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
			/*cout << "University Academic Reputation Rank: " << current->arRank << endl;
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
			cout << "University Employement Outcome: " << current->gerScore << endl;
			cout << "University Employement Outcome: " << current->gerRank << endl;
			cout << "University Score Scaled: " << current->scoreScaled << endl<<endl;*/
		
			current = current->NextAddress;
		}
		cout << "University Details Display Ended Here!" << endl << endl;
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
		getline(university_file, arScore);
		/*getline(university_file, arRank, ',');
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
		getline(university_file, scoreScaled);*/

		if (id == "Rank" || universityName == "Institution") {
			
			continue;
		}
		else if (id == "") {
			break;
		}

		//Insert From the Back (Customer View)
			//, stod(arScore), stoi(arRank), stod(erScore), stoi(erRank), stod(fsrScore), stoi(fsrRank), stod(cpfScore), stoi(cpfRank), stod(ifrScore), stoi(ifrRank), stod(isrScore), stoi(isrRank), stod(irnScore), stoi(irnRank), stod(gerScore), stoi(gerRank), stod(scoreScaled)
		UniversityFile.Cus_InsertFromTheEnd(id, universityName, locationCode, location, stod(arScore));

	}

	university_file.close();
	cout << "2023 QS World University Ranking CSV Data Listed As Below " << endl << endl;
	UniversityFile.Cus_DisplayAllDetails();
	cout << endl << string(100, '=') << endl;


}