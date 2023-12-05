



#include <stdlib.h>
#include <iostream>
#include <string>
#include <cppconn/prepared_statement.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

sql::Connection *con;

using namespace std;
using namespace sql;
//#include //the SQL DB
sql::PreparedStatement *prep_stmt;


// function to create a movie
// the database will go into the createMovie function

void insertMovie(sql::Connection *con) {
    string name;
    string description;
    int yearReleased;
    int runtime;

    prep_stmt = con->prepareStatement("INSERT INTO MOVIE(name, yearReleased, runtime, description) VALUES (?,?,?,?)");

    cout << "Enter movie title:";
    getline(cin, name);
    prep_stmt->setString(1, name);
    //cin >> name;
    cin.ignore(); // Ignore newline character from previous input

    cout << "Enter movie year: ";
    cin >> yearReleased;
    prep_stmt->setInt(2, yearReleased);
    cin.ignore(); // Ignore newline character from previous input


    cout << "Enter movie runtime (in minutes): ";
    cin >> runtime;
    prep_stmt->setInt(3, runtime);
    cin.ignore(); // Ignore newline character from previous input

    cout << "Enter movie description: ";

    getline(cin, description);
    prep_stmt->setString(4, description);
    //cin >> description;
    cin.ignore(); // Ignore newline character from previous input

    // then insert into the table 
   // prep_stmt = con->prepareStatement("INSERT INTO MOVIE(name, yearReleased, runtime, description) VALUES (?,?,?,?)");
    
    /*prep_stmt->setString(1, name);
    prep_stmt->setInt(2, yearReleased);
    prep_stmt->setInt(3, runtime);
    prep_stmt->setString(4, description);
    */
   
    prep_stmt->execute();

    delete prep_stmt;
    delete con;

    cout << "All done ᕙ(▀̿ĺ̯▀̿ ̿)ᕗ" << endl;

}

void updateMovie(sql::Connection *con){
    
    //create var for user input
    string userInput;
    string newName;
    string newDscrip;
    int movieId;
    int newYear;
    int newRuntime;

    // prompt user for movie being updated
    cout << "PLEASE ENTER ID:" <<endl;
    cin  >> movieId;
    prep_stmt->setInt(2, movieId);
    cin.ignore();

    //do we update each individual? yes i think so 
    cout << "What field do you want to update:" << endl;
    cout << "Name" << endl;
    cout << "Description" << endl;
    cout << "YearReleased" << endl;
    cout << "Runtime" << endl;

    getline(cin, userInput);
    //cin >> userInput;
    //cin.ignore();

    if (userInput == "Name")
    {
        cout << "ENTER NEW MOVIE NAME:" << endl;

        prep_stmt = con->prepareStatement("UPDATE MOVIE SET Name = ? WHERE id = ?");

        getline(cin, newName);
        prep_stmt->setString(1, newName);
        //cin >> newName;
        cin.ignore(); // Ignore newline character from previous input

        // then insert into the table 
       // prep_stmt = con->prepareStatement("UPDATE MOVIE SET Name = ? WHERE id = ?");
        
        /*
        prep_stmt->setString(1, newName);
        prep_stmt->setInt(2, movieId);
        */

        prep_stmt->execute();

        cout << "All done ᕙ(▀̿ĺ̯▀̿ ̿)ᕗ" << endl;

        delete prep_stmt;
        delete con;

    }
    else if (userInput == "Description")
    {
        cout << "ENTER NEW MOVIE DESCRIPTION:" << endl;

        prep_stmt = con->prepareStatement("UPDATE MOVIE SET Description = ? WHERE id = ?");

        getline(cin, newDscrip);
        prep_stmt->setString(1, newDscrip);
        //cin >> newDscrip;
        cin.ignore(); // Ignore newline character from previous input

        // then insert into the table 
       // prep_stmt = con->prepareStatement("UPDATE MOVIE SET Description = ? WHERE id = ?");
        
        /*
        prep_stmt->setString(1, newDscrip);
        prep_stmt->setInt(2, movieId);
        */

        prep_stmt->execute();

        cout << "All done ᕙ(▀̿ĺ̯▀̿ ̿)ᕗ" << endl;

        delete prep_stmt;
        delete con;
    }
    else if (userInput == "YearReleased")
    {
        cout << "ENTER NEW MOVIE YEAR RELEASED:" << endl;

        prep_stmt = con->prepareStatement("UPDATE MOVIE SET YearReleased = ? WHERE id = ?");

        cin >> newYear;
        prep_stmt->setInt(1, newYear);
        cin.ignore(); // Ignore newline character from previous input

        // then insert into the table 
        //prep_stmt = con->prepareStatement("UPDATE MOVIE SET YearReleased = ? WHERE id = ?");
        
        /*
        prep_stmt->setInt(1, newYear);
        prep_stmt->setInt(2, movieId);
        */

        prep_stmt->execute();

        cout << "All done ᕙ(▀̿ĺ̯▀̿ ̿)ᕗ" << endl;

        delete prep_stmt;
        delete con;
    }
    else if (userInput == "Runtime")
    {
        cout << "ENTER NEW MOVIE RUNTIME:" << endl;

        prep_stmt = con->prepareStatement("UPDATE MOVIE SET Runtime = ? WHERE id = ?");

        cin >> newRuntime;
        prep_stmt->setInt(1, newRuntime);
        cin.ignore(); // Ignore newline character from previous input

        // then insert into the table 
       // prep_stmt = con->prepareStatement("UPDATE MOVIE SET Runtime = ? WHERE id = ?");
        
        /*
        prep_stmt->setInt(1, newRuntime);
        prep_stmt->setInt(2, movieId);
        */

        cout << "All done ᕙ(▀̿ĺ̯▀̿ ̿)ᕗ" << endl;

        prep_stmt->execute();

        delete prep_stmt;
        delete con;
    }

}

