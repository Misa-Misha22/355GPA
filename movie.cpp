
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

    cout << "All done ᕙ(▀̿ĺ̯▀̿ ̿)ᕗ" << endl;

}

void updateMovie(){
    
    //create var for user input
    string userinput;
    string newName;
    string newDscrip
    string movieId;
    string newYear;
    string newRuntime;
    // prompt user for movie being updated
    cout << "PLEASE ENTER ID:" <<endl;
    cin  >> movieId;
    cin.ignore();

    //do we update each individual? yes i think so 
    cout << "What field do you want to update:" << endl;
    cout << "Name" << endl;
    cout << "Description" << endl;
    cout << "YearReleased" << endl;
    cout << "Runtime" << endl;

    cin >> userinput;
    cin.ignore();

    if (userinput == "Name")
    {
        cout << "ENTER NEW MOVIE NAME:" << endl;
        cin >> newName;
        cin.ignore(); // Ignore newline character from previous input

        // then insert into the table 
        prep_stmt = con->PreparedStatement("UPDATE MOVIE SET Name = ? WHERE id = ?");
        
        prep_stmt->setString(1, newName);
        prep_stmt->setString(2, movieId);

        prep_stmt->execute();

        cout << "All done ᕙ(▀̿ĺ̯▀̿ ̿)ᕗ" << endl;

        delete prep_stmt;
        delete con;

    }
    else if (userinput == "Description")
    {
        cout << "ENTER NEW MOVIE DESCRIPTION:" << endl;
        cin >> newDscrip;
        cin.ignore(); // Ignore newline character from previous input

        // then insert into the table 
        prep_stmt = con->PreparedStatement("UPDATE MOVIE SET Description = ? WHERE id = ?");
        
        prep_stmt->setString(1, newDscrip);
        prep_stmt->setString(2, movieId);

        prep_stmt->execute();

        cout << "All done ᕙ(▀̿ĺ̯▀̿ ̿)ᕗ" << endl;

        delete prep_stmt;
        delete con;
    }
    else if (userinput == "YearReleased")
    {
        cout << "ENTER NEW MOVIE YEAR RELEASED:" << endl;
        cin >> newYear
        cin.ignore(); // Ignore newline character from previous input

        // then insert into the table 
        prep_stmt = con->PreparedStatement("UPDATE MOVIE SET YearReleased = ? WHERE id = ?");
        
        prep_stmt->setString(1, newYear);
        prep_stmt->setString(2, movieId);

        prep_stmt->execute();

        cout << "All done ᕙ(▀̿ĺ̯▀̿ ̿)ᕗ" << endl;

        delete prep_stmt;
        delete con;
    }
    else if (userinput == "Runtime")
    {
        cout << "ENTER NEW MOVIE RUNTIME:" << endl;
        cin >> newRuntime;;
        cin.ignore(); // Ignore newline character from previous input

        // then insert into the table 
        prep_stmt = con->PreparedStatement("UPDATE MOVIE SET Runtime = ? WHERE id = ?");
        
        prep_stmt->setString(1, newRuntime;);
        prep_stmt->setString(2, movieId);

        cout << "All done ᕙ(▀̿ĺ̯▀̿ ̿)ᕗ" << endl;

        prep_stmt->execute();

        delete prep_stmt;
        delete con;
    }

}

void deleteMovie(){

    string userInput;
    string movieId;

    cout << "ENTER ID OF MOVIE TO DELETE: " << endl;
    cin >> movieId;
    cin.ignore(); // Ignore newline character from previous input

        // then insert into the table 
        prep_stmt = con->PreparedStatement("DELETE FROM Customers WHERE id = ?");
        
        prep_stmt->setString(1, movieId);
        
        int rowsDeleted = prep_stmt->executeUpdate();

        if (rowsDeleted > 0) {
            cout << "All done ᕙ(▀̿ĺ̯▀̿ ̿)ᕗ" << endl;
        }
        else {
            cout << "No files deleted (ↁ_ↁ)" << endl;
        }

        // are we deleting one by one? or row by row?

        delete prep_stmt;
        delete con;
    

}

void readMovie(){

    // select from
    string userInput;
    string movieId;

    cout << "ENTER MOVIE ID: " << endl;
    cin >> movieId;
    cin.ignore(); // Ignore newline character from previous input

        // then insert into the table 
        prep_stmt = con->PreparedStatement("SELECT * FROM MOVIE WHERE id = ?");
        
        prep_stmt->setString(1, movieId);
        
        // ResultSet grabs the values that match the id
        // executeQuery() executes the select statement and returns a result
        sql::ResultSet *res = prep_stmt->executeQuery();

        // we need a while loop to check the table for all variables and retreive them
        while (res->next())
        {
            
            cout << "ID: " << res->getInt("id") << endl;
            cout << "Name: " << res->getString("Name") << endl;
            cout << "Year Released: " << res->getInt("YearReleased") << endl;
            cout << "Runtime: " << res->getInt("Runtime") << endl;
            cout << "Description: " << res->getString("Description") << endl;

        }

        delete res;
        delete pstmt;
        delete con;

        return 0;
}



int main()
{

    //create a var for user input
    string userInput;

    // prompt the user for what they want to do
    cout << "What do you want to do:" << endl;
    cout << "Insert" << endl;
    cout << "Read" << endl;
    cout << "Update" << endl;
    cout << "Delete" << endl;

    cin >> userinput;

    while ((userInput != "Insert") || (userInput != "Read") || (userInput != "Update") || (userInput != "Delete"))
    {
        cout << "CASE SENSITIVE PLEASE TYPE OPTION EXACTLY" << endl;
        cout << "What do you want to do:" << endl;
        cout << "Insert" << endl;
        cout << "Read" << endl;
        cout << "Update" << endl;
        cout << "Delete" << endl;

        // prompt user again
        cin >> userInput; 
    }


    if (userinput == "Insert")
    {
        //call function insertMovie within database 
        insertMovie()
    }


}