#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// structures
struct Appointment
{
    int doctor_id;
    char patient_name[100];
    char patient_phone[100];
    char patient_email[100];
    char patient_gender[100];
    char patient_address[100];
    char doctor_name[100];
    char slot[100];
} appointment_data;
struct Doctor
{
    int id;
    char name[100];
    char password[20];
    char speciality[100];
    char slots[3][100];
};
struct Doctor doctor_data[10];

struct patient
{
    char name[30];
    char phone[14];
    char email[30];
    char gender[8];
    char address[30];
} P_info;
// FUNCTIONS DECLARATION
void patient();
void receptionist();
void appointment();
void emergency();
// void Doctor_data(struct Doctor *d);
void Doctor_fetch(struct Doctor *d, int max_doctors); // CAlling this in Appointment data
void doctor(struct Doctor *d);                        // Function declaration
// void Appointment_fetch(struct Appointment *A,int id);
int doctors_id(int which_doctor, int speciality);      // used for calculating doctor id
void Appointment_fetch(struct Appointment *A, int id); // USING IN DOCTOR
void Questioning(char phone[], char address[]);
void appointmentdata(struct Doctor *d, struct patient *p, int id, int slot);
int is_valid_email(const char *email);//Fuction used in appointment function to verify email
// MAIN FUNCTION

