#include "prenotation.h"
#include <random>

// Constructor
Prenotation::Prenotation(const std::string& departure, const std::string& arrival,
                         const std::chrono::year_month_day& departure_date, 
                         const std::chrono::year_month_day& arrival_date, 
                         const std::chrono::hours& departure_time, 
                         const std::chrono::hours& arrival_time, 
                         const User& user)
    : _departure(departure), _arrival(arrival), 
      _departure_date(departure_date), _arrival_date(arrival_date),
      _departure_time(departure_time), _arrival_time(arrival_time),
      _user(user) {
    _numberFlight = generateNumberFlight();
    _prenotation_number = generatePrenotationNumber();
}

// Generate a random flight number
int Prenotation::generateNumberFlight() {
    std::random_device rd;  
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> dist(1000, 9999); 

    return dist(gen);
}

// Generate a random prenotation number
int Prenotation::generatePrenotationNumber() {
    std::random_device rd;  
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> dist(1000, 9999); 

    return dist(gen);
}

// Setters
void Prenotation::setDepartureDate(const std::chrono::year_month_day& departure_date) {
    _departure_date = departure_date;
}

void Prenotation::setArrivalDate(const std::chrono::year_month_day& arrival_date) {
    _arrival_date = arrival_date;
}

void Prenotation::setDepartureTime(const std::chrono::hours& departure_time) {
    _departure_time = departure_time;
}

void Prenotation::setArrivalTime(const std::chrono::hours& arrival_time) {
    _arrival_time = arrival_time;
}

void Prenotation::setDeparture(const std::string& newDeparture) {
    _departure = newDeparture;
}

void Prenotation::setArrival(const std::string& newArrival) {
    _arrival = newArrival;
}

// Getters
int Prenotation::getNumberFlight() const {
    return _numberFlight;
}

int Prenotation::getPrenotationNumber() const {
    return _prenotation_number;
}

const std::string& Prenotation::getDeparture() const {
    return _departure;
}

const std::string& Prenotation::getArrival() const {
    return _arrival;
}

const std::chrono::year_month_day& Prenotation::getDepartureDate() const {
    return _departure_date;
}

const std::chrono::year_month_day& Prenotation::getArrivalDate() const {
    return _arrival_date;
}

const std::chrono::hours& Prenotation::getDepartureTime() const {
    return _departure_time;
}

const std::chrono::hours& Prenotation::getArrivalTime() const {
    return _arrival_time;
}
