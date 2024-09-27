class MyCalendarTwo {
private:
    vector<pair<int, int>> singleBookings;  // Stores intervals with single bookings (no overlaps yet)
    vector<pair<int, int>> doubleBookings;  // Stores intervals with double bookings (to prevent triple bookings)

public:
    // Constructor to initialize the calendar
    MyCalendarTwo() {}

    // Method to book a new event
    bool book(int start, int end) {
        // Check if the new event would cause a triple booking by overlapping with any double booking
        for (const pair<int, int>& doubleBooking : doubleBookings) {
            // Check if there is an overlap between the double booking interval and the new event
            // Condition: doubleBooking.first < end && doubleBooking.second > start
            if (doubleBooking.first < end && doubleBooking.second > start) {
                return false;  // Triple booking detected, so the booking is not allowed
            }
        }

        // Iterate through all single bookings to check for overlaps and possibly create double bookings
        for (const pair<int, int>& singleBooking : singleBookings) {
            // Check if there is an overlap between the single booking interval and the new event
            // Condition: singleBooking.first < end && singleBooking.second > start
            if (singleBooking.first < end && singleBooking.second > start) {
                // Calculate the overlapping interval and add it to doubleBookings
                int overlapStart = max(singleBooking.first, start); // Start of the overlap interval
                int overlapEnd = min(singleBooking.second, end);    // End of the overlap interval
                doubleBookings.push_back(make_pair(overlapStart, overlapEnd)); // Add to double bookings
            }
        }

        // Add the new event to the list of single bookings
        singleBookings.push_back(make_pair(start, end));

        // Booking is successful as no triple booking was detected
        return true;
    }
};

/**
 * Usage:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool result = obj->book(start, end);
 */