/*
Victor Semenok MW 8-9 AM
Chapter 6 User Defined Functions required project
Display information such as student average grades, overall average grades,
the top student and their score, average grades for teachers and subjects,  and the hardest teacher. 
*/

#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>

using namespace std;


void studentGrade(); //calculates grades, averages, and finds top student
//void topStudent(string name, double score); // displays top student and accolades

int main(){
	cout << showpoint << setprecision(2) << fixed;

	studentGrade();


	system("Pause");
return 0;
}

void studentGrade() {
	
	ifstream scoreFile;
	scoreFile.open("Q1StudentScores.txt");
	
	string topStudent = "Victor Semenok"; //stores the top students name
	double topScore = 0; //stores top students score

	string student;
	double score;
	double avgScore;
	char grade;

	while (!scoreFile.eof()) {
		scoreFile >> student;
		if (scoreFile.eof()) break; //breaks before outputting the EOF after line 20
		cout << setw(15) << left << student;
		int counter = 0;
		double total = 0;
		do {

			scoreFile >> score;
			if (score != -99) {
				counter++;
				total += score;
			}
			else {
				avgScore = total / counter;

				if (avgScore >= 90.00) {
					grade = 'A';
				}
				else if(avgScore >= 80.00) {
					grade = 'B';
				}
				else if (avgScore >= 70.00) {
					grade = 'C';
				}
				else if (avgScore >= 60.00) {
					grade = 'D';
				}
				else{
					grade = 'F';
				}

				if (avgScore > topScore) {
					topScore = avgScore;
					topStudent = student;
				}

				cout << setw(6) << avgScore << grade << endl;
			}
		} while (score != -99);
	}
}
