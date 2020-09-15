#include <stdio.h>
#include <stdlib.h>

struct point {
    int x;
    int y;
};

typedef struct {
    char * name;
    int age;
} person;

void print_hello_world();
void print_pointers();
void print_modify_pointer_variable();
void structures();
void move(struct point * p);
void argument_by_reference();
void addone(int n);
void addone_pointer(int * n);
void memory_allocation();
void pascals_triangle();

int main() {
    // print_hello_world();
    // print_pointers();
    // print_modify_pointer_variable();
    // structures();
    // argument_by_reference();
    // memory_allocation();
    pascals_triangle();
    
    return 0;
}

void print_hello_world() {
    printf("Hello world!\n");
}

void print_pointers() {
    int a = 1;

    // int * pointer_to_a = &a;

    int * b = &a;

    printf("a=%d b=%d\n",a,*b);

    a = a+1;

    printf("a=%d b=%d\n",a,*b);

    // printf("The value of a is %d\n", a);
    // printf("The value of a is also %d\n", *pointer_to_a);
}

void print_modify_pointer_variable() {
    int a = 1;
    int * pointer_to_a = &a;

    a += 1;

    printf("The value of a* is %d\n", *pointer_to_a);

    *pointer_to_a += 1;
    printf("The value of a* is now %d\n", *pointer_to_a);
    printf("The value of a is now %d\n", a);
    pointer_to_a += 1;

    printf("The value of a is now %d\n", a);
    printf("The value of a* is now %d\n", *pointer_to_a);
}

void structures() {
    struct point p;
    p.x = 10;
    p.y = 12;
    printf("p.x: %d\n p.y: %d\n", p.x, p.y);

    person pe;
    pe.name = "John";
    pe.age = 25;
    printf("pe.name: %s\n pe.age: %d\n", pe.name, pe.age);

    printf("Before: %d, %d\n", p.x, p.y);
    move(&p);
    printf("After: %d, %d\n", p.x, p.y);
}

void move(struct point * p) {
    (*p).x += 1;
    (*p).y += 1;
    p->x += 1;
    p->y += 1;
}

void argument_by_reference() {
    int n = 1;

    printf("Before: %d\n", n);
    addone(n);
    printf("Afer: %d\n", n);

    printf("Before: %d\n", n);
    addone_pointer(&n);
    printf("Afer: %d\n", n);
}

void addone(int n) {
    n += 1;
}

void addone_pointer(int * n) {
    *n += 1;
}

void memory_allocation() {
    person * myperson = NULL;
    myperson = (person *) malloc(sizeof(person));

    myperson->name = "Blep";
    myperson->age = 3;

    printf("name: %s, age: %d", myperson->name, myperson->age);

    free(myperson); // release the data pointed to
}

void pascals_triangle() {
    int ** pnumbers; // 2d pointer
    int nrows = 3;

    pnumbers = (int **) malloc(nrows * sizeof(int *));

    for (int i = 0; i < nrows; i++) {
        pnumbers[i] = (int *) malloc(sizeof(int));
    }

    pnumbers[0][0] = 1;
    pnumbers[1][0] = 1;
    pnumbers[1][1] = 1;
    pnumbers[2][0] = 1;
    pnumbers[2][1] = 2;
    pnumbers[2][2] = 1;

    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d", pnumbers[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < nrows; i++) {
        free(pnumbers[i]);
    }

    free(pnumbers);
}