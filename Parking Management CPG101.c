
#include <stdio.h>

#define MAX_SLOTS 10

// Structure to store vehicle information
struct Vehicle{
    int slotNumber;
    char vehicleNumber[20];
    int occupied;   // 0 = Empty, 1 = Occupied
};

// Function to initialize parking slots
void initializeParking(struct Vehicle parking[]) {
    for (int i = 0; i < MAX_SLOTS; i++) {
        parking[i].slotNumber = i + 1;
        parking[i].occupied = 0;
    }
}

// Function to park a vehicle
void parkVehicle(struct Vehicle parking[]) {
    char number[20];

    printf("Enter Vehicle Number: ");
    scanf("%s", number);

    for (int i = 0; i < MAX_SLOTS; i++) {
        if (parking[i].occupied == 0) {
            parking[i].occupied = 1;

            // Copy vehicle number manually
            int j = 0;
            while (number[j] != '\0') {
                parking[i].vehicleNumber[j] = number[j];
                j++;
            }
            parking[i].vehicleNumber[j] = '\0';

            printf("Vehicle parked at Slot %d\n",
                   parking[i].slotNumber);
            return;
        }
    }

    printf("Parking Lot is Full!\n");
}

// Function to remove a vehicle
void removeVehicle(struct Vehicle parking[]) {
    char number[20];

    printf("Enter Vehicle Number to Remove: ");
    scanf("%s", number);

    for (int i = 0; i < MAX_SLOTS; i++) {
        if (parking[i].occupied == 1) {

            int j = 0;
            while (parking[i].vehicleNumber[j] == number[j] &&
                   parking[i].vehicleNumber[j] != '\0' &&
                   number[j] != '\0') {
                j++;
            }

            if (parking[i].vehicleNumber[j] == '\0' &&
                number[j] == '\0') {

                parking[i].occupied = 0;
                printf("Vehicle Removed from Slot %d\n",
                       parking[i].slotNumber);
                return;
            }
        }
    }

    printf("Vehicle Not Found!\n");
}

// Function to display parking status
void displayParking(struct Vehicle parking[]) {
    printf("\n--- Parking Status ---\n");

    for (int i = 0; i < MAX_SLOTS; i++) {
        if (parking[i].occupied == 1) {
            printf("Slot %d : %s\n",
                   parking[i].slotNumber,
                   parking[i].vehicleNumber);
        } else {
            printf("Slot %d : Empty\n",
                   parking[i].slotNumber);
        }
    }
}

// Main Function
int main() {
    struct Vehicle parking[MAX_SLOTS];
    int choice;

    initializeParking(parking);

    do {
        printf("\n===== Parking Management System =====\n");
        printf("1. Park Vehicle\n");
        printf("2. Remove Vehicle\n");
        printf("3. Display Parking Status\n");
        printf("4. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                parkVehicle(parking);
                break;

            case 2:
                removeVehicle(parking);
                break;

            case 3:
                displayParking(parking);
                break;

            case 4:
                printf("Exiting Program...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while (choice != 4);

    return 0;
}