/*
 * @Author: Dragon
 * @Date: 2023-08-11 16:52:52
 * @LastEditTime: 2023-08-16 10:17:50
 * @FilePath: \oop\oop.c
 * @Description:C语言面向对象尝试
 * @Wearing:  Read only, do not modify place!!!
 * @Shortcut keys:  ctrl+alt+/ ctrl+alt+t
 */

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>
// 使用了新github账号 重新上传 修改
typedef struct Animal Animal; // 声明一个类
typedef struct Animal         // 定义类的属性和方法
{
    // 属性
    int age;
    char name[10];
    // 方法
    void (*eat)(Animal *P_animal);
    void (*run)(Animal *P_animal, int speed);
} Animal;
// 类方法的声明
void eat(Animal *P_animal);
void run(Animal *P_animal, int speed);

Animal *creatAnimal(int age, const char name[]);

int main()
{
    Animal *p_dog;
    p_dog = creatAnimal(10, "Mydog");
    printf("age = %d\n", p_dog->age);
    printf("name = %s\n", p_dog->name);
    p_dog->eat(p_dog);
    p_dog->run(p_dog, 100);

    return 0;
}
// 方法定义
void eat(Animal *P_animal)
{
    printf("name:%s ", P_animal->name);
    printf("eating\n");
}
void run(Animal *P_animal, int speed)
{
    printf("name:%s ", P_animal->name);
    printf("speed:%d\n", speed);
}

// 构造函数定义

/**
 * @description:
 * @param {int} age
 * @param {char} name
 * @return {*}
 */
Animal *creatAnimal(int age, const char name[])
{
    Animal *P_animal = malloc(sizeof(Animal));
    if (!P_animal)
    {
        return NULL;
    }
    // 属性赋值
    P_animal->age = age;
    strcpy(P_animal->name, name);
    // 方法确定
    P_animal->eat = eat;
    P_animal->run = run;
    age++;
    return P_animal;
}