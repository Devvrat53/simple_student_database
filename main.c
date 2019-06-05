#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    char name[20];
    int rollNo;
    char branch[20];
    int yearOfAdmission;
    char email[30];
    int n1,n2,n3,total;
    struct node *next;
};

struct node *start = NULL;
struct node *create(struct node *);
struct node *display(struct node *);
struct node *length(struct node *);
struct node *searchByRollNo(struct node *);
struct node *searchByName(struct node *);
struct node *insertBeg(struct node *);
struct node *insertEnd(struct node *);
struct node *insertBefore(struct node *);
struct node *insertAfter(struct node *);
struct node *deleteBeg(struct node *);
struct node *deleteEnd(struct node *);
struct node *deleteNode(struct node *);
struct node *deleteDuplicate(struct node *);
struct node *deleteList(struct node *);
struct node *sortByRollNo(struct node *);  //Sorting according to the Roll No
struct node *sortByTotalMarks(struct node *start); //Sorting according to Total Marks
struct node *sortByAdmissionYear(struct node *); //Sorting according to the Year of Admission

int main()
{
    int option;

    do
    {
        printf("\n****COLLEGE DATABASE****");
        printf("\n1.Create a Database!");
        printf("\n2.Display.");
        printf("\n3.No. of Data entered of the Student!");
        printf("\n4.Search a particular Student by his Roll No.");
        printf("\n5.Search a particular Student by his Name.");
        printf("\n6.Insert Data at the Beginning.");
        printf("\n7.Insert Data at the End.");
        printf("\n8.Insert Student's Data before a particular Roll No.");
        printf("\n9.Insert Student's Data after a particular Roll No.");
        printf("\n10.Delete a Student's Data at the Beginning.");
        printf("\n11.Delete a Student's Data from the End.");
        printf("\n12.Delete a Student's Data.");
        printf("\n13.Delete a Duplicate Record of the Students.");
        printf("\n14.Erase Entire Record!");
        printf("\n15.Sort the Student's Record according to the Roll No.");
        printf("\n16.Sort the Student's Record according to the Total Marks.");
        printf("\n17. Sort the Student's Record according to the Year of Admission");
        printf("\n18.Exit!");
        printf("\nEnter your choice:");
        scanf("%d", &option);
        switch(option)
        {
            case 1:start = create(start);
            printf("\nDATABASE CREATED.\n\n");
            break;
            case 2: start = display(start);
            break;
            case 3: start = length(start);
            break;
            case 4: start = searchByRollNo(start);
            break;
            case 5: start = searchByName(start);
            break;
            case 6: start = insertBeg(start);
            break;
            case 7: start = insertEnd(start);
            break;
            case 8: start = insertBefore(start);
            break;
            case 9: start = insertAfter(start);
            break;
            case 10: start = deleteBeg(start);
            break;
            case 11: start = deleteEnd(start);
            break;
            case 12: start = deleteNode(start);
            break;
            case 13: start = deleteDuplicate(start);
            break;
            case 14: start = deleteList(start);
            break;
            case 15: start = sortByRollNo(start);
            break;
            case 16:start = sortByTotalMarks(start);
            break;
            case 17:start = sortByAdmissionYear(start);
            break;
        }
    }while(option != 18);
    return 0;
}
struct node *create(struct node *start)
{
    struct node *new_node, *ptr;
    if(start == NULL)
    {
        new_node=(struct node*)malloc(sizeof(struct node));
        printf("Enter the name of the student:");
        scanf("%s", new_node->name);
        printf("Enter the roll no of the student:");
        scanf("%d", &new_node->rollNo);
        printf("Enter the branch of the student:");
        scanf("%s", new_node->branch);
        printf("Enter the year of admission of the student:");
        scanf("%d", &new_node->yearOfAdmission);
        printf("Enter the email_id of the student:");
        scanf("%s", new_node->email);
        printf("Enter the marks of the student in Data Structure:");
        scanf("%d",&new_node->n1);
        printf("Enter the marks of the student in DLDA:");
        scanf("%d",&new_node->n2);
        printf("Enter the marks of the student in Maths:");
        scanf("%d",&new_node->n3);
        new_node->total=new_node->n1+new_node->n2+new_node->n3;
        new_node->next = NULL;
        start = new_node;
    }
    else
    {
        ptr = start;
        new_node=(struct node *)malloc(sizeof(struct node));

        printf("Enter the name of the student:");
        scanf("%s",new_node->name);
        printf("Enter the roll no of the student:");
        scanf("%d",&new_node->rollNo);
        printf("Enter the branch of the student:");
        scanf("%s",new_node->branch);
        printf("Enter the year of admission of the student:");
        scanf("%d",&new_node->yearOfAdmission);
        printf("Enter the email_id of the student:");
        scanf("%s",new_node->email);
        printf("Enter the marks of the student in Data Structure:");
        scanf("%d",&new_node->n1);
        printf("Enter the marks of the student in DLDA:");
        scanf("%d",&new_node->n2);
        printf("Enter the marks of the student in Maths:");
        scanf("%d",&new_node->n3);
        new_node->total=new_node->n1+new_node->n2+new_node->n3;
        while(ptr->next != NULL)
            ptr = ptr->next;

        ptr->next = new_node;
        new_node->next=NULL;
    }
    return start;
    }