int main()
  { 
   printf("                    ___\n");
   printf("                   |   |\n");
   printf("              _____|   |_____\n");
   printf("             |   MUHAMMADAN  |\n");
   printf("             |____HOSPITAL___|\n");
   printf("                   |   |\n");
   printf("                   |___|\n");
char term;
    int role;
    while (1)
    {
        printf("1-->Patient\n2-->Doctor\n3-->Receptionist\n4-->Exit\nEnter: ");
        if (scanf("%d%c", &role, &term) != 2 || term != '\n') {
            // Invalid input: Clear the input buffer
            while (getchar() != '\n');
            printf("Invalid input. Please enter a valid number.\n");
            continue;
        }
(int)role;
        switch (role)
        {
        case 1:
            patient();
            break;
        case 2:
            doctor(doctor_data); // Call doctor function
            break;
        case 3:
            receptionist(); // Call receptionist function
            break;
        case 4:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
}

// PATIENT FUNCTION
void patient()
{
    int choice;
	char term;
    while (choice != 3)
    {
        printf("\n1-->Book Appointment\n2-->Emergency\n3-->back\nEnter: ");
        scanf("%d%c", &choice,&term);
        if(term!='\n'){
        	while(getchar()!='\n'){
        		 printf("Invalid input. Please enter a valid number.\n");
            continue;
			}
		}
        switch (choice)
        {
        case 1:
            appointment();
            return;
        case 2:
            emergency();
            return;
        case 3:
            return;
        default:
            printf("Invalid  choice\n");
        }
    }
    return;
}
// Email validation
int is_valid_email(const char *email) {
    int at_count = 0, dot_count = 0;
    int i;

    // Email should contain at least one '@' and one '.'
    for (i = 0; email[i] != '\0'; i++) {
        if (email[i] == '@') at_count++;
        if (email[i] == '.') dot_count++;
        if (!isalnum(email[i]) && email[i] != '@' && email[i] != '.') {
            return 0; // Invalid character in email
        }
    }

    // Return true if the email contains exactly one '@' and at least one '.'
    return at_count == 1 && dot_count > 0;
}

// Function to handle appointment
void appointment() {
    int speciality = 0, which_doctor, slot;
getchar();//to clear unwanted character.
    // Getting patient details
    printf("Enter your details\n");

    // Getting and sanitizing patient name
    printf("FULL NAME: ");
    fgets(P_info.name, sizeof(P_info.name), stdin);
    P_info.name[strcspn(P_info.name, "\n")] = '\0';  // Remove newline if present

    // Getting and sanitizing gender
    printf("GENDER: ");
    fgets(P_info.gender, sizeof(P_info.gender), stdin);
    P_info.gender[strcspn(P_info.gender, "\n")] = '\0';

    // Getting and sanitizing phone number
    printf("PHONE NUMBER: ");
    fgets(P_info.phone, sizeof(P_info.phone), stdin);
    P_info.phone[strcspn(P_info.phone, "\n")] = '\0';
    
    if(strlen(P_info.phone)!=11){
    	printf("Invalid Phone. Please try again.\n");
        return; 
     }
    // Email validation
    printf("EMAIL: ");
    fgets(P_info.email, sizeof(P_info.email), stdin);
    P_info.email[strcspn(P_info.email, "\n")] = '\0';  // Remove newline if present
    
     // Validate email format
    if (!is_valid_email(P_info.email)) {
        printf("Invalid email format. Please try again.\n");
        return;  // Exit if the email is invalid
    }

    // Getting and sanitizing address
    printf("ADDRESS: ");
    fgets(P_info.address, sizeof(P_info.address), stdin);
    P_info.address[strcspn(P_info.address, "\n")] = '\0';

    // Choosing a specialty and doctor
    while (speciality != 6) {
        printf("Choose Speciality\n");
        printf("1. Cardiologist\n2. Gynecologist\n3. Urologist\n4. Neurologist\n5. Dermatologist\n6. Back\nEnter: ");
        
        if (scanf("%d", &speciality) != 1 || speciality < 1 || speciality > 6) {
            printf("Invalid choice. Please try again.\n");
            while (getchar() != '\n'); // Clear the input buffer
            continue;
        }

        switch (speciality) {
        case 1: // Cardiologist
            printf("Best Cardiologists:\n");
            printf("1. Dr Muhammad Faisal Khanzada\n2. Dr. Asad Pathan\nEnter: ");
            if (scanf("%d", &which_doctor) != 1 || which_doctor < 1 || which_doctor > 2) {
                printf("Invalid choice. Please try again.\n");
                break;
            }
            printf("Select time slot :\n1.Mon-Tue: 9AM-5PM\n2.Wed-Fri: 10AM-2PM\n3.Sat:12PM-6PM\nEnter: ");
            if (scanf("%d", &slot) != 1 || slot < 1 || slot > 3) {
                printf("Invalid slot choice. Please try again.\n");
                break;
            }
            printf("Thanks for booking.\n");
            {
                int id = doctors_id(which_doctor, speciality);
                appointmentdata(doctor_data, &P_info, id, slot); // Assuming doctor_data is passed properly
            }
            return;

        case 2: // Gynecologist
            printf("Best Gynecologists:\n");
            printf("1. Dr. Asma Jabeen\n2. Dr. Azra Shamsi\nEnter: ");
            if (scanf("%d", &which_doctor) != 1 || which_doctor < 1 || which_doctor > 2) {
                printf("Invalid choice. Please try again.\n");
                break;
            }
            printf("Select time slot :\n1.Mon-Tue: 9AM-5PM\n2.Wed-Fri: 10AM-2PM\n3.Sat:12PM-6PM\nEnter: ");
            if (scanf("%d", &slot) != 1 || slot < 1 || slot > 3) {
                printf("Invalid slot choice. Please try again.\n");
                break;
            }
            printf("Thanks for booking.\n");
            {
                int id = doctors_id(which_doctor, speciality);
                appointmentdata(doctor_data, &P_info, id, slot); // Assuming doctor_data is passed properly
            }
            return;

        case 3: // Urologist
            printf("Best Urologists:\n");
            printf("1. Prof. Dr. Muhammad Farooq\n2. Dr. Muhammad Imran Malik\nEnter: ");
            if (scanf("%d", &which_doctor) != 1 || which_doctor < 1 || which_doctor > 2) {
                printf("Invalid choice. Please try again.\n");
                break;
            }
            printf("Select time slot :\n1.Mon-Tue: 9AM-5PM\n2.Wed-Fri: 10AM-2PM\n3.Sat:12PM-6PM\nEnter: ");
            if (scanf("%d", &slot) != 1 || slot < 1 || slot > 3) {
                printf("Invalid slot choice. Please try again.\n");
                break;
            }
            printf("Thanks for booking.\n");
            {
                int id = doctors_id(which_doctor, speciality);
                appointmentdata(doctor_data, &P_info, id, slot); // Assuming doctor_data is passed properly
            }
            return;

        case 4: // Neurologist
            printf("Best Neurologists:\n");
            printf("1. Dr. Tabinda Batool\n2. Prof. Dr. Arif Herekar\nEnter: ");
            if (scanf("%d", &which_doctor) != 1 || which_doctor < 1 || which_doctor > 2) {
                printf("Invalid choice. Please try again.\n");
                break;
            }
            printf("Select time slot :\n1.Mon-Tue: 9AM-5PM\n2.Wed-Fri: 10AM-2PM\n3.Sat:12PM-6PM\nEnter: ");
            if (scanf("%d", &slot) != 1 || slot < 1 || slot > 3) {
                printf("Invalid slot choice. Please try again.\n");
                break;
            }
            printf("Thanks for booking.\n");
            {
                int id = doctors_id(which_doctor, speciality);
                appointmentdata(doctor_data, &P_info, id, slot); // Assuming doctor_data is passed properly
            }
            return;

        case 5: // Dermatologist
            printf("Best Dermatologists:\n");
            printf("1. Dr. Muhammad Amjad\n2. Dr. Aisha Ahmad\nEnter: ");
            if (scanf("%d", &which_doctor) != 1 || which_doctor < 1 || which_doctor > 2) {
                printf("Invalid choice. Please try again.\n");
                break;
            }
            printf("Select time slot :\n1.Mon-Tue: 9AM-5PM\n2.Wed-Fri: 10AM-2PM\n3.Sat:12PM-6PM\nEnter: ");
            if (scanf("%d", &slot) != 1 || slot < 1 || slot > 3) {
                printf("Invalid slot choice. Please try again.\n");
                break;
            }
            printf("Thanks for booking.\n");
            {
                int id = doctors_id(which_doctor, speciality);
                appointmentdata(doctor_data, &P_info, id, slot); // Assuming doctor_data is passed properly
            }
            return;

        case 6: // Back
            return;

        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }
}
int doctors_id(int which_doctor, int speciality)
{
    int res = (speciality - 1) * 2 + (which_doctor);
    return res;
}
void Appointment_fetch(struct Appointment *A, int id)
{
    // Open the appointment file
    FILE *appointment_data_ptr = fopen("appointment.txt", "r");
    if (appointment_data_ptr == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    // Temporary variable to hold doctor_id from the file
    int doctor_id;

    // Use a for loop to process each appointment
    for (;;)
    {
        // Read doctor ID from the file
        if (fscanf(appointment_data_ptr, "%d", &doctor_id) != 1)
        {
            break; // End of file reached or failed to read doctor_id
        }

        // Skip the newline after reading doctor_id
        while (fgetc(appointment_data_ptr) != '\n')
        {
        }

        // Check if the doctor_id matches the passed id
        if (doctor_id == id)
        {
            //            printf("Found matching doctor ID %d. Reading appointment details...\n", doctor_id);

            // Store the doctor_id in the structure
            A->doctor_id = doctor_id;

            // Read the remaining appointment data and store it in the structure
            fgets(A->patient_name, sizeof(A->patient_name), appointment_data_ptr);
            A->patient_name[strcspn(A->patient_name, "\n")] = 0; // Remove trailing newline

            fgets(A->patient_phone, sizeof(A->patient_phone), appointment_data_ptr);
            A->patient_phone[strcspn(A->patient_phone, "\n")] = 0;

            fgets(A->patient_email, sizeof(A->patient_email), appointment_data_ptr);
            A->patient_email[strcspn(A->patient_email, "\n")] = 0;

            fgets(A->patient_gender, sizeof(A->patient_gender), appointment_data_ptr);
            A->patient_gender[strcspn(A->patient_gender, "\n")] = 0;

            fgets(A->patient_address, sizeof(A->patient_address), appointment_data_ptr);
            A->patient_address[strcspn(A->patient_address, "\n")] = 0;

            fgets(A->doctor_name, sizeof(A->doctor_name), appointment_data_ptr);
            A->doctor_name[strcspn(A->doctor_name, "\n")] = 0;

            fgets(A->slot, sizeof(A->slot), appointment_data_ptr);
            A->slot[strcspn(A->slot, "\n")] = 0;

            printf("Appointments for Doctor ---------> %s <---------\n", A->doctor_name);
            printf("\nPatient Name: %s\n", A->patient_name);
            printf("Patient Phone: %s\n", A->patient_phone);
            printf("Patient Email: %s\n", A->patient_email);
            printf("Patient Gender: %s\n", A->patient_gender);
            printf("Patient Address: %s\n", A->patient_address);
            printf("Slot: %s\n", A->slot);
            printf("-----------------------------\n");
            // Exit the loop after reading the appointment for the matching doctor
            //            break;
        }
        else
        {
            // Skip the rest of the fields for the current appointment if doctor_id doesn't match

            char temp[200];
            fgets(temp, sizeof(temp), appointment_data_ptr); // Skip patient_name
            fgets(temp, sizeof(temp), appointment_data_ptr); // Skip patient_phone
            fgets(temp, sizeof(temp), appointment_data_ptr); // Skip patient_email
            fgets(temp, sizeof(temp), appointment_data_ptr); // Skip patient_gender
            fgets(temp, sizeof(temp), appointment_data_ptr); // Skip patient_address
            fgets(temp, sizeof(temp), appointment_data_ptr); // Skip doctor_name
            fgets(temp, sizeof(temp), appointment_data_ptr); // Skip slot
        }
    }

    // If no appointment was found for the given doctor ID
    if (ftell(appointment_data_ptr) == 0)
    {
        printf("No appointments found for doctor ID %d\n", id);
    }

    // Close the file
    fclose(appointment_data_ptr);
}
void appointmentdata(struct Doctor *d, struct patient *p, int id, int slot)
{ // USING in Appointment func to store pateint info in file

    Doctor_fetch(d, 10);                       // ASSIGNING data doctor structure from file doctor2
                                               // appointment
    FILE *ptr = fopen("appointment.txt", "a"); // Open file in append mode to add new appointments
    if (ptr == NULL)
    {
        printf("Error opening file\n");
        return;
    }
    fprintf(ptr, "%d\n%s\n%s\n%s\n%s\n%s\n%s\n", id, p->name, p->phone, p->email, p->gender, p->address, d[id - 1].name);
    switch (slot)
    {
    case 1:
        fprintf(ptr, "%s\n", d[id - 1].slots[0]);

        break;
    case 2:
        fprintf(ptr, "%s\n", d[id - 1].slots[1]);

        break;
    case 3:
        fprintf(ptr, "%s\n", d[id - 1].slots[2]);

        break;
    }
    fclose(ptr); // Close the file after writing
}
// Doctor fetch used in Appointment function
void Doctor_fetch(struct Doctor *d, int max_doctors)
{

    FILE *doctor_data_ptr = fopen("doctor2.txt", "r"); // Open the file in read mode

    if (doctor_data_ptr == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    int i = 0, j;
    // Read doctor data from the file
    while (i < max_doctors && fscanf(doctor_data_ptr, "%d\n", &d[i].id) == 1)
    {
        // Read password, name, speciality, and slots
        fgets(d[i].password, sizeof(d[i].password), doctor_data_ptr);
        d[i].password[strcspn(d[i].password, "\n")] = 0; // Remove the trailing newline

        fgets(d[i].name, sizeof(d[i].name), doctor_data_ptr);
        d[i].name[strcspn(d[i].name, "\n")] = 0; // Remove the trailing newline

        fgets(d[i].speciality, sizeof(d[i].speciality), doctor_data_ptr);
        d[i].speciality[strcspn(d[i].speciality, "\n")] = 0; // Remove the trailing newline

        // Read the 3 slots for the doctor
        for (j = 0; j < 3; j++)
        {
            fgets(d[i].slots[j], sizeof(d[i].slots[j]), doctor_data_ptr);
            d[i].slots[j][strcspn(d[i].slots[j], "\n")] = 0; // Remove the trailing newline
        }

        i++;
    }

    fclose(doctor_data_ptr); // Close the file after reading
}
// Emergency
void emergency()
{
    int Que;
    int choice;
    FILE *fp;
    char term;
    while (choice != 2)
    {
        printf("1-->Call Ambulance\n2-->Exit\nEnter: ");
        scanf("%d%c", &choice,&term);
        if(term!="\n"){
        	while(getchar()!='\n'){
        		 printf("Invalid input. Please enter a valid number.\n");
            continue;
			}
		}
        switch (choice)
        {
        case 1:
            printf("Enter your Address: ");
            getchar(); // To consume the newline
            fgets(P_info.address, sizeof(P_info.address), stdin);
            P_info.address[strcspn(P_info.address, "\n")] = '\0';

            printf("Enter your phone number: ");
            fgets(P_info.phone, sizeof(P_info.phone), stdin);
            P_info.phone[strcspn(P_info.phone, "\n")] = '\0';

            printf("We are sending Ambulance.\n");
            printf("Could you tell us about pateint condition so we can do all prepration before you reach Hospital.");
            printf("\n1.Yes\n2.No\nEnter:");

            scanf("%d", &Que);
            switch (Que)
            {
            case 1:
                Questioning(P_info.phone, P_info.address);

                break;
            case 2:
                printf("\nOK");
                fp = fopen("Emergency.txt", "a");
                fprintf(fp, "PHONE: %s\n", P_info.phone);
                fprintf(fp, "ADDRESS: %s\n", P_info.address);
                fprintf(fp, "--------------------------------------------------------------");

                fclose(fp);
                exit(0);
            default:
                printf("Invalid choice\n");
            }
            break;
        case 2:
            printf("Exiting..");
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}
void Questioning(char phone[], char address[])
{
    FILE *fp;
    fp = fopen("Emergency.txt", "a");
    if (fp == NULL)
    {
        printf("FILE Error\n");
        return;
    }

    int i;
    char response[10]; // Declare 'response' as an array to store the answer

    fprintf(fp, "Phone: %s\n", phone);
    fprintf(fp, "Address: %s\n", address);

    char questions[10][256] = {
        "Is the patient experiencing difficulty breathing?",
        "Is the patient conscious and alert?",
        "Does the patient have chest pain?",
        "Is the patient bleeding or showing signs of severe blood loss?",
        "Does the patient have a history of heart disease?",
        "Is the patient experiencing severe pain or discomfort?",
        "Does the patient have any known allergies (especially to medications)?",
        "Is the patient pregnant or may be pregnant?",
        "Does the patient have a known history of seizures?",
        "Is the patient at risk of infection (e.g., fever, cough, recent exposure)?"};

    for (i = 0; i < 10; i++)
    {
        printf("%s\n", questions[i]);
        printf("Yes or No: ");
        scanf("%s", response); // Read response as a string
        fprintf(fp, "%d. %s\nResponse: %s\n", i + 1, questions[i], response);
        printf("\n");
    }

    fprintf(fp, "-------------------------------------------------------------");

    fclose(fp);
}
void receptionist()
{
    char recep_name[20];
    char password[10];
    int choice;
    FILE *ptr;
    int id;
    char ch;
    int attempts = 3; // Allow 3 attempts for login

    while (attempts > 0)
    {
        printf("Enter Username: ");
        if (scanf("%19s", recep_name) != 1)  // Limit input size to avoid overflow
        {
            printf("Invalid input. Please try again.\n");
            while (getchar() != '\n');  // Clear the input buffer
            continue;
        }

        // Example valid username and password
        char name[] = {'m', 'a', 'r', 'y', 'a', 'm'};
        char pass[] = {'1', '2', '3', '4', '5'};

        // Remove any newline character from input
        recep_name[strcspn(recep_name, "\n")] = '\0';

        printf("Enter Password: ");
        if (scanf("%9s", password) != 1)  // Limit password input size
        {
            printf("Invalid input. Please try again.\n");
            while (getchar() != '\n');  // Clear the input buffer
            continue;
        }

        // Remove any newline character from input
        password[strcspn(password, "\n")] = '\0';

        // Check if username and password match
        if (strcmp(recep_name, name) == 0  && strcmp(password, pass) == 0)
        {
            printf("Login successful.\n");

            while (1)
            {
                // Display the receptionist menu
                printf("\n1.Book Appointment\n2. See data\n3. Back\nEnter your choice: ");
                if (scanf("%d", &choice) != 1)
                {
                    printf("Invalid input. Please enter a valid number.\n");
                    while (getchar() != '\n');  // Clear the input buffer
                    continue;
                }

                switch (choice)
                {
                case 1:
                    appointment();  // Function for booking an appointment
                    break;

                case 2:
                    printf("1. Emergency\n2. Doctors\n3. Appointments\n4. Back\nEnter your choice: ");
                    if (scanf("%d", &choice) != 1)
                    {
                        printf("Invalid input. Please enter a valid number.\n");
                        while (getchar() != '\n');  // Clear the input buffer
                        continue;
                    }

                    switch (choice)
                    {
                    case 1:
                        printf("\n\n\n");
                        ptr = fopen("emergency.txt", "r");
                        if (ptr == NULL)
                        {
                            printf("File Error: Could not open emergency file.\n");
                        }
                        else
                        {
                            while ((ch = fgetc(ptr)) != EOF)
                            {
                                putchar(ch); // Print each character from the file
                            }
                            fclose(ptr); // Close the file
                        }
                        break;

                    case 2:
                        printf("\n\n\n");
                        ptr = fopen("doctor2.txt", "r");
                        if (ptr == NULL)
                        {
                            printf("File Error: Could not open doctor file.\n");
                        }
                        else
                        {
                            while ((ch = fgetc(ptr)) != EOF)
                            {
                                putchar(ch);
                            }
                            fclose(ptr); // Close the file
                        }
                        break;

                    case 3:
                        printf("Enter ID of doctor: ");
                        if (scanf("%d", &id) != 1)
                        {
                            printf("Invalid input for doctor ID.\n");
                            while (getchar() != '\n');  // Clear the input buffer
                            continue;
                        }
                        printf("\n\n\n");
                        Appointment_fetch(&appointment_data, id);  // Fetch and display appointments
                        break;

                    case 4:
                        break; // Return to previous menu
                    default:
                        printf("Invalid Input. Please try again.\n");
                    }
                    break;

                case 3:
                    return;  // Exit receptionist function

                default:
                    printf("Invalid Input. Please try again.\n");
                }
            }
        }
        else
        {
            attempts--;
            if (attempts > 0)
            {
                printf("Wrong username or password. You have %d attempt(s) left.\n", attempts);
            }
            else
            {
                printf("Too many failed login attempts. Exiting.\n");
                return;  // Exit after too many failed attempts
            }
        }
    }
}
void doctor(struct Doctor *d)
{
    char password[20];
    int found = 0;
    int choice;
    int doc_id;
    int i;
    int attempts = 3;  // Allow 3 attempts for password

    printf("You are in the doctor section\n");

    // Loop to allow for multiple password attempts
    while (attempts > 0) {
        printf("Enter your password: ");
        if (scanf("%19s", password) != 1) {  // Read at most 19 characters (one for null terminator)
            printf("Invalid input. Please enter a valid password.\n");
            while (getchar() != '\n');  // Clear the input buffer
            continue;
        }

        Doctor_fetch(doctor_data, 10);  // Fetch doctor data (make sure this function handles errors internally)

        for (i = 0; i < 10; i++) {
            if (strcmp(password, d[i].password) == 0) {
                printf("Welcome doctor %s\n", d[i].name);
                found = 1;
                doc_id = d[i].id;
                break;
            }
        }

        if (found) {
            break;  // Exit the loop if password is correct
        } else {
            attempts--;
            if (attempts > 0) {
                printf("Invalid password. You have %d attempt(s) left.\n", attempts);
            } else {
                printf("Too many incorrect attempts. Exiting.\n");
                return;  // Exit the function after 3 failed attempts
            }
        }
    }

    // Once the password is correct, show the menu options
    if (found) {
        printf("1-->Scheduled Appointments\n2-->Exit\nEnter your choice: ");
        
        // Validate input for the menu choice
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');  // Clear the input buffer
            return;
        }

        switch (choice) {
        case 1:
            Appointment_fetch(&appointment_data, doc_id);
            if (appointment_data.doctor_id == 0) {
                printf("No appointments found\n");
            }
            break;
        case 2:
            printf("Exiting doctor section...\n");
            break;
        default:
            printf("Invalid input. Please choose a valid option.\n");
            break;
        }
    }
}
