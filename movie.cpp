
#include <iostream>
using namespace std;
//#include //the SQL DB



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

    // then insert into the table 

    string insertStatementSQL = "INSERT INTO movie(name, yearReleased, runtime, description) VALUES (" + name + ", ", + yearReleased + ", " + runtime + "," + description + ");";

    
}

void updateMovie(){
    
    //create var for user input
    string userinput;

    //do we update each individual? yes i think so 
    cout << "What do you want to update:" << endl;
    cout << "Name" << endl;
    cout << "Description" << endl;
    cout << "yearReleased" << endl;
    cout << "runtime" << endl;

    cin >> userinput;

    if (userinput == "Name")
    {

    }
    else if (userinput == "Description")
    {

    }
    else if (userinput == "yearReleased")
    {

    }
    else if (userinput == "runtime")
    {

    }

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
        //call function createMovie within database 
        createMovie()
    }


}