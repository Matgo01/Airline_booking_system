#ifndef PRENOTATION_H
#define PRENOTATION_H

#include <chrono>
#include <string>
#include "user.h"

using namespace std::chrono;

class Prenotation {

private:
    std::string _departure;
    std::string _arrival;
    year_month_day _departure_date;
    year_month_day _arrival_date;
    int _numberFlight;
    int _prenotation_number;
    hours _departure_time; 
    hours _arrival_time;
    User _user;

public:
    // Constructor
    Prenotation(const std::string& departure, const std::string& arrival, 
                const year_month_day& departure_date, const year_month_day& arrival_date, 
                const hours& departure_time, const hours& arrival_time, 
                const User& user);

    // Setters
    void setDepartureDate(const year_month_day& departure_date);
    void setArrivalDate(const year_month_day& arrival_date);
    void setNumberFlight(int numberFlight);
    void setPrenotationNumber(int prenotation_number);
    void setDepartureTime(const hours& departure_time);
    void setArrivalTime(const hours& arrival_time);
    void setDeparture(const std::string& newDeparture);
    void setArrival(const std::string& newArrival);

    // Getters
    year_month_day getDepartureDate() const;
    year_month_day getArrivalDate() const;
    int getNumberFlight() const;
    int getPrenotationNumber() const;
    hours getDepartureTime() const;
    hours getArrivalTime() const;
    std::string getDeparture() const;
    std::string getArrival() const;
    User getUser() const;

    // Generate numbers
    int generateNumberFlight();
    int generatePrenotationNumber();
};

#endif // PRENOTATION_H
