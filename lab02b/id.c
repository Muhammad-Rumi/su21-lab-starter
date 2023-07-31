// "Copyright [2023] Rumi"
#include <stdio.h>

// Define the Student structure
struct student {
  char name[20];
  int ID;
  int age;
};

int main() {
  struct student dummy;
  // struct student s2;

  // Enter the student detail
  printf("Enter name: ");
  scanf("%s", dummy.name);
  printf("Enter ID: ");
  scanf("%d", &dummy.ID);
  printf("Enter age: ");
  scanf("%d", &dummy.age);

  // It will print the student detail
  printf("\nStudent detail:\n");
  printf("Name: %s\n", dummy.name);
  printf("ID: %d\n", dummy.ID);
  printf("Age: %d\n", dummy.age);

  return 0;
}
