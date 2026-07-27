struct User {
    int id;
    char name[50];
};

typedef struct {
    int x;
    int y;
} Point;

int main() {
    Point p1 = {10, 20};
    Point *ptr = &p1;

    p1.x = 30;
    ptr->y = 40;

    return 0;
}