struct node *display(struct node *start)
{
     struct node *current;

     current = start;
     if(current == NULL)
     {
        printf("No element in the database.\n");
     }
     else
     {
         printf("\n*********************Student Database*******************");
         printf("\nName\tRoll No\t\tBranch\tYear Of Admission\tEmail ID\tData Structure\tDLDA\tMaths\tTotal marks");
         printf("\n-----------------------------------------------------------------------------------------------------------------------------");
         while(current!=NULL)
         {
            printf("\n%s\t %d\t\t %s\t\t %d\t\t %s\t\t %d\t\t %d\t %d\t\t %d", current->name, current->rollNo, current->branch, current->yearOfAdmission, current->email,current->n1,current->n2,current->n3,current->total);
            current = current->next;
         }
           printf("\n%s\t %d\t\t %s\t\t %d\t\t %s\t\t %d\t\t %d\t %d\t\t %d", current->name, current->rollNo, current->branch, current->yearOfAdmission, current->email,current->n1,current->n2,current->n3,current->total);
     }
     return start;
}

struct node *length(struct node *start)
{
    int num = 0;
    struct node *ptr;
    ptr = start;
    while(ptr!= NULL)
    {
        num+=1;
        ptr = ptr->next;
    }
    printf("\nThe No. of data present in the List=%d", num);
    return start;
}

struct node *searchByRollNo(struct node *start)
{
    struct node *ptr;
    int rollNo;
    printf("\nEnter the Student's Roll No=");
    scanf("%d", &rollNo);
    ptr = start;
    while(ptr != NULL)
    {
        if(ptr->rollNo == rollNo)
        {
            printf("\nStudent found!");
            printf("\nName\t Roll No\t Branch\t\t Year Of Admission\tEmail ID\tMarks obtained in Data Structure\tMarks obtained in DLDA\t\tMarks obtained in Maths\t\t Total marks");
            printf("\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
            printf("\n%s\t %d\t\t %s\t\t %d\t\t\t %s\t\t\t %d\t\t\t\t\t\t %d\t\t\t\t\t %d\t\t\t%d", ptr->name, ptr->rollNo, ptr->branch, ptr->yearOfAdmission, ptr->email,ptr->n1,ptr->n2,ptr->n3,ptr->total);
            return start;
        }
        ptr = ptr->next;
    }
    printf("\nNo such Student present in the database!");
    return start;
}

struct node *searchByName(struct node *start)
{
    struct node *ptr;
    char name[20];
    //int rollNo;
    ptr = start;
    printf("\nEnter the Student's Name=");
    scanf("%s", ptr->name);
    while(ptr != NULL)
    {
        if(strcmp(ptr->name, name) == 0)
        {
            printf("\nStudent found!");
            printf("\nName\t Roll No\t Branch\t\t Year Of Admission\tEmail ID\tMarks obtained in Data Structure\tMarks obtained in DLDA\t\tMarks obtained in Maths\t\t Total marks");
            printf("\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
            printf("\n%s\t %d\t\t %s\t\t %d\t\t\t %s\t\t\t %d\t\t\t\t\t\t %d\t\t\t\t\t %d\t\t\t%d",ptr->name, ptr->rollNo, ptr->branch, ptr->yearOfAdmission, ptr->email,ptr->n1,ptr->n2,ptr->n3,ptr->total);
            return start;
        }
        ptr = ptr->next;
    }
    printf("\nNo such Student present in the database!");
    return start;
}

struct node *insertBeg(struct node *start)
{
    struct node *ptr;
    //int rollNo,yearOfAdmission;
     ptr=(struct node *)malloc(sizeof(struct node));

