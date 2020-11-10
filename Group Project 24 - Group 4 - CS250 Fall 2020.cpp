// GROUP 4 - GROUP PROJECT 24


#include <iostream>
#include <iomanip>
#include <locale>

using namespace std;

// Vu Tuan Son
// Return number of traveled day
int get_day();
// Return hour and minute when the trip starts
void get_time_begin(string&, string&);
// Return hour and minute when the trip ends
void get_time_end(string&, string&);
// TRUE if input in string is bool
bool is_two_digit(string);
// TRUE if input is in 24 hours format
bool is_hour(string);
bool is_minute(string);
// Convert input in string to number
int str_to_int(string);
double str_to_double(string);
// Return cost for input
double get_cost_of(string);
// Return cost of private vehicle = miles driven * cost/mile
double private_vehicle();
// Return cost of conference/seminar registration
double conference();
// TRUE if input is number
bool is_number(string);
// Return number of allowable meals
void number_of_allowable_meals(int, int, int,
                    int&, int&, int&);
// Return meal expenses
void meal_expense(double&, double&, double&);

// -------------------------------------------------------------
// Mai Quang Dao
//get parking fees
double get_parking_fees();
//get taxi fees
double get_taxi_fees();
//get hotel expenses
double get_hotel_expenses();
//get meals expenses


// Vu Tuan Son 1575302
// Main function
int main()
{
    /**
        The reason to declare these values in string is
        that it is easier to check user input validation
        and it is easier to edit.
        Some value that will be used in other function in
        number format will be converted to integer or double
    */
    string  hour_begin_str,
            minute_begin,
            hour_end_str,
            minute_end;
    
    int day,
        hour_begin_int,
        hour_end_int,
        num_breakfast,
        num_lunch,
        num_dinner;

    double  airfair_cost,
            car_rental_cost,
            private_vehicle_cost,
            conference_cost,
            parking_fee, allow_parking_fee,
            taxi_fee, allow_taxi_fee,
            hotel_expense, allow_hotel,
            total,
            saving,
            meal_cost, allow_meal,
            breakfast_cost,
            lunch_cost,
            dinner_cost;

    // Get value for all variables
    day = get_day();
    get_time_begin(hour_begin_str, minute_begin);
    get_time_end(hour_end_str, minute_end);

    // Convert hour to int to use in the following function
    hour_begin_int = str_to_int(hour_begin_str);
    hour_end_int = str_to_int(hour_end_str);
    number_of_allowable_meals(day, hour_begin_int, hour_end_int,
                                num_breakfast, num_lunch, num_dinner);

    // Get costs
    airfair_cost = get_cost_of("Did you travel by plane?");
    car_rental_cost = get_cost_of("Did you rent any car?");
    private_vehicle_cost = private_vehicle();
    conference_cost = conference();
    parking_fee = get_parking_fees();
    taxi_fee = get_taxi_fees();
    hotel_expense = get_hotel_expenses();
    meal_expense(breakfast_cost, lunch_cost, dinner_cost);
    
    // Calculate total cost
    meal_cost = breakfast_cost + lunch_cost + dinner_cost;
    total = airfair_cost + car_rental_cost + private_vehicle_cost
            + parking_fee + taxi_fee + hotel_expense + conference_cost
            + breakfast_cost + lunch_cost + dinner_cost;
    
    
    
    // Calculate allowable fees and saving
    allow_meal = num_breakfast * 9 + num_lunch * 12 + num_dinner * 16;
    allow_parking_fee = day * 6;
    allow_taxi_fee = day * 10;
    allow_hotel = day * 90;

    saving = (allow_parking_fee + allow_taxi_fee + allow_hotel + allow_meal)
            -(parking_fee + taxi_fee + hotel_expense + meal_cost);

    


    // Print out all transactions
    int width = 35;
    cout << fixed << setprecision(2);
    cout << "\n--------------------------------------------" << endl
         << "------------ F I N A L  I N F O ------------" << endl
         << "--------------------------------------------" << endl
         << setw(width) << left << "Number of days traveled: "  << day << endl
         << setw(width) << "Time arrived (24h): "               << hour_begin_str << ":" << minute_begin << endl
         << setw(width) << "Time came home (24h): "             << hour_end_str   << ":" << minute_end << endl
         << setw(width) << "Round-trip airfair: "               << "$" << airfair_cost          << endl
         << setw(width) << "Car rental: "                       << "$" << car_rental_cost       << endl
         << setw(width) << "Private vehicle: "                  << "$" << private_vehicle_cost  << endl
         << setw(width) << "Parking: "                          << "$" << parking_fee           << endl
         << setw(width) << "Taxi: "                             << "$" << taxi_fee              << endl
         << setw(width) << "Hotel: "                            << "$" << hotel_expense         << endl
         << setw(width) << "Conference/seminar registration: "  << "$" << conference_cost       << endl
         << setw(width) << "Breakfast: "                        << "$" << breakfast_cost        << endl
         << setw(width) << "Lunch: "                            << "$" << lunch_cost            << endl
         << setw(width) << "Dinner: "                           << "$" << dinner_cost           << endl
         << setw(width) << "Total spending: "                   << "$" << total                 << endl
         << setw(width) << "Total allowable cost: "             << "$" << allow_parking_fee
                                                                        + allow_taxi_fee
                                                                        + allow_hotel
                                                                        + allow_meal            << endl;
    if (saving >= 0)
    {
        cout << setw(width) << "You saved total:" << "$" << saving << endl;
    }
    else
    {
        cout << setw(width) << "Your spending exceeds total:" << "$" << 0 - saving << endl;
    }
    
    cout << "\nThank you!" << endl;
    cout << "Press enter to exit...";
    cin.ignore();
    cin.get();
    return 0;
}


