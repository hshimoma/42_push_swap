#include <stdio.h>
#include <string.h>

struct Person
{
    char name[50];
    int age;
};

int main(void)
{
    struct Person person1;

    // データの入力
    person1.name, "Alice";
    person1.age = 30;

    // データの表示
    printf("Name: %s\n", person1.name);
    printf("Age: %d\n", person1.age);

    return 0;
}
