#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STUDENTS 100          //最大学生数
#define FILE_NAME "student.dat"   //存储文件名
enum subject {Math,English,Chinese,Physics,History};  //枚举学生的科目

typedef struct {
	long id;
	char name[4];
	int scores[5];
	struct { int month; int day; };
}student;

student students[MAX_STUDENTS];
student* ptr;
ptr = students;
int student_count = 0; //当前学生人数

void showMenu();                  // 显示主菜单
void addStudent();                // 添加学生
void deleteStudent();             // 删除学生
void modifyStudent();             // 修改学生信息
void queryStudent();              // 查询学生
void showAllStudents();           // 显示所有学生
bool saveToFile();                // 保存数据到文件
bool loadFromFile();              // 从文件加载数据
int findStudentById(const char* id); // 根据学号查找学生下标




