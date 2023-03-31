#include<stdio.h>
#include<string.h> 

void user_login();
void cast_vote(FILE *lead1b, FILE *lead2b, FILE *lead1g, FILE *lead2g);
void cvoter_id();
void lead_party(FILE *lead1b, FILE *lead2b, FILE *lead1g, FILE *lead2g);
void admin_login(FILE *lead1b, FILE *lead2b, FILE *lead1g, FILE *lead2g);

/*typedef struct student_details
{
    char name[100];
    int roll_no;
    char section;
    char password[100];
}student[100];

typedef struct candidate_details
{
    char name[100];
    int total_votes;
}candidate;*/


int main(){
    FILE *lead1b;
    FILE *lead2b;
    FILE *lead1g; 
    FILE *lead2g;
    lead1b = fopen("lead1b.txt", "a");
    lead2b = fopen("lead2b.txt", "a");
    lead1g = fopen("lead1g.txt", "a");
    lead2g = fopen("lead2g.txt", "a");

    do{
        int choice;
    // char str1[] = "*      *   * * *   * * * * *   * * * * *     \n";
    // char str2[] = " *   *     *   *       *       *  *            \n";
    // char str3[] = "   *       * * *       *       * * * * *        \n";
    // printf("%s", str1);
    // printf("%s", str2);
    // printf("%s", str3);


        printf("1. Admin login\n");
        printf("2. Create voter ID\n");
        printf("3. Cast Vote\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice); 
        switch(choice){
            case 1:
               admin_login(lead1b, lead2b, lead1g, lead2g);
               break;

            case 2:
            //    cvoter_id();
               break;

            case 3:
               cast_vote(lead1b, lead2b, lead1g, lead2g);
               printf("Vote Casted Successfully! :) \n");
               break;

            case 4:
                printf("Thank You!\n");
                return 0;
                break;

            default: 
               printf("Invalid Entry! \n");             
        }
        //break;
    }while(1);

    fclose(lead1b);
    fclose(lead2b);
    fclose(lead1g);
    fclose(lead2g);

    return 0;
} 

void admin_login(FILE *lead1b, FILE *lead2b, FILE *lead1g, FILE *lead2g){

    char userid[100];
    char upwrd[100];
    int n;

    printf("Enter UserId: ");
    scanf("%s", &userid);
    printf("Enter Password: ");
    scanf("%s", &upwrd);

    if(strcmp(userid,"nam2022") == 0){
        if(strcmp(upwrd,"icecream") == 0){
            printf("You have entered as an admin!\n");
            printf("0. Exit\n");
            printf("1. Check leading party\n");
            printf("Enter: ");
            scanf("%d",&n);
            if (n == 1){
                lead_party(lead1b, lead2b, lead1g, lead2g);
            }
        }
    }

    else{
        printf("Not an Admin! Blocked!\n");
    }
}

void cast_vote(FILE *lead1b, FILE *lead2b, FILE *lead1g, FILE *lead2g){
    lead1b = fopen("lead1b.txt", "a");
    lead2b = fopen("lead2b.txt", "a");
    lead1g = fopen("lead1g.txt", "a");
    lead2g = fopen("lead2g.txt", "a");

    int chooseB, chooseG; 
    char pwd[50];
    printf("Caste your vote wisely!\n");
    printf("\nEnter your password: ");
    scanf("%[^\n]s", pwd);

    printf("Please choose your Candidate for School Head Boy \n");
    printf("1. Candidate 1 \n");
    printf("2. Candidate 2 \n");
    printf("Enter : ");
    scanf("%d",&chooseB);

    printf("\n");

    printf("Please choose your Candidate for School Head Girl \n");
    printf("1. Candidate 1 \n");
    printf("2. Candidate 2 \n");
    printf("Enter : ");
    scanf("%d",&chooseG);


    if (chooseB == 1){
        fprintf(lead1b, "%d\n", 1);
    }

    else if (chooseB == 2){
        fprintf(lead2b, "%d\n", 1);
    }

    if (chooseG == 1){
        fprintf(lead1g, "%d\n", 1);
    }

    else if (chooseG == 2){
        fprintf(lead2g, "%d\n", 1);
    }

    fclose(lead1b);
    fclose(lead2b);
    fclose(lead1g);
    fclose(lead2g);
}

void lead_party(FILE *lead1b, FILE *lead2b, FILE *lead1g, FILE *lead2g){
    lead1b = fopen("lead1b.txt", "a+");
    lead2b = fopen("lead2b.txt", "a+");
    lead1g = fopen("lead1g.txt", "a+");
    lead2g = fopen("lead2g.txt", "a+");

    int count1b = 0, count2b = 0, count1g = 0, count2g = 0;
    char ch1, ch2, ch3, ch4;

    for (int i = 0; (ch1 = fgetc(lead1b)) != EOF; i++){
        if (ch1 == '1'){
            count1b++;
        }
    }

    for (int i = 0; (ch2 = fgetc(lead2b)) != EOF; i++){
        if (ch2 == '1'){
            count2b++;
        }
    }

    for (int i = 0; (ch3 = fgetc(lead1g)) != EOF; i++){
        if (ch3 == '1'){
            count1g++;
        }
    }

    for (int i = 0; (ch4 = fgetc(lead2g)) != EOF; i++){
        if (ch4 == '1'){
            count2g++;
        }
    }

    
    printf("\nBoy Candidate 1 has %d votes!\n", count1b);
    printf("Boy Candidate 2 has %d votes!\n", count2b);
    printf("Girl Candidate 1 has %d votes!\n", count1g);
    printf("Girl Candidate 2 has %d votes!\n", count2g);

    printf("\nSo...\n");

    if (count1b == count2b){
        printf("\nBoth Boy Candidates have equal number of votes!\n");
    }

    else if (count1b > count2b){
        printf("\nBoy Candidate 1 leads by %d vote(s)\n", (count1b - count2b));
    }

    else {
        printf("\nBoy Candidate 2 leads by %d vote(s)\n", (count2b - count1b));
    }

    if (count1g == count2g){
        printf("Both Girl Candidates have equal number of votes!\n");
    }

    else if (count1g > count2g){
        printf("Girl Candidate 1 leads by %d vote(s)\n", (count1g - count2g));
    }

    else {
        printf("Girl Candidate 2 leads by %d vote(s)\n", (count2g - count1g));
    }

    printf("\nGraph:\n\n");

    for(int i=0; i<2*count1b; i++){
        printf("%c",178);
    }
    printf("  %d Boy Candidate 1\n",count1b);
    printf("\n");

    for(int i=0; i<2*count2b; i++){
        printf("%c",178);
    }
    printf("  %d Boy Candidate 2 \n",count2b);
    printf("\n");

    for(int i=0; i<2*count1g; i++){
        printf("%c",178);
    }
    printf("  %d Girl Candidate 1\n",count1g);
    printf("\n");

    for(int i=0; i< 2*count2g; i++){
        printf("%c",178);
    }
    printf("  %d Girl Candidate 2\n",count2g);


    fclose(lead1b);
    fclose(lead2b);
    fclose(lead1g);
    fclose(lead2g);
}

void cvoter_id(){

}