    printf("Enter the name of the student:");
    scanf("%s",ptr->name);
    printf("Enter the roll no of the student:");
    scanf("%d",& ptr->rollNo);
    printf("Enter the branch of the student:");
    scanf("%s", ptr->branch);
    printf("Enter the year of admission of the student:");
    scanf("%d",& ptr->yearOfAdmission);
    printf("Enter the email_id of the student:");
    scanf("%s", ptr->email);
    printf("Enter the marks of the student in Data Structure:");
    scanf("%d",&ptr->n1);
    printf("Enter the marks of the student in DLDA:");
    scanf("%d",&ptr->n2);
    printf("Enter the marks of the student in Maths:");
    scanf("%d",&ptr->n3);
    ptr->total=ptr->n1+ptr->n2+ptr->n3;
    ptr->next = start;
    start = ptr;
    return start;
}

struct node *insertEnd(struct node *start)
{
    struct node *ptr, *new_node;
    //int rollNo,yearOfAdmission;
    ptr = start;
    new_node = (struct node *)malloc(sizeof(struct node));

    printf("Enter the name of the student:");
    scanf("%s", new_node->name);
    printf("Enter the roll no of the student:");
    scanf("%d", &new_node->rollNo);
    printf("Enter the branch of the student:");
    scanf("%s", new_node->branch);
    printf("Enter the year of admission of the student:");
    scanf("%d", &new_node->yearOfAdmission);
    printf("Enter the email_id of the student:");
    scanf("%s", new_node->email);
    printf("Enter the marks of the student in Data Structure:");
    scanf("%d",&new_node->n1);
    printf("Enter the marks of the student in DLDA:");
    scanf("%d",&new_node->n2);
    printf("Enter the marks of the student in Maths:");
    scanf("%d",&new_node->n3);
    new_node->total=new_node->n1+new_node->n2+new_node->n3;
    while(ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = new_node;
    new_node->next = NULL;
    return start;
}

struct node *insertBefore(struct node *start)
{
    struct node *new_node, *ptr, *preptr;
    int num;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the Roll No before which the Student's data is to be inserted=");
    scanf("%d", &num);
    printf("\nEnter the name of the Student=");
    scanf("%s", new_node->name);
    printf("\nEnter the Roll no=");
    scanf("%d", &new_node->rollNo);
    printf("\nEnter the Branch of the Student=");
    scanf("%s", new_node->branch);
    printf("\nEnter the year of Admission=");
    scanf("%d", &new_node->yearOfAdmission);
    printf("\nEnter the Email ID=");
    scanf("%s", new_node->email);
    printf("Enter the marks of the student in Data Structure:");
    scanf("%d",&new_node->n1);
    printf("Enter the marks of the student in DLDA:");
    scanf("%d",&new_node->n2);
    printf("Enter the marks of the student in Maths:");
    scanf("%d",&new_node->n3);
    new_node->total=new_node->n1+new_node->n2+new_node->n3;
    ptr = start;
    while(ptr->rollNo != num)
    {
         preptr = ptr;
         ptr = ptr->next;
    }
    preptr->next = new_node;
    new_node->next = ptr;
    return start;
}

struct node *insertAfter(struct node *start)
{
    struct node *new_node, *ptr, *preptr;
    int num;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the Roll No after which the Student's data is to be inserted=");
    scanf("%d", &num);
    printf("\nEnter the name of the Student=");
    scanf("%s", new_node->name);
    printf("\nEnter the Roll no=");
    scanf("%d", &new_node->rollNo);
    printf("\nEnter the Branch of the Student=");
    scanf("%s", new_node->branch);
    printf("\nEnter the year of Admission=");
    scanf("%d", &new_node->yearOfAdmission);
    printf("\nEnter the Email ID=");
    scanf("%s", new_node->email);
    printf("Enter the marks of the student in Data Structure:");
    scanf("%d",&new_node->n1);
    printf("Enter the marks of the student in DLDA:");
    scanf("%d",&new_node->n2);
    printf("Enter the marks of the student in Maths:");
    scanf("%d",&new_node->n3);
    new_node->total=new_node->n1+new_node->n2+new_node->n3;
    ptr = start;
    preptr = ptr;
    while(preptr->rollNo != num)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = new_node;
    new_node->next = ptr;
    return start;
}

struct node *deleteBeg(struct node *start)
{
    struct node *ptr;
    ptr = start;
    start = start->next;
    free(ptr);
    return start;
}

struct node *deleteEnd(struct node *start)
{
    struct node *ptr, *preptr;
    ptr = start;
    while(ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    free(ptr);
    return start;
}

struct node *deleteNode(struct node *start)
{
    struct node *ptr, *preptr;
    int roll_no;
    printf("\nEnter the Roll No of the Student to delete his/her data!=");
    scanf("%d", &roll_no);
    ptr = start;
    if(ptr->rollNo == roll_no)
    {
        start = deleteBeg(start);
        return start;
    }
    else
    {
        while(ptr->rollNo != roll_no)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next;
        free(ptr);
        return start;
    }
}

struct node *deleteDuplicate(struct node *start)
{
    struct node *ptr, *p, *q, *prev, *temp;
    ptr = start;
    p = q = prev = ptr;
    q = q->next;
    while (p != NULL)
    {
        while (q != NULL && q->rollNo != p->rollNo)
        {
            prev = q;
            q = q->next;
        }
        if (q == NULL)
        {
            p = p->next;
            if (p != NULL)
            {
                q = p->next;
            }
        }
        else if (q->rollNo == p->rollNo)
        {
            prev->next = q->next;
            temp = q;
            q = q->next;
            free(temp);
        }
    }
    return start;
}

struct node *deleteList(struct node *start)
{
    struct node *ptr;
    if(start != NULL)
    {
        ptr = start;
        while(ptr != NULL)
        {
            start = deleteBeg(ptr);
            ptr = start;
        }
    }
    return start;
}

struct node *sortByRollNo(struct node *start) //Sorting according to Roll No
{
    struct node *ptr1, *ptr2,*temp;
    temp=(struct node *)malloc(sizeof(struct node));
    ptr1 = start;
    while(ptr1 != NULL)
    {
        ptr2 = ptr1->next;
        while(ptr2 != NULL)
        {
            if(ptr1->rollNo > ptr2-> rollNo)
            {
                strcpy(temp->name, ptr1->name);
                temp->rollNo = ptr1->rollNo;
                strcpy(temp->branch, ptr1->branch);
                temp->yearOfAdmission = ptr1->yearOfAdmission;
                strcpy(temp->email, ptr1->email);
                temp->n1 = ptr1->n1;
                temp->n2 = ptr1->n2;
                temp->n3 = ptr1->n3;
                temp->total=ptr1->total;

                strcpy(ptr1->name, ptr2->name);
                ptr1->rollNo = ptr2->rollNo;
                strcpy(ptr1->branch, ptr2->branch);
                ptr1->yearOfAdmission = ptr2->yearOfAdmission;
                strcpy(ptr1->email, ptr2->email);
                ptr1->n1=ptr2->n1;
                ptr1->n2=ptr2->n2;
                ptr1->n3=ptr2->n3;
                ptr1->total=ptr2->total;

                strcpy(ptr2->name, temp->name);
                ptr2->rollNo = temp->rollNo;
                strcpy(ptr2->branch, temp->branch);
                ptr2->yearOfAdmission = temp->yearOfAdmission;
                strcpy(ptr2->email, temp->email);
                ptr2->n1=temp->n1;
                ptr2->n2=temp->n2;
                ptr2->n3=temp->n3;
                ptr2->total=temp->total;


            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return start;
}
struct node *sortByTotalMarks(struct node *start) //Sorting according to Total Marks
{
    struct node *ptr1, *ptr2,*temp;
    temp=(struct node *)malloc(sizeof(struct node));
    ptr1 = start;
    while(ptr1 != NULL)
    {
        ptr2 = ptr1->next;
        while(ptr2 != NULL)
        {
            if(ptr1->total > ptr2-> total)
            {
                strcpy(temp->name, ptr1->name);
                temp->rollNo = ptr1->rollNo;
                strcpy(temp->branch, ptr1->branch);
                temp->yearOfAdmission = ptr1->yearOfAdmission;
                strcpy(temp->email, ptr1->email);
                temp->n1 = ptr1->n1;
                temp->n2 = ptr1->n2;
                temp->n3 = ptr1->n3;
                temp->total=ptr1->total;

                strcpy(ptr1->name, ptr2->name);
                ptr1->rollNo = ptr2->rollNo;
                strcpy(ptr1->branch, ptr2->branch);
                ptr1->yearOfAdmission = ptr2->yearOfAdmission;
                strcpy(ptr1->email, ptr2->email);
                ptr1->n1=ptr2->n1;
                ptr1->n2=ptr2->n2;
                ptr1->n3=ptr2->n3;
                ptr1->total=ptr2->total;

                strcpy(ptr2->name, temp->name);
                ptr2->rollNo = temp->rollNo;
                strcpy(ptr2->branch, temp->branch);
                ptr2->yearOfAdmission = temp->yearOfAdmission;
                strcpy(ptr2->email, temp->email);
                ptr2->n1=temp->n1;
                ptr2->n2=temp->n2;
                ptr2->n3=temp->n3;
                ptr2->total=temp->total;


            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return start;
}
struct node *sortByAdmissionYear(struct node *start)
{
    struct node *ptr1, *ptr2,*temp;
    temp=(struct node *)malloc(sizeof(struct node));
    ptr1 = start;
    while(ptr1 != NULL)
    {
        ptr2 = ptr1->next;
        while(ptr2 != NULL)
        {
            if(ptr1->yearOfAdmission > ptr2->yearOfAdmission)
            {
                strcpy(temp->name, ptr1->name);
                temp->rollNo = ptr1->rollNo;
                strcpy(temp->branch, ptr1->branch);
                temp->yearOfAdmission = ptr1->yearOfAdmission;
                strcpy(temp->email, ptr1->email);
                temp->n1 = ptr1->n1;
                temp->n2 = ptr1->n2;
                temp->n3 = ptr1->n3;
                temp->total=ptr1->total;

                strcpy(ptr1->name, ptr2->name);
                ptr1->rollNo = ptr2->rollNo;
                strcpy(ptr1->branch, ptr2->branch);
                ptr1->yearOfAdmission = ptr2->yearOfAdmission;
                strcpy(ptr1->email, ptr2->email);
                ptr1->n1=ptr2->n1;
                ptr1->n2=ptr2->n2;
                ptr1->n3=ptr2->n3;
                ptr1->total=ptr2->total;

                strcpy(ptr2->name, temp->name);
                ptr2->rollNo = temp->rollNo;
                strcpy(ptr2->branch, temp->branch);
                ptr2->yearOfAdmission = temp->yearOfAdmission;
                strcpy(ptr2->email, temp->email);
                ptr2->n1=temp->n1;
                ptr2->n2=temp->n2;
                ptr2->n3=temp->n3;
                ptr2->total=temp->total;

            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return start;
}
