# LLD

## Requirement Specifications for Movie Ticket Booking System.

    1. System should be able to list all cities where cinema halls are affiliated to show the movies.
    2. Each city can have multiple cinema halls.
    3. Each cinema halls can have one or multiple screens.
    4. Each screen can have multiple shows in a day but only one show at a time.
    5. Each Movie has multiple shows.
    6. Customers should be able to search the movie by title, language, genre, location.
    7. Once customer selects a movie in a given location the system should be able to display the cinema hall and the show timings.
    8. The customer should be able to select a cinema as well as show in that cinema.
    9. The system should be able to show the seating lay out of the hall as well as the availability of the seats.
    10. The system should allow users to select one or multiple seats.
    11. System should be able to send notification and provide option to download booked tickets.
    12. Customers should be able to pay using card or wallet.
    13. The system should provide the option to cancel the ticket as refund the amount.
    14. No two customer should be able to book same seat in the same show.
    
  ## Use case diagram
  
  ##### Main Actors in our system:
    1. Admin
    2. Customer
    3. Guest User
    4. System
    
  ##### Use Cases:
    1. Search Movies
    2. Create Booking
    3. Pay for booking
    4. Assign seat
    5. Cancel bookings
    6. Refund for cancellation
    7. Apply coupons for payment offers
    
  ## List of classes
    1. User Accounts (Admin, Customer)
    2. Movie
    3. Cinema
    4. Cinema Hall
    5. City
    6. Address
    7. Show
    8. Cinema Hall Seat
    9. Show Seat
    10. Payment
    11. Notification
    12. Ticket
