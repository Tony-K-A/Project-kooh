// Use fadmin for accessing admin content
// Use fuser for accessing user content
//Use fuser_number to access last user number

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define AD 50
#define ad 100

void admin_func();

struct ADMIN_S{
  char name[AD];
  char fname[AD];
  char username[AD];
  char password[AD];
};

struct USER_S{
  char name[AD];
  char fname[AD];
  char username[AD];
  char password[AD];
};

struct PATIENT{
  char name[AD];
  char fname[AD];
  char nid[AD];
  char phone[AD];
  char file_num[AD];
  char cause[AD];
  struct COST{
    char 
  }
};

int main(){
  //Data part
  FILE *fadmin;
  FILE *fuser;
  FILE *fuser_number;
  FILE *temp;
  struct ADMIN_S admin;
  struct USER_S user;
  int adminflag = 0;
  fadmin = fopen("admin.txt", "r");
  int size = 0;
  int u;
  int choice;
  char namee[AD];
  char fnamee[AD];
  char usernamee[AD];
  char passwordd[AD];
  char namee1[AD];
  char fnamee1[AD];
  char usernamee1[AD];
  char passwordd1[AD];
  char username1[AD];
  char password1[AD];
  char str1[ad];
  char str2[ad];
  char str3[ad];
  char str4[ad];
  char str5[ad], str6[ad], str7[ad], str8[ad], str9[ad], str10[ad], str11[ad], str12[ad];
  int open = 0;
  int adminflag1 = 0;  // Use this statement to check if Admin Has logged in or not.
  char str[ad];
  char atstr[ad];
  int i=0;
  int k=0;
  int cnt = 0;
  int lno;
  int ctr = 0;


  //____________________________________________________________________________
  if(fadmin != NULL){  // Checking if admin file is NULL...
      fseek (fadmin, 0, SEEK_END);
      size = ftell (fadmin);
      rewind(fadmin);
  }
  if (size==0){
    adminflag = 1;
  }
  fclose(fadmin);
  switch (adminflag) {   // Admins file functions in NULL and not empty situation...
    case 1:
      printf("Hello admin, welcome to the system...\nPlease enter your information following the instruction.\n");
      printf("Enter name: ");    scanf("%s", admin.name);
      printf("Enter family-name:");    scanf("%s", admin.fname);
      printf("Enter username:");    scanf("%s", admin.username);
      printf("Enter password:");    scanf("%s", admin.password);
      fadmin = fopen("admin.txt", "w");
      fprintf(fadmin, "%s\t%s\t%s\t%s\n", admin.name, admin.fname, admin.username, admin.password);
      fclose(fadmin);
      fuser = fopen("user.txt", "w");
      fclose(fuser);
      u = 0;
      fuser_number = fopen("user_number.txt", "w");
      fprintf(fuser_number, "%d\n", u);
      fclose(fuser_number);
      break;
    case 0:
      fadmin = fopen("admin.txt", "r");    //First entering username and password to gain access to the main program...
      fuser = fopen("user.txt", "r");
      printf("Enter username: "); scanf("%s", username1);
      printf("Enter password: "); scanf("%s", password1);
      while(!feof(fuser)){
        fscanf(fuser, "%s%s%s%s", str1, str2, str3, str4);
        if(strcmp(username1, str3) == 0 && strcmp(password1, str4) == 0){
          open = 1;
          break;
        }
      }
      fscanf(fadmin, "%s%s%s%s", str1, str2, str3, str4);
      if(strcmp(username1, str3) == 0 && strcmp(password1, str4) == 0){
        open = 1;
        adminflag1 = 1;
      }
      if(open == 0){
        printf("\n\nUsername or password is wrong...\nExiting from program...\n");
        exit(1);
      }
      fclose(fadmin);
      fclose(fuser);
      //________________________________________________________________________
      // adminflag1 works correctly
      if(adminflag1 = 1){
      admin_func();
      scanf("%d", &choice);
      switch (choice) { // Admins switch for functions...
        case 1://Adding a new user...
          printf("Enter user information.\n");
          printf("Enter name: "); scanf("%s", user.name);
          printf("Enter family-name: "); scanf("%s", user.fname);
          printf("Enter username: "); scanf("%s", user.username);
          printf("Enter password for username: "); scanf("%s", user.password);
          fuser = fopen ("user.txt", "a");
          fprintf(fuser, "%s\t%s\t%s\t%s\n", user.name, user.fname, user.username, user.password);
          fclose(fuser);
          break;
        case 2://Deleting an existing user...
          fuser = fopen("user.txt", "r");
          temp = fopen("temp.txt", "w");
          printf("Enter information of user to delete account.\n");
          printf("Enter name: ");        scanf("%s", namee1);
          printf("Enter family-name: "); scanf("%s", fnamee1);
          printf("Enter user-name: ");   scanf("%s", usernamee1);
          printf("Enter password: ");    scanf("%s", passwordd1);
          strcat(namee1, fnamee1);
          strcat(usernamee1, passwordd1);
          strcat(namee1, usernamee1);
          while(!feof(fuser)){
            fscanf(fuser, "%s%s%s%s", str5, str6, str7, str8);
            strcat(str5, str6);
            strcat(str7, str8);
            strcat(str5, str7);
            cnt++;
            if(strcmp(str5, namee1) == 0){
              lno = cnt;
            }
          }
          fclose(fuser);
          fclose(temp);
          //Deleting process starts from here...
          fuser = fopen("user.txt", "r");
          temp = fopen("temp.txt", "w");
          while(!feof(fuser) && ctr < cnt){
            fscanf(fuser, "%s%s%s%s", str5, str6, str7, str8);
            ctr++;
            if(ctr != lno && ctr < cnt){
              fprintf(temp, "%s\t%s\t%s\t%s\n", str5, str6, str7, str8);
            }
            else{
            }
          }
          printf("Deleted successfuly.\n");
          fclose(fuser);
          fclose(temp);
          remove("user.txt");
          rename("temp.txt", "user.txt");
        case 3:
          //continue here...
      }
    }
  }
}

void admin_func(){
  printf("Enter your choice.\n");
  printf("1.Add user.\n");
  printf("2.Delete user.\n");
  printf("3.Access to the main program.\n");
}
