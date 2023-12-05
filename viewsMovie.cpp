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
sql::PreparedStatement *prep_stmt;

// function to create a movie
// the database will go into the createMovie function

void insertViewsMovie() {
    int percentComplete;
    int movieID;
    int profileID;

    cout << "Enter movie ID: ";
    cin >> movieID;
    cin.ignore(); // Ignore newline character from previous input

    cout << "Enter profile ID: ";
    cin >> profileID;
    cin.ignore(); // Ignore newline character from previous input

    cout << "Enter percent complete: ";
    cin >> percentComplete;
    cin.ignore(); // Ignore newline character from previous input

    // then insert into the table 
    prep_stmt = con->PreparedStatement("INSERT INTO VIEWS_MOVIE(MovieID, ProfileID, PercentComplete) VALUES (?,?,?)");
    
    prep_stmt->setInt(1, movieID);
    prep_stmt->setInt(2, profileID);
    prep_stmt->setString(3, percentComplete);

    prep_stmt->execute();

    delete prep_stmt;
    delete con;

    cout << "All done ᕙ(▀̿ĺ̯▀̿ ̿)ᕗ" << endl;

}

void updateViewsMovie(){
    
    //create var for user input

    string movieID;
    string profileID;
    string percentComplete;
    string newMovieID;
    string newProfileID;
    string newPercentComplete;

    // prompt user for movie being updated
    cout << "PLEASE ENTER PROFILE ID:" <<endl;
    cin  >> profileID;
    cin.ignore();

    //do we update each individual? yes i think so 
    cout << "What field do you want to update:" << endl;
    cout << "Movie ID" << endl;
    cout << "Profile ID" << endl;
    cout << "Percent complete" << endl;

    cin >> userInput;
    cin.ignore();

    if (userInput == "Movie ID")
    {
        cout << "ENTER NEW MOVIE ID:" << endl;
        cin >> newMovieID;
        cin.ignore(); // Ignore newline character from previous input

        // then insert into the table 
        prep_stmt = con->PreparedStatement("UPDATE VIEWS_MOVIE SET MovieID = ? WHERE id = ?");
        
        prep_stmt->setString(1, newMovieID);
        prep_stmt->setString(2, movieID);

        prep_stmt->execute();

        cout << "All done ᕙ(▀̿ĺ̯▀̿ ̿)ᕗ" << endl;

        delete prep_stmt;
        delete con;

    }
    else if (userInput == "Profile ID")
    {
        cout << "ENTER NEW PROFILE ID:" << endl;
        cin >> newProfileID;
        cin.ignore(); // Ignore newline character from previous input

        // then insert into the table 
        prep_stmt = con->PreparedStatement("UPDATE VIEWS_MOVIE SET ProfileID = ? WHERE id = ?");
        
        prep_stmt->setString(1, newProfileID);
        prep_stmt->setString(2, movieID);

        prep_stmt->execute();

        cout << "All done ᕙ(▀̿ĺ̯▀̿ ̿)ᕗ" << endl;

        delete prep_stmt;
        delete con;
    }
    else if (userInput == "Percent complete")
    {
        cout << "ENTER NEW PERCENT COMPLETE:" << endl;
        cin >> newPercentComplete;
        cin.ignore(); // Ignore newline character from previous input

        // then insert into the table 
        prep_stmt = con->PreparedStatement("UPDATE VIEWS_MOVIE SET PercentComplete = ? WHERE id = ?");
        
        prep_stmt->setString(1, newPercentComplete);
        prep_stmt->setString(2, movieID);

        prep_stmt->execute();

        cout << "All done ᕙ(▀̿ĺ̯▀̿ ̿)ᕗ" << endl;

        delete prep_stmt;
        delete con;
    }

}

void deleteViewsMovie(){

    string userInput;
    string movieID;

    cout << "ENTER ID OF MOVIE TO DELETE: " << endl;
    cin >> movieID;
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

void readViewsMovie(){

    // select from
    string userInput;
    string movieId;

    cout << "ENTER MOVIE ID: " << endl;
    cin >> movieId;
    cin.ignore(); // Ignore newline character from previous input

        // then insert into the table 
        prep_stmt = con->PreparedStatement("SELECT * FROM VIEWS_MOVIE WHERE id = ?");
        
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
        delete prep_stmt;
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

    cin >> userInput;

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


    if (userInput == "Insert")
    {
        //call function insertMovie within database 
        insertViewsMovie();
        return 0;
    }
    else if (userInput == "Read")
    {
        //call function readmovie within database
        readViewsMovie();
        return 0;
    }
    else if (userInput == "Update")
    {
        //call function updatemovie within database
        updateViewsMovie();
        return 0;
    }
    else if (userInput == "Delete")
    {
        //call function deleteMovie within database
        deleteViewsMovie();
        return 0;
    }

    return 0;
}