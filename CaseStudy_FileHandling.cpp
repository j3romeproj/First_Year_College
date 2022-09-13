/*                                            Case Study AY 2021-2022
                                                  File Handling

    Create a file for the define a set of employee records that will have the following fields:

    Employee Structure:
    
    Employee Number         10 characters
    Employee Name           15 characters
    Status Code             R or C
    Hours Worked            999
    Deductions              99999.99

    The program will have the following requirements:

    1. Created file may be in text or binary file processing modes.
    2. Input the required data for the following fields for n employees.
    3. Status code R is for Regular and C is for Casual.
    4. If status code is R, input a basic salary amount 
    and check if the employee exceeded 160 hours of work for the month. 
    If employee exceeded 160 hours of work for the month, basic rate is basic pay amount divided by 160 hours. 
    Overtime rate is 0.5 more than his/her basic rate. Compute for Overtime pay.
    Note: Overtime hour/s is hours worked > 160.
    5. If status code is C, then input basic rate. 
    Basic salary amount is equivalent to 160 hours worked multiplied by basic rate. 
    If hours worked exceeds 160 hours then the employee is entitled to an Overtime pay which is 0.5 more than his/her basic rate. 
    Compute for Overtime pay.
    Note: Overtime hour/s is hours worked > 160.
    6. Compute for Net pay using the formula
    Net pay = Basic Pay + Overtime pay – Deductions */
    
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<process.h>

struct record                                             // Structure for records
{ charnum[10];
  charname[15];
  charstatuscode[1];
  floathoursworked;
  floatdeduction;
}employee;

float basic_pay, basic_rate, net_pay, overtime_pay;       // Declaration of variables
char ans;
void restrict();                                          // Function Prototyping
float overtime(float x, float y);

main()                                                    // Main Function
{   FILE *fp;                                             // File Creation
      fp = fopen("employee.txt","a");                     // File opening / named employee.txt, append
      if(fp==NULL){                                       //  if file is not created successfully
        printf("Filecannotbecreated!");
        exit(1);
      }
      
      do{
        printf("\n\tEnterEmployees'");                    // Printing 
        printf("\n\t\tName:");
          scanf("\n");                                    // Getting the user's input for employee name
        printf("\t\tNumber:");                            // Printing
          scanf("\n");
          gets(employee.num);                             // Getting the user's input for employee number
        printf("\t\tStatus[R/C]:");                       // Printing
          scanf("\n");
          gets(employee.statuscode);                      // Getting the user's input for employee status
          restrict();                                     // Restrictions
        if(stricmp(employee.statuscode,"R") == 0){        // If the user input R 
          printf("\t\tBasicSalary:");
            scanf("%f",&basic_pay);
          basic_rate=basic_pay/160;
        }else if(stricmp(employee.statuscode,"C") == 0){  // If the user input C 
          printf("\t\tBasicRate:");
            scanf("%f",&basic_rate);
          basic_pay=basic_rate*160;
        }
        printf("\t\tHour/sWorked:");                      // Printing
          scanf("%f",&employee.hoursworked);              // data stored at employee.hoursworked
        printf("\t\tDeduction:");                         // Printing
          scanf("%f",&employee.deduction);                // employee.deduction
          
        fprintf(fp,"\nEmployeeName: %s\nEmployee Number: %s\nEmployee Status: %s\nEmployee Hour/s Worked: %.2f
                    \nEmployee Deduction: %.2f\nEmployee Basic Salary: %.2f\nEmployee Basic Rate: %.2f\n\n"
                    ,employee.name, employee.num, employee.statuscode, employee.hoursworked, employee.deduction, basic_pay,basic_rate);
                    
        printf("\n\tDo you want to add more employee?");
          scanf("%s",&ans);
        
        system("cls");
      }
      while(ans == 'Y'||ans == 'y');
      
      fclose(fp);                                         // file close
      
    system("cls");
      fp = fopen("employee.txt","r");                     // file open and read
      if(fp==NULL){                                       // if file is not created successfully
        printf("File cannot be opened for reading!");
        exit(1);
      }
      
      printf("\n\t\t\t\t\t\tAl Submarsan Vilencia Corporation\n\t\t\t\t\t\t\tMakati City\n\n\t\t\t\t\t\t\tPayroll\n");
      printf("\n\tEmployee Number\tEmployee Name\tStatus\tBasic Salary\tOvertime Pay\tDeduction\tNet Pay\n\n");
      
      while(fscanf(fp,"\nEmployee Name: %s\nEmployee Number: %s\nEmployee Status: %s\nEmployee Hour/s Worked: %f
                       \nEmployee Deduction: %f\nEmployee Basic Salary: %f\nEmployee Basic Rate: %f\n\n"
                       , &employee.name, &employee.num, &employee.statuscode, &employee.hoursworked, &employee.deduction, &basic_pay, &basic_rate)
                       != EOF){                                             // scan and save data on the file
      
      if(stricmp(employee.statuscode,"R") == 0){                            //If the input status was R
        overtime_pay = 0;
        overtime_pay = overtime(basic_rate, employee.hoursworked);
        strcpy(employee.statuscode,"Regular");                              // R = Regular 
        net_pay = basic_pay + overtime_pay - employee.deduction;            // Netpay is basic pay + overtime pay - deduction
        printf("\t%10s\t%15s\t%s%16.2f%16.2f%13.2f%18.2f\n", employee.num, employee.name, employee.statuscode, basic_pay, overtime_pay, employee.deduction, net_pay);
      } else if(stricmp(employee.statuscode,"C") == 0){                     // If the input status was C, then the formula for casual overtime pay is used 
        overtime_pay = 0;
        overtime_pay = overtime(basic_rate, employee.hoursworked);
        strcpy(employee.statuscode,"Casual");                               // C = Casual
        net_pay = basic_pay + overtime_pay - employee.deduction;            // Netpay is basic pay + overtime pay - deduction
        printf("\t%10s\t%15s\t%s%17.2f%16.2f%13.2f%18.2f\n", employee.num, employee.name, employee.statuscode, basic_pay, overtime_pay, employee.deduction, net_pay);
      }
    }
    
    fclose(fp);                                                             // File close 

  getch();
  return0;
}                                                                           
// function definition
void restrict()                                                             // Function restriction if ever the user input a different data
{ while(stricmp(employee.statuscode,"R") != 0 && stricmp(employee.statuscode,"C") != 0){
    system("cls");
    printf("\n\t===================================================");
    printf("\n\tERROREnteredCode!");
    printf("\n\tEnter:");
    printf("\n\t\tR=Regular");
    printf("\n\t\tC=Casual");
    printf("\n\t===================================================");
    printf("\n\n\tEnterEmployees'");
    printf("\n\t\tName:%s", employee.name);
    printf("\n\t\tNumber:%s", employee.num);
    printf("\n\t\tStatus[R/C]:");
      gets(employee.statuscode);
      
    system("cls");
    printf("\n\tEnterEmployees'");
    printf("\n\t\tName:%s", employee.name);
    printf("\n\t\tNumber:%s", employee.num);
    printf("\n\t\tStatus[R/C]:%s\n", employee.statuscode);
  }
}

float overtime(float x, float y)                                          // function for overtime pay
{ float etime;                                                            // excess time 
  float overtime_rate;
  
  if(y > 160){                                                            // y = employee.hoursworked
    etime = y - 160;                                                      // excess time = employee.hoursworked - 160
    overtime_rate = x *1.5;                                               // x = basic_rate | multiplied by 1.5 
    overtime_pay = etime * overtime_rate;                                 // overtime_pay = excess time multiplied by overtime rate
  }
  
  return overtime_pay;
}
