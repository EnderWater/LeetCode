#include <iostream>
#include <sstream>
#include <string>

#define DEBUG
#ifdef DEBUG
#include <crtdbg.h>
#include <assert.h>
#endif

using namespace std;

class Node {
    public:
    Node* next;
    string data;
    
    Node(string d) : data(d), next(nullptr) {}
    Node(string d, Node* n) : next(n), data(d) {}
};

class Stack {
    public:
    Node* head;
    int size;

    Stack() : head(nullptr), size(0) {}
    ~Stack(){
        while (head != nullptr){
            Node* next = head->next;
            delete head;
            head = next;
        }
    }

    void push(string newData){
        // Creates a new node and sets the new nodes next to the current head
        Node* newNode = new Node(newData, head);
        // The current head is replaced with the new node; effectively completing the push
        head = newNode;
        size++;
    }

    string pop(){
        if (head == nullptr)
            return "";
        // Saves the data to be returned
        string data = head->data;
        // Saves the next node to be set as the new head
        Node* temp = head->next;
        // Deletes the head node to save memory
        delete head;
        head = temp;
        
        size--;

        return data;
    }

    int sizeOf(){
        return size;
    }

    void clear(){
        while (head != nullptr){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        size = 0;
    }
};

class BrowserHistory {
public:
    string home;
    string currentURL;
    Stack backwardHistory;
    Stack forwardHistory;

    BrowserHistory(string homepage) : home(homepage), currentURL(homepage) {}
    
    void visit(string url) {
        backwardHistory.push(currentURL);
        currentURL = url;
        forwardHistory.clear();

    }
    
    string back(int steps) {
        if (steps > backwardHistory.sizeOf())
            steps = backwardHistory.sizeOf();

        for (int i=0; i < steps; i++){
            forwardHistory.push(currentURL);
            currentURL = backwardHistory.pop();
        }
        return currentURL;
    }
    
    string forward(int steps) {
        if (steps > forwardHistory.sizeOf())
            steps = forwardHistory.sizeOf();

        for (int i=0; i < steps; i++){
            backwardHistory.push(currentURL);
            currentURL = forwardHistory.pop();
        }
        return currentURL;
    }
};

int main(){
    BrowserHistory b("Leetcode");
    b.visit("google");
    b.visit("facebook");
    b.visit("youtube");
    b.back(1);
    b.back(1);
    b.forward(1);
    b.visit("LinkedIn");
    b.forward(2);
    b.back(2);
    b.back(2);
}