// Vu Tuan Son 1575302
// Get number of day
int get_day()
{
    string day;
    bool exit = false;
    cout << "Enter number of days spent on the trip" << endl;
    while (!exit)
    {
        bool invalid = false;
        cout << "Numer of days: ";
        cin >> day;
        for (int i = 0; i < day.size(); i++)
        {
            if ( !isdigit(day[i]) )
            {
                cout << "Input invalid!" << endl;
                invalid = true;
                break;
            }
            
        }
        if (!invalid)
        {
            exit = true;
        }
    
    }
    int output = str_to_int(day);
    return output;
}


// Vu Tuan Son 1575302
// Get time begin of the trip
void get_time_begin(string &hour_begin, string &minute_begin)
{
    cout << "\nThe time of departure on the first day of the trip" << endl
         << "(in 24 hours format)" << endl;
    while (true)
    {
        cout << "Hour: ";
        cin >> hour_begin;
        if (is_hour(hour_begin))
        {
            break;
        }
        else
        {
            cout << "Input invalid!" << endl;
        }
        
    }
    while (true)
    {
        cout << "Minute: ";
        cin >> minute_begin;
        if (is_minute(minute_begin))
        {
            break;
        }
        else
        {
            cout << "Input invalid!" << endl;
        }
        
    }
    
    // Fill a zero before time if user input has only 1 character
    if (hour_begin.size() < 2)
    {
        hour_begin = "0" + hour_begin;
    }
    if (minute_begin.size() < 2)
    {
        minute_begin = "0" + minute_begin;
    }

}


// Vu Tuan Son 1575302
// Get time when the trip end
void get_time_end(string &hour_end, string &minute_end)
{
    cout << "\nThe time of arrival back home on the last day of the trip" << endl
         << "(in 24 hours format)" << endl;
    while (true)
    {
        cout << "Hour: ";
        cin >> hour_end;
        if (is_hour(hour_end))
        {
            break;
        }
        else
        {
            cout << "Input invalid!" << endl;
        }
        
    }
    while (true)
    {
        cout << "Minute: ";
        cin >> minute_end;
        if (is_minute(minute_end))
        {
            break;
        }
        else
        {
            cout << "Input invalid!" << endl;
        }
        
    }

    // Fill a zero before time if user input has only 1 character
    if (hour_end.size() < 2)
    {
        hour_end = "0" + hour_end;
    }
    if (minute_end.size() < 2)
    {
        minute_end = "0" + minute_end;
    }

}


// Vu Tuan Son 1575302
// Return FALSE if input is not number
bool is_two_digit(string input)
{
    if (input.size() > 2)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < input.size(); i++)
        {
            if ( !isdigit(input[i]) )
            {
                return false;
            }
            
        }
        
    }
    return true;
    
}


// Vu Tuan Son 1575302
// Return FALSE if hour exceeds 24
bool is_hour(string input)
{
    if (is_two_digit(input))
    {
        if (str_to_int(input) < 24 && str_to_int(input) >= 0)
        {
            return true;
        }
        
    }
    return false;
}


// Vu Tuan Son 1575302
// Return FALSE if minute exceeds 60
bool is_minute(string input)
{
    if (is_two_digit(input))
    {
        if (str_to_int(input) < 60 && str_to_int(input) >= 0)
        {
            return true;
        }
        
    }
    return false;
}


// Vu Tuan Son 1575302
// Convert string to int
int str_to_int (string input)
{
    stringstream geek(input);
    int output = 0;
    geek >> output;
    return output;
}


// Vu Tuan Son 1575302
// Convert string to double
double str_to_double (string input)
{
    stringstream geek(input);
    double output = 0.0;
    geek >> output;
    return output;
}


// Vu Tuan Son 1575302
// Return cost of "title"
double get_cost_of(string title)
{
    string answer, cost;
    double output;
    while (true)
    {
        cout << '\n' << title << " (Y/N): ";
        cin >> answer;
        if (answer == "Y" || answer == "y")
        {
            while (true)
            {
                cout << "Enter total cost: $";
                cin >> cost;
                if (is_number(cost))
                {
                    output = str_to_double(cost);
                    return output;
                }
                else
                {
                    cout << "Input invalid!" << endl;
                }
                            
            }
            
        }

        else if (answer == "N" || answer == "n")
        {
            output = 0;
            break;
        }

        else
        {
            cout << "Input invalid!" << endl;
        }
             
    }

    return output;
    
}


