//resubmitted
#include <stdlib.h>
#include <iostream>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

using namespace std;

//#include //the SQL DB
sql::Connection *con;
sql::PreparedStatement *prep_stmt;

// function to create a movie
// the database will go into the createMovie function

void insertViewsMovie(sql::Connection *con) {
    string percentComplete;
    string movieID;
    string profileID;

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
try {  
  prep_stmt = con->prepareStatement("INSERT INTO VIEWS_MOVIE (MovieID, ProfileID, PercentComplete) VALUES (?,?,?)");
    
    prep_stmt->setString(1, movieID);
    prep_stmt->setString(2, profileID);
    prep_stmt->setString(3, percentComplete);

    prep_stmt->execute();
}
catch(sql::SQLException &e)
{
	cout << e.what();
}
    delete prep_stmt;
    delete con;

    cout << "All done ᕙ(▀̿ĺ̯▀̿ ̿)ᕗ" << endl;

}

void updateViewsMovie(sql::Connection *con){
    
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


    cout << "PLEASE ENTER MOVIE ID:" <<endl;
    cin  >> movieID;
    cin.ignore();


        cout << "ENTER NEW PERCENT COMPLETE:" << endl;
        cin >> newPercentComplete;
        cin.ignore(); // Ignore newline character from previous input

        // then insert into the table 
        prep_stmt = con->prepareStatement("UPDATE VIEWS_MOVIE SET PercentComplete = ? WHERE ProfileID = ? AND MovieID = ?");
        
        prep_stmt->setString(1, percentComplete);
        prep_stmt->setString(2, profileID);
        prep_stmt->setString(3, movieID);


        prep_stmt->execute();

        cout << "All done ᕙ(▀̿ĺ̯▀̿ ̿)ᕗ" << endl;

        delete prep_stmt;
        delete con;


}

void deleteViewsMovie(sql::Connection *con){

    string userInput;
    string movieID;

    cout << "ENTER ID OF MOVIE PERCENT COMPLETE TO DELETE: " << endl;
    cin >> movieID;
    cin.ignore(); // Ignore newline character from previous input

        // then insert into the table 
        prep_stmt = con->prepareStatement("DELETE FROM VIEWS_MOVIE WHERE MovieID = ?");
        
        prep_stmt->setString(1, movieID);
        
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

void readViewsMovie(sql::Connection *con){

    // select from
    string userInput;
    string movieId;
    string profileId;

    cout << "ENTER MOVIE ID: " << endl;
    cin >> movieId;
    cin.ignore(); // Ignore newline character from previous input

    cout << "ENTER PROFILE ID: " << endl;
    cin >> movieId;
    cin.ignore(); // Ignore newline character from previous input

        // then insert into the table 
        prep_stmt = con->prepareStatement("SELECT * FROM VIEWS_MOVIE WHERE id = ? AND ProfileID = ?");
        
        prep_stmt->setString(1, movieId);
        prep_stmt->setString(2, profileId);
        
        // ResultSet grabs the values that match the id
        // executeQuery() executes the select statement and returns a result
        sql::ResultSet *res = prep_stmt->executeQuery();

        // we need a while loop to check the table for all variables and retreive them
        while (res->next())
        {
            
            cout << "Movie ID: " << res->getString("MovieID") << endl;
            cout << "Profile ID: " << res->getString("ProfileID") << endl;
            cout << "Percent Complete: " << res->getString("PercentComplete") << endl;

        }

        delete res;
        delete prep_stmt;
        delete con;

       
}



int main()
{

//  SQL CONNECTION
    sql::Driver *_driver;
    sql::Connection *con;
    sql::ResultSet *res;

    string user = "my.jamesm12";
    string password = "3tffz5m!1";
    string host = "tcp://deltona.birdnest.org:3306";
    string database = "my_jamesm12_juul";


    try {

        // Standard connection protocol
       // driver = sql::mysql::get_mysql_driver_instance();
        _driver = get_driver_instance();
        con = _driver->connect("tcp://deltona.birdnest.org:3306", "my.jamesm12", "3tffz5m!1");
       // prep_stmt = con->prepareStatement("USE " + database);
        con->setSchema("my_jamesm12_juul");
        // allows user to input data
       // prep_stmt = con->createStatement();

        // prints out if the user is connected
        if (con->isValid()) {
            cout << "Program is connected to SQL Database" << endl;
        } else {
            cout << "System is not connected. Rerun the Code" << endl;
            return 1; // Exit with an error code
        }

        // closes statement
//        delete prep_stmt;

        // closes connection for the server
  //      delete con;
    } catch (sql::SQLException &e) {
        cout << "SQL Exception: " << e.what() << endl;
        return 1; // Exit with an error code
    }

	

    //create a var for user input
    string userInput;


        cout << "CASE SENSITIVE PLEASE TYPE OPTION EXACTLY" << endl;
        cout << "What do you want to do:" << endl;
        cout << "Insert" << endl;
        cout << "Read" << endl;
        cout << "Update" << endl;
        cout << "Delete" << endl;

        // prompt user again
        cin >> userInput; 



    if (userInput == "Insert")
    {
        //call function insertMovie within database 
        insertViewsMovie(con);
        return 0;
    }
    else if (userInput == "Read")
    {
        //call function readmovie within database
        readViewsMovie(con);
        return 0;
    }
    else if (userInput == "Update")
    {
        //call function updatemovie within database
        updateViewsMovie(con);
        return 0;
    }
    else if (userInput == "Delete")
    {
        //call function deleteMovie within database
        deleteViewsMovie(con);
        return 0;
    }

    return EXIT_SUCCESS;
}