void deleteMovie(sql::Connection *con){

    string userInput;
    int movieId;

    cout << "ENTER ID OF MOVIE TO DELETE: " << endl;

    prep_stmt = con->prepareStatement("DELETE FROM MOVIE WHERE id = ?");
        

    cin >> movieId;
    prep_stmt->setInt(1, movieId);
    cin.ignore(); // Ignore newline character from previous input

        // then insert into the table 
        //prep_stmt = con->prepareStatement("DELETE FROM MOVIE WHERE id = ?");
        
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

void readMovie(sql::Connection *con){

    // select from
    string userInput;
    int movieId;

    cout << "ENTER MOVIE ID: " << endl;

    prep_stmt = con->prepareStatement("SELECT * FROM MOVIE WHERE id = ?");

    cin >> movieId;
    prep_stmt->setInt(1, movieId);
    cin.ignore(); // Ignore newline character from previous input

        // then insert into the table 
        //prep_stmt = con->prepareStatement("SELECT * FROM MOVIE WHERE id = ?");
        
        //prep_stmt->setInt(1, movieId);
        
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
     _driver = get_driver_instance();
        con = _driver->connect("tcp://deltona.birdnest.org:3306", "my.jamesm12", "3tffz5m!1");
       // prep_stmt = con->prepareStatement("USE " + database);
        con->setSchema("my_jamesm12_juul");


    try {

        // Standard connection protocol
       // driver = sql::mysql::get_mysql_driver_instance();
        //_driver = get_driver_instance();
        //con = _driver->connect("tcp://deltona.birdnest.org:3306", "my.jamesm12", "3tffz5m!1");
       // prep_stmt = con->prepareStatement("USE " + database);
       // con->setSchema("my_jamesm12_juul");
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
        delete prep_stmt;

        // closes connection for the server
        delete con;
    } catch (sql::SQLException &e) {
        cout << "SQL Exception: " << e.what() << endl;
        return 1; // Exit with an error code
    }

    //create a var for user input
    string userInput;

    // prompt the user for what they want to do
    cout << "What do you want to do:" << endl;
    cout << "Insert" << endl;
    cout << "Read" << endl;
    cout << "Update" << endl;
    cout << "Delete" << endl;

    getline(cin, userInput);
    ////cin >> userInput; 

    if (userInput == "Insert")
    {
        //call function insertMovie within database 
        insertMovie(con);
        return 0;
    }
    else if (userInput == "Read")
    {
        //call function readmovie within database
        readMovie(con);
        return 0;
    }
    else if (userInput == "Update")
    {
        //call function updatemovie within database
        updateMovie(con);
        return 0;
    }
    else if (userInput == "Delete")
    {
        //call function deleteMovie within database
        deleteMovie(con);
        return 0;
    }
    else 
    {
        cout << "CASE SENSITIVE PLEASE TYPE OPTION EXACTLY" << endl;
        cout << "What do you want to do:" << endl;
        cout << "Insert" << endl;
        cout << "Read" << endl;
        cout << "Update" << endl;
        cout << "Delete" << endl;

        // prompt user again
        getline(cin, userInput);
        //cin >> userInput; 
    }

    return EXIT_SUCCESS;
}