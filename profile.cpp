//resubmitted
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string> 

#include <mysql_driver.h>
#include <mysql_connection.h>

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>


sql::Driver *_driver;
sql::Connection *con;
sql::PreparedStatement *prep_stmt;
sql::ResultSet *res;

using namespace std;
using namespace sql;

void insertProfile() 
{
    string name;
    int acctID;

    cout << "Enter profile Name";
    cin >> name;
    cin.ignore();

    cout << "Enter acctID: ";
    cin >> acctID;
    cin.ignore(); 

    // then insert into the table 
    try
        {
            // driver = mysql:get_mysql_driver_instance();
            _driver = get_driver_instance();

            // con = driver->connect()
            con = _driver->connect("tcp://deltona.birdnest.org:3306", "my.jamesm12", "3tffz5m!1");

            con->setSchema("my_jamesm12_juul");
        prep_stmt = con->prepareStatement("INSERT INTO profile(Name, AcctID) VALUES (?,?)");
            
        prep_stmt->setString(1, name);
        prep_stmt->setInt(2, acctID);

        prep_stmt->execute();

        delete prep_stmt;
        //delete con;
        }
        catch (sql::SQLException &e)
        {
            cout << "SQLException: " << e.what() << endl;
        }
    cout << "Program has executed." << endl;

}

void updateProfile()
{
    
    //create var for user input
    string userInput;
    string newName;
    int profileId;
    int acctID;

    // prompt user for id being updated
    cout << "PLEASE ENTER ID: " <<endl;
    cin  >> profileId;
    cin.ignore();

    //do we update each individual? yes i think so 
    cout << "What field do you want to update:" << endl;
    cout << "Name" << endl;
    cout << "AcctID" << endl;

    cin >> userInput;
    cin.ignore();

    if (userInput == "Name")
    {
        cout << "ENTER NEW NAME: " << endl;
        cin >> newName;
        cin.ignore();

        try
        {
            // driver = mysql:get_mysql_driver_instance();
            _driver = get_driver_instance();

            // con = driver->connect()
            con = _driver->connect("tcp://deltona.birdnest.org:3306", "my.jamesm12", "3tffz5m!1");

            con->setSchema("my_jamesm12_juul");
        // then insert into the table 
        prep_stmt = con->prepareStatement("UPDATE profile SET Name = ? WHERE id = ?");
        
        prep_stmt->setString(1, newName);
        prep_stmt->setInt(2, profileId);

        prep_stmt->execute();

        cout << "Program has executed." << endl;

        delete prep_stmt;
        //delete con;
        }
        catch (sql::SQLException &e)
        {
            cout << "SQLException: " << e.what() << endl;
        }
    }
    else if (userInput == "AcctID")
    {
        cout << "ENTER NEW AcctID that exists in the USER_ACCOUNT Table under ID: " << endl;
        cin >> acctID;
        cin.ignore(); // Ignore newline character from previous input

        try
        {
            // driver = mysql:get_mysql_driver_instance();
            _driver = get_driver_instance();

            // con = driver->connect()
            con = _driver->connect("tcp://deltona.birdnest.org:3306", "my.jamesm12", "3tffz5m!1");

            con->setSchema("my_jamesm12_juul");
        prep_stmt = con->prepareStatement("UPDATE profile SET AcctID = ? FROM Profile INNER JOIN user_account on Profile.AcctID = user_account.id AND Profile.id = ?");
        
        prep_stmt->setInt(1, acctID);
        prep_stmt->setInt(2, profileId);

        prep_stmt->execute();

        cout << "Program has executed." << endl;

        delete prep_stmt;
        //delete con;
        }
        catch (sql::SQLException &e)
        {
            cout << "SQLException: " << e.what() << endl;
        }
    }

}

void deleteProfile()
{

    string userInput;
    int profileID;

    cout << "ENTER THE PROFILE ID TO DELETE: " << endl;
    cin >> profileID;

    cin.ignore();

    try
    {
        // driver = mysql:get_mysql_driver_instance();
        _driver = get_driver_instance();

        // con = driver->connect()
        con = _driver->connect("tcp://deltona.birdnest.org:3306", "my.jamesm12", "3tffz5m!1");

        con->setSchema("my_jamesm12_juul");
    prep_stmt = con->prepareStatement("DELETE FROM profile WHERE id = ?");
    prep_stmt->setInt(1, profileID);
    
    int rowsDeleted = prep_stmt->executeUpdate();

    if (rowsDeleted > 0) 
    {
        cout << "Program has executed." << endl;
    }
    else 
    {
        cout << "No files deleted (ↁ_ↁ)" << endl;
    }

    delete prep_stmt;
    //delete con;
        }
    catch (sql::SQLException &e)
    {
        cout << "SQLException: " << e.what() << endl;
    }
}

void readProfile()
{

    // select from
    string userInput;
    int profileID;

    cout << "ENTER THE PROFILE ID: " << endl;
    cin >> profileID;
    cin.ignore(); // Ignore newline character from previous input

    try
    {
        // driver = mysql:get_mysql_driver_instance();
        _driver = get_driver_instance();

        // con = driver->connect()
        con = _driver->connect("tcp://deltona.birdnest.org:3306", "my.jamesm12", "3tffz5m!1");

        con->setSchema("my_jamesm12_juul");
    prep_stmt = con->prepareStatement("SELECT * FROM profile WHERE id = ?");
    
    prep_stmt->setInt(1, profileID);
    
    // ResultSet grabs the values that match the id
    // executeQuery() executes the select statement and returns a result
    sql::ResultSet *res = prep_stmt->executeQuery();

    // we need a while loop to check the table for all variables and retreive them
    while (res->next())
    {
        cout << "ID: " << res->getInt("id") << endl;
        cout << "Name: " << res->getString("Name") << endl;
        cout << "AcctID: " << res->getInt("AcctID") << endl;

    }

    delete res;
    delete prep_stmt;
    //delete con;
    }
    catch (sql::SQLException &r)
    {
        //cout << "SQLException: " << e.what() << endl;
        cout << "Possible Error.";
    }
}



int main()
{
    string userInput;

    // prompt the user for what they want to do
    cout << "What do you want to do:" << endl;
    cout << "Insert" << endl;
    cout << "Read" << endl;
    cout << "Update" << endl;
    cout << "Delete" << endl;

    cout << endl;
    cin >> userInput;

    /*
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
    */

    if (userInput == "Insert")
    {
        insertProfile();
        return 0;
    }
    else if (userInput == "Read")
    {
        readProfile();
        return 0;
    }
    else if (userInput == "Update")
    {
        updateProfile();
        return 0;
    }
    else if (userInput == "Delete")
    {
        deleteProfile();
        return 0;
    }

    return 0;
}