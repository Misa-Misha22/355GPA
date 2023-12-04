#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include <mysql_driver.h>
#include <mysql_connection.h>

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>


using namespace std;
using namespace sql;



int main(){

    sql::Driver *_driver;
    sql::Connection *con;
    sql::PreparedStatement *prep_stmt;
    sql::ResultSet *res;

    string operation;
    cout << "What operation would you like to perform? Create, Update, Read, or Delete?";
    cin >> operation;

    // CREATE or insert
    if (operation == "Create")
    {
        try
        {
            // driver = mysql:get_mysql_driver_instance();
            driver = get_driver_instance();

            // con = driver->connect()
            con = driver->connect("tcp://deltona.birdnest.org:3306", "my.jamesm12", "3tffz5m!1");

            con->setSchema("my_jamesm12_juul");

        prep_stmt = con->prepareStatement("INSERT INTO user_account(email, FirstName, LastName,
        Phone, StreetAddress, City, State, Zip, Salt, Hash ) VALUES (?,?,?,?,?,?,?,?,?,?)");

        string email;
        string firstName;
        string lastName;
        int phone = 0;
        string streetAddress;
        string city;
        string state;
        int zip = 0;
        string salt;
        string hash;

        // auto increment id

        cout << "Enter your email: " << endl;
        cin >> email;
        prep_stmt->setString(1, email);

        cout << "Enter your first name: " << endl;
        cin >> firstName;
        prep_stmt->setString(2, firstName);

        cout << "Enter your last name: " << endl;
        cin >> lastName;
        prep_stmt->setString(3, lastName);

        cout << "Enter your phone number: " << endl;
        cin >> phone;
        prep_stmt->setInt(4, phone);

        cout << "Enter your Street Address: " << endl;
        cin >> streetAddress;
        prep_stmt->setString(5, streetAddress);

        cout << "Enter your city: " << endl;
        cin >> city;
        prep_stmt->setString(6, city);

        cout << "Enter your state: " << endl;
        cin >> state;
        prep_stmt->setString(7, state);

        cout << "Enter your 5 digit zipcode: " << endl;
        cin >> zip;
        prep_stmt->setInt(8, zip);

        salt = "et52ed";
        prep_stmt->setString(9, salt);

        hash = "lvn49sa";
        prep_stmt->setString(10, hash);

        prep_stmt->execute();
        cout << "User Inserted." << endl;

        delete prep_stmt;
        // delete con;
        }
        catch (sql::SQLException &e)
        {
            cout << "SQLException: " << e.what() << endl;
        }
    }

        // READ READ READ READ READ READ READ READ READ READ READ READ READ READ READ READ READ READ READ READ READ

        if (operation == "Read")
        {
            try
            {
                // driver = mysql:get_mysql_driver_instance();
            driver = get_driver_instance();

            // con = driver->connect()
            con = driver->connect("tcp://deltona.birdnest.org:3306", "my.jamesm12", "3tffz5m!1");

            con->setSchema("my_jamesm12_juul");

                prep_stmt = con->prepareStatement("SELECT * FROM user_account WHERE email=?");

                string email;
                cout << "Enter your email to view user information: ";
                cin >> email

                           prep_stmt->setString(1, email);

                cout << "Finding Your Infor Now!: " << endl;

                res = prep_stmt->executeQuery();

                delete res;
                delete prep_stmt;
            }
            catch (sql::SQLException &r)
            {
                cout << "SQLException: " << e.what() << endl;
            }
        }

        // UPDATE UPDATE UPDATE UPDATE UPDATE UPDATE UPDATE UPDATE UPDATE UPDATE UPDATE UPDATE UPDATE UPDATE UPDATE

        if (operation == "Update")
        {
            try
            {

                // driver = mysql:get_mysql_driver_instance();
            driver = get_driver_instance();

            // con = driver->connect()
            con = driver->connect("tcp://deltona.birdnest.org:3306", "my.jamesm12", "3tffz5m!1");

            con->setSchema("my_jamesm12_juul");

                prep_stmt = con->prepareStatement("UPDATE user_account SET FirstName = ?, LastName = ?, Phone =?, StreetAddress = ?, City = ?, State = ?, Zip = ?, Salt = ?, Hash =? WHERE email = ? ");

                string email;
                string firstName;
                string lastName;
                int phone = 0;
                string streetAddress;
                string city;
                string state;
                int zip = 0;
                string salt = "et52ed";
                string hash = "lvn49sa";

                cout << "Please enter the email of the user you want to update: " << endl;
                cin >> email;
                prep_stmt->setString(10, email);

                cout << "Enter new First Name: ";
                cin >> firstName;
                prep_stmt->setString(1, firstName);

                cout << "Enter new Last Name: ";
                cin >> lastName;
                prep_stmt->setString(2, lastName);

                cout << "Enter new Phone Number: ";
                cin >> phone;
                prep_stmt->setInt(3, phone);

                cout << "Enter new Street Address: ";
                cin >> streetAddress;
                prep_stmt->setString(4, streetAddress);

                cout << "Enter new City: ";
                cin >> city;
                prep_stmt->setString(5, city);

                cout << "Enter new State Name: ";
                cin >> state;
                prep_stmt->setString(6, state);

                cout << "Enter new Zip code: ";
                cin >> zip;
                prep_stmt->setInt(7, zip);

                prep_stmt->SetString(8, salt);
                prep_stmt->SetString(9, hash);

                cout << "User updated." << endl;

                prep_stmt->execute();
                delete prep_stmt;
            }
            catch (sql::SQLException &e)
            {
                cout << "SQL Exception" << e.what << endl;
            }
        }

        //DELETE DELETE DELETE DELETE DELETE DELETE DELETE DELETE DELETE DELETE DELETE DELETE DELETE DELETE DELETE 

        if (operation == "Delete")
        {
            try
            {

                // driver = mysql:get_mysql_driver_instance();
            driver = get_driver_instance();

            // con = driver->connect()
            con = driver->connect("tcp://deltona.birdnest.org:3306", "my.jamesm12", "3tffz5m!1");

            con->setSchema("my_jamesm12_juul");

                prep_stmt = con->prepareStatement("DELETE FROM user_account WHERE email = ? ");

                string email;

                cout << "Enter the email of the account you want to delte: ";
                cin >> email;

                prep_stmt->setString(1, email);

                cout << "User Deleted. Sorry it had to end this way :(" << endl;

                prep_stmt->execute();

                delete prep_stmt;
            }
            catch (sql::SQLException &e)
            {
                cout << "SQLException: " << e.what() << endl;
            }
        }

        delete con;
        return EXIT_SUCCESS;
        // return 0;
    }