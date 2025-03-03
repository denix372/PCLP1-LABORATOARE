#include <stdio.h>

struct multime {
unsigned char a; //Obs: merge si cu int
};

void init(struct multime *m) { 
    m->a = 0; 
}

void add(struct multime *m, int x) { 
    m->a = m->a | 1 << x; //Seteaza bitul 1
}

void del(struct multime *m, int x) { 
    m->a = m->a & ~(1 << x);  //Seteaza bitul zero
}

void print(struct multime *m) { 
    int i;
    for (i = 0; i < 8; i++) 
        if(m->a & (1<<i)) printf("%d ", i);
    printf("\n");
}

int contains(struct multime *m, int x) 
{
    return (m->a & (1<<x)) != 0;
}

int main() { 
    int n;
    struct multime m;
    init(&m);

    add(&m,0);add(&m,1); add(&m,5); add(&m,6);
    printf("Se adauga bitii 0 1 5 si 6 =>");
    print(&m);

    if (contains(&m, 5)) printf("multimea %d contine bitul 5\n", m.a);
    
    del(&m, 0); del(&m, 5); del(&m, 6);
    if (contains(&m, 5)==0) printf("multimea %d NU contine bitul 5\n", m.a);
    return 0;
}