#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct poly_node {
    float coef;
    int expx, expy, expz;
    struct poly_node *link;
} POLY;

POLY *getNode(), *add_poly(POLY *, POLY *), *delete(POLY *, POLY *);
void read_poly(POLY *, int), print_poly(POLY *), attach(float, POLY *, POLY **), evaluate(POLY *);
int compare(POLY *, POLY *);

void main() {
    int n1, n2;
    POLY *POLY1 = getNode(), *POLY2 = getNode(), *POLYSUM = getNode();
    POLY1->link = POLY1; POLY2->link = POLY2; POLYSUM->link = POLYSUM;
    printf("Enter number of terms for both polynomials\n");
    scanf("%d%d", &n1, &n2);
    printf("Enter 1st Polynomial\n"); read_poly(POLY1, n1); printf("1st Polynomial:\n"); print_poly(POLY1);
    printf("Enter 2nd Polynomial\n"); read_poly(POLY2, n2); printf("2nd Polynomial:\n"); print_poly(POLY2);
    POLYSUM = add_poly(POLY1, POLY2);
    printf("Resultant Polynomial:\n"); print_poly(POLYSUM);
    evaluate(POLYSUM);
}

POLY *getNode() {
    POLY *temp = (POLY *)malloc(sizeof(POLY));
    if (!temp) exit(0);
    return temp;
}

void read_poly(POLY *head, int n) {
    POLY *temp = head;
    for (int i = 0; i < n; i++) {
        POLY *new = getNode();
        printf("Enter Coef and Exps\n");
        scanf("%f%d%d%d", &new->coef, &new->expx, &new->expy, &new->expz);
        temp->link = new; temp = temp->link;
    }
    temp->link = head;
}

void print_poly(POLY *head) {
    for (POLY *temp = head->link; temp != head; temp = temp->link)
        printf("%f*X^%d*Y^%d*Z^%d\t", temp->coef, temp->expx, temp->expy, temp->expz);
    printf("\n");
}

POLY *add_poly(POLY *h1, POLY *h2) {
    POLY *temp1 = h1->link, *temp2, *result = getNode(), *tempres = result;
    float cf;
    while (temp1 != h1) {
        temp2 = h2->link;
        while (temp2 != h2) {
            if (compare(temp1, temp2) == 1) {
                cf = temp1->coef + temp2->coef;
                if (cf) attach(cf, temp1, &tempres);
                temp1 = temp1->link; h2 = delete(h2, temp2); temp2 = h2->link;
            } else temp2 = temp2->link;
        }
        if (temp1 != h1) attach(temp1->coef, temp1, &tempres), temp1 = temp1->link;
    }
    for (temp2 = h2->link; temp2 != h2; temp2 = temp2->link)
        attach(temp2->coef, temp2, &tempres);
    tempres->link = result;
    return result;
}

int compare(POLY *t1, POLY *t2) {
    return (t1->expx == t2->expx && t1->expy == t2->expy && t1->expz == t2->expz) ? 1 : 2;
}

void attach(float cf, POLY *exptemp, POLY **tempres) {
    POLY *new = getNode();
    *new = (POLY){.coef = cf, .expx = exptemp->expx, .expy = exptemp->expy, .expz = exptemp->expz};
    (*tempres)->link = new; *tempres = new;
}

POLY *delete(POLY *head, POLY *temp) {
    POLY *prev = head, *pres = head->link;
    while (pres != temp) prev = pres, pres = pres->link;
    prev->link = pres->link; free(pres);
    return head;
}

void evaluate(POLY *head) {
    float result = 0.0; int x, y, z;
    printf("Enter exponents\n"); scanf("%d%d%d", &x, &y, &z);
    for (POLY *temp = head->link; temp != head; temp = temp->link)
        result += temp->coef * pow(x, temp->expx) * pow(y, temp->expy) * pow(z, temp->expz);
    printf("Result after evaluation: %f\n", result);
}
