#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void patient();
void doctor();  // Function declaration
void receptionist();  // Function declaration
void appointment();
void emergency();
int doctors_id(int which_doctor, int speciality);

struct patient {
    char name[30];
    char phone[12];
    char email[30];
    char gender[8];
    char address[30];
} pinfo;

void appointmentdata(struct patient *p, char doctors[10][100], int id) {
    FILE *ptr;
    ptr = fopen("appointment2.txt", "a"); // Open file in append mode to add new appointments
    if (ptr == NULL) {
        printf("Error opening file\n");
        return;
    }
    fprintf(ptr, "ID: %d , Name: %s , Phone: %s , Email: %s , Gender: %s , Address: %s , Doctor: %s\n", 
            id, p->name, p->phone, p->email, p->gender, p->address, doctors[id]);
    fclose(ptr); // Close the file after writing
}

int main() {
    int role;
    printf("1.Patient\n2.Doctor\n3.Receptionist\n4.Exit\nEnter: ");
    scanf("%d", &role);
    switch (role) {
        case 1:
            patient();
            break;
        case 2:
            doctor();  // Call doctor function
            break;
        case 3:
            receptionist();  // Call receptionist function
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice\n");
    }
    return 0;
}

void patient() {
    int choice;
    printf("\n1.Book Appointment\n2.Emergency\n3.Exit\nEnter: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            appointment();
            break;
        case 2:
            emergency();
            break;
        case 3:
            return;
        default:
            printf("Invalid choice\n");
    }
    return;
}

void appointment() {
    char doctors[10][100] = {
        "Dr Muhammad Faisal Khanzada(PMC Verified)\n.FCPS, Cardiology, MBBS, LUMHS\n.Experience: 14 Year(s)",
        "Dr. Asad Pathan(PMC Verfied)\n.FACC, FSCAI\n.Experience: 15 Year(s)",
        "Dr. Asma Jabeen (PMDC Verified) MBBS , MCPS (Obstetrics & Gynecology)",
        "Dr. Azra Shamsi (PMDC Verified) MBBS, MCPS (Obstetrics & Gynaecology), FCPS",
        "Prof. Dr. Muhammad Farooq (PMDC Verified) MBBS, FCPS (Urology), FCPS (Surgery)",
        "Dr. Muhammad Imran Malik (PMDC Verified) MBBS, FCPS",
        "Dr. Tabinda Batool (PMDC Verified) MBBS, Certified Course in Hypertension by   of Hypertension",
        "Prof. Dr. Arif Herekar (PMDC Verified) MBBS, MCPS (Medicine), MD Neurology",
        "Dr. Muhammad Amjad (PMDC Verified) MBBS, MCPS (Dermatology), FCPS (Dermatology)",
        "Dr. Aisha Ahmad (PMDC Verified) MBBS, FCPS (Dermatology), Certified (Aesthetic Medicine)"
    };
    int speciality, which_doctor;

    // Getting patient details
    printf("Enter your details\n");
    printf("FULL NAME: ");
    getchar(); // to consume leftover newline
    fgets(pinfo.name, sizeof(pinfo.name), stdin);
    pinfo.name[strcspn(pinfo.name, "\n")] = '\0';
    printf("GENDER: ");
    fgets(pinfo.gender, sizeof(pinfo.gender), stdin);
    pinfo.gender[strcspn(pinfo.gender, "\n")] = '\0';
    printf("PHONE NUMBER: ");
    fgets(pinfo.phone, sizeof(pinfo.phone), stdin);
    pinfo.phone[strcspn(pinfo.phone, "\n")] = '\0';
    printf("EMAIL: ");
    fgets(pinfo.email, sizeof(pinfo.email), stdin);
    pinfo.email[strcspn(pinfo.email, "\n")] = '\0';
    printf("ADDRESS: ");
    fgets(pinfo.address, sizeof(pinfo.address), stdin);
    pinfo.address[strcspn(pinfo.address, "\n")] = '\0';

    // Choosing a specialty and doctor
    printf("Choose Speciality\n");
    printf("1.Cardiologist\n2.Gynecologist\n3.Urologist\n4.Neurologist\n5.Dermatologist\n6.Exit\nEnter: ");
    scanf("%d", &speciality);
    switch (speciality) {
        case 1:
            printf("Best Cardiologists:\n");
            printf("1. Dr Muhammad Faisal Khanzada\n2. Dr. Asad Pathan\nEnter: ");
            scanf("%d", &which_doctor);
            if (which_doctor < 1 || which_doctor > 2) {
                printf("Invalid choice\n");
                return;
            }
            {
                int id = doctors_id(which_doctor, speciality);
                appointmentdata(&pinfo, doctors, id);
            }
            break;
        case 2:
            printf("Best Gynecologists:\n");
            printf("1. Dr. Asma Jabeen\n2. Dr. Azra Shamsi\nEnter: ");
            scanf("%d", &which_doctor);
            if (which_doctor < 1 || which_doctor > 2) {
                printf("Invalid choice\n");
                return;
            }
            {
                int id = doctors_id(which_doctor, speciality);
                appointmentdata(&pinfo, doctors, id);
            }
            break;
        case 3:
            printf("Best Urologists:\n");
            printf("1. Prof. Dr. Muhammad Farooq\n2. Dr. Muhammad Imran Malik\nEnter: ");
            scanf("%d", &which_doctor);
            if (which_doctor < 1 || which_doctor > 2) {
                printf("Invalid choice\n");
                return;
            }
            {
                int id = doctors_id(which_doctor, speciality);
                appointmentdata(&pinfo, doctors, id);
            }
            break;
        case 4:
            printf("Best Neurologists:\n");
            printf("1. Dr. Tabinda Batool\n2. Prof. Dr. Arif Herekar\nEnter: ");
            scanf("%d", &which_doctor);
            if (which_doctor < 1 || which_doctor > 2) {
                printf("Invalid choice\n");
                return;
            }
            {
                int id = doctors_id(which_doctor, speciality);
                appointmentdata(&pinfo, doctors, id);
            }
            break;
        case 5:
            printf("Best Dermatologists:\n");
            printf("1. Dr. Muhammad Amjad\n2. Dr. Aisha Ahmad\nEnter: ");
            scanf("%d", &which_doctor);
            if (which_doctor < 1 || which_doctor > 2) {
                printf("Invalid choice\n");
                return;
            }
            {
                int id = doctors_id(which_doctor, speciality);
                appointmentdata(&pinfo, doctors, id);
            }
            break;
        case 6:
            return;
        default:
            printf("Invalid choice\n");
    }
}

int doctors_id(int which_doctor, int speciality) {
    int res = (speciality - 1) * 2 + (which_doctor - 1); 
    return res;
}

void emergency() {
    int choice;
    printf("1.Call Ambulance\n2.Exit\nEnter: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Enter your Address: ");
            getchar(); // To consume the newline
            fgets(pinfo.address, sizeof(pinfo.address), stdin);
            pinfo.address[strcspn(pinfo.address, "\n")] = '\0';
            printf("Enter your phone number: ");
            fgets(pinfo.phone, sizeof(pinfo.phone), stdin);
            pinfo.phone[strcspn(pinfo.phone, "\n")] = '\0';
            printf("We are sending Ambulance.\n");
            break;
        case 2:
            return;
        default:
            printf("Invalid choice\n");
    }
}

void doctor() {
    printf("You are in the doctor section\n");
    // Add any specific logic for the doctor section here.
}

void receptionist() {
    printf("You are in the receptionist section\n");
    // Add any specific logic for the receptionist section here.
}
