#include<stdio.h>
#include<string.h>
#include <stdlib.h>
void patient();
void doctor();
void receptionist();
void appointment();
void emergency();
int doctors_id(int which_doctor,int speciality);

struct patient{
char name[30];
char phone [12];
char email[30];
char gender[8];
char address[30];
}pinfo;
void appointmentdata(struct patient *p,char doctors[10][100],int id){
	 int id1;
    FILE *ptr;
   
    char data[100];
    ptr = fopen("appointment2.txt", "r");
    if (ptr == NULL) {
        printf("Error opening file\n");
        
        return;
    }
//    fscanf(ptr,"%d %s",&id1,data);
//    printf("data :%d %s",id1,data);
//    fprintf(ptr, "%d , %s , %s , %s , %s , %s , %s",id, p->name, p->phone,p->email, p->gender, p->address,doctors[id-1]);
//    fclose(ptr); // Don't forget to close the file
    
}                    
int main(){
int role;
printf("1.Patient\n2.Doctor\n3.Receptionist\n4.Exit\nEnter:");
scanf("%d",&role);
switch(role){
case 1:
patient();
break;
// case 2:
//    doctor();
//    break;
//  case 3:
//   receptionist();
  break;
case 4:
   return 0;

}
return 0;
}
void patient(){
int choice;
printf("\n1.Book Appointment\n2.Emergency\n3.Exit\nEnter");
scanf("%d",&choice);
switch (choice){
case 1:
appointment();
break;
// case 2:
// emergency();
// break;
case 3:
return;
}
return;
}
void appointment(){
char doctors[10][100]={"DR Muhammad Faisal Khanzada(PMC Verified)\n.FCPS, Cardiology, MBBS, LUMHS\n.Experience: 14 Year(s)","Dr. Asad Pathan(PMC Verfied)\n.FACC, FSCAI\n.Experience: 15 Year(s)",
"Dr. Asma Jabeen (PMDC Verified) MBBS , MCPS (Obstetrics & Gynecology))","Dr. Azra Shamsi (PMDC Verified) MBBS, MCPS (Obstetrics & Gynaecology),FCPS",
"Prof. Dr. Muhammad Farooq (PMDC Verified) MBBS, FCPS (Urology), FCPS (Surgery)\n","Dr.Muhammad Imran Malik (PMDC Verified) MBBS, FCPS",
"Dr. Tabinda Batool (PMDC Verified) MBBS, Certified Course in Hypertension by European Society of Hypertension",
"Prof. Dr. Arif Herekar (PMDC Verified) MBBS, MCPS (Medicine), MD Neurology, Masters In Adult Neurology, Masters In Child Neurology","Dr. Muhammad Amjad (PMDC Verified) MBBS, MCPS (Dermatology), FCPS (Dermatology)",
"Dr. Aisha Ahmad (PMDC Verified) MBBS, FCPS (Dermatology), Certified (Aesthetic Medicine)"};
int speciality;
int which_doctor;
printf("Enter your details\n");
printf("FULL NAME: ");
getchar();
fgets(pinfo.name,sizeof(pinfo.name),stdin);
pinfo.name[strcspn(pinfo.name, "\n")] = '\0';
printf("GENDER: ");
fgets(pinfo.gender,sizeof(pinfo.gender),stdin);
pinfo.gender[strcspn(pinfo.gender, "\n")] = '\0';
printf("PHONE NUMBER: ");
fgets(pinfo.phone,sizeof(pinfo.phone),stdin);
getchar();
pinfo.phone[strcspn(pinfo.phone, "\n")] = '\0';
printf("EMAIL: ");
fgets(pinfo.email,sizeof(pinfo.email),stdin);
pinfo.gender[strcspn(pinfo.gender, "\n")] = '\0';
printf("ADSRESS: ");
fgets(pinfo.address,sizeof(pinfo.address),stdin);
pinfo.address[strcspn(pinfo.address, "\n")] = '\0';

printf("Choose Speciality\n");
printf("1.Cardiologist\n2.Gynacologist\n3.Urologist\n4.Neurologist\n5.Dermatologist\n6.Exit\nEnter: ");
scanf("%d",&speciality);
switch(speciality){
case 1:
printf("Best Cardiologist.\n");
printf("1.DR Muhammad Faisal Khanzada(PMC Verified)\n.FCPS, Cardiology, MBBS, LUMHS\n.Experience: 14 Year(s)");
       printf("\n2.Dr. Asad Pathan(PMC Verfied)\n.FACC, FSCAI\n.Experience: 15 Year(s)");
       printf("Enter: ");
       scanf("%d",& which_doctor);
       int id=doctors_id(which_doctor,speciality);
       appointmentdata(&pinfo,doctors,id);
       break;
   case 2:
   printf("Best Gynacologist.\n");
   printf("1.Dr. Asma Jabeen (PMDC Verified) MBBS , MCPS (Obstetrics & Gynecology))\n");
   printf("2.Dr. Azra Shamsi (PMDC Verified) MBBS, MCPS (Obstetrics & Gynaecology),FCPS\n");
    printf("Enter: ");
       scanf("%d",& which_doctor);
break;  
 case 3:
   printf("Best Urologist.\n");
   printf("Prof. Dr. Muhammad Farooq (PMDC Verified) MBBS, FCPS (Urology), FCPS (Surgery)\n");
   printf("Dr.Muhammad Imran Malik (PMDC Verified) MBBS, FCPS\n");
    printf("Enter: ");
       scanf("%d",& which_doctor);
   break;
     case 4:
      printf("Best Neurologist.\n");
      printf("1.Dr. Tabinda Batool (PMDC Verified) MBBS, Certified Course in Hypertension by European Society of Hypertension\n");
      printf("2.Prof. Dr. Arif Herekar (PMDC Verified) MBBS, MCPS (Medicine), MD Neurology, Masters In Adult Neurology, Masters In Child Neurology\n");
      printf("Enter: ");
       scanf("%d",& which_doctor);
      break;
     case 5:
  printf("Best Dermatologist.\n");
printf("1.Dr. Muhammad Amjad (PMDC Verified) MBBS, MCPS (Dermatology), FCPS (Dermatology)\n");
printf("2.Dr. Aisha Ahmad (PMDC Verified) MBBS, FCPS (Dermatology), Certified (Aesthetic Medicine)\n");
printf("Enter: ");
       scanf("%d",& which_doctor);
break;

case 6:
return 1;
}
}
int doctors_id(int which_doctor,int speciality){
	int res;
	res=speciality*2;
	if(which_doctor==1){
		res-=1;
	}
	return res;

}
//void emergency(){
//int choice;
//printf("1.Call Ambulance\n2.Exit\nEnter: ");
//scanf("%d",&choice);
//switch(choice){
//case 1:
//printf("Enter your Adrress: ");
//fgets(pinfo.address,sizeof(pinfo.address),stdin);
//pinfo.address[strcspn(pinfo.address, "\n")] = '\0';
//printf("Enter your phone number: ");
//fgets(pinfo.phone,sizeof(pinfo.phone),stdin);
//getchar();
//printf("We are sending Ambulace.");
//break;
////yeh data receptionist ke pass bhej sakte ho
//case 2:
//retrun 1;
//}


