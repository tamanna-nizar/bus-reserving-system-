#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEATS 60
#define MAX_NAME_LENGTH 50

struct Booking {
    char name[MAX_NAME_LENGTH];
    int seatNo;
    int age;
    char source[MAX_NAME_LENGTH];
    char destination[MAX_NAME_LENGTH];
 
};

struct Booking bookings[MAX_SEATS];
int bookedSeats = 0;

void bookSeat() {
    if (bookedSeats >= MAX_SEATS) {
        printf("No more seats available.\n");
        return;
    }

    struct Booking newBooking;

    printf("Enter name: ");
    scanf("%s", newBooking.name);
    printf("Enter Age: ");
    scanf("%d", &newBooking.age);
    printf("Enter seat number: ");
    scanf("%d", &newBooking.seatNo);
    printf("From: ");
    scanf("%s", newBooking.source);
    printf("To: ");
    scanf("%s", newBooking.destination);


    bookings[bookedSeats++] = newBooking;
    printf("Seat booked successfully.\n");
}

void viewReservations() {
    if (bookedSeats == 0) {
        printf("No reservations made yet.\n");
        return;
    }

    printf("All reservations:\n");
    printf("Seat No.  \tName       \tAge\t        Source\t       \t\tDestination\n");
    for (int i = 0; i < bookedSeats; ++i) {
        printf("%d\t        %s\t     %d\t   \t%s\t\t         %s\t\n", bookings[i].seatNo, bookings[i].name, bookings[i].age,bookings[i].source, bookings[i].destination );
    }
}

void printTicket() {
    int seatToPrint;
    printf("Enter seat number to print ticket: ");
    scanf("%d", &seatToPrint);

    int found = 0;
    for (int i = 0; i < bookedSeats; ++i) {
        if (bookings[i].seatNo == seatToPrint) {
             printf("\n=================================\n");
        printf("  BUS TICKET");
        printf("\n=================================\n");
            printf("Ticket for Seat No. %d\n", bookings[i].seatNo);
            printf("Passenger Name: %s\n", bookings[i].name);
            printf("Passenger Age: %d\n", bookings[i].age);
            printf("Passenger Source: %s\n", bookings[i].source);
             printf("Passenger Destination: %s\n", bookings[i].destination);
             printf("\n=================================\n");
     

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Reservation not found.\n");
    }
}

int main() {
    int choice;
    printf("\t\t|           BUS TICKET RERSERVATION SYSTEM           |\n");
    printf("\t\t------------------------------------------------------\n");
    printf("\t\t------------------------------------------------------\n");
    do {
        printf("\n=================================\n");
printf("    BUS RESERVATION SYSTEM");
printf("\n=================================");
printf("\n1>> Reserve A Ticket");
printf("\n------------------------");
printf("\n2>> View Reservation");
printf("\n------------------------");
printf("\n3>>Print A Ticket");
printf("\n------------------------");
printf("\n4>>Exit");
printf("\n------------------------");
printf("\n\n-->");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bookSeat();
                break;
            case 2:
                viewReservations();
                break;
            case 3:
                printTicket();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
