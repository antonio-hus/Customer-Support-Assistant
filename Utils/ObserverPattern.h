#ifndef CUSTOMER_SUPPORT_ASSISTANT_OBSERVERPATTERN_H
#define CUSTOMER_SUPPORT_ASSISTANT_OBSERVERPATTERN_H

///////////////////////
/// IMPORTS SECTION ///
//////////////////////
// C++ Libraries
#include <vector>
#include <algorithm>


////////////////////////
/// CLASS DEFINITION ///
///////////////////////
// Observer Base Pure Abstract Class
class Observer {
public:

    // Virtual notify
    // Function to notify concrete observer to update
    virtual void notify()=0;

    // Virtual destructor
    // Inherited Objects follow their own destructor
    virtual ~Observer() = default;

};

// Subject Base Class
class Subject {
private:

    // List of concrete Observers
    std::vector<Observer*> observers;

public:

    // Add a new observer
    void attach(Observer* o) { this->observers.push_back(o); };

    // Detach an observer
    void detach(Observer* o) { this->observers.erase(std::find(this->observers.begin(), this->observers.end(), o)); };

    // Notify all observers
    void notify() { for(auto o:this->observers) o->notify(); };
};

#endif
