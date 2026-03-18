#include"014stu_manage.h"

int main(void)
{
	int choice;

    if (!loadFromFile()) {
        printf("首次运行，未检测到数据文件，已创建新数据环境！\n");
    }
    else {
        printf("成功加载 %d 条学生数据！\n", student_count);
    }
    while (true)
    {
        showMenu();
        puts("请输入所要执行的功能代码。");
        if (scanf_s("%d", &choice) != 1 || choice < 0 || choice >8)
        {
            puts("输入错误，请输入正确的序号。");
            while (getchar() != '\0')               
                continue;
        }
        else
        {
            puts("====================================");
        }
        switch (choice) {
            case 1: addStudent(*ptr); break;
            case 2: queryStudent(*ptr); break;
            case 3: analysisStudent(*ptr); break;
            case 4: saveToFile(*ptr); break;
            case 5: loadFromFile(); break;
            case 6: showAllStudents(*ptr); break;
            case 7: modifyStudent(*ptr); break;
            case 8: getNumber(); break;
            case 0:
                if (loadFromFile())
                    puts("数据已经成功保存！");
                else
                    puts("数据未成功保存。");
                exit(0);
            default: puts("输入错误，请重新输入。");


        }
    }
    return 0;
}

void showMenu(void)
{
    puts("\n==========学生成绩存储与分析系统==========\n");
    puts("1.添加学生。");
    puts("2.查询学生。");
    puts("3.分析成绩并打印。");
    puts("4.保存至指定文件中。");
    puts("5.从文件加载数据。");
    puts("6.显示所有学生。");
    puts("7.修改学生信息。");
    puts("8.获取一个幸运数字。");
    puts("0.退出系统。")
}

void getNumber(void)
{ 
    int random_int;
    int max = 100;
    int min = 77;
    
    
    srand((unsigned int)time(NULL));   
    random_int = rand() % (max - min + 1) + min;
    //生成[min,max]范围内的随机数;
    printf("今天，你的考试幸运分数是：__________\b\b\b\b\b\b\%d",
        random_int);

}

bool loadFormFile()
{

}
void addStudent(struct student *ptr)
{
    if (ptr == NULL) { //避免程序崩溃
        printf("错误：传入的指针为空指针。");
        exit(0);
    }

    for (int i = student_count ; i < MAX_STUDENTS; i++)
    {
        char temp[LEN];
        long id;
        int month[2]; int day[2];

        puts("请输入学生学号。");
        if (scanf_s("%ld", &id) != 1)
        {
            puts("输入错误。"); exit(0);
        }
        puts("请输入学生姓名");
        s_gets(temp, LEN);
        //分配内存以存储姓名
        ptr->name = (long*)malloc(sizeof(long) * LEN);
        //把名字拷贝到动态分配的内存中
        stcpy(ptr->name, temp);
       
        puts("请输入学生出生月份（eg:11）");
        if (scanf_s("%d", &month) != 1)
        {
            puts("输入错误。"); exit(0);
        }
        puts("请输入学生出生日份（eg:09）");
        if (scanf_s("%d", &day) != 1)
        {
            puts("输入错误。"); exit(0);
        }

    }


}