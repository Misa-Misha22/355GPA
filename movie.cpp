
#include <iostream>
using namespace std;
#include //the SQL DB



// function to create a movie
// the database will go into the createMovie function
void createMovie() {
    string name;
    string description;
    int yearReleased;
    int runtime;

    cout << "Enter movie title:";
    cin >> name;
    cin.ignore(); // Ignore newline character from previous input

    cout << "Enter movie year: ";
    cin >> yearReleased;
    cin.ignore(); // Ignore newline character from previous input

    cout << "Enter movie runtime (in minutes): ";
    cin >> runtime;
    cin.ignore(); // Ignore newline character from previous input

    cout << "Enter movie description: ";
    cin >> description;
    cin.ignore(); // Ignore newline character from previous input

}

void updateMovie(){

}




int main()
{

    //create a var for user input
    string userinput;

    // prompt the user for what they want to do
    cout << "What do you want to do:" << endl;
    cout << "Create" << endl;
    cout << "Read" << endl;
    cout << "Update" << endl;
    cout << "Delete" << endl;

    cin >> userinput;

    while (userinput != "Create" || "Read" || "Update" || "Delete") 
    {
        cout << "CASE SENSITIVE PLEASE TYPE OPTION EXACTLY" << endl;

        cout << "What do you want to do:" << endl;
    }


    if (userinput == "Create")
    {

    }


}