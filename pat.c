#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void patient();
void receptionist();  // Function declaration
void appointment();
void emergency();
//void Doctor_data(struct Doctor *d);
int doctors_id(int which_doctor, int speciality);
struct Appointment {
    int doctor_id;
    char patient_name[100];
    char patient_phone[100];
    char patient_email[100];
    char patient_gender[100];
    char patient_address[100];
    char doctor_name[100];
    char slot[100];
}appointment_data;
struct Doctor{
int id;
char name[100];
char password[20];
char speciality[100];
char slots[3][100];	
};
struct Doctor doctor_data[10];

struct patient {
    char name[30];
    char phone[12];
    char email[30];
    char gender[8];
    char address[30];
} pinfo;
void Doctor_fetch(struct Doctor *d,int max_doctors);
void doctor(struct Doctor *d);  // Function declaration
//void Appointment_fetch(struct Appointment *A,int id);


//void Appointment_fetch(struct Appointment *A, int id) {
////	Doctor_fetch(doctor_data,10);
////    printf("Attempting to fetch appointments for doctor with ID %d\n", id);
//    // Open the appointment file
//    FILE *appointment_data_ptr = fopen("appointment.txt", "r");
//    if (appointment_data_ptr == NULL) {
//        printf("Error opening file\n");
//        return;
//    }
//
//    int doctor_id;
////    printf("%d is doctor id\n",doctor_id);
//    printf("%d is arg id\n",id);
//    while (fscanf(appointment_data_ptr, "%d", &A->doctor_id ) == 1 ) {
////    fscanf(appointment_data_ptr, "%d", &doctor_id);
////  getchar();
//while (fgetc(appointment_data_ptr) != '\n') {}
//        	printf("%d is doctor id\n",A->doctor_id );
//
//        if (A->doctor_id == id) {
//
//           printf("Found matching doctor ID. Reading appointment details...\n");
//            //appointment_data.doctor_id=doctor_id;
//            // Read the remaining appointment data
//
//            fgets(A->patient_name, sizeof(A->patient_name), appointment_data_ptr);
//            A->patient_name[strcspn(A->patient_name, "\n")] = 0;  // Remove trailing newline
//
//            fgets(A->patient_phone, sizeof(A->patient_phone), appointment_data_ptr);
//            A->patient_phone[strcspn(A->patient_phone, "\n")] = 0;
//
//            fgets(A->patient_email, sizeof(A->patient_email), appointment_data_ptr);
//            A->patient_email[strcspn(A->patient_email, "\n")] = 0;
//
//            fgets(A->patient_gender, sizeof(A->patient_gender), appointment_data_ptr);
//            A->patient_gender[strcspn(A->patient_gender, "\n")] = 0;
//
//            fgets(A->patient_address, sizeof(A->patient_address), appointment_data_ptr);
//            A->patient_address[strcspn(A->patient_address, "\n")] = 0;
//
//            fgets(A->doctor_name, sizeof(A->doctor_name), appointment_data_ptr);
//            A->doctor_name[strcspn(A->doctor_name, "\n")] = 0;
//
//            fgets(A->slot, sizeof(A->slot), appointment_data_ptr);
//            A->slot[strcspn(A->slot, "\n")] = 0;
//
//            // Display the appointment details
//            
//break;
//          
//             // Exit the function after printing the appointment
//        }
//    }
//
//    // If no appointment is found for the given doctor ID
////    printf("No appointments found for doctor ID %d\n", id);
//    fclose(appointment_data_ptr);
//}
void Appointment_fetch(struct Appointment *A, int id) {
    // Open the appointment file
    FILE *appointment_data_ptr = fopen("appointment.txt", "r");
    if (appointment_data_ptr == NULL) {
        printf("Error opening file\n");
        return;
    }

    // Temporary variable to hold doctor_id from the file
    int doctor_id;

    // Use a for loop to process each appointment
    for (;;) {
        // Read doctor ID from the file
        if (fscanf(appointment_data_ptr, "%d", &doctor_id) != 1) {
            break;  // End of file reached or failed to read doctor_id
        }

        // Skip the newline after reading doctor_id
        while (fgetc(appointment_data_ptr) != '\n') {}

        // Check if the doctor_id matches the passed id
        if (doctor_id == id) {
            printf("Found matching doctor ID %d. Reading appointment details...\n", doctor_id);

            // Store the doctor_id in the structure
            A->doctor_id = doctor_id;

            // Read the remaining appointment data and store it in the structure
            fgets(A->patient_name, sizeof(A->patient_name), appointment_data_ptr);
            A->patient_name[strcspn(A->patient_name, "\n")] = 0;  // Remove trailing newline

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

            // Exit the loop after reading the appointment for the matching doctor
            break;
        } else {
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
    if (ftell(appointment_data_ptr) == 0) {
        printf("No appointments found for doctor ID %d\n", id);
    }

    // Close the file
    fclose(appointment_data_ptr);
}
void Doctor_fetch(struct Doctor *d, int max_doctors) {
    FILE *doctor_data_ptr = fopen("doctor2.txt", "r");  // Open the file in read mode
    
    if (doctor_data_ptr == NULL) {
        printf("Error opening file\n");
        return;
    }

    int i = 0;
    // Read doctor data from the file
    while (i < max_doctors && fscanf(doctor_data_ptr, "%d\n", &d[i].id) == 1) {
        // Read password, name, speciality, and slots
        fgets(d[i].password, sizeof(d[i].password), doctor_data_ptr);
        d[i].password[strcspn(d[i].password, "\n")] = 0;  // Remove the trailing newline

        fgets(d[i].name, sizeof(d[i].name), doctor_data_ptr);
        d[i].name[strcspn(d[i].name, "\n")] = 0;  // Remove the trailing newline

        fgets(d[i].speciality, sizeof(d[i].speciality), doctor_data_ptr);
        d[i].speciality[strcspn(d[i].speciality, "\n")] = 0;  // Remove the trailing newline

        // Read the 3 slots for the doctor
        for (int j = 0; j < 3; j++) {
            fgets(d[i].slots[j], sizeof(d[i].slots[j]), doctor_data_ptr);
            d[i].slots[j][strcspn(d[i].slots[j], "\n")] = 0;  // Remove the trailing newline
        }

        i++;
    }

    fclose(doctor_data_ptr);  // Close the file after reading
}

void appointmentdata(struct Doctor *d,struct patient *p, int id,int slot) {

Doctor_fetch(d,10);
	// appointment
        FILE *ptr = fopen("appointment.txt", "a"); // Open file in append mode to add new appointments
    if (ptr == NULL) {
        printf("Error opening file\n");
        return;
    }
    fprintf(ptr, "%d\n%s\n%s\n%s\n%s\n%s\n%s\n", 
            id, p->name, p->phone, p->email, p->gender, p->address,d[id-1].name);
           switch(slot){
           	case 1:
           	fprintf(ptr,"%s\n",d[id-1].slots[0]);
            break;
            case 2:
           	fprintf(ptr,"%s\n",d[id-1].slots[1]);
            break;
            case 3:
           	fprintf(ptr,"%s\n",d[id-1].slots[2]);
            break;
		   }
			
  fclose(ptr); // Close the file after writing
}

int main() {
    int role;
    int stop=0;
    
    
//    Appointment_fetch(&appointment_data,2);  
//		  	printf("Appointments for Doctor %d\n", appointment_data.doctor_id);
//		  	printf("\nPatient Name: %s\n", appointment_data.patient_name);
//            printf("Patient Phone: %s\n", appointment_data.patient_phone);
//            printf("Patient Email: %s\n", appointment_data.patient_email);
//            printf("Patient Gender: %s\n", appointment_data.patient_gender);
//            printf("Patient Address: %s\n", appointment_data.patient_address);
//            printf("Slot: %s\n", appointment_data.slot);
//            printf("-----------------------------\n");
             printf("1.Patient\n2.Doctor\n3.Receptionist\n4.Exit\nEnter: ");
    scanf("%d", &role);
   while(stop==0){
   	
   	 
    switch (role) {
        case 1:
            patient();
            break;
        case 2:
            doctor(doctor_data);  // Call doctor function
            break;
        case 3:
            receptionist();  // Call receptionist function
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice\n");
    }
   }
    if(!doctor_data[0].name){
    printf("kaam band hai ");	
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
   
    int speciality, which_doctor,slot;

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
    printf("1. Cardiologist\n2. Gynecologist\n3. Urologist\n4. Neurologist\n5. Dermatologist\n6. Exit\nEnter: ");
    scanf("%d", &speciality);
    switch (speciality) {
        case 1:
            printf("Best Cardiologists:\n");
            printf("1. Dr Muhammad Faisal Khanzada\n2. Dr. Asad Pathan\nEnter: ");
            scanf("%d", &which_doctor);
            printf("Select time slot :\n");
            printf("1.Mon-Tue: 9AM-5PM\n2.Wed-Fri: 10AM-2PM\n3.Sat:12PM-6PM\n");
            printf("Enter :");
            scanf("%d",&slot);
            if (which_doctor < 1 || which_doctor > 2) {
                printf("Invalid choice\n");
                return;
            }
            
               { 
			    int id = doctors_id(which_doctor, speciality);
                appointmentdata(doctor_data,&pinfo,id,slot);
               }
            break;
        case 2:
           printf("Best Gynecologists:\n");
            printf("1. Dr. Asma Jabeen\n2. Dr. Azra Shamsi\nEnter: ");
            scanf("%d", &which_doctor);
            printf("Select time slot :\n");
            printf("1.Mon-Tue: 9AM-5PM\n2.Wed-Fri: 10AM-2PM\n3.Sat:12PM-6PM\n");
            printf("Enter :");
            scanf("%d",&slot);
            if (which_doctor < 1 || which_doctor > 2) {
                printf("Invalid choice\n");
                return;
            }
               { 
			    int id = doctors_id(which_doctor, speciality);
                appointmentdata(doctor_data,&pinfo,id,slot);
               }
            break;
        case 3:
            printf("Best Urologists:\n");
            printf("1. Prof. Dr. Muhammad Farooq\n2. Dr. Muhammad Imran Malik\nEnter: ");
            scanf("%d", &which_doctor);
            printf("Select time slot :\n");
            printf("1.Mon-Tue: 9AM-5PM\n2.Wed-Fri: 10AM-2PM\n3.Sat:12PM-6PM\n");
            printf("Enter :");
            scanf("%d",&slot);
            if (which_doctor < 1 || which_doctor > 2) {
                printf("Invalid choice\n");
                return;
            }
            
               { 
			    int id = doctors_id(which_doctor, speciality);
                appointmentdata(doctor_data,&pinfo,id,slot);
               }
            break;
        case 4:
            printf("Best Neurologists:\n");
            printf("1. Dr. Tabinda Batool\n2. Prof. Dr. Arif Herekar\nEnter: ");
            scanf("%d", &which_doctor);
            printf("Select time slot :\n");
            printf("1.Mon-Tue: 9AM-5PM\n2.Wed-Fri: 10AM-2PM\n3.Sat:12PM-6PM\n");
            printf("Enter :");
            scanf("%d",&slot);
            if (which_doctor < 1 || which_doctor > 2) {
                printf("Invalid choice\n");
                return;
            }
            
                { 
			    int id = doctors_id(which_doctor, speciality);
                appointmentdata(doctor_data,&pinfo,id,slot);
               }
            break;
        case 5:
            printf("Best Dermatologists:\n");
            printf("1. Dr. Muhammad Amjad\n2. Dr. Aisha Ahmad\nEnter: ");
            scanf("%d", &which_doctor);
            printf("Select time slot :\n");
            printf("1.Mon-Tue: 9AM-5PM\n2.Wed-Fri: 10AM-2PM\n3.Sat:12PM-6PM\n");
            printf("Enter :");
            scanf("%d",&slot);
            if (which_doctor < 1 || which_doctor > 2) {
                printf("Invalid choice\n");
                return;
            }
            
               { 
			    int id = doctors_id(which_doctor, speciality);
                appointmentdata(doctor_data,&pinfo,id,slot);
               }
            break;
        case 6:
            return;
        default:
            printf("Invalid choice\n");
    }
}

int doctors_id(int which_doctor, int speciality) {
    int res = (speciality - 1) * 2 + (which_doctor); 
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

void doctor(struct Doctor *d) {
    char password[20];
    int found = 0;
	int choice;
	int doc_id;
	
    

    printf("You are in the doctor section\n");
    printf("Enter your password: ");
   scanf("%s",password);

 Doctor_fetch(doctor_data,10);

    for (int i = 0; i < 10; i++) {
        if (strcmp(password, d[i].password) == 0) {
            printf("Welcome doctor %s\n", d[i].name);
            found = 1;
            doc_id=d[i].id;
            break;
        }
    }

    if (!found) {
        printf("Invalid password. Please try again.\n");
    }else{
    	printf("Id for doctor is %d",doc_id);
    	 printf("1.Scheduled Appointments\n2.exit\n ");
    	 printf("Enter :");
    	 scanf("%d",&choice);
    	 getchar();
    switch(choice){
     case 1:
    	 Appointment_fetch(&appointment_data,doc_id);  
		  	printf("Appointments for Doctor %s\n", appointment_data.doctor_name);
		  	printf("\nPatient Name: %s\n", appointment_data.patient_name);
            printf("Patient Phone: %s\n", appointment_data.patient_phone);
            printf("Patient Email: %s\n", appointment_data.patient_email);
            printf("Patient Gender: %s\n", appointment_data.patient_gender);
            printf("Patient Address: %s\n", appointment_data.patient_address);
            printf("Slot: %s\n", appointment_data.slot);
            printf("-----------------------------\n");
    	break;
    	case 2:
    	break;
    	default:
		break;											    	
	}
	
    	    
	}
   
}

void receptionist() {
    printf("You are in the receptionist section\n");
    // Add any specific logic for the receptionist section here.
}
