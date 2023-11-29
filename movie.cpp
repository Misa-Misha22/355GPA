
#include <stdlib.h>
#include <iostream>

#include <mysql_connection.h>

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

//#include //the SQL DB

sql::Connection *con;
sql::PreparedStatement *prep_stmt

// function to create a movie
// the database will go into the createMovie function

void insertMovie() {
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
    prep_stmt = con->PreparedStatement("INSERT INTO MOVIE(name, yearReleased, runtime, description) VALUES (?,?,?,?)");
    
    prep_stmt->setString(1, name);
    prep_stmt->setInt(2, yearReleased);
    prep_stmt->setInt(3, runtiime)
    prep_stmt->setString(4, description);

    prep_stmt->execute();

    delete prep_stmt;
    delete con;

}

void updateMovie(){
    
    //create var for user input
    string userinput;

    // prompt user for movie being updated

    cout << "PLEASE ENTER ID:" <<endl;


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

void deleteMovie(){


}

void readMovie(){

    // select from
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