// Vu Tuan Son 1575302
// Return cost of miles driven if used private vehicle
double private_vehicle()
{
    string answer, miles;
    double output;
    while (true)
    {
        cout << "\nDid you travel by your own car? (Y/N): ";
        cin >> answer;
        if (answer == "Y" || answer == "y")
        {
            while (true)
            {
                cout << "Enter miles driven: ";
                cin >> miles;
                if (is_number(miles))
                {
                    output = str_to_double(miles) * 0.27;
                    return output;
                }
                else
                {
                    cout << "Input invalid!" << endl;
                }
                            
            }
            
        }

        else if (answer == "N" || answer == "n")
        {
            output = 0;
            break;
        }

        else
        {
            cout << "Input invalid!" << endl;
        }
             
    }

    return output;
    
}


// Vu Tuan Son 1575302
// Return cost of conference/seminar registration
double conference()
{
    string cost;
    double output;
    cout << "\nConference/seminar registration fees" << endl;
    while (true)
    {
        cout << "Enter total cost: $";
        cin >> cost;
        if (is_number(cost))
        {
            output = str_to_double(cost);
            break;
        }
        else
        {
            cout << "Input invalid!" << endl;
        }
        
    }
    return output;

}


// Vu Tuan Son 1575302
// Return TRUE if input is double or int
bool is_number(string input)
{
    int dot_count = 0;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == '.')
        {
            dot_count += 1;
        }
        else if (!isdigit(input[i]))
        {
            return false;
        }
        
    }
    if (dot_count <= 1)
    {
        return true;
    }
    return false;
    
}


// Vu Tuan Son 1575302
// Get number of allowable meals
void number_of_allowable_meals( int day, int time_begin, int time_end,
                                int &breakfast, int &lunch, int &dinner )
{
    breakfast = day;
    lunch = day;
    dinner = day;

    if (time_begin < 7);
    else if (time_begin < 12)
    {
        breakfast = breakfast - 1;
    }
    else if (time_begin < 18)
    {
        breakfast = breakfast - 1;
        lunch = lunch - 1;
    }
    else
    {
        breakfast = lunch = dinner = day - 1;
    }
    
    if (time_end >= 19);
    else if (time_end >= 13)
    {
        dinner = dinner - 1;
    }
    else if (time_end >= 8)
    {
        lunch = lunch - 1;
        dinner = dinner - 1;
    }
    else
    {
        breakfast = breakfast - 1;
        lunch = lunch - 1;
        dinner = dinner - 1;
    }

}


// Vu Tuan Son 1575302
// Get meal expenses
void meal_expense(double &breakfast, double &lunch, double &dinner)
{
    string breakfast_str, lunch_str, dinner_str;
    cout << "\nPlease enter total expenses of meals" << endl;
    // Get total expense of breakfast
    while (true)
    {
        cout << "Breakfast expenses: ";
        cin >> breakfast_str;
        if (is_number(breakfast_str))
        {
            break;
        }
        else
        {
            cout <<  "Input invalid!" << endl;
        }
                
    }
    // Get total expense of lunch
    while (true)
    {
        cout << "Lunch expenses: ";
        cin >> lunch_str;
        if (is_number(lunch_str))
        {
            break;
        }
        else
        {
            cout <<  "Input invalid!" << endl;
        }
                
    }
    // Get total expense of dinner
    while (true)
    {
        cout << "Dinner expenses: ";
        cin >> dinner_str;
        if (is_number(dinner_str))
        {
            break;
        }
        else
        {
            cout <<  "Input invalid!" << endl;
        }
                
    }

    breakfast = str_to_double(breakfast_str);
    lunch = str_to_double(lunch_str);
    dinner = str_to_double(dinner_str);
}


// -------------------------------------------------------------
// Mai Quang Dao 1575296
// get parking fees
double get_parking_fees()
{
    double fee = 0;
    char choice;

    cout << "\nDid you have to pay for parking? (Y/N) ";
    cin >> choice;
    if (choice == 'Y' || choice == 'y')
    {
        cout << "How much did you pay for parking: $";
        cin >> fee;
        while (fee < 0)
        {
            cout << "Input invalid!\n";
            cout << "Enter positive value: $";
            cin >> fee;
        }
        return fee;
    }
    else
        return fee;
}

// Mai Quang Dao 1575296
// get taxi fees
double get_taxi_fees()
{
    double fee = 0;
    char choice;
    cout << "\nDid you use a taxi during the trip? (Y/N) ";
    cin >> choice;
    if (choice == 'Y' || choice == 'y')
    {
        cout << "How much did you pay for taxi: $";
        cin >> fee;
        while (fee < 0)
        {
            cout << "Input invalid!\n";
            cout << "Enter positive value: $";
            cin >> fee;
        }
        return fee;
    }
    else
        return fee;

}

// Mai Quang Dao 1575296
// get hotel expenses
double get_hotel_expenses()
{
    double fee = 0;

    cout << "\nHow much did you pay for the hotel? $";
    cin >> fee;

    while (fee < 0)
    {
        cout << "Please enter a positive value! $";
        cin >> fee;
    }

    return fee;
}