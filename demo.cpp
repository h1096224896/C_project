#include <iostream>
using namespace std;

struct Node {
    int coef;
    int exp;
    Node* next;
};

void addTerm(Node*& poly, int coef, int exp) {
    Node* newNode = new Node;
    newNode->coef = coef;
    newNode->exp = exp;
    newNode->next = nullptr;

    if (poly == nullptr) {
        poly = newNode;
    } else {
        Node* curr = poly;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

Node* addPoly(Node* poly1, Node* poly2) {
    Node* result = nullptr;

    while (poly1 != nullptr && poly2 != nullptr) {
        if (poly1->exp > poly2->exp) {
            addTerm(result, poly1->coef, poly1->exp);
            poly1 = poly1->next;
        } else if (poly1->exp < poly2->exp) {
            addTerm(result, poly2->coef, poly2->exp);
            poly2 = poly2->next;
        } else {
            addTerm(result, poly1->coef + poly2->coef, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while (poly1 != nullptr) {
        addTerm(result, poly1->coef, poly1->exp);
        poly1 = poly1->next;
    }

    while (poly2 != nullptr) {
        addTerm(result, poly2->coef, poly2->exp);
        poly2 = poly2->next;
    }

    return result;
}

void printPoly(Node* poly) {
    while (poly != nullptr) {
        cout << poly->coef << "x^" << poly->exp;
        if (poly->next != nullptr) {
            cout << " + ";
        }
        poly = poly->next;
    }
    cout << endl;
}

int main() {
    Node* poly1 = nullptr; 
    addTerm(poly1, 3, 2);
    addTerm(poly1, 4, 1);
    addTerm(poly1, 2, 0);
    cout << "Poly1: ";
    printPoly(poly1);

    Node* poly2 = nullptr;
    addTerm(poly2, 1, 3);
    addTerm(poly2, 2, 1);
    addTerm(poly2, 5, 0);
    cout << "Poly2: ";
    printPoly(poly2);

    Node* result = addPoly(poly1, poly2);
    cout << "Result: ";
    printPoly(result);

    return 0;
}