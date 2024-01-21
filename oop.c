/*
 * @Author: Dragon
 * @Date: 2023-08-11 16:52:52
 * @LastEditTime: 2024-01-21 15:23:10
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
    void (*speak)(Animal *P_animal, char content[]);
} Animal;

// 类方法的声明
void eat(Animal *P_animal);
void run(Animal *P_animal, int speed);
void speak(Animal *P_animal, char content[]);

Animal *creatAnimal(int age, const char name[]);

int main()
{
    Animal *p_dog;
    p_dog = creatAnimal(10, "Mydog");
    printf("age = %d\n", p_dog->age);
    printf("name = %s\n", p_dog->name);
    p_dog->eat(p_dog);
    p_dog->run(p_dog, 100);
    p_dog->speak(p_dog, "hello");

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
void speak(Animal *P_animal, char content[])
{
    char *buff = NULL;
    buff = content;
    printf("name:%s ", P_animal->name);
    printf("content:%s\n", buff);
}

// 构造函数定义

/**
 * @description: 实例化一个Animal对象 带参数
 * @param {int} age 年龄
 * @param {char} name 名字
 * @return {Animal*} 返回实例化类的地址
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
    P_animal->speak = speak;
    age++;
    return P_animal;
}