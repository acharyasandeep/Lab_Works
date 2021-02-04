#include <stdio.h>
#define SIZE 5
struct student{
    char name[20];
    int rollno;
    char address[40];
    char phone[10];
};
int main()
{
    struct student s1[SIZE];
    struct student s2[SIZE];
    struct student temp;
    int i,j;
    FILE *fp;
    //Writing to a file by taking input from keyboard
    fp=fopen("student_file.dat","wb");
    for(i=0;i<SIZE;i++)
    {
        printf("Enter student[%d] name: ",i+1);
        gets(s1[i].name);
        printf("\nEnter student[%d] roll: ",i+1);
        scanf(" %d",&s1[i].rollno);
        fflush(stdin);
        printf("\nEnter student[%d] address: ",i+1);
        gets(s1[i].address);
        printf("\nEnter students[%d] phone: ",i+1);
        gets(s1[i].phone);
        printf("\n");

    }
    fwrite(s1,sizeof(struct student),SIZE,fp);
    fclose(fp);
    //Opening a file to read
    fp=fopen("student_file.dat","rb");
    fread(s2,sizeof(struct student),SIZE,fp);

    //Sorting according to name

    for(i=0;i<SIZE-1;i++)
    {
        for(j=i;j<SIZE;j++)
        {
            if(strcmp(s2[i].name,s2[j].name)>0)
            {
                temp=s2[i];
                s2[i]=s2[j];
                s2[j]=temp;
            }
        }
    }

    //Display Data

    printf("\nDisplaying Data\n\n");
    for(i=0;i<SIZE;i++)
    {
        printf("\nSTUDENT %d\n\n",i);
        printf("Name: %s\n",s2[i].name);
        printf("Roll no: %d\n",s2[i].rollno);
        printf("Address: %s\n",s2[i].address);
        printf("Phone: %s\n",s2[i].phone);
    }
    fclose(fp);

}
