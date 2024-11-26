#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void patient();
void doctor();  // Function declaration
void receptionist();  // Function declaration
void appointment();
void emergency();
int doctors_id(int which_doctor, int speciality);
struct Doctor{
char name[100];
char speciality[100];
char slots[3][100];	
}doctor_data[10];
struct patient {
    char name[30];
    char phone[12];
    char email[30];
    char gender[8];
    char address[30];
} pinfo;

void appointmentdata(struct Doctor *d,struct patient *p, int id,int slot) {
    FILE *ptr;
    FILE *doctor_data_ptr;
    //doctor
    doctor_data_ptr=fopen("doctor.txt","r");
    if(doctor_data_ptr==NULL){
    	printf("Error in opening file");
	}
	for(int i=0;i<10;i++){
		
		fgets(d[i].name,sizeof(d[i].name),doctor_data_ptr);
		d[i].name[strcspn(d[i].name,"/n")]=0;
		fgets(d[i].speciality,sizeof(d[i].speciality),doctor_data_ptr);
		d[i].speciality[strcspn(d[i].speciality,"\n")]=0;
		for(int j=0;j<3;j++){
		fgets(d[i].slots[j],sizeof(d[i].slots[j]),doctor_data_ptr);
	  	d[i].slots[j][strcspn(d[i].slots[j],"\n")]=0;	
		}
		


	}
	
	// appointment
    ptr = fopen("appointment.txt", "a"); // Open file in append mode to add new appointments
    if (ptr == NULL) {
        printf("Error opening file\n");
        return;
    }
    fprintf(ptr, "doctor_id: %d , Name: %s , Phone: %s , Email: %s , Gender: %s , Address: %s , Doctor: %s", 
            id, p->name, p->phone, p->email, p->gender, p->address,d[id-1].name);
           switch(slot){
           	case 1:
           	fprintf(ptr," , Slot: %s\n",d[id-1].slots[0]);
            break;
            case 2:
           	fprintf(ptr," , Slot: %s\n",d[id-1].slots[1]);
            break;
            case 3:
           	fprintf(ptr," , Slot: %s\n",d[id-1].slots[2]);
            break;
		   }
			
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
    printf("%s",doctor_data[0].name);
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

void doctor() {
    printf("You are in the doctor section\n");
    // Add any specific logic for the doctor section here.
}

void receptionist() {
    printf("You are in the receptionist section\n");
    // Add any specific logic for the receptionist section here.
}
