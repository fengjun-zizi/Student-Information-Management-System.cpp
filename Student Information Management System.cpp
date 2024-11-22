#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void printMainMenu();
int grade[10];
void CountTheNumberOfPeopleInEachBand(int grade[10])
{
    int i =0 ;
    int j;
    int excellent = 0;
    int middle = 0;
    int bad = 0 ;
    for ( i = 0; i < 10; i++)
    {
        if (grade[i] > 70 )
        {
            excellent++;
        }else if (grade[i] > 60 )
        {
            middle++;
        }else
        {
            bad++;
        }   
    }
    printf("优秀的人数：%d",excellent);
    printf("中间层次的人数：%d",middle);
    printf("学习困难：%d\n",bad);
    printf("**************************************\n");
    printf("       请输入1返回主菜单                 \n");
    printf("**************************************\n");
    while (1)
    {
        fflush(NULL);        
        scanf("%d",&j);
        if (j == 1)
        {
            system("clear");
            printMainMenu();
            break;
        }else
        {
            printf("不存在该指令，请重新输入\n");
            
        }
    }
}

void showMaxMin(int grade[10])
{
    int i;
    int j;
    int higest = 0;
    int lowest = 100;
    for ( i = 0; i < 10; i++)
    {
        if (grade[i] > higest)
        {
            higest = grade[i] ;
        }

        if (grade[i] < lowest)
        {
            lowest = grade[i] ;
        }
        
    }
    
    printf("**************************************\n");
    printf("      最高分：%d      最低分：%d           \n",higest,lowest);
    printf("**************************************\n");
    printf("**************************************\n");
    printf("       请输入1返回主菜单                 \n");
    printf("**************************************\n");
    while (1)
    {
        fflush(NULL);
        scanf("%d",&j);
        if (j == 1)
        {
            system("clear");
            printMainMenu();
            break;
        }else
        {
            printf("不存在该指令，请重新输入\n");
            
        }
    }
}

void statisticalTotalAndAverageScores(int grade[10])
{
    int i;
    int sum = 0;
    int average = 0;
    int j ;
    for ( i = 0; i < 10; i++)
    {
        sum = sum + grade[i];

    }
    average = sum / 10;
    printf("**************************************\n");
    printf("      总分：%d      平均分：%d           \n",sum,average);
    printf("**************************************\n");
    printf("       请输入1返回主菜单                 \n");
    printf("**************************************\n");
    while (1)
    {
        fflush(NULL);
        scanf("%d",&j);
        if (j == 1)
        {
            system("clear");
            printMainMenu();
            break;
        }else
        {
            printf("不存在该指令，请重新输入\n");
            
        }
    }
    
    
}

void printStudentGrade(int grade[10])
{
    int i;
    int  j;
    int x;
    printf("            学生成绩       \n");
    printf("学号              成绩 \n");
    for ( j = 0; j < 10; j++)
    {
        printf("%d               %d\n",1001 + j,grade[j]);
    }

    printf("**************************************\n");
    printf("       请输入1返回主菜单                 \n");
    printf("**************************************\n");
    while (1)
    {
        fflush(NULL);
        scanf("%d",&x);
        if (x == 1)
        {
            system("clear");
            printMainMenu();
            break;
        }else
        {
            printf("不存在该指令，请重新输入\n");
            
        }
    }

}

void studentGrade(int grade[10])
{
    int i = 1;
    int  gradeTemp;
    printf("请依次输入学生的成绩（退出：-1）\n");
    while (1)
    {
        printf("第%d个学生的成绩：",i);
        //fflush(NULL);
        scanf("%d",&gradeTemp);
        if (gradeTemp >= 0 && gradeTemp <= 100)
        {
            grade[i-1] = gradeTemp; 
        }else if (gradeTemp == -1)
        {
            printf("输入结束\n");
            printf("\n\n\n\n");
            system("clear");
            printMainMenu();
            break;
        }else 
        {
            printf("输入有误，请重新输入\n");
            while (1)
            {
                printf("第%d个学生的成绩：",i);
                scanf("%d",&gradeTemp);
                grade[i-1] = gradeTemp; 
                if (gradeTemp >= 0 && gradeTemp <= 100)
                {
                    break;
                }
                
            }
            

        }
          
        i++;
    }
}

void printMainMenu()
{

    printf("**************************************\n");
    printf("          学生成绩管理系统               \n");
    printf("**************************************\n");
    printf("          1 录入学生成绩                \n");
    printf("          2 显示学生成绩                \n");
    printf("        3 统计总分和平均分              \n");
    printf("        4 统计最高分和最低分            \n");
    printf("        5 统计各分数段人数              \n");
    printf("         0     退出                    \n");
    printf("**************************************\n");
    printf("          请选择主菜单序号（0～5）        \n");
    int IntputNumber;
    scanf("%d",&IntputNumber);
    if (IntputNumber == 1)
    {
        system("clear");
        studentGrade(grade);
    }else if (IntputNumber == 2)
    {
        system("clear");
        printStudentGrade(grade);
    }else if (IntputNumber == 3)
    {
        system("clear");
        statisticalTotalAndAverageScores(grade); 
    }else if (IntputNumber == 4)
    {
        system("clear");
        showMaxMin(grade);
    }else if (IntputNumber == 5)
    {
        system("clear");
        CountTheNumberOfPeopleInEachBand(grade);
    }else if (IntputNumber == 0)
    {
        exit(1);
    }
}

void login()
{
    char input[6];
    char password[6] = {'1','2','3','4','5','6'};
    int i;
    i = 0;
    printf("请输入你的密码：");
    while (1)
    {
        scanf("%s",input);
        for ( i = 0; i < 6; i++)
        {
            if (password[i] != input[i])
            {
                printf("密码不正确，请重新输入：");
                break;
            }
                
        }

        if (i == 6)
        {
            break;
        } 
    }
    
    printf("密码正确，登陆成功\n"); 
    sleep(1);
    system("clear");
}

int main()
{
    login();
    printMainMenu(); 
    return 0;
}
